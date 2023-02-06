TEMPLATE = subdirs

SUBDIRS += service \
	plugins

android:!android-embedded: SUBDIRS += java

plugins.depends += service

QMAKE_EXTRA_TARGETS += run-tests

lupdate.target = lupdate
lupdate.CONFIG = recursive
lupdate.recurse_target = lupdate
QMAKE_EXTRA_TARGETS += lupdate
