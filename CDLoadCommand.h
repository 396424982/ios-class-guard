//
// $Id: CDLoadCommand.h,v 1.3 2004/01/06 01:51:53 nygard Exp $
//

//  This file is part of class-dump, a utility for exmaing the
//  Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004  Steve Nygard

#import <Foundation/NSObject.h>

#include <mach-o/loader.h>

@class CDMachOFile;

@interface CDLoadCommand : NSObject
{
    CDMachOFile *nonretainedMachOFile;

    const struct load_command *loadCommand;
}

+ (id)loadCommandWithPointer:(const void *)ptr machOFile:(CDMachOFile *)aMachOFile;

- (id)initWithPointer:(const void *)ptr machOFile:(CDMachOFile *)aMachOFile;

- (CDMachOFile *)machOFile;

- (const void *)bytes;
- (unsigned long)cmd;
- (unsigned long)cmdsize;

- (NSString *)commandName;
- (NSString *)description;
- (NSString *)extraDescription;

@end
