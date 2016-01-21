#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Enum describing various styles that an image can be rendered in
typedef enum : NSUInteger {
    /// No image should be rendered
    HUBComponentImageStyleNone,
    /// The image should be rendered in a rectangular shape
    HUBComponentImageStyleRectangular,
    /// The image should be rendered in a circular shape
    HUBComponentImageStyleCircular
} HUBComponentImageStyle;

/**
 *  Protocol defining the public API of an object that describes image data for a Component in the Hub Framework
 *
 *  You don't conform to this protocol yourself, instead the Hub Framework will create implementations of it for you
 *  based on the data supplied to a `HUBComponentModelBuilder` or through JSON data.
 */
@protocol HUBComponentImageData <NSObject>

/**
 *  The style that the image should be rendered in
 *
 *  If HUBComponentImageStyleNone, that indicates to a component that no image should actually be rendered. This might
 *  be the case of the API user wishes to use the image for another purpose than rendering in a component (such as
 *  providing it to an external data API user). See `HUBComponentImageStyle` for more information.
 */
@property (nonatomic, readonly) HUBComponentImageStyle style;

/**
 *  Any HTTP URL of a remote image that should be downloaded and then rendered
 *
 *  The Hub Framework will take care of the image downloading itself, and will notify a component once that operation is
 *  completed, so a component normally doesn't have to interact with this property itself.
 */
@property (nonatomic, copy, readonly, nullable) NSURL *URL;

/**
 *  Any identifier of an icon that should be used either as a placeholder image before the actual image has been downloaded,
 *  or as a permanent image.
 *
 *  It's up to a component how to enterpret this identifier, and turn it into an actual `UIImage` that can be rendered.
 */
@property (nonatomic, copy, readonly, nullable) NSString *iconIdentifier;

@end

NS_ASSUME_NONNULL_END
