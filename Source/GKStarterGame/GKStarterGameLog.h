// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "Stats/Stats.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGKStarterGame, Log, All);

#define GKSG_FATAL(Format, ...)   UE_LOG(LogGKStarterGame, Fatal, Format, ##__VA_ARGS__)
#define GKSG_ERROR(Format, ...)   UE_LOG(LogGKStarterGame, Error, Format, ##__VA_ARGS__)
#define GKSG_WARNING(Format, ...) UE_LOG(LogGKStarterGame, Warning, Format, ##__VA_ARGS__)
#define GKSG_DISPLAY(Format, ...) UE_LOG(LogGKStarterGame, Display, Format, ##__VA_ARGS__)
#define GKSG_LOG(Format, ...)     UE_LOG(LogGKStarterGame, Log, Format, ##__VA_ARGS__)
#define GKSG_VERBOSE(Format, ...) UE_LOG(LogGKStarterGame, Verbose, Format, ##__VA_ARGS__)
#define GKSG_VERYVERBOSE(Format, ...) UE_LOG(LogGKStarterGame, VeryVerbose, Format, ##__VA_ARGS__)

DECLARE_STATS_GROUP(TEXT("GKSG"), STATGROUP_GKStarterGame, STATCAT_Advanced);
