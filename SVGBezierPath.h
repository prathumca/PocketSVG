/*
 * This file is part of the PocketSVG package.
 * Copyright (c) Ponderwell, Ariel Elkin, Fjölnir Ásgeirsson, and Contributors
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SVGPortability.h"

NS_ASSUME_NONNULL_BEGIN

@class SVGBezierPath;

FOUNDATION_EXTERN CGRect SVGAdjustCGRectForContentsGravity(CGRect aRect, CGSize aSize, NSString *aGravity);
FOUNDATION_EXTERN CGRect SVGBoundingRectForPaths(NSArray<SVGBezierPath*> *paths);
FOUNDATION_EXTERN void SVGDrawPaths(NSArray<SVGBezierPath*> *paths, CGContextRef ctx, CGRect rect,
                                    __nullable CGColorRef defaultFillColor,
                                    __nullable CGColorRef defaultStrokeColor);
FOUNDATION_EXTERN void SVGDrawPathsWithBlock(NSArray<SVGBezierPath*> * const paths,
                                             CGContextRef const ctx,
                                             CGRect rect,
                                             void (^drawingBlock)(SVGBezierPath *path));

/// A NSBezierPath or UIBezierPath subclass that represents an SVG path
/// and its SVG attributes
@interface SVGBezierPath : PSVGBezierPath


/*!
 *  @discussion A set of paths and their attributes.
 *
 */
@property(nonatomic, readonly) NSDictionary<NSString*, id> *svgAttributes;


/*!
 *  @discussion The string representation of an SVG.
 *
 */
@property(nonatomic, readonly) NSString *SVGRepresentation;



/*!
 *  Returns an array of SVGBezierPaths given an SVG's URL.
 *
 *  @param aURL The URL from which to load an SVG.
 *
 */
+ (NSArray<SVGBezierPath*> *)pathsFromSVGAtURL:(NSURL *)aURL;


/*!
 *  Returns an array of paths given the XML string of an SVG.
 *
 */
+ (NSArray *)pathsFromSVGString:(NSString *)svgString;


#if !TARGET_OS_IPHONE
@property(nonatomic, readonly) CGPathRef CGPath;
#endif


+ (void)resetCache;


#if !TARGET_OS_IPHONE
- (void)applyTransform:(CGAffineTransform)transform;
#endif
@end
NS_ASSUME_NONNULL_END

