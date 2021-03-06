/* { dg-do compile } */
// { dg-additional-options "-Wno-objc-root-class" }

@protocol MyProto1 
@optional
- (void) FOO;
@optional
- (void) FOO;
@optional 
- (void) REQ;
@optional
@end

@interface  MyProto2 <MyProto1>
@required 		/* { dg-error ".@required. is allowed in @protocol context only" }  */
- (void) FOO2;
@optional		/* { dg-error ".@optional. is allowed in @protocol context only" }  */
- (void) FOO3;
@end

@implementation MyProto2
- (void) FOO2{}
- (void) FOO3{}
@end
