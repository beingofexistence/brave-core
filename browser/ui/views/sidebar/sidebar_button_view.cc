/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/views/sidebar/sidebar_button_view.h"

#include "brave/browser/ui/color/brave_color_id.h"
#include "ui/base/metadata/metadata_impl_macros.h"
#include "ui/gfx/color_palette.h"
#include "ui/views/animation/ink_drop.h"
#include "ui/views/controls/focus_ring.h"
#include "ui/views/controls/highlight_path_generator.h"

SidebarButtonView::SidebarButtonView(const std::u16string& accessible_name) {
  // Locate image at center of the button.
  SetImageHorizontalAlignment(views::ImageButton::ALIGN_CENTER);
  SetImageVerticalAlignment(views::ImageButton::ALIGN_MIDDLE);
  DCHECK(GetInstallFocusRingOnFocus());
  views::FocusRing::Get(this)->SetColorId(gfx::kBraveBlurple300);

  views::InstallRoundRectHighlightPathGenerator(this, gfx::Insets(4),
                                                /*highlight_radius*/ 8);
  views::InkDrop::Get(this)->SetMode(views::InkDropHost::InkDropMode::ON);
  views::InkDrop::Get(this)->SetHighlightOpacity(1.0f);
  views::InkDrop::Get(this)->SetBaseColorId(kColorSidebarItemBackgroundHovered);
  SetHasInkDropActionOnClick(true);
  SetShowInkDropWhenHotTracked(true);

  // Views resulting in focusable nodes later on in the accessibility tree need
  // to have an accessible name for screen readers to see what they are about.
  SetAccessibleName(accessible_name);
}

SidebarButtonView::~SidebarButtonView() = default;

gfx::Size SidebarButtonView::CalculatePreferredSize() const {
  return {kSidebarButtonSize, kSidebarButtonSize};
}

std::u16string SidebarButtonView::GetTooltipText(const gfx::Point& p) const {
  return GetAccessibleName();
}

BEGIN_METADATA(SidebarButtonView, views::ImageButton)
END_METADATA
