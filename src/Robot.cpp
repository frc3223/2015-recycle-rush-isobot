#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <HAL/HAL.hpp>
#include "base/commands_base.hpp"

class Robot : public IterativeRobot {
 private:
  Command* autonomous_command_;
  LiveWindow* lw_;

  void RobotInit() {
    retrobotics::isobot::commands::Base::init();
    autonomous_command_ = nullptr;
    lw_ = LiveWindow::GetInstance();
  }

  void DisabledPeriodic() {
    Scheduler::GetInstance()->Run();
  }

  void AutonomousInit() {
    if (autonomous_command_ != nullptr)
      autonomous_command_->Start();
  }

  void AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
  }

  void TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (autonomous_command_ != nullptr)
      autonomous_command_->Cancel();
  }

  void TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
  }

  void TestPeriodic() {
    lw_->Run();
  }
};

START_ROBOT_CLASS(Robot);

