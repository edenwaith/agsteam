//
// AGSteam: Steam API Plugin for AGS
// (C) 2011-2014 MonkeyMoto Productions, Inc.
//
// NOTICE: THIS FILE IS NOT OPEN SOURCE, AND SHOULD NEVER LEAVE THE PROPERTIES OF MONKEYMOTO PRODUCTIONS, INC.
// ("MMP") WITHOUT PRIOR EXPRESS WRITTEN PERMISSION INCLUDED AS AN ADDENDUM BELOW, ONLY BY AUTHORIZED
// PERSONNEL ACTING ON BEHALF OF MMP. IF YOU HAVE NOT BEEN SO AUTHORIZED AND HAVE OBTAINED THIS FILE, YOU ARE
// UNDER LEGAL OBLIGATION TO DELETE ALL COPIES OF IT AND ALL DERIVATIVE WORKS IMMEDIATELY. MMP AND AFFILIATED
// PARTIES SHALL NOT BE HELD LIABLE FOR ANY UNAUTHORIZED USAGE OR DISTRIBUTION OF THIS FILE, INTERNALLY OR BY
// ANY THIRD-PARTY. BY ACCESSING THIS FILE YOU ARE AGREEING TO THE TERMS AND CONDITIONS OF THIS NOTICE, AND
// ALL APPLICABLE ADDENDUMS, AND MAY BE HELD LEGALLY RESPONSIBLE FOR UNAUTHORIZED USAGE.
//
// ADDENDUM: MMP RESERVES ALL FIRST-PARTY RIGHTS TO THIS FILE AND ITS CONTENTS, INCLUDING, BUT NOT LIMITED TO
// THE RIGHT TO AUTHORIZE THIRD-PARTY USAGE OF THIS FILE, AND THE RIGHT TO REVOKE SUCH AUTHORIZATION FROM ANY
// THIRD-PARTY. AUTHORIZATION MAY BE GRANTED OR REVOKED AT ANY TIME AND FOR ANY REASON BY MMP. UPON NOTICE OF
// REVOCATION OF RIGHTS, THIRD-PARTIES MUST COMPLY IMMEDIATELY WITH THE REVISED TERMS GIVEN BY MMP. ANY
// ADDENDUMS OR CHANGES TO THIS ADDENDUM OR THE PRIOR NOTICE SHALL BE HELD NULL AND VOID BY MMP, PURSUANT TO
// THE RESTRICTIONS STATED WITHIN.
//
// ADDENDUM: IN AGREEMENT WITH WADJET EYE GAMES ("WEG"), THE FOLLOWING PRIVILEGES ARE GRANTED, BEGINNING ON
// 16 FEBRUARY 2013. AUTHORIZED PERSONNEL OF WEG ARE HEREBY AUTHORIZED BY MONKEYMOTO PRODUCTIONS, INC. TO
// ACCESS AND MODIFY THE CONTENTS OF THIS FILE, PURSUANT TO THE PRIOR RESTRICTIONS, AND THE TERMS AND
// CONDITIONS OF EXISTING NON-DISCLOSURE AGREEMENTS BETWEEN VALVE CORPORATION ("VALVE") AND MMP, AND VALVE AND
// WEG. LIMITED AUTHORIZATION IS ALSO GRANTED TO AUTHORIZED WEG PERSONNEL TO REDISTRIBUTE THIS FILE, PURSUANT
// TO THE FOLLOWING RESTRICTIONS:
//
//     THE ABOVE NOTICE AND ALL EXISTING ADDENDUMS MUST REMAIN UNCHANGED AT THE BEGINNING OF THIS C++ FILE.
//
//     WEG ACCEPTS FULL RESPONSIBILITY AND LIABILITY FOR ANY USAGE OF THIS FILE BY THIRD-PARTIES IT
//     AUTHORIZES, PURSUANT TO THEIR OWN TERMS AND RESTRICTIONS, WHICH MUST NOT PLACE ANY FURTHER LIABILITY
//     UPON MMP.
//
// ADDENDUM: ALL PARTIES ARE GRANTED NON-EXCLUSIVE LICENSE TO REDISTRIBUTE THE COMPILED FORM OF THIS C++ FILE
// FOR THE PURPOSES OF STATIC OR DYNAMIC CODE LINKING, SUCH AS IN THE FORM OF A WINDOWS DYNAMIC-LINK LIBRARY
// ("DLL") FILE. THIS ADDENDUM DOES NOT APPLY TO THE NON-COMPILED SOURCE OF THIS C++ FILE.
//
// ADDENDUM: ADDITIONAL RESTRICTIONS AND DEFINITION OF TERMS MAY BE INCLUDED IN A SEPARATE FILE NAMED
// "LICENSE" ("THE LICENSE FILE"), WITH NO TRAILING FILE EXTENSION. THE LICENSE FILE WILL BE WRITTEN IN PLAIN-
// TEXT, IN THE ENGLISH LANGUAGE, WITH A UTF-8 CHARACTER ENCODING. THE LICENSE FILE AND THIS ADDENDUM MAY BE
// AMENDED AS NECESSARY BY ANY AUTHORIZED PERSONS, WHILE UNAUTHORIZED CHANGES WILL BE NULL AND VOID.
//
// ADDENDUM: BEGINNING ON 2 APRIL 2014 THE FOLLOWING RESTRICTIONS SHALL BE ENFORCED UPON ALL AUTHORIZED THIRD-
// PARTY USAGE, INCLUDING, BUT NOT LIMITED TO SUBLICENSING OR REDISTRIBUTION OF THIS FILE. THESE RESTRICTIONS
// SUPERCEDE AND NULLIFY ALL PRIOR THIRD-PARTY AUTHORIZATIONS GRANTED BY MONKEYMOTO PRODUCTIONS, INC.:
//
//     THE ABOVE NOTICE AND ALL EXISTING ADDENDUMS MUST REMAIN UNCHANGED AT THE BEGINNING OF THIS C++ FILE AND
//     AT THE BEGINNING OF THE LICENSE FILE.
//
//     LIMITED AUTHORIZATION IS GRANTED TO AUTHORIZED THIRD-PARTIES TO REDISTRIBUTE OR SUBLICENSE THIS FILE,
//     PURSUANT TO ALL TERMS INCLUDED HEREIN. ADDITIONAL LICENSES MUST NOT PERMIT LESS RESTRICTIVE USAGE OF
//     THIS FILE THAN ORIGINALLY AUTHORIZED.
//
//     NO FURTHER LIABILITY MUST BE PLACED UPON MONKEYMOTO PRODUCTIONS, INC. BY THE AUTHORIZED THIRD-PARTY,
//     INCLUDING, BUT NOT LIMITED TO, ANY LIABILITY ARISING FROM THIRD-PARTIES NOT DIRECTLY AUTHORIZED BY
//     MONKEYMOTO PRODUCTIONS, INC.
//
//     THE AUTHORIZED THIRD-PARTY ACCEPTS FULL RESPONSIBILITY AND LIABILITY FOR ANY USAGE OF THIS FILE BY
//     THE AUTHORIZED THIRD-PARTY OR OTHER THIRD-PARTIES IT AUTHORIZES, PURSUANT TO THEIR OWN TERMS AND
//     RESTRICTIONS.
//
//     THE AUTHORIZED THIRD-PARTY IS SOLELY RESPONSIBLE FOR VALIDATING THE RIGHTS OF ANY OTHER THIRD-PARTIES
//     THEY WISH TO GRANT ACCESS TO THIS FILE. THIS INCLUDES, BUT IS NOT LIMITED TO, ENSURING THAT THE OTHER
//     PARTY HAS A CURRENT AND VALID NON-DISCLOSURE AGREEMENT WITH VALVE CORPORATION IN ORDER TO GAIN ACCESS
//     TO THE STEAMWORKS SDK AND API.
//
//     IF AT ANY TIME OR FOR ANY REASON AN AUTHORIZED THIRD-PARTY BECOMES INELIGIBLE TO ACCESS THE
//     STEAMWORKS SDK OR API, SUCH AS, BUT NOT LIMITED TO DISSOLUTION OF A NON-DISCLOSURE AGREEMENT WITH
//     VALVE CORPORATION, THE PARTY MUST NOTIFY MONKEYMOTO PRODUCTIONS, INC. WITHIN TWENTY-FOUR HOURS AND
//     IMMEDIATELY DISCONTINUE ALL USAGE OF THIS FILE. AT SUCH TIME AS THE THIRD-PARTY THUS BECOMES SO
//     INELIGIBLE, ALL RIGHTS AND PRIVILEGES GRANTED TO THE PARTY BY MONKEYMOTO PRODUCTIONS, INC. REGARDING
//     THIS FILE BECOME NULL AND VOID.
//
//     ALL OTHER APPLICABLE RESTRICTIONS APPLY. THIS INCLUDES BUT IS NOT LIMITED TO THE TERMS AND CONDITIONS
//     OF NON-DISCLOSURE AGREEMENTS BETWEEN VALVE CORPORATION AND THE AUTHORIZED THIRD-PARTY, AND BETWEEN
//     VALVE CORPORATION AND MONKEYMOTO PRODUCTIONS, INC., THE RESTRICTIONS DETAILED ABOVE, AND LOCAL AND
//     INTERNATIONAL LAWS. MONKEYMOTO PRODUCTIONS, INC. RESERVES ALL RIGHT TO PURSUIT OF LEGAL RECOURSE IN
//     THE EVENT THAT THESE RESTRICTIONS ARE BROKEN BY ANY THIRD-PARTY.
//
// ADDENDUM: IN AGREEMENT WITH WADJET EYE GAMES, THE FOLLOWING PRIVILEGES ARE GRANTED, BEGINNING ON 2 APRIL
// 2014. AUTHORIZED PERSONNEL OF WADJET EYE GAMES ARE HEREBY AUTHORIZED BY MONKEYMOTO PRODUCTIONS, INC. TO
// ACCESS AND MODIFY THIS FILE, PURSUANT TO THE TERMS AND RESTRICTIONS DETAILED ABOVE.
//
// ADDENDUM: IN AGREEMENT WITH INFAMOUS QUESTS, LLC, THE FOLLOWING PRIVILEGES ARE GRANTED, BEGINNING ON 2
// APRIL 2014. AUTHORIZED PERSONNEL OF INFAMOUS QUESTS, LLC ARE HEREBY AUTHORIZED BY MONKEYMOTO PRODUCTIONS,
// INC. TO ACCESS AND MODIFY THIS FILE, PURSUANT TO THE TERMS AND RESTRICTIONS DETAILED ABOVE.
//
// ADDENDUM: IN AGREEMENT WITH PHOENIX ONLINE STUDIOS LLC, THE FOLLOWING PRIVILEGES ARE GRANTED, BEGINNING ON
// 2 APRIL 2014. AUTHORIZED PERSONNEL OF PHOENIX ONLINE STUDIOS LLC ARE HEREBY AUTHORIZED BY MONKEYMOTO
// PRODUCTIONS, INC. TO ACCESS AND MODIFY THIS FILE, PURSUANT TO THE TERMS AND RESTRICTIONS DETAILED ABOVE.
//
#include "Stub/agsplugin.h"
#include "Stub/IAGSteam.h"
#include "SteamLeaderboards.h"

