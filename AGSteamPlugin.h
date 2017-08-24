//
// AGSteam: Steam API Plugin for AGS
// (C) 2011-2017 MonkeyMoto Productions, Inc.
//
#ifndef AGSTEAM_AGSTEAMPLUGIN_H
#define AGSTEAM_AGSTEAMPLUGIN_H

#include "ags2client/Cpp11Fix.h"
#include "ags2client/IAGS2Client.h"

namespace AGSteam
{
	namespace Plugin
	{

		class AGSteamPlugin : public AGS2Client::IAGS2Client
		{
		protected:
			DEFAULT_CTOR(AGSteamPlugin);

		public:
			DEFAULT_DTOR(AGSteamPlugin);
			static AGSteamPlugin& GetAGSteamPlugin() noexcept;
			bool IsInitialized() const noexcept override;
			void ResetStatsAndAchievements() const noexcept override;
			char const* GetCurrentGameLanguage() const noexcept;
			char const* GetUserName() const noexcept override;
			void Startup() const noexcept override;
            void Shutdown() const noexcept override;
			void Update() const noexcept override;
			char const* GetAGSPluginName() const noexcept override;
			char const* GetAGSPluginDesc() const noexcept override;
			float GetVersion() const noexcept override;
			bool ClaimKeyPress(int data, int(*IsKeyPressed)(int)) const noexcept override;
			void RegisterScriptFunctions(IAGSEngine *engine) const noexcept override;
		};

	} // namespace Plugin
} // namespace AGSteam

#endif // AGSTEAM_AGSTEAMPLUGIN_H
