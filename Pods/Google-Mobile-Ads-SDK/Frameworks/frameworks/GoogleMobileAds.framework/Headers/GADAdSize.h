//
//  GADAdSize.h
//  Google Mobile Ads SDK
//
//  Copyright 2012 Google Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAdsDefines.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// A valid GADAdSize is considered to be one of the predefined GADAdSize constants or a GADAdSize
/// constructed by GADAdSizeFromCGSize, GADAdSizeFullWidthPortraitWithHeight,
/// GADAdSizeFullWidthLandscapeWithHeight.
///
/// Do not create a GADAdSize manually. Use one of the kGADAdSize constants. Treat GADAdSize as an
/// opaque type. Do not access any fields directly. To obtain a concrete CGSize, use the function
/// CGSizeFromGADAdSize().
typedef struct GAD_BOXABLE GADAdSize GADAdSize;

/// Ad size.
///
/// @see typedef GADAdSize
struct GAD_BOXABLE GADAdSize {
  CGSize size;       ///< The ad size. Don't modify this value directly.
  NSUInteger flags;  ///< Reserved.
};

#pragma mark Standard Sizes

/// iPhone and iPod Touch ad size. Typically 320x50.
GAD_EXTERN GADAdSize const kGADAdSizeBanner;

/// Taller version of kGADAdSizeBanner. Typically 320x100.
GAD_EXTERN GADAdSize const kGADAdSizeLargeBanner;

/// Medium Rectangle size for the iPad (especially in a UISplitView's left pane). Typically 300x250.
GAD_EXTERN GADAdSize const kGADAdSizeMediumRectangle;

/// Full Banner size for the iPad (especially in a UIPopoverController or in
/// UIModalPresentationFormSheet). Typically 468x60.
GAD_EXTERN GADAdSize const kGADAdSizeFullBanner;

/// Leaderboard size for the iPad. Typically 728x90.
GAD_EXTERN GADAdSize const kGADAdSizeLeaderboard;

/// Skyscraper size for the iPad. Mediation only. AdMob/Google does not offer this size. Typically
/// 120x600.
GAD_EXTERN GADAdSize const kGADAdSizeSkyscraper;

/// An ad size that spans the full width of the application in portrait orientation. The height is
/// typically 50 points on an iPhone/iPod UI, and 90 points tall on an iPad UI.
GAD_EXTERN GADAdSize const kGADAdSizeSmartBannerPortrait;

/// An ad size that spans the full width of the application in landscape orientation. The height is
/// typically 32 points on an iPhone/iPod UI, and 90 points tall on an iPad UI.
GAD_EXTERN GADAdSize const kGADAdSizeSmartBannerLandscape;

/// An ad size that spans the full width of its container, with a height dynamically determined by
/// the ad.
GAD_EXTERN GADAdSize const kGADAdSizeFluid;

/// Invalid ad size marker.
GAD_EXTERN GADAdSize const kGADAdSizeInvalid;

#pragma mark Custom Sizes

/// Returns a custom GADAdSize for the provided CGSize. Use this only if you require a non-standard
/// size. Otherwise, use one of the standard size constants above.
GAD_EXTERN GADAdSize GADAdSizeFromCGSize(CGSize size);

/// Returns a custom GADAdSize that spans the full width of the application in portrait orientation
/// with the height provided.
GAD_EXTERN GADAdSize GADAdSizeFullWidthPortraitWithHeight(CGFloat height);

/// Returns a custom GADAdSize that spans the full width of the application in landscape orientation
/// with the height provided.
GAD_EXTERN GADAdSize GADAdSizeFullWidthLandscapeWithHeight(CGFloat height);

#pragma mark Convenience Functions

/// Returns YES if the two GADAdSizes are equal, otherwise returns NO.
GAD_EXTERN BOOL GADAdSizeEqualToSize(GADAdSize size1, GADAdSize size2);

/// Returns a CGSize for the provided a GADAdSize constant. If the GADAdSize is unknown, returns
/// CGSizeZero.
GAD_EXTERN CGSize CGSizeFromGADAdSize(GADAdSize size);

/// Returns YES if |size| is one of the predefined constants or is a custom GADAdSize generated by
/// GADAdSizeFromCGSize.
GAD_EXTERN BOOL IsGADAdSizeValid(GADAdSize size);

/// Returns YES if |size| is a fluid ad size.
GAD_EXTERN BOOL GADAdSizeIsFluid(GADAdSize size);

/// Returns a NSString describing the provided GADAdSize.
GAD_EXTERN NSString *NSStringFromGADAdSize(GADAdSize size);

/// Returns an NSValue representing the GADAdSize.
GAD_EXTERN NSValue *NSValueFromGADAdSize(GADAdSize size);

/// Returns a GADAdSize from an NSValue. Returns kGADAdSizeInvalid if the value is not a GADAdSize.
GAD_EXTERN GADAdSize GADAdSizeFromNSValue(NSValue *value);

#pragma mark Deprecated Macros

#define GAD_SIZE_320x50 CGSizeFromGADAdSize(kGADAdSizeBanner)
#define GAD_SIZE_320x100 CGSizeFromGADAdSize(kGADAdSizeLargeBanner)
#define GAD_SIZE_300x250 CGSizeFromGADAdSize(kGADAdSizeMediumRectangle)
#define GAD_SIZE_468x60 CGSizeFromGADAdSize(kGADAdSizeFullBanner)
#define GAD_SIZE_728x90 CGSizeFromGADAdSize(kGADAdSizeLeaderboard)
#define GAD_SIZE_120x600 CGSizeFromGADAdSize(kGADAdSizeSkyscraper)

NS_ASSUME_NONNULL_END