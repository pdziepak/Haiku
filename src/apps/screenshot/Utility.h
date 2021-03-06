/*
 * Copyright 2010-2014, Haiku Inc. All rights reserved.
 * Copyright 2010 Wim van der Meer <WPJvanderMeer@gmail.com>
 * Distributed under the terms of the MIT License.
 */
#ifndef UTILITY_H
#define UTILITY_H


#include <Point.h>
#include <Rect.h>
#include <String.h>
#include <TranslatorRoster.h>


// Command constant for sending utility data to the GUI app
const int32 SS_UTILITY_DATA = 'SSUD';


class Utility {
public:
						Utility();
						~Utility();

			void		CopyToClipboard(const BBitmap& screenshot) const;
			status_t	Save(BBitmap* screenshot, const char* fileName,
							uint32 imageType) const;
			BBitmap*	MakeScreenshot(bool includeCursor, bool activeWindow,
							bool includeBorder) const;
			BString		FileNameExtension(uint32 imageType) const;
			status_t	FindTranslator(uint32 imageType, translator_id& id,
							BString* _mimeType = NULL) const;

			BBitmap*	wholeScreen;
			BBitmap*	cursorBitmap;
			BBitmap*	cursorAreaBitmap;
			BPoint		cursorPosition;
			BRect		activeWindowFrame;
			BRect		tabFrame;
			float		borderSize;

	static	const char*	sDefaultFileNameBase;

private:
			void		_MakeTabSpaceTransparent(BBitmap* screenshot,
							BRect frame) const;
			BString		_MimeType(uint32 imageType) const;
};


#endif // UTILITY_H
