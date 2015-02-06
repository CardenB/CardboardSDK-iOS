//
//  CardboardViewController.h
//  CardboardSDK-iOS
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>


@interface EyeWrapper : NSObject

- (GLKMatrix4)eyeViewMatrix;
- (GLKMatrix4)perspectiveMatrixWithZNear:(float)zNear zFar:(float)zFar;

@end


@protocol StereoRendererDelegate <NSObject>

- (void)setupRendererWithView:(GLKView *)GLView;
- (void)shutdownRendererWithView:(GLKView *)GLView;
- (void)renderViewDidChangeSize:(CGSize)size;

- (void)prepareNewFrameWithHeadViewMatrix:(GLKMatrix4)headViewMatrix;
- (void)drawEyeWithEye:(EyeWrapper *)eye;
- (void)finishFrameWithViewportRect:(CGRect)viewPort;

@optional

- (void)magneticTriggerPressed;

@end


@interface CardboardViewController : GLKViewController

@property (nonatomic, readonly) GLKView *view;
@property (nonatomic, readonly) NSLock *glLock;

@property (nonatomic, assign) id <StereoRendererDelegate> stereoRendererDelegate;
@property (nonatomic) BOOL vrModeEnabled;
@property (nonatomic) BOOL distortionCorrectionEnabled;
@property (nonatomic) BOOL vignetteEnabled;
@property (nonatomic) BOOL chromaticAberrationCorrectionEnabled;
@property (nonatomic) BOOL restoreGLStateEnabled;
@property (nonatomic) BOOL neckModelEnabled;

//- (void)getFrameParameters:(float *)frameParemeters near:(float)near far:(float)far;
- (float *)getFrameParameters:(float *)frameParameters near:(float)near far:(float)far;
- (void)setConvertTapIntoTrigger:(BOOL) enabled;

- (void)initFromUnity:(const char *) unityObjectName;



@end
