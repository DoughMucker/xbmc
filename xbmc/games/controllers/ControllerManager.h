/*
 *      Copyright (C) 2015 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "ControllerTypes.h"
#include "utils/Observer.h"
#include "threads/CriticalSection.h"

#include <vector>

namespace GAME
{

class CControllerManager : public Observer
{
private:
  CControllerManager(void) { }

public:
  static CControllerManager& GetInstance(void);
  virtual ~CControllerManager(void) { }

  void Start(void);
  void Stop(void);

  /*!
   * \brief Get the controller by its ID
   * \param strControllerId The target controller ID
   * \param controller The discovered controller, or untouched if the ID is not found
   * \return true If controller points to a valid controller
   */
  bool GetController(const std::string& strControllerId, ControllerPtr& controller) const;

  /*!
   * \brief Get all controllers tracked by the controller manager
   * \return The controllers sorted alphabetically, with the default controller
   *         always appearing first
   */
  ControllerVector GetControllers(void) const;

  // implementation of Observer
  virtual void Notify(const Observable& obs, const ObservableMessage msg) override;

private:
  void UpdateAddons(void);
  void ClearAddons(void);

  ControllerVector m_controllers;
  CCriticalSection     m_critSection;
};

}
