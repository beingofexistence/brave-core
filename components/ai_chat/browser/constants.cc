/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/ai_chat/browser/constants.h"
#include "base/strings/strcat.h"

namespace ai_chat {

base::span<const webui::LocalizedString> GetLocalizedStrings() {
  constexpr webui::LocalizedString kLocalizedStrings[] = {
      {"siteTitle", IDS_CHAT_UI_TITLE},
      {"summarizeFailedLabel", IDS_CHAT_UI_SUMMARIZE_FAILED_LABEL},
      {"acceptButtonLabel", IDS_CHAT_UI_ACCEPT_BUTTON_LABEL},
      {"summarizeButtonLabel", IDS_CHAT_UI_SUMMARIZE_BUTTON_LABEL},
      {"aboutTitle", IDS_CHAT_UI_ABOUT_TITLE},
      {"aboutDescription", IDS_CHAT_UI_ABOUT_DESCRIPTION},
      {"aboutDescription_2", IDS_CHAT_UI_ABOUT_DESCRIPTION_2},
      {"placeholderLabel", IDS_CHAT_UI_PLACEHOLDER_LABEL},
      {"enableQuestionsTitle", IDS_CHAT_UI_ENABLE_QUESTIONS_TITLE},
      {"enableQuestionsDesc", IDS_CHAT_UI_ENABLE_QUESTIONS_DESC},
      {"enableQuestionsButtonLabel", IDS_CHAT_UI_ENABLE_QUESTIONS_BUTTON_LABEL},
      {"noThanksButtonLabel", IDS_CHAT_UI_NO_THANKS_BUTTON_LABEL},
      {"pageContentWarning", IDS_CHAT_UI_PAGE_CONTENT_WARNING},
      {"errorNetworkLabel", IDS_CHAT_UI_ERROR_NETWORK},
      {"errorRateLimit", IDS_CHAT_UI_ERROR_RATE_LIMIT},
      {"retryButtonLabel", IDS_CHAT_UI_RETRY_BUTTON_LABEL}};

  return kLocalizedStrings;
}

bool UsesLlama2PromptTemplate(const std::string& model) {
  if (model.find("llama-2") != std::string::npos &&
      model.find("chat") != std::string::npos) {
    return true;
  }

  return false;
}

}  // namespace ai_chat
