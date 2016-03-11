#!/bin/sh
ldapsearch -Q sn | grep ^sn: | grep -ic bon
