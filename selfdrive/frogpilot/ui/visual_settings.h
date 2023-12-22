#pragma once

#include <set>

#include "selfdrive/ui/qt/offroad/settings.h"

class FrogPilotVisualsPanel : public ListWidget {
  Q_OBJECT

public:
  explicit FrogPilotVisualsPanel(SettingsWindow *parent);

private:
  void hideEvent(QHideEvent *event);
  void hideSubToggles();
  void setDefaults();
  void showEvent(QShowEvent *event);
  void updateMetric();

  ButtonControl *backButton;

  std::set<QString> customOnroadUIKeys;
  std::set<QString> customThemeKeys;
  std::set<QString> modelUIKeys;

  std::map<std::string, ParamControl*> toggles;

  Params params;
  Params paramsMemory{"/dev/shm/params"};

  bool isMetric;
  bool previousIsMetric;
};