namespace AGSteam
{
namespace Plugin
{

using namespace Stub;

SteamLeaderboard::SteamLeaderboard() : CurrentLeaderboard(NULL), LeaderboardEntriesCount(0),
                                         CallResultFindLeaderboard(), CallResultUploadScore(),
                                         CallResultDownloadScore()
{
  for (int i = 0; i < 10; ++i)
  {
    LeaderboardEntries[i].m_steamIDUser.Clear();
  }
}

SteamLeaderboard::~SteamLeaderboard()
{
}

void SteamLeaderboard::FindLeaderboard(char const *leaderboardName)
{
  if (leaderboardName == NULL) return;
  CurrentLeaderboard = NULL;
  CallResultFindLeaderboard.Set(SteamUserStats()->FindLeaderboard(leaderboardName), this, &SteamLeaderboard::OnFindLeaderboard);
}

void SteamLeaderboard::OnFindLeaderboard(LeaderboardFindResult_t *callback, bool IOFailure)
{
  // see if there was an error
  if ((!callback->m_bLeaderboardFound) || (IOFailure)) return;
  CurrentLeaderboard = callback->m_hSteamLeaderboard;
}

bool SteamLeaderboard::UploadScore(int score)
{
  if (CurrentLeaderboard == NULL) return false;
  CallResultUploadScore.Set(SteamUserStats()->UploadLeaderboardScore(CurrentLeaderboard, k_ELeaderboardUploadScoreMethodKeepBest, static_cast<int32>(score), NULL, 0), this, &SteamLeaderboard::OnUploadScore);
  return true;
}

void SteamLeaderboard::OnUploadScore(LeaderboardScoreUploaded_t *callback, bool IOFailure)
{
}

bool SteamLeaderboard::DownloadScores(AGSteamScoresRequestType type)
{
  if (CurrentLeaderboard == NULL) return false;
  CallResultDownloadScore.Set(SteamUserStats()->DownloadLeaderboardEntries(CurrentLeaderboard, static_cast<ELeaderboardDataRequest>(type), -4, 5), this, &SteamLeaderboard::OnDownloadScore);
  return true;
}

bool SteamLeaderboard::DownloadScores(int type)
{
    return DownloadScores(MapAGSteamScoresRequestToNative(type));
}

inline int get_min(int a, int b) // MSVC++ defines "min" as a macro but GCC expects std::min -- this is simpler
{
  return (a > b ? b : a);
}

void SteamLeaderboard::OnDownloadScore(LeaderboardScoresDownloaded_t *callback, bool IOFailure)
{
  if (IOFailure) return;
  LeaderboardEntriesCount = get_min(callback->m_cEntryCount, 10);
  int i = 0;
  for ( ; i < LeaderboardEntriesCount; ++i)
  {
    SteamUserStats()->GetDownloadedLeaderboardEntry(callback->m_hSteamLeaderboardEntries, i, &LeaderboardEntries[i], NULL, 0);
  }
  for ( ; i < 10; ++i)
  {
    LeaderboardEntries[i].m_steamIDUser.Clear();
  }
}

char const* SteamLeaderboard::GetCurrentLeaderboardName()
{
  if ((!AGSteam_IsSteamInitialized()) || (CurrentLeaderboard == NULL)) return NULL;
  return SteamUserStats()->GetLeaderboardName(CurrentLeaderboard);
}

char const* SteamLeaderboard::GetLeaderName(int index)
{
  if ((!AGSteam_IsSteamInitialized()) || (index < 0) || (index > LeaderboardEntriesCount) || (!LeaderboardEntries[index].m_steamIDUser.IsValid())) return NULL;
  return SteamFriends()->GetFriendPersonaName(LeaderboardEntries[index].m_steamIDUser);
}

int SteamLeaderboard::GetLeaderScore(int index)
{
  if ((!AGSteam_IsSteamInitialized()) || (index < 0) || (index > LeaderboardEntriesCount) || (!LeaderboardEntries[index].m_steamIDUser.IsValid())) return 0;
  return static_cast<int>(LeaderboardEntries[index].m_nScore);
}

int SteamLeaderboard::GetLeaderCount()
{
    return LeaderboardEntriesCount;
}

} // namespace Plugin
} // namespace AGSteam
