AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'aplite'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'aplite'
BUNDLE_NAME = 'pebble_habit_tracker.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'linux'
INCLUDES = ['aplite']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_JSON = [{u'license': u'MIT', u'name': u'pebble-clay', u'repository': {u'url': u'git+https://github.com/pebble/clay.git', u'type': u'git'}, u'author': u'Pebble Technology', u'bugs': {u'url': u'https://github.com/pebble/clay/issues'}, u'version': u'1.0.4', 'js_paths': ['node_modules/pebble-clay/dist/js/index.js'], u'dependencies': {}, u'scripts': {u'pebble-publish': u'npm run pebble-clean && npm run build && pebble build && pebble package publish && npm run pebble-clean', u'test-travis': u'./node_modules/.bin/gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --single-run --browsers chromeTravisCI && ./node_modules/.bin/eslint ./', u'pebble-build': u'npm run build && pebble build', u'pebble-clean': u'rm -rf tmp src/js/index.js && pebble clean', u'lint': u'./node_modules/.bin/eslint ./', u'dev': u'gulp dev', u'build': u'gulp', u'test': u'./node_modules/.bin/gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --single-run', u'test-debug': u'(export DEBUG=true && ./node_modules/.bin/gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --no-single-run)'}, u'keywords': [u'pebble', u'config', u'configuration', u'pebble-package'], u'devDependencies': {u'chai': u'^3.4.1', u'mocha': u'^2.3.4', u'through': u'^2.3.8', u'gulp-inline': u'0.0.15', u'karma-source-map-support': u'^1.1.0', u'deepcopy': u'^0.6.1', u'eslint-plugin-standard': u'^1.3.1', u'stringify': u'^3.2.0', u'gulp-insert': u'^0.5.0', u'gulp': u'^3.9.0', u'gulp-htmlmin': u'^1.3.0', u'deamdify': u'^0.2.0', u'bourbon': u'^4.2.6', u'eslint-config-pebble': u'^1.2.0', u'eslint': u'^1.5.1', u'karma-coverage': u'^0.5.3', u'watchify': u'^3.7.0', u'require-from-string': u'^1.1.0', u'gulp-sourcemaps': u'^1.6.0', u'karma-mocha': u'^0.2.1', u'sinon': u'^1.17.3', u'joi': u'^6.10.1', u'browserify': u'^13.0.0', u'sassify': u'^0.9.1', u'gulp-autoprefixer': u'^3.1.0', u'karma-mocha-reporter': u'^1.1.5', u'autoprefixer': u'^6.3.1', u'browserify-istanbul': u'^0.2.1', u'karma-threshold-reporter': u'^0.1.15', u'gulp-sass': u'^2.1.1', u'vinyl-source-stream': u'^1.1.0', u'gulp-uglify': u'^1.5.2', u'karma-chrome-launcher': u'^0.2.2', u'vinyl-buffer': u'^1.0.0', u'del': u'^2.0.2', u'karma': u'^0.13.19', u'karma-browserify': u'^5.0.1', u'tosource': u'^1.0.0', u'postcss': u'^5.0.14'}, u'pebble': {u'sdkVersion': u'3', u'capabilities': [u'configurable'], u'projectType': u'package', u'targetPlatforms': [u'aplite', u'basalt', u'chalk', u'diorite', u'emery'], u'resources': {u'media': []}}, 'path': 'node_modules/pebble-clay/dist', u'homepage': u'https://github.com/pebble/clay#readme', u'description': u'Pebble Config Framework'}]
LIB_RESOURCES_JSON = {u'pebble-clay': []}
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {u'Habit0': 10000, u'Habit1': 10001, u'Habit2': 10002, u'Habit3': 10003, u'Habit4': 10004, u'Habit5': 10005, u'Habit6': 10006, u'Habit7': 10007, u'Habit8': 10008, u'Habit9': 10009}
MESSAGE_KEYS_DEFINITION = '/home/rebble/code/pebble_habit_tracker/build/src/message_keys.auto.c'
MESSAGE_KEYS_HEADER = '/home/rebble/code/pebble_habit_tracker/build/include/message_keys.auto.h'
MESSAGE_KEYS_JSON = '/home/rebble/code/pebble_habit_tracker/build/js/message_keys.json'
NODE_PATH = '/home/rebble/.pebble-sdk/SDKs/current/node_modules'
PEBBLE_SDK_COMMON = '/home/rebble/.pebble-sdk/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/home/rebble/.pebble-sdk/SDKs/current/sdk-core/pebble/aplite'
PEBBLE_SDK_ROOT = '/home/rebble/.pebble-sdk/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['aplite', 'bw', 'rect', 'compass', '144w', '168h'], 'MAX_FONT_GLYPH_SIZE': 256, 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 524288, 'MAX_APP_MEMORY_SIZE': 24576, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'aplite', 'BUNDLE_BIN_DIR': 'aplite', 'BUILD_DIR': 'aplite', 'MAX_RESOURCES_SIZE_APPSTORE_2_X': 98304, 'MAX_RESOURCES_SIZE_APPSTORE': 131072, 'DEFINES': ['PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168']}
PLATFORM_NAME = 'aplite'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {u'Habit0': 10000, u'Habit1': 10001, u'Habit2': 10002, u'Habit3': 10003, u'Habit4': 10004, u'Habit5': 10005, u'Habit6': 10006, u'Habit7': 10007, u'Habit8': 10008, u'Habit9': 10009}, u'sdkVersion': u'3', u'displayName': u'pebble_habit_tracker', u'uuid': u'75e4c603-51c9-4f3b-b9c9-86a38ab19ac1', u'messageKeys': {u'Habit0': 10000, u'Habit1': 10001, u'Habit2': 10002, u'Habit3': 10003, u'Habit4': 10004, u'Habit5': 10005, u'Habit6': 10006, u'Habit7': 10007, u'Habit8': 10008, u'Habit9': 10009}, 'companyName': u'jerroh', u'enableMultiJS': True, u'targetPlatforms': [u'aplite', u'basalt', u'chalk', u'diorite'], u'capabilities': [u'configurable'], 'versionLabel': u'1.0', 'longName': u'pebble_habit_tracker', 'shortName': u'pebble_habit_tracker', u'watchapp': {u'watchface': False}, u'resources': {u'media': [{u'type': u'bitmap', u'name': u'CHECKED', u'file': u'images/checked.png'}, {u'type': u'bitmap', u'name': u'UNCHECKED', u'file': u'images/unchecked.png'}, {u'type': u'bitmap', u'name': u'CHALK_ICON', u'file': u'images/spike_chalk.pbl.png'}, {u'type': u'bitmap', u'name': u'WHITE_CHECKED', u'file': u'images/white_checked.png'}, {u'type': u'bitmap', u'name': u'WHITE_UNCHECKED', u'file': u'images/white_unchecked.png'}]}, 'name': u'pebble_habit_tracker'}
REQUESTED_PLATFORMS = [u'aplite', u'basalt', u'chalk', u'diorite']
RESOURCES_JSON = [{u'type': u'bitmap', u'name': u'CHECKED', u'file': u'images/checked.png'}, {u'type': u'bitmap', u'name': u'UNCHECKED', u'file': u'images/unchecked.png'}, {u'type': u'bitmap', u'name': u'CHALK_ICON', u'file': u'images/spike_chalk.pbl.png'}, {u'type': u'bitmap', u'name': u'WHITE_CHECKED', u'file': u'images/white_checked.png'}, {u'type': u'bitmap', u'name': u'WHITE_UNCHECKED', u'file': u'images/white_unchecked.png'}]
RPATH_ST = '-Wl,-rpath,%s'
SANDBOX = False
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 78
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['basalt', 'aplite', 'emery', 'diorite', 'chalk']
TARGET_PLATFORMS = ['diorite', 'chalk', 'basalt', 'aplite']
TIMESTAMP = 1677184021
USE_GROUPS = True
VERBOSE = 0
WEBPACK = '/home/rebble/.pebble-sdk/SDKs/current/node_modules/.bin/webpack'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'
