SUBDIRS(
	# Extensions must come before ElVisCLI since that is where the tests are setup.
    Core
	Extensions
    #ElVisCLI
	ElVisCore
	ElVisGUI
    ModelConversion
    QtPropertyBrowser
	Main
)

