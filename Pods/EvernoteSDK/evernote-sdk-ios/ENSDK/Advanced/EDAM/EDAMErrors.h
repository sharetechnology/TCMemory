/*
 * Copyright (c) 2017 by Evernote Corporation, All rights reserved.
 *
 * Use of the source code and binary libraries included in this package
 * is permitted under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#import <Foundation/Foundation.h>

#import "ENTProtocol.h"
#import "ENTException.h"
#import "FATObject.h"
#import "EDAMTypes.h"

enum EDAMErrorCode {
  EDAMErrorCode_UNKNOWN = 1,
  EDAMErrorCode_BAD_DATA_FORMAT = 2,
  EDAMErrorCode_PERMISSION_DENIED = 3,
  EDAMErrorCode_INTERNAL_ERROR = 4,
  EDAMErrorCode_DATA_REQUIRED = 5,
  EDAMErrorCode_LIMIT_REACHED = 6,
  EDAMErrorCode_QUOTA_REACHED = 7,
  EDAMErrorCode_INVALID_AUTH = 8,
  EDAMErrorCode_AUTH_EXPIRED = 9,
  EDAMErrorCode_DATA_CONFLICT = 10,
  EDAMErrorCode_ENML_VALIDATION = 11,
  EDAMErrorCode_SHARD_UNAVAILABLE = 12,
  EDAMErrorCode_LEN_TOO_SHORT = 13,
  EDAMErrorCode_LEN_TOO_LONG = 14,
  EDAMErrorCode_TOO_FEW = 15,
  EDAMErrorCode_TOO_MANY = 16,
  EDAMErrorCode_UNSUPPORTED_OPERATION = 17,
  EDAMErrorCode_TAKEN_DOWN = 18,
  EDAMErrorCode_RATE_LIMIT_REACHED = 19,
  EDAMErrorCode_BUSINESS_SECURITY_LOGIN_REQUIRED = 20,
  EDAMErrorCode_DEVICE_LIMIT_REACHED = 21,
  EDAMErrorCode_OPENID_ALREADY_TAKEN = 22,
  EDAMErrorCode_INVALID_OPENID_TOKEN = 23,
  EDAMErrorCode_USER_NOT_ASSOCIATED = 24,
  EDAMErrorCode_USER_NOT_REGISTERED = 25,
  EDAMErrorCode_USER_ALREADY_ASSOCIATED = 26,
  EDAMErrorCode_ACCOUNT_CLEAR = 27
};

enum EDAMInvalidContactReason {
  EDAMInvalidContactReason_BAD_ADDRESS = 0,
  EDAMInvalidContactReason_DUPLICATE_CONTACT = 1,
  EDAMInvalidContactReason_NO_CONNECTION = 2
};

/*
 * This exception is thrown by EDAM procedures when a call fails as a result of
 * a problem that a caller may be able to resolve.  For example, if the user
 * attempts to add a note to their account which would exceed their storage
 * quota, this type of exception may be thrown to indicate the source of the
 * error so that they can choose an alternate action.
 * 
 * This exception would not be used for internal system errors that do not
 * reflect user actions, but rather reflect a problem within the service that
 * the user cannot resolve.
 * 
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 * 
 * parameter:  If the error applied to a particular input parameter, this will
 *   indicate which parameter.
 */
@interface EDAMUserException : FATException 
@property (nonatomic, strong) NSNumber * errorCode; // int
@property (nonatomic, strong) NSString * parameter;
@end

/*
 * This exception is thrown by EDAM procedures when a call fails as a result of
 * a problem in the service that could not be changed through caller action.
 * 
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 * 
 * message:  This may contain additional information about the error
 * 
 * rateLimitDuration:  Indicates the minimum number of seconds that an application should
 *   expect subsequent API calls for this user to fail. The application should not retry
 *   API requests for the user until at least this many seconds have passed. Present only
 *   when errorCode is RATE_LIMIT_REACHED,
 */
@interface EDAMSystemException : FATException 
@property (nonatomic, strong) NSNumber * errorCode; // int
@property (nonatomic, strong) NSString * message;
@property (nonatomic, strong) NSNumber * rateLimitDuration; // int32_t
@end

/*
 * This exception is thrown by EDAM procedures when a caller asks to perform
 * an operation on an object that does not exist.  This may be thrown based on an invalid
 * primary identifier (e.g. a bad GUID), or when the caller refers to an object
 * by another unique identifier (e.g. a User's email address).
 * 
 * identifier:  A description of the object that was not found on the server.
 *   For example, "Note.notebookGuid" when a caller attempts to create a note in a
 *   notebook that does not exist in the user's account.
 * 
 * key:  The value passed from the client in the identifier, which was not
 *   found. For example, the GUID that was not found.
 */
@interface EDAMNotFoundException : FATException 
@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * key;
@end

/*
 * An exception thrown when the provided Contacts fail validation. For instance,
 * email domains could be invalid, phone numbers might not be valid for SMS,
 * etc.
 * 
 * We will not provide individual reasons for each Contact's validation failure.
 * The presence of the Contact in this exception means that the user must figure
 * out how to take appropriate action to fix this Contact.
 * 
 * <dl>
 *   <dt>contacts</dt>
 *   <dd>The list of Contacts that are considered invalid by the service</dd>
 * 
 *   <dt>parameter</dt>
 *   <dd>If the error applied to a particular input parameter, this will
 *   indicate which parameter.</dd>
 * 
 *   <dt>reasons</dt>
 *   <dd>If supplied, the list of reasons why the server considered a contact invalid,
 *   matching, in order, the list returned in the contacts field.</dd>
 * </dl>
 */
@interface EDAMInvalidContactsException : FATException 
@property (nonatomic, strong) NSArray<EDAMContact *> * contacts;
@property (nonatomic, strong) NSString * parameter;
@property (nonatomic, strong) NSArray<NSNumber *> * reasons;
@end

@interface ErrorsConstants : NSObject 
@end