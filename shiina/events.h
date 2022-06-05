#pragma once

#include <ntifs.h>

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImage, HANDLE ProcessId, PIMAGE_INFO ImageInfo);


