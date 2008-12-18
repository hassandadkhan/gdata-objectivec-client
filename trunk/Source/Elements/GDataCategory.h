/* Copyright (c) 2007 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

//
//  GDataCategory.h
//

#import "GDataObject.h"

#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GDATACATEGORY_DEFINE_GLOBALS
#define _EXTERN 
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

_EXTERN NSString* kGDataCategoryLabelScheme _INITIALIZE_AS(@"http://schemas.google.com/g/2005/labels");

_EXTERN NSString* kGDataCategoryLabelStarred          _INITIALIZE_AS(@"starred");
_EXTERN NSString* kGDataCategoryLabelTrashed          _INITIALIZE_AS(@"trashed");
_EXTERN NSString* kGDataCategoryLabelPublished        _INITIALIZE_AS(@"published");
_EXTERN NSString* kGDataCategoryLabelMine             _INITIALIZE_AS(@"mine");
_EXTERN NSString* kGDataCategoryLabelSharedWithDomain _INITIALIZE_AS(@"shared-with-domain");
_EXTERN NSString* kGDataCategoryLabelHidden           _INITIALIZE_AS(@"hidden");

// for categories, like
//  <category scheme="http://schemas.google.com/g/2005#kind"
//        term="http://schemas.google.com/g/2005#event"/>
@interface GDataCategory : GDataObject <GDataExtension> {
}

+ (GDataCategory *)categoryWithScheme:(NSString *)scheme
                                 term:(NSString *)term;

+ (GDataCategory *)categoryWithLabel:(NSString *)label;

- (NSString *)scheme;
- (void)setScheme:(NSString *)str;
- (NSString *)term;
- (void)setTerm:(NSString *)str;
- (NSString *)label;
- (void)setLabel:(NSString *)str;
- (NSString *)labelLang;
- (void)setLabelLang:(NSString *)str;

#pragma mark -

// utilities for extracting a subset of categories
+ (NSArray *)categoriesWithScheme:(NSString *)scheme fromCategories:(NSArray *)array;
+ (NSArray *)categoriesWithSchemePrefix:(NSString *)prefix fromCategories:(NSArray *)array;

+ (NSArray *)categoryLabelsFromCategories:(NSArray *)array;
+ (BOOL)categories:(NSArray *)array containsCategoryWithLabel:(NSString *)label;
@end