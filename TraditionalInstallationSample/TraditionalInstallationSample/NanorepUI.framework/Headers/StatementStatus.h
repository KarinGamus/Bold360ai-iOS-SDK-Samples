
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

/************************************************************/
// MARK: - StatementStatus
/************************************************************/

/// An StatementStatus is an enum of different statemen states
typedef NS_ENUM(NSInteger, StatementStatus) {
    /// Sent when statement response status is ok
    OK,
    /// Sent when statement response status is pending
    Pending,
    /// Sent when statement response status is error
    Error,
    /// Shouldn't be presented
    Repost
};

