
// NanorepUI version number: v1.6.1 

// ===================================================================================================
// Copyright © 2018 nanorep.
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
    Error
};

