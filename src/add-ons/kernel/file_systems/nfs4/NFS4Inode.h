/*
 * Copyright 2012-2014 Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Paweł Dziepak, pdziepak@quarnos.org
 */
#ifndef NFS4INODE_H
#define NFS4INODE_H


#include <sys/stat.h>

#include <SupportDefs.h>

#include "Cookie.h"
#include "FileInfo.h"
#include "FileSystem.h"
#include "NFS4Object.h"
#include "ReplyInterpreter.h"


class NFS4Inode : public NFS4Object {
public:
			status_t	GetChangeInfo(uint64* change, bool attrDir = false);
			status_t	ReadLink(void* buffer, size_t* length);

protected:
			status_t	Access(uint32* allowed);

			status_t	CommitWrites();

			status_t	ManualLookUpUp(uint64* fileID);
			status_t	LookUp(const char* name, uint64* change, uint64* fileID,
							FileHandle* handle, bool parent = false);

			status_t	Link(Inode* dir, const char* name,
							ChangeInfo* changeInfo);

	static	status_t	RenameNode(Inode* from, Inode* to, const char* fromName,
							const char* toName, ChangeInfo* fromChange,
							ChangeInfo* toChange, uint64* fileID,
							bool attribute = false);

			status_t	GetStat(AttrValue** values, uint32* count,
							OpenAttrCookie* attr = NULL);
			status_t	WriteStat(OpenState* state, AttrValue* attrs,
							uint32 attrCount);

			status_t	CreateFile(const char* name, int mode, int perms,
							OpenState* state, ChangeInfo* changeInfo,
							uint64* fileID, FileHandle* handle,
							OpenDelegationData* delegation);
			status_t	OpenFile(OpenState* state, int mode,
							OpenDelegationData* delegation);

			status_t	OpenAttr(OpenState* state, const char* name, int mode,
							OpenDelegationData* delegation, bool create);

			status_t	ReadFile(OpenStateCookie* cookie, OpenState* state,
							uint64 position, uint32* length, void* buffer,
							bool* eof);
			status_t	WriteFile(OpenStateCookie* cookie, OpenState* state,
							uint64 position, uint32* length,
							const void* buffer, bool commit = false);

			status_t	CreateObject(const char* name, const char* path,
							int mode, FileType type, ChangeInfo* changeInfo,
							uint64* fileID, FileHandle* handle,
							bool parent = false);
			status_t	RemoveObject(const char* name, FileType type,
							ChangeInfo* changeInfo, uint64* fileID);

			status_t	ReadDirOnce(DirEntry** dirents, uint32* count,
							OpenDirCookie* cookie, bool* eof, uint64* change,
							uint64* dirCookie, uint64* dirCookieVerf,
							bool attribute);

			status_t	OpenAttrDir(FileHandle* handle);

			status_t	TestLock(OpenFileCookie* cookie, LockType* type,
							uint64* position, uint64* length, bool& conflict);
			status_t	AcquireLock(OpenFileCookie* cookie, LockInfo* lockInfo,
							bool wait);
			status_t	ReleaseLock(OpenFileCookie* cookie, LockInfo* lockInfo);
};


#endif	// NFS4INODE_H

