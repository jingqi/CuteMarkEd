
# XXX ����ò����qmake��һ��bug������������� _DEBUG/NDEBUG ��
CONFIG(debug, debug|release): DEFINES += _DEBUG
else: DEFINES += NDEBUG

# ��������
CONFIG(debug, debug|release): DEBUG_MODE = debug
else: DEBUG_MODE = release

win32: OUT_TAIL = /$${DEBUG_MODE}

mac: OS_NAME = darwin
else:win32: OS_NAME = win
else:unix: OS_NAME = unix
