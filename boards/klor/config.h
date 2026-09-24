/*
Copyright 2022 GEIST <@geigeigeist>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// ┌─────────────────────────────────────────────────┐
// │ k e y   m a t r i x                             │
// └─────────────────────────────────────────────────┘

#define DEBOUNCE 5

// ┌─────────────────────────────────────────────────┐
// │ s p l i t   c o m m u n i c a t i o n           │
// └─────────────────────────────────────────────────┘

#define USE_SERIAL
#define SOFT_SERIAL_PIN GP4
#define SERIAL_USE_MULTI_TRANSACTION
//#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_USB_DETECT

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT


// ┌─────────────────────────────────────────────────┐
// │ e n c o d e r s                                 │
// └─────────────────────────────────────────────────┘

#define ENCODER_RESOLUTION 2


// ┌─────────────────────────────────────────────────┐
// │ o l e d s                                       │
// └─────────────────────────────────────────────────┘



// ┌─────────────────────────────────────────────────┐
// │ r g b   l e d s                                 │
// └─────────────────────────────────────────────────┘

#define LAYOUT LAYOUT_saegewerk
