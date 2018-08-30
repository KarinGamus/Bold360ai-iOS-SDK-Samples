
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

/************************************************************/
// MARK: - AgentType
/************************************************************/

/// An AgentType is an enum of different agent states
typedef NS_ENUM(NSInteger, AgentType) {
    /// Sent when agent type is bot
    Bot,
    /// Sent when agent type is live
    Live,
    /// Sent when agent type is none
    None = -1
};
