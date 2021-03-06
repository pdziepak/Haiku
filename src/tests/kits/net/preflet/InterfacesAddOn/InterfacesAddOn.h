/*
 * Copyright 2004-2013 Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Alexander von Gluck, <kallisti5@unixzen.com>
 *		Philippe Houdoin
 * 		Fredrik Modéen
 *		John Scipione, jscipione@gmail.com
 */
#ifndef INTERFACES_ADDON_H
#define INTERFACES_ADDON_H


#include <Box.h>

#include "NetworkSetupAddOn.h"
#include "InterfacesListView.h"


static const uint32 kMsgInterfaceSelected = 'ifce';
static const uint32 kMsgInterfaceToggle = 'onof';
static const uint32 kMsgInterfaceRenegotiate = 'redo';


class BButton;
class BView;

class InterfaceView;

class InterfacesAddOn : public NetworkSetupAddOn, public BBox
{
public:
								InterfacesAddOn(image_id addon_image);
								~InterfacesAddOn();

			const char* 		Name();
			status_t			Save();
			status_t			Revert();

			BView*				CreateView();

			void				AttachedToWindow();
			void				MessageReceived(BMessage* msg);

private:
			InterfacesListView*	fListView;
			InterfaceView*		fSettingsView;
			BButton*			fOnOff;
			BButton*			fRenegotiate;
};


#endif // INTERFACES_ADDON_H

