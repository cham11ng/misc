import * as asyncHooks from 'async_hooks';

class AsyncStore {
  private hook: asyncHooks.AsyncHook;

  /**
   * async_hooks registers callback tracking the lifetime of asynchronous resources.
   * So, during the lifetime of a request it has different unique id i.e. ascynId.
   *
   * storeMap is a mapping variable to store map of asyncId to request payload.
   * For Example: { 1: { reqId: '101' }, 10: { reqId: '102' } }
   *
   * asyncIdToParentStoreMap is also a mapping variable to store asyncId to parent asyncId.
   * It points to parent's corresponding request payload.
   * For Example: { 2: 1, 3: 1, 11: 10, 12: 10 }
   */
  private storeMap = new Map();
  private asyncIdToParentStoreMap = new Map();

  constructor() {
    this.hook = asyncHooks.createHook({
      /**
       * Init callback of async_hooks which initiates the map variable for each asychronous resource.
       *
       * "TCPWRAP" is the type of ascynchronous resource invoked at the beginning of the request.
       * It identifies the initial ascyncId of request and sets current ascyncId as parent.
       * For other ascync resource it sets triggerId which is previous ascnc resource.
       *
       * @param {number} asyncId
       * @param {string} type
       * @param {number} triggerAsyncId
       */
      init: (asyncId: number, type: string, triggerAsyncId: number) => {
        if (this.storeMap.has(triggerAsyncId)) {
          if (type === 'TCPWRAP') {
            this.asyncIdToParentStoreMap.set(asyncId, asyncId);

            return;
          }

          const parentAsyncId = this.getParentAsyncId(triggerAsyncId);
          this.asyncIdToParentStoreMap.set(asyncId, parentAsyncId);
        }
      },

      /**
       * Destroy callback of async_hooks which is invoked after a request is completed.
       *
       * It deletes all the maps created during the lifetime of async resources.
       *
       * @param {number} asyncId
       */
      destroy: (asyncId: number) => {
        if (this.storeMap.has(asyncId)) {
          this.storeMap.delete(asyncId);
        }

        if (this.asyncIdToParentStoreMap.has(asyncId)) {
          this.asyncIdToParentStoreMap.delete(asyncId);
        }
      }
    });

    this.hook.enable();
  }

  /**
   * Set data in store.
   *
   * @param {object} data
   */
  public set(data: object): void {
    const asyncId = this.getCurrentAsyncId();
    const parentAsyncId = this.getParentAsyncId(asyncId);

    this.storeMap.set(parentAsyncId, data);
  }

  /**
   * Get data from store.
   */
  public get() {
    const asyncId = this.getCurrentAsyncId();
    const parentAsyncId = this.getParentAsyncId(asyncId);

    return this.storeMap.get(parentAsyncId);
  }

  /**
   * Set parent asyncId of given asyncId.
   *
   * By Default: Returns parent of current asyncId.
   *
   * @param {number | null} asyncId
   */
  private getParentAsyncId(asyncId: number) {
    return this.asyncIdToParentStoreMap.get(asyncId);
  }

  /**
   * Get current async id.
   *
   * @returns {number}
   */
  private getCurrentAsyncId() {
    return asyncHooks.executionAsyncId();
  }
}

export default AsyncStore;
