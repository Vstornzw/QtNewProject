@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\Qt\5.6.3_vs2010\qtbase\lib;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\Qt\5.6.3_vs2010\qtbase\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\Qt\5.6.3_vs2010\qtbase\plugins
)
D:\Qt\5.6.3_vs2010\qtbase\bin\uic.exe %*
EndLocal
