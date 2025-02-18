#!/usr/bin/env bash
set -euo pipefail
export port=/dev/ttyACM0
export fqbn=arduino:avr:leonardo
arduino-cli board attach -b "$fqbn" -p "$port" ledit.ino
arduino-cli compile
arduino-cli upload
arduino-cli monitor
