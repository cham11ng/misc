import * as React from 'react';

import TooltipPosition from 'app/enums/TooltipPosition';
import TooltipState, { TooltipComponentProps } from 'app/domain/misc/TooltipProperties';

/**
 * HOC to inject the tooltip properties into the components
 * to show box shadow in scrollable elements.
 *
 * @param {number} distance
 * @param {TooltipPosition=TooltipPosition.TOP} position
 * @returns {React.ReactNode}
 */
function injectTooltipProperties<T extends React.Component<TooltipComponentProps, TooltipState>>(
  distance: number,
  position: TooltipPosition = TooltipPosition.TOP
) {
  return (WrappedComponent: new (props: TooltipComponentProps) => T): React.ReactNode => {
    class Tooltip extends React.Component<{}, TooltipState> {
      constructor(props: {}) {
        super(props);

        this.state = {
          top: 0,
          left: 0,
          isActive: false
        };
      }

      toggleTooltip = () => {
        this.setState(prevState => ({ isActive: !prevState.isActive }));
      };

      handleMouseMove = (e: any) => {
        let left = e.clientX;
        let top = e.clientY;

        switch (position) {
          case TooltipPosition.TOP:
            top -= distance;
            break;

          case TooltipPosition.BOTTOM:
            top += distance;
            break;

          case TooltipPosition.LEFT:
            left -= distance;
            break;

          case TooltipPosition.RIGHT:
            left += distance;
            break;

          default:
        }

        this.setState({ top, left });
      };

      render() {
        return (
          <WrappedComponent
            tooltipProperties={this.state}
            toggleTooltip={this.toggleTooltip}
            handleMouseMove={this.handleMouseMove}
          />
        );
      }
    }

    return Tooltip;
  };
}

export default injectTooltipProperties;
