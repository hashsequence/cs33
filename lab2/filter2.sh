#!/bin/sh

sed 's/Watchpoint/=> Watchpoint/g' | sed 's/Old/=> Old/g' | sed 's/New/=> New/g' | grep "=>.*" | sed 's/=> //g' 
