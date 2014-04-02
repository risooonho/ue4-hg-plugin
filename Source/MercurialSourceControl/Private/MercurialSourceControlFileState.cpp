//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------

#include "MercurialSourceControlPrivatePCH.h"
#include "MercurialSourceControlFileState.h"

namespace MercurialSourceControl {

int32 FFileState::GetHistorySize() const
{
	return History.Num();
}

FSourceControlRevisionPtr FFileState::GetHistoryItem(int32 HistoryIndex) const
{
	check(History.IsValidIndex(HistoryIndex));
	return History[HistoryIndex];
}

FSourceControlRevisionPtr FFileState::FindHistoryRevision(int32 RevisionNumber) const
{
	for (int32 i = 0; i < History.Num(); ++i)
	{
		if (History[i]->GetRevisionNumber() == RevisionNumber)
		{
			return History[i];
		}
	}
	return NULL;
}

FName FFileState::GetIconName() const
{
	// TODO
	return NAME_None;
}

FName FFileState::GetSmallIconName() const
{
	// TODO
	return NAME_None;
}

FText FFileState::GetDisplayName() const
{
	// TODO
	return FText();
}

FText FFileState::GetDisplayTooltip() const
{
	// TODO
	return FText();
}

const FString& FFileState::GetFilename() const
{
	return Filename;
}

const FDateTime& FFileState::GetTimeStamp() const
{
	return TimeStamp;
}

bool FFileState::CanCheckout() const
{
	return true;
}

bool FFileState::IsCheckedOut() const
{
	// TODO: figure out how this interacts with CanCheckout()
	return false;
}

bool FFileState::IsCheckedOutOther(FString* Who) const
{
	// Mercurial doesn't keep track of who checked what out
	return false;
}

bool FFileState::IsCurrent() const
{
	// TODO
	return true;
}

bool FFileState::IsSourceControlled() const
{
	return (Status != EFileStatus::NotTracked) && (Status != EFileStatus::Unknown);
}

bool FFileState::IsAdded() const
{
	return Status == EFileStatus::Added;
}

bool FFileState::IsDeleted() const
{
	return Status == EFileStatus::Deleted;
}

bool FFileState::IsIgnored() const
{
	return Status == EFileStatus::Ignored;
}

bool FFileState::CanEdit() const
{
	return true;
}

bool FFileState::IsUnknown() const
{
	return Status == EFileStatus::Unknown;
}

bool FFileState::IsModified() const
{
	return Status == EFileStatus::Modified;
}

} // namespace MercurialSourceControl