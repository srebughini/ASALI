# -*- mode: python ; coding: utf-8 -*-
excluded_modules = ['tkinter','unittest', 'pydoc', 'doctest', 'http', 'xmlrpc', 'distutils', 'setuptools', 'test',
'asyncio', 'concurrent', 'multiprocessing', 'sqlite3', 'wsgiref']
hiddenimports=['PySide6.QtWidgets', 'PySide6.QtCore', 'PySide6.QtGui']

a = Analysis(
    ['app.py'],
    pathex=[],
    binaries=[],
    datas=[("src/resources/images", "src/resources/images"),
    ("src/resources/qss", "src/resources/qss"),
    ("src/resources/database", "src/resources/database"),
    ("src/gui/ui/input", "src/gui/ui/input"),
    ("src/gui/ui/output", "src/gui/ui/output")],
    hiddenimports=hiddenimports,
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=excluded_modules,
    noarchive=False,
    optimize=0,
)
pyz = PYZ(a.pure, cipher=None)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name='asali',
    debug=False,
    bootloader_ignore_signals=False,
    strip=True,
    upx=True,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
    icon="src/resources/images/Icon.ico"
)
coll = COLLECT(
    exe,
    a.binaries,
    a.datas,
    strip=True,
    upx=True,
    upx_exclude=[],
    name='asali'
)
