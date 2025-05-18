#!/bin/sh
find -name "*.o" -exec rm "{}" \;
find -perm 0755 -name "[0-9][0-9][0-9][0-9]" -exec rm "{}" \;
find -perm 0755 -name "[0-9][0-9][0-9][0-9][0-9]" -exec rm "{}" \;
