import { AxiosError } from 'axios';
import * as HttpStatus from 'http-status-codes';
import { Request, Response, NextFunction } from 'express';

import log from '../utils/log';
import errors from '../lang/errors';
import AuthError from '../errors/AuthError';
import RequestMethod from '../enums/RequestMethod';
import CallbackParams from './CallbackParams';
import UnauthorizedError from '../errors/UnauthorizedError';


export interface LoggedInUser {
  id: string;
  email: string
}

export interface CallbackParams {
  user?: LoggedInUser;
  method: RequestMethod;
  params: Dictionary<string>;
  headers: IncomingHttpHeaders;
}

/**
 * Higher order function for generating express middleware.
 *
 * @param  {(value:CallbackParams)=>Promise<any>} callback
 * @returns {void}
 */
export function composeMiddleware(
  callback: (value: CallbackParams) => Promise<any>
) {
  return async (req: Request, res: Response, next: NextFunction) => {
    try {
      const { params, method, headers } = req;

      const data = await callback({
        params,
        headers,
        method: method as RequestMethod,
        user: res.locals.data
      });

      if (res) {
        res.locals.data = data;
      }

      next();
    } catch (err) {
      next(handleError(err));
    }
  };
}

/**
 * Handle request error.
 *
 * @param  {AuthError | AxiosError} err
 * @returns {AuthError | AxiosError}
 */
function handleError(err: AuthError | AxiosError): AuthError | AxiosError {
  log('Auth error:', err);

  if (err instanceof AuthError || !err.response) {
    return err;
  }

  switch (err.response.status) {
    case HttpStatus.UNAUTHORIZED:
      return new UnauthorizedError(err.response.data.error.code);

    case HttpStatus.NOT_FOUND:
      return new AuthError(errors.auth.uRLInvalid);

    default:
      return err;
  }
}
