(() => {
  var __create = Object.create;
  var __defProp = Object.defineProperty;
  var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
  var __getOwnPropNames = Object.getOwnPropertyNames;
  var __getProtoOf = Object.getPrototypeOf;
  var __hasOwnProp = Object.prototype.hasOwnProperty;
  var __commonJS = (cb, mod2) => function __require() {
    return mod2 || (0, cb[__getOwnPropNames(cb)[0]])((mod2 = { exports: {} }).exports, mod2), mod2.exports;
  };
  var __copyProps = (to, from, except, desc) => {
    if (from && typeof from === "object" || typeof from === "function") {
      for (let key of __getOwnPropNames(from))
        if (!__hasOwnProp.call(to, key) && key !== except)
          __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
    }
    return to;
  };
  var __toESM = (mod2, isNodeMode, target) => (target = mod2 != null ? __create(__getProtoOf(mod2)) : {}, __copyProps(
    // If the importer is in node compatibility mode or this is not an ESM
    // file that has been converted to a CommonJS file using a Babel-
    // compatible transform (i.e. "__esModule" has not been set), then set
    // "default" to the CommonJS "module.exports" for node compatibility.
    isNodeMode || !mod2 || !mod2.__esModule ? __defProp(target, "default", { value: mod2, enumerable: true }) : target,
    mod2
  ));

  // node_modules/object-keys/isArguments.js
  var require_isArguments = __commonJS({
    "node_modules/object-keys/isArguments.js"(exports, module) {
      "use strict";
      var toStr = Object.prototype.toString;
      module.exports = function isArguments(value) {
        var str = toStr.call(value);
        var isArgs = str === "[object Arguments]";
        if (!isArgs) {
          isArgs = str !== "[object Array]" && value !== null && typeof value === "object" && typeof value.length === "number" && value.length >= 0 && toStr.call(value.callee) === "[object Function]";
        }
        return isArgs;
      };
    }
  });

  // node_modules/object-keys/implementation.js
  var require_implementation = __commonJS({
    "node_modules/object-keys/implementation.js"(exports, module) {
      "use strict";
      var keysShim;
      if (!Object.keys) {
        has = Object.prototype.hasOwnProperty;
        toStr = Object.prototype.toString;
        isArgs = require_isArguments();
        isEnumerable = Object.prototype.propertyIsEnumerable;
        hasDontEnumBug = !isEnumerable.call({ toString: null }, "toString");
        hasProtoEnumBug = isEnumerable.call(function() {
        }, "prototype");
        dontEnums = [
          "toString",
          "toLocaleString",
          "valueOf",
          "hasOwnProperty",
          "isPrototypeOf",
          "propertyIsEnumerable",
          "constructor"
        ];
        equalsConstructorPrototype = function(o) {
          var ctor = o.constructor;
          return ctor && ctor.prototype === o;
        };
        excludedKeys = {
          $applicationCache: true,
          $console: true,
          $external: true,
          $frame: true,
          $frameElement: true,
          $frames: true,
          $innerHeight: true,
          $innerWidth: true,
          $onmozfullscreenchange: true,
          $onmozfullscreenerror: true,
          $outerHeight: true,
          $outerWidth: true,
          $pageXOffset: true,
          $pageYOffset: true,
          $parent: true,
          $scrollLeft: true,
          $scrollTop: true,
          $scrollX: true,
          $scrollY: true,
          $self: true,
          $webkitIndexedDB: true,
          $webkitStorageInfo: true,
          $window: true
        };
        hasAutomationEqualityBug = (function() {
          if (typeof window === "undefined") {
            return false;
          }
          for (var k in window) {
            try {
              if (!excludedKeys["$" + k] && has.call(window, k) && window[k] !== null && typeof window[k] === "object") {
                try {
                  equalsConstructorPrototype(window[k]);
                } catch (e) {
                  return true;
                }
              }
            } catch (e) {
              return true;
            }
          }
          return false;
        })();
        equalsConstructorPrototypeIfNotBuggy = function(o) {
          if (typeof window === "undefined" || !hasAutomationEqualityBug) {
            return equalsConstructorPrototype(o);
          }
          try {
            return equalsConstructorPrototype(o);
          } catch (e) {
            return false;
          }
        };
        keysShim = function keys(object) {
          var isObject2 = object !== null && typeof object === "object";
          var isFunction2 = toStr.call(object) === "[object Function]";
          var isArguments = isArgs(object);
          var isString2 = isObject2 && toStr.call(object) === "[object String]";
          var theKeys = [];
          if (!isObject2 && !isFunction2 && !isArguments) {
            throw new TypeError("Object.keys called on a non-object");
          }
          var skipProto = hasProtoEnumBug && isFunction2;
          if (isString2 && object.length > 0 && !has.call(object, 0)) {
            for (var i = 0; i < object.length; ++i) {
              theKeys.push(String(i));
            }
          }
          if (isArguments && object.length > 0) {
            for (var j = 0; j < object.length; ++j) {
              theKeys.push(String(j));
            }
          } else {
            for (var name86 in object) {
              if (!(skipProto && name86 === "prototype") && has.call(object, name86)) {
                theKeys.push(String(name86));
              }
            }
          }
          if (hasDontEnumBug) {
            var skipConstructor = equalsConstructorPrototypeIfNotBuggy(object);
            for (var k = 0; k < dontEnums.length; ++k) {
              if (!(skipConstructor && dontEnums[k] === "constructor") && has.call(object, dontEnums[k])) {
                theKeys.push(dontEnums[k]);
              }
            }
          }
          return theKeys;
        };
      }
      var has;
      var toStr;
      var isArgs;
      var isEnumerable;
      var hasDontEnumBug;
      var hasProtoEnumBug;
      var dontEnums;
      var equalsConstructorPrototype;
      var excludedKeys;
      var hasAutomationEqualityBug;
      var equalsConstructorPrototypeIfNotBuggy;
      module.exports = keysShim;
    }
  });

  // node_modules/object-keys/index.js
  var require_object_keys = __commonJS({
    "node_modules/object-keys/index.js"(exports, module) {
      "use strict";
      var slice = Array.prototype.slice;
      var isArgs = require_isArguments();
      var origKeys = Object.keys;
      var keysShim = origKeys ? function keys(o) {
        return origKeys(o);
      } : require_implementation();
      var originalKeys = Object.keys;
      keysShim.shim = function shimObjectKeys() {
        if (Object.keys) {
          var keysWorksWithArguments = (function() {
            var args = Object.keys(arguments);
            return args && args.length === arguments.length;
          })(1, 2);
          if (!keysWorksWithArguments) {
            Object.keys = function keys(object) {
              if (isArgs(object)) {
                return originalKeys(slice.call(object));
              }
              return originalKeys(object);
            };
          }
        } else {
          Object.keys = keysShim;
        }
        return Object.keys || keysShim;
      };
      module.exports = keysShim;
    }
  });

  // node_modules/has-symbols/shams.js
  var require_shams = __commonJS({
    "node_modules/has-symbols/shams.js"(exports, module) {
      "use strict";
      module.exports = function hasSymbols() {
        if (typeof Symbol !== "function" || typeof Object.getOwnPropertySymbols !== "function") {
          return false;
        }
        if (typeof Symbol.iterator === "symbol") {
          return true;
        }
        var obj = {};
        var sym = /* @__PURE__ */ Symbol("test");
        var symObj = Object(sym);
        if (typeof sym === "string") {
          return false;
        }
        if (Object.prototype.toString.call(sym) !== "[object Symbol]") {
          return false;
        }
        if (Object.prototype.toString.call(symObj) !== "[object Symbol]") {
          return false;
        }
        var symVal = 42;
        obj[sym] = symVal;
        for (var _ in obj) {
          return false;
        }
        if (typeof Object.keys === "function" && Object.keys(obj).length !== 0) {
          return false;
        }
        if (typeof Object.getOwnPropertyNames === "function" && Object.getOwnPropertyNames(obj).length !== 0) {
          return false;
        }
        var syms = Object.getOwnPropertySymbols(obj);
        if (syms.length !== 1 || syms[0] !== sym) {
          return false;
        }
        if (!Object.prototype.propertyIsEnumerable.call(obj, sym)) {
          return false;
        }
        if (typeof Object.getOwnPropertyDescriptor === "function") {
          var descriptor = (
            /** @type {PropertyDescriptor} */
            Object.getOwnPropertyDescriptor(obj, sym)
          );
          if (descriptor.value !== symVal || descriptor.enumerable !== true) {
            return false;
          }
        }
        return true;
      };
    }
  });

  // node_modules/es-object-atoms/index.js
  var require_es_object_atoms = __commonJS({
    "node_modules/es-object-atoms/index.js"(exports, module) {
      "use strict";
      module.exports = Object;
    }
  });

  // node_modules/es-errors/index.js
  var require_es_errors = __commonJS({
    "node_modules/es-errors/index.js"(exports, module) {
      "use strict";
      module.exports = Error;
    }
  });

  // node_modules/es-errors/eval.js
  var require_eval = __commonJS({
    "node_modules/es-errors/eval.js"(exports, module) {
      "use strict";
      module.exports = EvalError;
    }
  });

  // node_modules/es-errors/range.js
  var require_range = __commonJS({
    "node_modules/es-errors/range.js"(exports, module) {
      "use strict";
      module.exports = RangeError;
    }
  });

  // node_modules/es-errors/ref.js
  var require_ref = __commonJS({
    "node_modules/es-errors/ref.js"(exports, module) {
      "use strict";
      module.exports = ReferenceError;
    }
  });

  // node_modules/es-errors/syntax.js
  var require_syntax = __commonJS({
    "node_modules/es-errors/syntax.js"(exports, module) {
      "use strict";
      module.exports = SyntaxError;
    }
  });

  // node_modules/es-errors/type.js
  var require_type = __commonJS({
    "node_modules/es-errors/type.js"(exports, module) {
      "use strict";
      module.exports = TypeError;
    }
  });

  // node_modules/es-errors/uri.js
  var require_uri = __commonJS({
    "node_modules/es-errors/uri.js"(exports, module) {
      "use strict";
      module.exports = URIError;
    }
  });

  // node_modules/math-intrinsics/abs.js
  var require_abs = __commonJS({
    "node_modules/math-intrinsics/abs.js"(exports, module) {
      "use strict";
      module.exports = Math.abs;
    }
  });

  // node_modules/math-intrinsics/floor.js
  var require_floor = __commonJS({
    "node_modules/math-intrinsics/floor.js"(exports, module) {
      "use strict";
      module.exports = Math.floor;
    }
  });

  // node_modules/math-intrinsics/max.js
  var require_max = __commonJS({
    "node_modules/math-intrinsics/max.js"(exports, module) {
      "use strict";
      module.exports = Math.max;
    }
  });

  // node_modules/math-intrinsics/min.js
  var require_min = __commonJS({
    "node_modules/math-intrinsics/min.js"(exports, module) {
      "use strict";
      module.exports = Math.min;
    }
  });

  // node_modules/math-intrinsics/pow.js
  var require_pow = __commonJS({
    "node_modules/math-intrinsics/pow.js"(exports, module) {
      "use strict";
      module.exports = Math.pow;
    }
  });

  // node_modules/math-intrinsics/round.js
  var require_round = __commonJS({
    "node_modules/math-intrinsics/round.js"(exports, module) {
      "use strict";
      module.exports = Math.round;
    }
  });

  // node_modules/math-intrinsics/isNaN.js
  var require_isNaN = __commonJS({
    "node_modules/math-intrinsics/isNaN.js"(exports, module) {
      "use strict";
      module.exports = Number.isNaN || function isNaN2(a) {
        return a !== a;
      };
    }
  });

  // node_modules/math-intrinsics/sign.js
  var require_sign = __commonJS({
    "node_modules/math-intrinsics/sign.js"(exports, module) {
      "use strict";
      var $isNaN = require_isNaN();
      module.exports = function sign4(number2) {
        if ($isNaN(number2) || number2 === 0) {
          return number2;
        }
        return number2 < 0 ? -1 : 1;
      };
    }
  });

  // node_modules/gopd/gOPD.js
  var require_gOPD = __commonJS({
    "node_modules/gopd/gOPD.js"(exports, module) {
      "use strict";
      module.exports = Object.getOwnPropertyDescriptor;
    }
  });

  // node_modules/gopd/index.js
  var require_gopd = __commonJS({
    "node_modules/gopd/index.js"(exports, module) {
      "use strict";
      var $gOPD = require_gOPD();
      if ($gOPD) {
        try {
          $gOPD([], "length");
        } catch (e) {
          $gOPD = null;
        }
      }
      module.exports = $gOPD;
    }
  });

  // node_modules/es-define-property/index.js
  var require_es_define_property = __commonJS({
    "node_modules/es-define-property/index.js"(exports, module) {
      "use strict";
      var $defineProperty = Object.defineProperty || false;
      if ($defineProperty) {
        try {
          $defineProperty({}, "a", { value: 1 });
        } catch (e) {
          $defineProperty = false;
        }
      }
      module.exports = $defineProperty;
    }
  });

  // node_modules/has-symbols/index.js
  var require_has_symbols = __commonJS({
    "node_modules/has-symbols/index.js"(exports, module) {
      "use strict";
      var origSymbol = typeof Symbol !== "undefined" && Symbol;
      var hasSymbolSham = require_shams();
      module.exports = function hasNativeSymbols() {
        if (typeof origSymbol !== "function") {
          return false;
        }
        if (typeof Symbol !== "function") {
          return false;
        }
        if (typeof origSymbol("foo") !== "symbol") {
          return false;
        }
        if (typeof /* @__PURE__ */ Symbol("bar") !== "symbol") {
          return false;
        }
        return hasSymbolSham();
      };
    }
  });

  // node_modules/get-proto/Reflect.getPrototypeOf.js
  var require_Reflect_getPrototypeOf = __commonJS({
    "node_modules/get-proto/Reflect.getPrototypeOf.js"(exports, module) {
      "use strict";
      module.exports = typeof Reflect !== "undefined" && Reflect.getPrototypeOf || null;
    }
  });

  // node_modules/get-proto/Object.getPrototypeOf.js
  var require_Object_getPrototypeOf = __commonJS({
    "node_modules/get-proto/Object.getPrototypeOf.js"(exports, module) {
      "use strict";
      var $Object = require_es_object_atoms();
      module.exports = $Object.getPrototypeOf || null;
    }
  });

  // node_modules/function-bind/implementation.js
  var require_implementation2 = __commonJS({
    "node_modules/function-bind/implementation.js"(exports, module) {
      "use strict";
      var ERROR_MESSAGE = "Function.prototype.bind called on incompatible ";
      var toStr = Object.prototype.toString;
      var max2 = Math.max;
      var funcType = "[object Function]";
      var concatty = function concatty2(a, b) {
        var arr = [];
        for (var i = 0; i < a.length; i += 1) {
          arr[i] = a[i];
        }
        for (var j = 0; j < b.length; j += 1) {
          arr[j + a.length] = b[j];
        }
        return arr;
      };
      var slicy = function slicy2(arrLike, offset) {
        var arr = [];
        for (var i = offset || 0, j = 0; i < arrLike.length; i += 1, j += 1) {
          arr[j] = arrLike[i];
        }
        return arr;
      };
      var joiny = function(arr, joiner) {
        var str = "";
        for (var i = 0; i < arr.length; i += 1) {
          str += arr[i];
          if (i + 1 < arr.length) {
            str += joiner;
          }
        }
        return str;
      };
      module.exports = function bind(that) {
        var target = this;
        if (typeof target !== "function" || toStr.apply(target) !== funcType) {
          throw new TypeError(ERROR_MESSAGE + target);
        }
        var args = slicy(arguments, 1);
        var bound;
        var binder = function() {
          if (this instanceof bound) {
            var result = target.apply(
              this,
              concatty(args, arguments)
            );
            if (Object(result) === result) {
              return result;
            }
            return this;
          }
          return target.apply(
            that,
            concatty(args, arguments)
          );
        };
        var boundLength = max2(0, target.length - args.length);
        var boundArgs = [];
        for (var i = 0; i < boundLength; i++) {
          boundArgs[i] = "$" + i;
        }
        bound = Function("binder", "return function (" + joiny(boundArgs, ",") + "){ return binder.apply(this,arguments); }")(binder);
        if (target.prototype) {
          var Empty = function Empty2() {
          };
          Empty.prototype = target.prototype;
          bound.prototype = new Empty();
          Empty.prototype = null;
        }
        return bound;
      };
    }
  });

  // node_modules/function-bind/index.js
  var require_function_bind = __commonJS({
    "node_modules/function-bind/index.js"(exports, module) {
      "use strict";
      var implementation = require_implementation2();
      module.exports = Function.prototype.bind || implementation;
    }
  });

  // node_modules/call-bind-apply-helpers/functionCall.js
  var require_functionCall = __commonJS({
    "node_modules/call-bind-apply-helpers/functionCall.js"(exports, module) {
      "use strict";
      module.exports = Function.prototype.call;
    }
  });

  // node_modules/call-bind-apply-helpers/functionApply.js
  var require_functionApply = __commonJS({
    "node_modules/call-bind-apply-helpers/functionApply.js"(exports, module) {
      "use strict";
      module.exports = Function.prototype.apply;
    }
  });

  // node_modules/call-bind-apply-helpers/reflectApply.js
  var require_reflectApply = __commonJS({
    "node_modules/call-bind-apply-helpers/reflectApply.js"(exports, module) {
      "use strict";
      module.exports = typeof Reflect !== "undefined" && Reflect && Reflect.apply;
    }
  });

  // node_modules/call-bind-apply-helpers/actualApply.js
  var require_actualApply = __commonJS({
    "node_modules/call-bind-apply-helpers/actualApply.js"(exports, module) {
      "use strict";
      var bind = require_function_bind();
      var $apply = require_functionApply();
      var $call = require_functionCall();
      var $reflectApply = require_reflectApply();
      module.exports = $reflectApply || bind.call($call, $apply);
    }
  });

  // node_modules/call-bind-apply-helpers/index.js
  var require_call_bind_apply_helpers = __commonJS({
    "node_modules/call-bind-apply-helpers/index.js"(exports, module) {
      "use strict";
      var bind = require_function_bind();
      var $TypeError = require_type();
      var $call = require_functionCall();
      var $actualApply = require_actualApply();
      module.exports = function callBindBasic(args) {
        if (args.length < 1 || typeof args[0] !== "function") {
          throw new $TypeError("a function is required");
        }
        return $actualApply(bind, $call, args);
      };
    }
  });

  // node_modules/dunder-proto/get.js
  var require_get = __commonJS({
    "node_modules/dunder-proto/get.js"(exports, module) {
      "use strict";
      var callBind = require_call_bind_apply_helpers();
      var gOPD = require_gopd();
      var hasProtoAccessor;
      try {
        hasProtoAccessor = /** @type {{ __proto__?: typeof Array.prototype }} */
        [].__proto__ === Array.prototype;
      } catch (e) {
        if (!e || typeof e !== "object" || !("code" in e) || e.code !== "ERR_PROTO_ACCESS") {
          throw e;
        }
      }
      var desc = !!hasProtoAccessor && gOPD && gOPD(
        Object.prototype,
        /** @type {keyof typeof Object.prototype} */
        "__proto__"
      );
      var $Object = Object;
      var $getPrototypeOf = $Object.getPrototypeOf;
      module.exports = desc && typeof desc.get === "function" ? callBind([desc.get]) : typeof $getPrototypeOf === "function" ? (
        /** @type {import('./get')} */
        function getDunder(value) {
          return $getPrototypeOf(value == null ? value : $Object(value));
        }
      ) : false;
    }
  });

  // node_modules/get-proto/index.js
  var require_get_proto = __commonJS({
    "node_modules/get-proto/index.js"(exports, module) {
      "use strict";
      var reflectGetProto = require_Reflect_getPrototypeOf();
      var originalGetProto = require_Object_getPrototypeOf();
      var getDunderProto = require_get();
      module.exports = reflectGetProto ? function getProto(O) {
        return reflectGetProto(O);
      } : originalGetProto ? function getProto(O) {
        if (!O || typeof O !== "object" && typeof O !== "function") {
          throw new TypeError("getProto: not an object");
        }
        return originalGetProto(O);
      } : getDunderProto ? function getProto(O) {
        return getDunderProto(O);
      } : null;
    }
  });

  // node_modules/hasown/index.js
  var require_hasown = __commonJS({
    "node_modules/hasown/index.js"(exports, module) {
      "use strict";
      var call = Function.prototype.call;
      var $hasOwn = Object.prototype.hasOwnProperty;
      var bind = require_function_bind();
      module.exports = bind.call(call, $hasOwn);
    }
  });

  // node_modules/get-intrinsic/index.js
  var require_get_intrinsic = __commonJS({
    "node_modules/get-intrinsic/index.js"(exports, module) {
      "use strict";
      var undefined2;
      var $Object = require_es_object_atoms();
      var $Error = require_es_errors();
      var $EvalError = require_eval();
      var $RangeError = require_range();
      var $ReferenceError = require_ref();
      var $SyntaxError = require_syntax();
      var $TypeError = require_type();
      var $URIError = require_uri();
      var abs3 = require_abs();
      var floor2 = require_floor();
      var max2 = require_max();
      var min2 = require_min();
      var pow3 = require_pow();
      var round2 = require_round();
      var sign4 = require_sign();
      var $Function = Function;
      var getEvalledConstructor = function(expressionSyntax) {
        try {
          return $Function('"use strict"; return (' + expressionSyntax + ").constructor;")();
        } catch (e) {
        }
      };
      var $gOPD = require_gopd();
      var $defineProperty = require_es_define_property();
      var throwTypeError = function() {
        throw new $TypeError();
      };
      var ThrowTypeError = $gOPD ? (function() {
        try {
          arguments.callee;
          return throwTypeError;
        } catch (calleeThrows) {
          try {
            return $gOPD(arguments, "callee").get;
          } catch (gOPDthrows) {
            return throwTypeError;
          }
        }
      })() : throwTypeError;
      var hasSymbols = require_has_symbols()();
      var getProto = require_get_proto();
      var $ObjectGPO = require_Object_getPrototypeOf();
      var $ReflectGPO = require_Reflect_getPrototypeOf();
      var $apply = require_functionApply();
      var $call = require_functionCall();
      var needsEval = {};
      var TypedArray = typeof Uint8Array === "undefined" || !getProto ? undefined2 : getProto(Uint8Array);
      var INTRINSICS = {
        __proto__: null,
        "%AggregateError%": typeof AggregateError === "undefined" ? undefined2 : AggregateError,
        "%Array%": Array,
        "%ArrayBuffer%": typeof ArrayBuffer === "undefined" ? undefined2 : ArrayBuffer,
        "%ArrayIteratorPrototype%": hasSymbols && getProto ? getProto([][Symbol.iterator]()) : undefined2,
        "%AsyncFromSyncIteratorPrototype%": undefined2,
        "%AsyncFunction%": needsEval,
        "%AsyncGenerator%": needsEval,
        "%AsyncGeneratorFunction%": needsEval,
        "%AsyncIteratorPrototype%": needsEval,
        "%Atomics%": typeof Atomics === "undefined" ? undefined2 : Atomics,
        "%BigInt%": typeof BigInt === "undefined" ? undefined2 : BigInt,
        "%BigInt64Array%": typeof BigInt64Array === "undefined" ? undefined2 : BigInt64Array,
        "%BigUint64Array%": typeof BigUint64Array === "undefined" ? undefined2 : BigUint64Array,
        "%Boolean%": Boolean,
        "%DataView%": typeof DataView === "undefined" ? undefined2 : DataView,
        "%Date%": Date,
        "%decodeURI%": decodeURI,
        "%decodeURIComponent%": decodeURIComponent,
        "%encodeURI%": encodeURI,
        "%encodeURIComponent%": encodeURIComponent,
        "%Error%": $Error,
        "%eval%": eval,
        // eslint-disable-line no-eval
        "%EvalError%": $EvalError,
        "%Float16Array%": typeof Float16Array === "undefined" ? undefined2 : Float16Array,
        "%Float32Array%": typeof Float32Array === "undefined" ? undefined2 : Float32Array,
        "%Float64Array%": typeof Float64Array === "undefined" ? undefined2 : Float64Array,
        "%FinalizationRegistry%": typeof FinalizationRegistry === "undefined" ? undefined2 : FinalizationRegistry,
        "%Function%": $Function,
        "%GeneratorFunction%": needsEval,
        "%Int8Array%": typeof Int8Array === "undefined" ? undefined2 : Int8Array,
        "%Int16Array%": typeof Int16Array === "undefined" ? undefined2 : Int16Array,
        "%Int32Array%": typeof Int32Array === "undefined" ? undefined2 : Int32Array,
        "%isFinite%": isFinite,
        "%isNaN%": isNaN,
        "%IteratorPrototype%": hasSymbols && getProto ? getProto(getProto([][Symbol.iterator]())) : undefined2,
        "%JSON%": typeof JSON === "object" ? JSON : undefined2,
        "%Map%": typeof Map === "undefined" ? undefined2 : Map,
        "%MapIteratorPrototype%": typeof Map === "undefined" || !hasSymbols || !getProto ? undefined2 : getProto((/* @__PURE__ */ new Map())[Symbol.iterator]()),
        "%Math%": Math,
        "%Number%": Number,
        "%Object%": $Object,
        "%Object.getOwnPropertyDescriptor%": $gOPD,
        "%parseFloat%": parseFloat,
        "%parseInt%": parseInt,
        "%Promise%": typeof Promise === "undefined" ? undefined2 : Promise,
        "%Proxy%": typeof Proxy === "undefined" ? undefined2 : Proxy,
        "%RangeError%": $RangeError,
        "%ReferenceError%": $ReferenceError,
        "%Reflect%": typeof Reflect === "undefined" ? undefined2 : Reflect,
        "%RegExp%": RegExp,
        "%Set%": typeof Set === "undefined" ? undefined2 : Set,
        "%SetIteratorPrototype%": typeof Set === "undefined" || !hasSymbols || !getProto ? undefined2 : getProto((/* @__PURE__ */ new Set())[Symbol.iterator]()),
        "%SharedArrayBuffer%": typeof SharedArrayBuffer === "undefined" ? undefined2 : SharedArrayBuffer,
        "%String%": String,
        "%StringIteratorPrototype%": hasSymbols && getProto ? getProto(""[Symbol.iterator]()) : undefined2,
        "%Symbol%": hasSymbols ? Symbol : undefined2,
        "%SyntaxError%": $SyntaxError,
        "%ThrowTypeError%": ThrowTypeError,
        "%TypedArray%": TypedArray,
        "%TypeError%": $TypeError,
        "%Uint8Array%": typeof Uint8Array === "undefined" ? undefined2 : Uint8Array,
        "%Uint8ClampedArray%": typeof Uint8ClampedArray === "undefined" ? undefined2 : Uint8ClampedArray,
        "%Uint16Array%": typeof Uint16Array === "undefined" ? undefined2 : Uint16Array,
        "%Uint32Array%": typeof Uint32Array === "undefined" ? undefined2 : Uint32Array,
        "%URIError%": $URIError,
        "%WeakMap%": typeof WeakMap === "undefined" ? undefined2 : WeakMap,
        "%WeakRef%": typeof WeakRef === "undefined" ? undefined2 : WeakRef,
        "%WeakSet%": typeof WeakSet === "undefined" ? undefined2 : WeakSet,
        "%Function.prototype.call%": $call,
        "%Function.prototype.apply%": $apply,
        "%Object.defineProperty%": $defineProperty,
        "%Object.getPrototypeOf%": $ObjectGPO,
        "%Math.abs%": abs3,
        "%Math.floor%": floor2,
        "%Math.max%": max2,
        "%Math.min%": min2,
        "%Math.pow%": pow3,
        "%Math.round%": round2,
        "%Math.sign%": sign4,
        "%Reflect.getPrototypeOf%": $ReflectGPO
      };
      if (getProto) {
        try {
          null.error;
        } catch (e) {
          errorProto = getProto(getProto(e));
          INTRINSICS["%Error.prototype%"] = errorProto;
        }
      }
      var errorProto;
      var doEval = function doEval2(name86) {
        var value;
        if (name86 === "%AsyncFunction%") {
          value = getEvalledConstructor("async function () {}");
        } else if (name86 === "%GeneratorFunction%") {
          value = getEvalledConstructor("function* () {}");
        } else if (name86 === "%AsyncGeneratorFunction%") {
          value = getEvalledConstructor("async function* () {}");
        } else if (name86 === "%AsyncGenerator%") {
          var fn = doEval2("%AsyncGeneratorFunction%");
          if (fn) {
            value = fn.prototype;
          }
        } else if (name86 === "%AsyncIteratorPrototype%") {
          var gen = doEval2("%AsyncGenerator%");
          if (gen && getProto) {
            value = getProto(gen.prototype);
          }
        }
        INTRINSICS[name86] = value;
        return value;
      };
      var LEGACY_ALIASES = {
        __proto__: null,
        "%ArrayBufferPrototype%": ["ArrayBuffer", "prototype"],
        "%ArrayPrototype%": ["Array", "prototype"],
        "%ArrayProto_entries%": ["Array", "prototype", "entries"],
        "%ArrayProto_forEach%": ["Array", "prototype", "forEach"],
        "%ArrayProto_keys%": ["Array", "prototype", "keys"],
        "%ArrayProto_values%": ["Array", "prototype", "values"],
        "%AsyncFunctionPrototype%": ["AsyncFunction", "prototype"],
        "%AsyncGenerator%": ["AsyncGeneratorFunction", "prototype"],
        "%AsyncGeneratorPrototype%": ["AsyncGeneratorFunction", "prototype", "prototype"],
        "%BooleanPrototype%": ["Boolean", "prototype"],
        "%DataViewPrototype%": ["DataView", "prototype"],
        "%DatePrototype%": ["Date", "prototype"],
        "%ErrorPrototype%": ["Error", "prototype"],
        "%EvalErrorPrototype%": ["EvalError", "prototype"],
        "%Float32ArrayPrototype%": ["Float32Array", "prototype"],
        "%Float64ArrayPrototype%": ["Float64Array", "prototype"],
        "%FunctionPrototype%": ["Function", "prototype"],
        "%Generator%": ["GeneratorFunction", "prototype"],
        "%GeneratorPrototype%": ["GeneratorFunction", "prototype", "prototype"],
        "%Int8ArrayPrototype%": ["Int8Array", "prototype"],
        "%Int16ArrayPrototype%": ["Int16Array", "prototype"],
        "%Int32ArrayPrototype%": ["Int32Array", "prototype"],
        "%JSONParse%": ["JSON", "parse"],
        "%JSONStringify%": ["JSON", "stringify"],
        "%MapPrototype%": ["Map", "prototype"],
        "%NumberPrototype%": ["Number", "prototype"],
        "%ObjectPrototype%": ["Object", "prototype"],
        "%ObjProto_toString%": ["Object", "prototype", "toString"],
        "%ObjProto_valueOf%": ["Object", "prototype", "valueOf"],
        "%PromisePrototype%": ["Promise", "prototype"],
        "%PromiseProto_then%": ["Promise", "prototype", "then"],
        "%Promise_all%": ["Promise", "all"],
        "%Promise_reject%": ["Promise", "reject"],
        "%Promise_resolve%": ["Promise", "resolve"],
        "%RangeErrorPrototype%": ["RangeError", "prototype"],
        "%ReferenceErrorPrototype%": ["ReferenceError", "prototype"],
        "%RegExpPrototype%": ["RegExp", "prototype"],
        "%SetPrototype%": ["Set", "prototype"],
        "%SharedArrayBufferPrototype%": ["SharedArrayBuffer", "prototype"],
        "%StringPrototype%": ["String", "prototype"],
        "%SymbolPrototype%": ["Symbol", "prototype"],
        "%SyntaxErrorPrototype%": ["SyntaxError", "prototype"],
        "%TypedArrayPrototype%": ["TypedArray", "prototype"],
        "%TypeErrorPrototype%": ["TypeError", "prototype"],
        "%Uint8ArrayPrototype%": ["Uint8Array", "prototype"],
        "%Uint8ClampedArrayPrototype%": ["Uint8ClampedArray", "prototype"],
        "%Uint16ArrayPrototype%": ["Uint16Array", "prototype"],
        "%Uint32ArrayPrototype%": ["Uint32Array", "prototype"],
        "%URIErrorPrototype%": ["URIError", "prototype"],
        "%WeakMapPrototype%": ["WeakMap", "prototype"],
        "%WeakSetPrototype%": ["WeakSet", "prototype"]
      };
      var bind = require_function_bind();
      var hasOwn = require_hasown();
      var $concat = bind.call($call, Array.prototype.concat);
      var $spliceApply = bind.call($apply, Array.prototype.splice);
      var $replace = bind.call($call, String.prototype.replace);
      var $strSlice = bind.call($call, String.prototype.slice);
      var $exec = bind.call($call, RegExp.prototype.exec);
      var rePropName = /[^%.[\]]+|\[(?:(-?\d+(?:\.\d+)?)|(["'])((?:(?!\2)[^\\]|\\.)*?)\2)\]|(?=(?:\.|\[\])(?:\.|\[\]|%$))/g;
      var reEscapeChar = /\\(\\)?/g;
      var stringToPath = function stringToPath2(string) {
        var first = $strSlice(string, 0, 1);
        var last = $strSlice(string, -1);
        if (first === "%" && last !== "%") {
          throw new $SyntaxError("invalid intrinsic syntax, expected closing `%`");
        } else if (last === "%" && first !== "%") {
          throw new $SyntaxError("invalid intrinsic syntax, expected opening `%`");
        }
        var result = [];
        $replace(string, rePropName, function(match, number2, quote, subString) {
          result[result.length] = quote ? $replace(subString, reEscapeChar, "$1") : number2 || match;
        });
        return result;
      };
      var getBaseIntrinsic = function getBaseIntrinsic2(name86, allowMissing) {
        var intrinsicName = name86;
        var alias;
        if (hasOwn(LEGACY_ALIASES, intrinsicName)) {
          alias = LEGACY_ALIASES[intrinsicName];
          intrinsicName = "%" + alias[0] + "%";
        }
        if (hasOwn(INTRINSICS, intrinsicName)) {
          var value = INTRINSICS[intrinsicName];
          if (value === needsEval) {
            value = doEval(intrinsicName);
          }
          if (typeof value === "undefined" && !allowMissing) {
            throw new $TypeError("intrinsic " + name86 + " exists, but is not available. Please file an issue!");
          }
          return {
            alias,
            name: intrinsicName,
            value
          };
        }
        throw new $SyntaxError("intrinsic " + name86 + " does not exist!");
      };
      module.exports = function GetIntrinsic(name86, allowMissing) {
        if (typeof name86 !== "string" || name86.length === 0) {
          throw new $TypeError("intrinsic name must be a non-empty string");
        }
        if (arguments.length > 1 && typeof allowMissing !== "boolean") {
          throw new $TypeError('"allowMissing" argument must be a boolean');
        }
        if ($exec(/^%?[^%]*%?$/, name86) === null) {
          throw new $SyntaxError("`%` may not be present anywhere but at the beginning and end of the intrinsic name");
        }
        var parts = stringToPath(name86);
        var intrinsicBaseName = parts.length > 0 ? parts[0] : "";
        var intrinsic = getBaseIntrinsic("%" + intrinsicBaseName + "%", allowMissing);
        var intrinsicRealName = intrinsic.name;
        var value = intrinsic.value;
        var skipFurtherCaching = false;
        var alias = intrinsic.alias;
        if (alias) {
          intrinsicBaseName = alias[0];
          $spliceApply(parts, $concat([0, 1], alias));
        }
        for (var i = 1, isOwn = true; i < parts.length; i += 1) {
          var part = parts[i];
          var first = $strSlice(part, 0, 1);
          var last = $strSlice(part, -1);
          if ((first === '"' || first === "'" || first === "`" || (last === '"' || last === "'" || last === "`")) && first !== last) {
            throw new $SyntaxError("property names with quotes must have matching quotes");
          }
          if (part === "constructor" || !isOwn) {
            skipFurtherCaching = true;
          }
          intrinsicBaseName += "." + part;
          intrinsicRealName = "%" + intrinsicBaseName + "%";
          if (hasOwn(INTRINSICS, intrinsicRealName)) {
            value = INTRINSICS[intrinsicRealName];
          } else if (value != null) {
            if (!(part in value)) {
              if (!allowMissing) {
                throw new $TypeError("base intrinsic for " + name86 + " exists, but the property is not available.");
              }
              return void undefined2;
            }
            if ($gOPD && i + 1 >= parts.length) {
              var desc = $gOPD(value, part);
              isOwn = !!desc;
              if (isOwn && "get" in desc && !("originalValue" in desc.get)) {
                value = desc.get;
              } else {
                value = value[part];
              }
            } else {
              isOwn = hasOwn(value, part);
              value = value[part];
            }
            if (isOwn && !skipFurtherCaching) {
              INTRINSICS[intrinsicRealName] = value;
            }
          }
        }
        return value;
      };
    }
  });

  // node_modules/call-bound/index.js
  var require_call_bound = __commonJS({
    "node_modules/call-bound/index.js"(exports, module) {
      "use strict";
      var GetIntrinsic = require_get_intrinsic();
      var callBindBasic = require_call_bind_apply_helpers();
      var $indexOf = callBindBasic([GetIntrinsic("%String.prototype.indexOf%")]);
      module.exports = function callBoundIntrinsic(name86, allowMissing) {
        var intrinsic = (
          /** @type {(this: unknown, ...args: unknown[]) => unknown} */
          GetIntrinsic(name86, !!allowMissing)
        );
        if (typeof intrinsic === "function" && $indexOf(name86, ".prototype.") > -1) {
          return callBindBasic(
            /** @type {const} */
            [intrinsic]
          );
        }
        return intrinsic;
      };
    }
  });

  // node_modules/object.assign/implementation.js
  var require_implementation3 = __commonJS({
    "node_modules/object.assign/implementation.js"(exports, module) {
      "use strict";
      var objectKeys = require_object_keys();
      var hasSymbols = require_shams()();
      var callBound = require_call_bound();
      var $Object = require_es_object_atoms();
      var $push = callBound("Array.prototype.push");
      var $propIsEnumerable = callBound("Object.prototype.propertyIsEnumerable");
      var originalGetSymbols = hasSymbols ? $Object.getOwnPropertySymbols : null;
      module.exports = function assign2(target, source1) {
        if (target == null) {
          throw new TypeError("target must be an object");
        }
        var to = $Object(target);
        if (arguments.length === 1) {
          return to;
        }
        for (var s = 1; s < arguments.length; ++s) {
          var from = $Object(arguments[s]);
          var keys = objectKeys(from);
          var getSymbols = hasSymbols && ($Object.getOwnPropertySymbols || originalGetSymbols);
          if (getSymbols) {
            var syms = getSymbols(from);
            for (var j = 0; j < syms.length; ++j) {
              var key = syms[j];
              if ($propIsEnumerable(from, key)) {
                $push(keys, key);
              }
            }
          }
          for (var i = 0; i < keys.length; ++i) {
            var nextKey = keys[i];
            if ($propIsEnumerable(from, nextKey)) {
              var propValue = from[nextKey];
              to[nextKey] = propValue;
            }
          }
        }
        return to;
      };
    }
  });

  // node_modules/object.assign/polyfill.js
  var require_polyfill = __commonJS({
    "node_modules/object.assign/polyfill.js"(exports, module) {
      "use strict";
      var implementation = require_implementation3();
      var lacksProperEnumerationOrder = function() {
        if (!Object.assign) {
          return false;
        }
        var str = "abcdefghijklmnopqrst";
        var letters = str.split("");
        var map = {};
        for (var i = 0; i < letters.length; ++i) {
          map[letters[i]] = letters[i];
        }
        var obj = Object.assign({}, map);
        var actual = "";
        for (var k in obj) {
          actual += k;
        }
        return str !== actual;
      };
      var assignHasPendingExceptions = function() {
        if (!Object.assign || !Object.preventExtensions) {
          return false;
        }
        var thrower = Object.preventExtensions({ 1: 2 });
        try {
          Object.assign(thrower, "xy");
        } catch (e) {
          return thrower[1] === "y";
        }
        return false;
      };
      module.exports = function getPolyfill() {
        if (!Object.assign) {
          return implementation;
        }
        if (lacksProperEnumerationOrder()) {
          return implementation;
        }
        if (assignHasPendingExceptions()) {
          return implementation;
        }
        return Object.assign;
      };
    }
  });

  // node_modules/assert/node_modules/util/support/isBufferBrowser.js
  var require_isBufferBrowser = __commonJS({
    "node_modules/assert/node_modules/util/support/isBufferBrowser.js"(exports, module) {
      module.exports = function isBuffer(arg) {
        return arg && typeof arg === "object" && typeof arg.copy === "function" && typeof arg.fill === "function" && typeof arg.readUInt8 === "function";
      };
    }
  });

  // node_modules/assert/node_modules/inherits/inherits_browser.js
  var require_inherits_browser = __commonJS({
    "node_modules/assert/node_modules/inherits/inherits_browser.js"(exports, module) {
      if (typeof Object.create === "function") {
        module.exports = function inherits(ctor, superCtor) {
          ctor.super_ = superCtor;
          ctor.prototype = Object.create(superCtor.prototype, {
            constructor: {
              value: ctor,
              enumerable: false,
              writable: true,
              configurable: true
            }
          });
        };
      } else {
        module.exports = function inherits(ctor, superCtor) {
          ctor.super_ = superCtor;
          var TempCtor = function() {
          };
          TempCtor.prototype = superCtor.prototype;
          ctor.prototype = new TempCtor();
          ctor.prototype.constructor = ctor;
        };
      }
    }
  });

  // node_modules/assert/node_modules/util/util.js
  var require_util = __commonJS({
    "node_modules/assert/node_modules/util/util.js"(exports) {
      var formatRegExp = /%[sdj%]/g;
      exports.format = function(f) {
        if (!isString2(f)) {
          var objects = [];
          for (var i = 0; i < arguments.length; i++) {
            objects.push(inspect(arguments[i]));
          }
          return objects.join(" ");
        }
        var i = 1;
        var args = arguments;
        var len = args.length;
        var str = String(f).replace(formatRegExp, function(x2) {
          if (x2 === "%%") return "%";
          if (i >= len) return x2;
          switch (x2) {
            case "%s":
              return String(args[i++]);
            case "%d":
              return Number(args[i++]);
            case "%j":
              try {
                return JSON.stringify(args[i++]);
              } catch (_) {
                return "[Circular]";
              }
            default:
              return x2;
          }
        });
        for (var x = args[i]; i < len; x = args[++i]) {
          if (isNull2(x) || !isObject2(x)) {
            str += " " + x;
          } else {
            str += " " + inspect(x);
          }
        }
        return str;
      };
      exports.deprecate = function(fn, msg) {
        if (isUndefined2(global.process)) {
          return function() {
            return exports.deprecate(fn, msg).apply(this, arguments);
          };
        }
        if (process.noDeprecation === true) {
          return fn;
        }
        var warned = false;
        function deprecated() {
          if (!warned) {
            if (process.throwDeprecation) {
              throw new Error(msg);
            } else if (process.traceDeprecation) {
              console.trace(msg);
            } else {
              console.error(msg);
            }
            warned = true;
          }
          return fn.apply(this, arguments);
        }
        return deprecated;
      };
      var debugs = {};
      var debugEnviron;
      exports.debuglog = function(set) {
        if (isUndefined2(debugEnviron))
          debugEnviron = process.env.NODE_DEBUG || "";
        set = set.toUpperCase();
        if (!debugs[set]) {
          if (new RegExp("\\b" + set + "\\b", "i").test(debugEnviron)) {
            var pid = process.pid;
            debugs[set] = function() {
              var msg = exports.format.apply(exports, arguments);
              console.error("%s %d: %s", set, pid, msg);
            };
          } else {
            debugs[set] = function() {
            };
          }
        }
        return debugs[set];
      };
      function inspect(obj, opts) {
        var ctx = {
          seen: [],
          stylize: stylizeNoColor
        };
        if (arguments.length >= 3) ctx.depth = arguments[2];
        if (arguments.length >= 4) ctx.colors = arguments[3];
        if (isBoolean2(opts)) {
          ctx.showHidden = opts;
        } else if (opts) {
          exports._extend(ctx, opts);
        }
        if (isUndefined2(ctx.showHidden)) ctx.showHidden = false;
        if (isUndefined2(ctx.depth)) ctx.depth = 2;
        if (isUndefined2(ctx.colors)) ctx.colors = false;
        if (isUndefined2(ctx.customInspect)) ctx.customInspect = true;
        if (ctx.colors) ctx.stylize = stylizeWithColor;
        return formatValue(ctx, obj, ctx.depth);
      }
      exports.inspect = inspect;
      inspect.colors = {
        "bold": [1, 22],
        "italic": [3, 23],
        "underline": [4, 24],
        "inverse": [7, 27],
        "white": [37, 39],
        "grey": [90, 39],
        "black": [30, 39],
        "blue": [34, 39],
        "cyan": [36, 39],
        "green": [32, 39],
        "magenta": [35, 39],
        "red": [31, 39],
        "yellow": [33, 39]
      };
      inspect.styles = {
        "special": "cyan",
        "number": "yellow",
        "boolean": "yellow",
        "undefined": "grey",
        "null": "bold",
        "string": "green",
        "date": "magenta",
        // "name": intentionally not styling
        "regexp": "red"
      };
      function stylizeWithColor(str, styleType) {
        var style = inspect.styles[styleType];
        if (style) {
          return "\x1B[" + inspect.colors[style][0] + "m" + str + "\x1B[" + inspect.colors[style][1] + "m";
        } else {
          return str;
        }
      }
      function stylizeNoColor(str, styleType) {
        return str;
      }
      function arrayToHash(array) {
        var hash = {};
        array.forEach(function(val, idx) {
          hash[val] = true;
        });
        return hash;
      }
      function formatValue(ctx, value, recurseTimes) {
        if (ctx.customInspect && value && isFunction2(value.inspect) && // Filter out the util module, it's inspect function is special
        value.inspect !== exports.inspect && // Also filter out any prototype objects using the circular check.
        !(value.constructor && value.constructor.prototype === value)) {
          var ret = value.inspect(recurseTimes, ctx);
          if (!isString2(ret)) {
            ret = formatValue(ctx, ret, recurseTimes);
          }
          return ret;
        }
        var primitive = formatPrimitive(ctx, value);
        if (primitive) {
          return primitive;
        }
        var keys = Object.keys(value);
        var visibleKeys = arrayToHash(keys);
        if (ctx.showHidden) {
          keys = Object.getOwnPropertyNames(value);
        }
        if (isError(value) && (keys.indexOf("message") >= 0 || keys.indexOf("description") >= 0)) {
          return formatError(value);
        }
        if (keys.length === 0) {
          if (isFunction2(value)) {
            var name86 = value.name ? ": " + value.name : "";
            return ctx.stylize("[Function" + name86 + "]", "special");
          }
          if (isRegExp2(value)) {
            return ctx.stylize(RegExp.prototype.toString.call(value), "regexp");
          }
          if (isDate2(value)) {
            return ctx.stylize(Date.prototype.toString.call(value), "date");
          }
          if (isError(value)) {
            return formatError(value);
          }
        }
        var base = "", array = false, braces = ["{", "}"];
        if (isArray2(value)) {
          array = true;
          braces = ["[", "]"];
        }
        if (isFunction2(value)) {
          var n = value.name ? ": " + value.name : "";
          base = " [Function" + n + "]";
        }
        if (isRegExp2(value)) {
          base = " " + RegExp.prototype.toString.call(value);
        }
        if (isDate2(value)) {
          base = " " + Date.prototype.toUTCString.call(value);
        }
        if (isError(value)) {
          base = " " + formatError(value);
        }
        if (keys.length === 0 && (!array || value.length == 0)) {
          return braces[0] + base + braces[1];
        }
        if (recurseTimes < 0) {
          if (isRegExp2(value)) {
            return ctx.stylize(RegExp.prototype.toString.call(value), "regexp");
          } else {
            return ctx.stylize("[Object]", "special");
          }
        }
        ctx.seen.push(value);
        var output;
        if (array) {
          output = formatArray2(ctx, value, recurseTimes, visibleKeys, keys);
        } else {
          output = keys.map(function(key) {
            return formatProperty(ctx, value, recurseTimes, visibleKeys, key, array);
          });
        }
        ctx.seen.pop();
        return reduceToSingleString(output, base, braces);
      }
      function formatPrimitive(ctx, value) {
        if (isUndefined2(value))
          return ctx.stylize("undefined", "undefined");
        if (isString2(value)) {
          var simple = "'" + JSON.stringify(value).replace(/^"|"$/g, "").replace(/'/g, "\\'").replace(/\\"/g, '"') + "'";
          return ctx.stylize(simple, "string");
        }
        if (isNumber2(value))
          return ctx.stylize("" + value, "number");
        if (isBoolean2(value))
          return ctx.stylize("" + value, "boolean");
        if (isNull2(value))
          return ctx.stylize("null", "null");
      }
      function formatError(value) {
        return "[" + Error.prototype.toString.call(value) + "]";
      }
      function formatArray2(ctx, value, recurseTimes, visibleKeys, keys) {
        var output = [];
        for (var i = 0, l = value.length; i < l; ++i) {
          if (hasOwnProperty2(value, String(i))) {
            output.push(formatProperty(
              ctx,
              value,
              recurseTimes,
              visibleKeys,
              String(i),
              true
            ));
          } else {
            output.push("");
          }
        }
        keys.forEach(function(key) {
          if (!key.match(/^\d+$/)) {
            output.push(formatProperty(
              ctx,
              value,
              recurseTimes,
              visibleKeys,
              key,
              true
            ));
          }
        });
        return output;
      }
      function formatProperty(ctx, value, recurseTimes, visibleKeys, key, array) {
        var name86, str, desc;
        desc = Object.getOwnPropertyDescriptor(value, key) || { value: value[key] };
        if (desc.get) {
          if (desc.set) {
            str = ctx.stylize("[Getter/Setter]", "special");
          } else {
            str = ctx.stylize("[Getter]", "special");
          }
        } else {
          if (desc.set) {
            str = ctx.stylize("[Setter]", "special");
          }
        }
        if (!hasOwnProperty2(visibleKeys, key)) {
          name86 = "[" + key + "]";
        }
        if (!str) {
          if (ctx.seen.indexOf(desc.value) < 0) {
            if (isNull2(recurseTimes)) {
              str = formatValue(ctx, desc.value, null);
            } else {
              str = formatValue(ctx, desc.value, recurseTimes - 1);
            }
            if (str.indexOf("\n") > -1) {
              if (array) {
                str = str.split("\n").map(function(line) {
                  return "  " + line;
                }).join("\n").substr(2);
              } else {
                str = "\n" + str.split("\n").map(function(line) {
                  return "   " + line;
                }).join("\n");
              }
            }
          } else {
            str = ctx.stylize("[Circular]", "special");
          }
        }
        if (isUndefined2(name86)) {
          if (array && key.match(/^\d+$/)) {
            return str;
          }
          name86 = JSON.stringify("" + key);
          if (name86.match(/^"([a-zA-Z_][a-zA-Z_0-9]*)"$/)) {
            name86 = name86.substr(1, name86.length - 2);
            name86 = ctx.stylize(name86, "name");
          } else {
            name86 = name86.replace(/'/g, "\\'").replace(/\\"/g, '"').replace(/(^"|"$)/g, "'");
            name86 = ctx.stylize(name86, "string");
          }
        }
        return name86 + ": " + str;
      }
      function reduceToSingleString(output, base, braces) {
        var numLinesEst = 0;
        var length = output.reduce(function(prev, cur) {
          numLinesEst++;
          if (cur.indexOf("\n") >= 0) numLinesEst++;
          return prev + cur.replace(/\u001b\[\d\d?m/g, "").length + 1;
        }, 0);
        if (length > 60) {
          return braces[0] + (base === "" ? "" : base + "\n ") + " " + output.join(",\n  ") + " " + braces[1];
        }
        return braces[0] + base + " " + output.join(", ") + " " + braces[1];
      }
      function isArray2(ar) {
        return Array.isArray(ar);
      }
      exports.isArray = isArray2;
      function isBoolean2(arg) {
        return typeof arg === "boolean";
      }
      exports.isBoolean = isBoolean2;
      function isNull2(arg) {
        return arg === null;
      }
      exports.isNull = isNull2;
      function isNullOrUndefined(arg) {
        return arg == null;
      }
      exports.isNullOrUndefined = isNullOrUndefined;
      function isNumber2(arg) {
        return typeof arg === "number";
      }
      exports.isNumber = isNumber2;
      function isString2(arg) {
        return typeof arg === "string";
      }
      exports.isString = isString2;
      function isSymbol(arg) {
        return typeof arg === "symbol";
      }
      exports.isSymbol = isSymbol;
      function isUndefined2(arg) {
        return arg === void 0;
      }
      exports.isUndefined = isUndefined2;
      function isRegExp2(re2) {
        return isObject2(re2) && objectToString(re2) === "[object RegExp]";
      }
      exports.isRegExp = isRegExp2;
      function isObject2(arg) {
        return typeof arg === "object" && arg !== null;
      }
      exports.isObject = isObject2;
      function isDate2(d) {
        return isObject2(d) && objectToString(d) === "[object Date]";
      }
      exports.isDate = isDate2;
      function isError(e) {
        return isObject2(e) && (objectToString(e) === "[object Error]" || e instanceof Error);
      }
      exports.isError = isError;
      function isFunction2(arg) {
        return typeof arg === "function";
      }
      exports.isFunction = isFunction2;
      function isPrimitive(arg) {
        return arg === null || typeof arg === "boolean" || typeof arg === "number" || typeof arg === "string" || typeof arg === "symbol" || // ES6 symbol
        typeof arg === "undefined";
      }
      exports.isPrimitive = isPrimitive;
      exports.isBuffer = require_isBufferBrowser();
      function objectToString(o) {
        return Object.prototype.toString.call(o);
      }
      function pad(n) {
        return n < 10 ? "0" + n.toString(10) : n.toString(10);
      }
      var months = [
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
      ];
      function timestamp() {
        var d = /* @__PURE__ */ new Date();
        var time = [
          pad(d.getHours()),
          pad(d.getMinutes()),
          pad(d.getSeconds())
        ].join(":");
        return [d.getDate(), months[d.getMonth()], time].join(" ");
      }
      exports.log = function() {
        console.log("%s - %s", timestamp(), exports.format.apply(exports, arguments));
      };
      exports.inherits = require_inherits_browser();
      exports._extend = function(origin, add3) {
        if (!add3 || !isObject2(add3)) return origin;
        var keys = Object.keys(add3);
        var i = keys.length;
        while (i--) {
          origin[keys[i]] = add3[keys[i]];
        }
        return origin;
      };
      function hasOwnProperty2(obj, prop) {
        return Object.prototype.hasOwnProperty.call(obj, prop);
      }
    }
  });

  // node_modules/assert/assert.js
  var require_assert = __commonJS({
    "node_modules/assert/assert.js"(exports, module) {
      "use strict";
      var objectAssign = require_polyfill()();
      function compare(a, b) {
        if (a === b) {
          return 0;
        }
        var x = a.length;
        var y = b.length;
        for (var i = 0, len = Math.min(x, y); i < len; ++i) {
          if (a[i] !== b[i]) {
            x = a[i];
            y = b[i];
            break;
          }
        }
        if (x < y) {
          return -1;
        }
        if (y < x) {
          return 1;
        }
        return 0;
      }
      function isBuffer(b) {
        if (global.Buffer && typeof global.Buffer.isBuffer === "function") {
          return global.Buffer.isBuffer(b);
        }
        return !!(b != null && b._isBuffer);
      }
      var util = require_util();
      var hasOwn = Object.prototype.hasOwnProperty;
      var pSlice = Array.prototype.slice;
      var functionsHaveNames = (function() {
        return function foo() {
        }.name === "foo";
      })();
      function pToString(obj) {
        return Object.prototype.toString.call(obj);
      }
      function isView(arrbuf) {
        if (isBuffer(arrbuf)) {
          return false;
        }
        if (typeof global.ArrayBuffer !== "function") {
          return false;
        }
        if (typeof ArrayBuffer.isView === "function") {
          return ArrayBuffer.isView(arrbuf);
        }
        if (!arrbuf) {
          return false;
        }
        if (arrbuf instanceof DataView) {
          return true;
        }
        if (arrbuf.buffer && arrbuf.buffer instanceof ArrayBuffer) {
          return true;
        }
        return false;
      }
      var assert2 = module.exports = ok;
      var regex = /\s*function\s+([^\(\s]*)\s*/;
      function getName(func) {
        if (!util.isFunction(func)) {
          return;
        }
        if (functionsHaveNames) {
          return func.name;
        }
        var str = func.toString();
        var match = str.match(regex);
        return match && match[1];
      }
      assert2.AssertionError = function AssertionError(options) {
        this.name = "AssertionError";
        this.actual = options.actual;
        this.expected = options.expected;
        this.operator = options.operator;
        if (options.message) {
          this.message = options.message;
          this.generatedMessage = false;
        } else {
          this.message = getMessage(this);
          this.generatedMessage = true;
        }
        var stackStartFunction = options.stackStartFunction || fail;
        if (Error.captureStackTrace) {
          Error.captureStackTrace(this, stackStartFunction);
        } else {
          var err = new Error();
          if (err.stack) {
            var out = err.stack;
            var fn_name = getName(stackStartFunction);
            var idx = out.indexOf("\n" + fn_name);
            if (idx >= 0) {
              var next_line = out.indexOf("\n", idx + 1);
              out = out.substring(next_line + 1);
            }
            this.stack = out;
          }
        }
      };
      util.inherits(assert2.AssertionError, Error);
      function truncate2(s, n) {
        if (typeof s === "string") {
          return s.length < n ? s : s.slice(0, n);
        } else {
          return s;
        }
      }
      function inspect(something) {
        if (functionsHaveNames || !util.isFunction(something)) {
          return util.inspect(something);
        }
        var rawname = getName(something);
        var name86 = rawname ? ": " + rawname : "";
        return "[Function" + name86 + "]";
      }
      function getMessage(self2) {
        return truncate2(inspect(self2.actual), 128) + " " + self2.operator + " " + truncate2(inspect(self2.expected), 128);
      }
      function fail(actual, expected, message, operator, stackStartFunction) {
        throw new assert2.AssertionError({
          message,
          actual,
          expected,
          operator,
          stackStartFunction
        });
      }
      assert2.fail = fail;
      function ok(value, message) {
        if (!value) fail(value, true, message, "==", assert2.ok);
      }
      assert2.ok = ok;
      assert2.equal = function equal3(actual, expected, message) {
        if (actual != expected) fail(actual, expected, message, "==", assert2.equal);
      };
      assert2.notEqual = function notEqual(actual, expected, message) {
        if (actual == expected) {
          fail(actual, expected, message, "!=", assert2.notEqual);
        }
      };
      assert2.deepEqual = function deepEqual2(actual, expected, message) {
        if (!_deepEqual(actual, expected, false)) {
          fail(actual, expected, message, "deepEqual", assert2.deepEqual);
        }
      };
      assert2.deepStrictEqual = function deepStrictEqual2(actual, expected, message) {
        if (!_deepEqual(actual, expected, true)) {
          fail(actual, expected, message, "deepStrictEqual", assert2.deepStrictEqual);
        }
      };
      function _deepEqual(actual, expected, strict2, memos) {
        if (actual === expected) {
          return true;
        } else if (isBuffer(actual) && isBuffer(expected)) {
          return compare(actual, expected) === 0;
        } else if (util.isDate(actual) && util.isDate(expected)) {
          return actual.getTime() === expected.getTime();
        } else if (util.isRegExp(actual) && util.isRegExp(expected)) {
          return actual.source === expected.source && actual.global === expected.global && actual.multiline === expected.multiline && actual.lastIndex === expected.lastIndex && actual.ignoreCase === expected.ignoreCase;
        } else if ((actual === null || typeof actual !== "object") && (expected === null || typeof expected !== "object")) {
          return strict2 ? actual === expected : actual == expected;
        } else if (isView(actual) && isView(expected) && pToString(actual) === pToString(expected) && !(actual instanceof Float32Array || actual instanceof Float64Array)) {
          return compare(
            new Uint8Array(actual.buffer),
            new Uint8Array(expected.buffer)
          ) === 0;
        } else if (isBuffer(actual) !== isBuffer(expected)) {
          return false;
        } else {
          memos = memos || { actual: [], expected: [] };
          var actualIndex = memos.actual.indexOf(actual);
          if (actualIndex !== -1) {
            if (actualIndex === memos.expected.indexOf(expected)) {
              return true;
            }
          }
          memos.actual.push(actual);
          memos.expected.push(expected);
          return objEquiv(actual, expected, strict2, memos);
        }
      }
      function isArguments(object) {
        return Object.prototype.toString.call(object) == "[object Arguments]";
      }
      function objEquiv(a, b, strict2, actualVisitedObjects) {
        if (a === null || a === void 0 || b === null || b === void 0)
          return false;
        if (util.isPrimitive(a) || util.isPrimitive(b))
          return a === b;
        if (strict2 && Object.getPrototypeOf(a) !== Object.getPrototypeOf(b))
          return false;
        var aIsArgs = isArguments(a);
        var bIsArgs = isArguments(b);
        if (aIsArgs && !bIsArgs || !aIsArgs && bIsArgs)
          return false;
        if (aIsArgs) {
          a = pSlice.call(a);
          b = pSlice.call(b);
          return _deepEqual(a, b, strict2);
        }
        var ka = objectKeys(a);
        var kb = objectKeys(b);
        var key, i;
        if (ka.length !== kb.length)
          return false;
        ka.sort();
        kb.sort();
        for (i = ka.length - 1; i >= 0; i--) {
          if (ka[i] !== kb[i])
            return false;
        }
        for (i = ka.length - 1; i >= 0; i--) {
          key = ka[i];
          if (!_deepEqual(a[key], b[key], strict2, actualVisitedObjects))
            return false;
        }
        return true;
      }
      assert2.notDeepEqual = function notDeepEqual(actual, expected, message) {
        if (_deepEqual(actual, expected, false)) {
          fail(actual, expected, message, "notDeepEqual", assert2.notDeepEqual);
        }
      };
      assert2.notDeepStrictEqual = notDeepStrictEqual;
      function notDeepStrictEqual(actual, expected, message) {
        if (_deepEqual(actual, expected, true)) {
          fail(actual, expected, message, "notDeepStrictEqual", notDeepStrictEqual);
        }
      }
      assert2.strictEqual = function strictEqual(actual, expected, message) {
        if (actual !== expected) {
          fail(actual, expected, message, "===", assert2.strictEqual);
        }
      };
      assert2.notStrictEqual = function notStrictEqual(actual, expected, message) {
        if (actual === expected) {
          fail(actual, expected, message, "!==", assert2.notStrictEqual);
        }
      };
      function expectedException(actual, expected) {
        if (!actual || !expected) {
          return false;
        }
        if (Object.prototype.toString.call(expected) == "[object RegExp]") {
          return expected.test(actual);
        }
        try {
          if (actual instanceof expected) {
            return true;
          }
        } catch (e) {
        }
        if (Error.isPrototypeOf(expected)) {
          return false;
        }
        return expected.call({}, actual) === true;
      }
      function _tryBlock(block) {
        var error;
        try {
          block();
        } catch (e) {
          error = e;
        }
        return error;
      }
      function _throws(shouldThrow, block, expected, message) {
        var actual;
        if (typeof block !== "function") {
          throw new TypeError('"block" argument must be a function');
        }
        if (typeof expected === "string") {
          message = expected;
          expected = null;
        }
        actual = _tryBlock(block);
        message = (expected && expected.name ? " (" + expected.name + ")." : ".") + (message ? " " + message : ".");
        if (shouldThrow && !actual) {
          fail(actual, expected, "Missing expected exception" + message);
        }
        var userProvidedMessage = typeof message === "string";
        var isUnwantedException = !shouldThrow && util.isError(actual);
        var isUnexpectedException = !shouldThrow && actual && !expected;
        if (isUnwantedException && userProvidedMessage && expectedException(actual, expected) || isUnexpectedException) {
          fail(actual, expected, "Got unwanted exception" + message);
        }
        if (shouldThrow && actual && expected && !expectedException(actual, expected) || !shouldThrow && actual) {
          throw actual;
        }
      }
      assert2.throws = function(block, error, message) {
        _throws(true, block, error, message);
      };
      assert2.doesNotThrow = function(block, error, message) {
        _throws(false, block, error, message);
      };
      assert2.ifError = function(err) {
        if (err) throw err;
      };
      function strict(value, message) {
        if (!value) fail(value, true, message, "==", strict);
      }
      assert2.strict = objectAssign(strict, assert2, {
        equal: assert2.strictEqual,
        deepEqual: assert2.deepStrictEqual,
        notEqual: assert2.notStrictEqual,
        notDeepEqual: assert2.notDeepStrictEqual
      });
      assert2.strict.strict = assert2.strict;
      var objectKeys = Object.keys || function(obj) {
        var keys = [];
        for (var key in obj) {
          if (hasOwn.call(obj, key)) keys.push(key);
        }
        return keys;
      };
    }
  });

  // node_modules/typed-function/typed-function.js
  var require_typed_function = __commonJS({
    "node_modules/typed-function/typed-function.js"(exports, module) {
      "use strict";
      (function(root, factory2) {
        if (typeof define === "function" && define.amd) {
          define([], factory2);
        } else if (typeof exports === "object") {
          module.exports = factory2();
        } else {
          root.typed = factory2();
        }
      })(exports, function() {
        function ok() {
          return true;
        }
        function notOk() {
          return false;
        }
        function undef() {
          return void 0;
        }
        function create() {
          var _types = [
            { name: "number", test: function(x) {
              return typeof x === "number";
            } },
            { name: "string", test: function(x) {
              return typeof x === "string";
            } },
            { name: "boolean", test: function(x) {
              return typeof x === "boolean";
            } },
            { name: "Function", test: function(x) {
              return typeof x === "function";
            } },
            { name: "Array", test: Array.isArray },
            { name: "Date", test: function(x) {
              return x instanceof Date;
            } },
            { name: "RegExp", test: function(x) {
              return x instanceof RegExp;
            } },
            { name: "Object", test: function(x) {
              return typeof x === "object" && x !== null && x.constructor === Object;
            } },
            { name: "null", test: function(x) {
              return x === null;
            } },
            { name: "undefined", test: function(x) {
              return x === void 0;
            } }
          ];
          var anyType = {
            name: "any",
            test: ok
          };
          var _ignore = [];
          var _conversions = [];
          var typed2 = {
            types: _types,
            conversions: _conversions,
            ignore: _ignore
          };
          function findTypeByName(typeName) {
            var entry = findInArray(typed2.types, function(entry2) {
              return entry2.name === typeName;
            });
            if (entry) {
              return entry;
            }
            if (typeName === "any") {
              return anyType;
            }
            var hint = findInArray(typed2.types, function(entry2) {
              return entry2.name.toLowerCase() === typeName.toLowerCase();
            });
            throw new TypeError('Unknown type "' + typeName + '"' + (hint ? '. Did you mean "' + hint.name + '"?' : ""));
          }
          function findTypeIndex(type) {
            if (type === anyType) {
              return 999;
            }
            return typed2.types.indexOf(type);
          }
          function findTypeName(value) {
            var entry = findInArray(typed2.types, function(entry2) {
              return entry2.test(value);
            });
            if (entry) {
              return entry.name;
            }
            throw new TypeError("Value has unknown type. Value: " + value);
          }
          function find(fn, signature) {
            if (!fn.signatures) {
              throw new TypeError("Function is no typed-function");
            }
            var arr;
            if (typeof signature === "string") {
              arr = signature.split(",");
              for (var i = 0; i < arr.length; i++) {
                arr[i] = arr[i].trim();
              }
            } else if (Array.isArray(signature)) {
              arr = signature;
            } else {
              throw new TypeError("String array or a comma separated string expected");
            }
            var str = arr.join(",");
            var match = fn.signatures[str];
            if (match) {
              return match;
            }
            throw new TypeError("Signature not found (signature: " + (fn.name || "unnamed") + "(" + arr.join(", ") + "))");
          }
          function convert(value, type) {
            var from = findTypeName(value);
            if (type === from) {
              return value;
            }
            for (var i = 0; i < typed2.conversions.length; i++) {
              var conversion = typed2.conversions[i];
              if (conversion.from === from && conversion.to === type) {
                return conversion.convert(value);
              }
            }
            throw new Error("Cannot convert from " + from + " to " + type);
          }
          function stringifyParams(params) {
            return params.map(function(param) {
              var typeNames = param.types.map(getTypeName);
              return (param.restParam ? "..." : "") + typeNames.join("|");
            }).join(",");
          }
          function parseParam(param, conversions) {
            var restParam = param.indexOf("...") === 0;
            var types = !restParam ? param : param.length > 3 ? param.slice(3) : "any";
            var typeNames = types.split("|").map(trim).filter(notEmpty).filter(notIgnore);
            var matchingConversions = filterConversions(conversions, typeNames);
            var exactTypes = typeNames.map(function(typeName) {
              var type = findTypeByName(typeName);
              return {
                name: typeName,
                typeIndex: findTypeIndex(type),
                test: type.test,
                conversion: null,
                conversionIndex: -1
              };
            });
            var convertibleTypes = matchingConversions.map(function(conversion) {
              var type = findTypeByName(conversion.from);
              return {
                name: conversion.from,
                typeIndex: findTypeIndex(type),
                test: type.test,
                conversion,
                conversionIndex: conversions.indexOf(conversion)
              };
            });
            return {
              types: exactTypes.concat(convertibleTypes),
              restParam
            };
          }
          function parseSignature(signature, fn, conversions) {
            var params = [];
            if (signature.trim() !== "") {
              params = signature.split(",").map(trim).map(function(param, index2, array) {
                var parsedParam = parseParam(param, conversions);
                if (parsedParam.restParam && index2 !== array.length - 1) {
                  throw new SyntaxError('Unexpected rest parameter "' + param + '": only allowed for the last parameter');
                }
                return parsedParam;
              });
            }
            if (params.some(isInvalidParam)) {
              return null;
            }
            return {
              params,
              fn
            };
          }
          function hasRestParam(params) {
            var param = last(params);
            return param ? param.restParam : false;
          }
          function hasConversions(param) {
            return param.types.some(function(type) {
              return type.conversion != null;
            });
          }
          function compileTest(param) {
            if (!param || param.types.length === 0) {
              return ok;
            } else if (param.types.length === 1) {
              return findTypeByName(param.types[0].name).test;
            } else if (param.types.length === 2) {
              var test0 = findTypeByName(param.types[0].name).test;
              var test1 = findTypeByName(param.types[1].name).test;
              return function or(x) {
                return test0(x) || test1(x);
              };
            } else {
              var tests = param.types.map(function(type) {
                return findTypeByName(type.name).test;
              });
              return function or(x) {
                for (var i = 0; i < tests.length; i++) {
                  if (tests[i](x)) {
                    return true;
                  }
                }
                return false;
              };
            }
          }
          function compileTests(params) {
            var tests, test0, test1;
            if (hasRestParam(params)) {
              tests = initial(params).map(compileTest);
              var varIndex = tests.length;
              var lastTest = compileTest(last(params));
              var testRestParam = function(args) {
                for (var i = varIndex; i < args.length; i++) {
                  if (!lastTest(args[i])) {
                    return false;
                  }
                }
                return true;
              };
              return function testArgs(args) {
                for (var i = 0; i < tests.length; i++) {
                  if (!tests[i](args[i])) {
                    return false;
                  }
                }
                return testRestParam(args) && args.length >= varIndex + 1;
              };
            } else {
              if (params.length === 0) {
                return function testArgs(args) {
                  return args.length === 0;
                };
              } else if (params.length === 1) {
                test0 = compileTest(params[0]);
                return function testArgs(args) {
                  return test0(args[0]) && args.length === 1;
                };
              } else if (params.length === 2) {
                test0 = compileTest(params[0]);
                test1 = compileTest(params[1]);
                return function testArgs(args) {
                  return test0(args[0]) && test1(args[1]) && args.length === 2;
                };
              } else {
                tests = params.map(compileTest);
                return function testArgs(args) {
                  for (var i = 0; i < tests.length; i++) {
                    if (!tests[i](args[i])) {
                      return false;
                    }
                  }
                  return args.length === tests.length;
                };
              }
            }
          }
          function getParamAtIndex(signature, index2) {
            return index2 < signature.params.length ? signature.params[index2] : hasRestParam(signature.params) ? last(signature.params) : null;
          }
          function getExpectedTypeNames(signature, index2, excludeConversions) {
            var param = getParamAtIndex(signature, index2);
            var types = param ? excludeConversions ? param.types.filter(isExactType) : param.types : [];
            return types.map(getTypeName);
          }
          function getTypeName(type) {
            return type.name;
          }
          function isExactType(type) {
            return type.conversion === null || type.conversion === void 0;
          }
          function mergeExpectedParams(signatures, index2) {
            var typeNames = uniq(flatMap(signatures, function(signature) {
              return getExpectedTypeNames(signature, index2, false);
            }));
            return typeNames.indexOf("any") !== -1 ? ["any"] : typeNames;
          }
          function createError(name86, args, signatures) {
            var err, expected;
            var _name = name86 || "unnamed";
            var matchingSignatures = signatures;
            var index2;
            for (index2 = 0; index2 < args.length; index2++) {
              var nextMatchingDefs = matchingSignatures.filter(function(signature) {
                var test = compileTest(getParamAtIndex(signature, index2));
                return (index2 < signature.params.length || hasRestParam(signature.params)) && test(args[index2]);
              });
              if (nextMatchingDefs.length === 0) {
                expected = mergeExpectedParams(matchingSignatures, index2);
                if (expected.length > 0) {
                  var actualType = findTypeName(args[index2]);
                  err = new TypeError("Unexpected type of argument in function " + _name + " (expected: " + expected.join(" or ") + ", actual: " + actualType + ", index: " + index2 + ")");
                  err.data = {
                    category: "wrongType",
                    fn: _name,
                    index: index2,
                    actual: actualType,
                    expected
                  };
                  return err;
                }
              } else {
                matchingSignatures = nextMatchingDefs;
              }
            }
            var lengths = matchingSignatures.map(function(signature) {
              return hasRestParam(signature.params) ? Infinity : signature.params.length;
            });
            if (args.length < Math.min.apply(null, lengths)) {
              expected = mergeExpectedParams(matchingSignatures, index2);
              err = new TypeError("Too few arguments in function " + _name + " (expected: " + expected.join(" or ") + ", index: " + args.length + ")");
              err.data = {
                category: "tooFewArgs",
                fn: _name,
                index: args.length,
                expected
              };
              return err;
            }
            var maxLength = Math.max.apply(null, lengths);
            if (args.length > maxLength) {
              err = new TypeError("Too many arguments in function " + _name + " (expected: " + maxLength + ", actual: " + args.length + ")");
              err.data = {
                category: "tooManyArgs",
                fn: _name,
                index: args.length,
                expectedLength: maxLength
              };
              return err;
            }
            err = new TypeError('Arguments of type "' + args.join(", ") + '" do not match any of the defined signatures of function ' + _name + ".");
            err.data = {
              category: "mismatch",
              actual: args.map(findTypeName)
            };
            return err;
          }
          function getLowestTypeIndex(param) {
            var min2 = 999;
            for (var i = 0; i < param.types.length; i++) {
              if (isExactType(param.types[i])) {
                min2 = Math.min(min2, param.types[i].typeIndex);
              }
            }
            return min2;
          }
          function getLowestConversionIndex(param) {
            var min2 = 999;
            for (var i = 0; i < param.types.length; i++) {
              if (!isExactType(param.types[i])) {
                min2 = Math.min(min2, param.types[i].conversionIndex);
              }
            }
            return min2;
          }
          function compareParams(param1, param2) {
            var c;
            c = param1.restParam - param2.restParam;
            if (c !== 0) {
              return c;
            }
            c = hasConversions(param1) - hasConversions(param2);
            if (c !== 0) {
              return c;
            }
            c = getLowestTypeIndex(param1) - getLowestTypeIndex(param2);
            if (c !== 0) {
              return c;
            }
            return getLowestConversionIndex(param1) - getLowestConversionIndex(param2);
          }
          function compareSignatures(signature1, signature2) {
            var len = Math.min(signature1.params.length, signature2.params.length);
            var i;
            var c;
            c = signature1.params.some(hasConversions) - signature2.params.some(hasConversions);
            if (c !== 0) {
              return c;
            }
            for (i = 0; i < len; i++) {
              c = hasConversions(signature1.params[i]) - hasConversions(signature2.params[i]);
              if (c !== 0) {
                return c;
              }
            }
            for (i = 0; i < len; i++) {
              c = compareParams(signature1.params[i], signature2.params[i]);
              if (c !== 0) {
                return c;
              }
            }
            return signature1.params.length - signature2.params.length;
          }
          function filterConversions(conversions, typeNames) {
            var matches = {};
            conversions.forEach(function(conversion) {
              if (typeNames.indexOf(conversion.from) === -1 && typeNames.indexOf(conversion.to) !== -1 && !matches[conversion.from]) {
                matches[conversion.from] = conversion;
              }
            });
            return Object.keys(matches).map(function(from) {
              return matches[from];
            });
          }
          function compileArgsPreprocessing(params, fn) {
            var fnConvert = fn;
            if (params.some(hasConversions)) {
              var restParam = hasRestParam(params);
              var compiledConversions = params.map(compileArgConversion);
              fnConvert = function convertArgs() {
                var args = [];
                var last2 = restParam ? arguments.length - 1 : arguments.length;
                for (var i = 0; i < last2; i++) {
                  args[i] = compiledConversions[i](arguments[i]);
                }
                if (restParam) {
                  args[last2] = arguments[last2].map(compiledConversions[last2]);
                }
                return fn.apply(this, args);
              };
            }
            var fnPreprocess = fnConvert;
            if (hasRestParam(params)) {
              var offset = params.length - 1;
              fnPreprocess = function preprocessRestParams() {
                return fnConvert.apply(
                  this,
                  slice(arguments, 0, offset).concat([slice(arguments, offset)])
                );
              };
            }
            return fnPreprocess;
          }
          function compileArgConversion(param) {
            var test0, test1, conversion0, conversion1;
            var tests = [];
            var conversions = [];
            param.types.forEach(function(type) {
              if (type.conversion) {
                tests.push(findTypeByName(type.conversion.from).test);
                conversions.push(type.conversion.convert);
              }
            });
            switch (conversions.length) {
              case 0:
                return function convertArg(arg) {
                  return arg;
                };
              case 1:
                test0 = tests[0];
                conversion0 = conversions[0];
                return function convertArg(arg) {
                  if (test0(arg)) {
                    return conversion0(arg);
                  }
                  return arg;
                };
              case 2:
                test0 = tests[0];
                test1 = tests[1];
                conversion0 = conversions[0];
                conversion1 = conversions[1];
                return function convertArg(arg) {
                  if (test0(arg)) {
                    return conversion0(arg);
                  }
                  if (test1(arg)) {
                    return conversion1(arg);
                  }
                  return arg;
                };
              default:
                return function convertArg(arg) {
                  for (var i = 0; i < conversions.length; i++) {
                    if (tests[i](arg)) {
                      return conversions[i](arg);
                    }
                  }
                  return arg;
                };
            }
          }
          function createSignaturesMap(signatures) {
            var signaturesMap = {};
            signatures.forEach(function(signature) {
              if (!signature.params.some(hasConversions)) {
                splitParams(signature.params, true).forEach(function(params) {
                  signaturesMap[stringifyParams(params)] = signature.fn;
                });
              }
            });
            return signaturesMap;
          }
          function splitParams(params, ignoreConversionTypes) {
            function _splitParams(params2, index2, types) {
              if (index2 < params2.length) {
                var param = params2[index2];
                var filteredTypes = ignoreConversionTypes ? param.types.filter(isExactType) : param.types;
                var typeGroups;
                if (param.restParam) {
                  var exactTypes = filteredTypes.filter(isExactType);
                  typeGroups = exactTypes.length < filteredTypes.length ? [exactTypes, filteredTypes] : [filteredTypes];
                } else {
                  typeGroups = filteredTypes.map(function(type) {
                    return [type];
                  });
                }
                return flatMap(typeGroups, function(typeGroup) {
                  return _splitParams(params2, index2 + 1, types.concat([typeGroup]));
                });
              } else {
                var splittedParams = types.map(function(type, typeIndex) {
                  return {
                    types: type,
                    restParam: typeIndex === params2.length - 1 && hasRestParam(params2)
                  };
                });
                return [splittedParams];
              }
            }
            return _splitParams(params, 0, []);
          }
          function hasConflictingParams(signature1, signature2) {
            var ii = Math.max(signature1.params.length, signature2.params.length);
            for (var i = 0; i < ii; i++) {
              var typesNames1 = getExpectedTypeNames(signature1, i, true);
              var typesNames2 = getExpectedTypeNames(signature2, i, true);
              if (!hasOverlap(typesNames1, typesNames2)) {
                return false;
              }
            }
            var len1 = signature1.params.length;
            var len2 = signature2.params.length;
            var restParam1 = hasRestParam(signature1.params);
            var restParam2 = hasRestParam(signature2.params);
            return restParam1 ? restParam2 ? len1 === len2 : len2 >= len1 : restParam2 ? len1 >= len2 : len1 === len2;
          }
          function createTypedFunction(name86, signaturesMap) {
            if (Object.keys(signaturesMap).length === 0) {
              throw new SyntaxError("No signatures provided");
            }
            var parsedSignatures = [];
            Object.keys(signaturesMap).map(function(signature) {
              return parseSignature(signature, signaturesMap[signature], typed2.conversions);
            }).filter(notNull).forEach(function(parsedSignature) {
              var conflictingSignature = findInArray(parsedSignatures, function(s) {
                return hasConflictingParams(s, parsedSignature);
              });
              if (conflictingSignature) {
                throw new TypeError('Conflicting signatures "' + stringifyParams(conflictingSignature.params) + '" and "' + stringifyParams(parsedSignature.params) + '".');
              }
              parsedSignatures.push(parsedSignature);
            });
            var signatures = flatMap(parsedSignatures, function(parsedSignature) {
              var params = parsedSignature ? splitParams(parsedSignature.params, false) : [];
              return params.map(function(params2) {
                return {
                  params: params2,
                  fn: parsedSignature.fn
                };
              });
            }).filter(notNull);
            signatures.sort(compareSignatures);
            var ok0 = signatures[0] && signatures[0].params.length <= 2 && !hasRestParam(signatures[0].params);
            var ok1 = signatures[1] && signatures[1].params.length <= 2 && !hasRestParam(signatures[1].params);
            var ok2 = signatures[2] && signatures[2].params.length <= 2 && !hasRestParam(signatures[2].params);
            var ok3 = signatures[3] && signatures[3].params.length <= 2 && !hasRestParam(signatures[3].params);
            var ok4 = signatures[4] && signatures[4].params.length <= 2 && !hasRestParam(signatures[4].params);
            var ok5 = signatures[5] && signatures[5].params.length <= 2 && !hasRestParam(signatures[5].params);
            var allOk = ok0 && ok1 && ok2 && ok3 && ok4 && ok5;
            var tests = signatures.map(function(signature) {
              return compileTests(signature.params);
            });
            var test00 = ok0 ? compileTest(signatures[0].params[0]) : notOk;
            var test10 = ok1 ? compileTest(signatures[1].params[0]) : notOk;
            var test20 = ok2 ? compileTest(signatures[2].params[0]) : notOk;
            var test30 = ok3 ? compileTest(signatures[3].params[0]) : notOk;
            var test40 = ok4 ? compileTest(signatures[4].params[0]) : notOk;
            var test50 = ok5 ? compileTest(signatures[5].params[0]) : notOk;
            var test01 = ok0 ? compileTest(signatures[0].params[1]) : notOk;
            var test11 = ok1 ? compileTest(signatures[1].params[1]) : notOk;
            var test21 = ok2 ? compileTest(signatures[2].params[1]) : notOk;
            var test31 = ok3 ? compileTest(signatures[3].params[1]) : notOk;
            var test41 = ok4 ? compileTest(signatures[4].params[1]) : notOk;
            var test51 = ok5 ? compileTest(signatures[5].params[1]) : notOk;
            var fns = signatures.map(function(signature) {
              return compileArgsPreprocessing(signature.params, signature.fn);
            });
            var fn0 = ok0 ? fns[0] : undef;
            var fn1 = ok1 ? fns[1] : undef;
            var fn2 = ok2 ? fns[2] : undef;
            var fn3 = ok3 ? fns[3] : undef;
            var fn4 = ok4 ? fns[4] : undef;
            var fn5 = ok5 ? fns[5] : undef;
            var len0 = ok0 ? signatures[0].params.length : -1;
            var len1 = ok1 ? signatures[1].params.length : -1;
            var len2 = ok2 ? signatures[2].params.length : -1;
            var len3 = ok3 ? signatures[3].params.length : -1;
            var len4 = ok4 ? signatures[4].params.length : -1;
            var len5 = ok5 ? signatures[5].params.length : -1;
            var iStart = allOk ? 6 : 0;
            var iEnd = signatures.length;
            var generic = function generic2() {
              "use strict";
              for (var i = iStart; i < iEnd; i++) {
                if (tests[i](arguments)) {
                  return fns[i].apply(this, arguments);
                }
              }
              return typed2.onMismatch(name86, arguments, signatures);
            };
            var fn = function fn6(arg0, arg1) {
              "use strict";
              if (arguments.length === len0 && test00(arg0) && test01(arg1)) {
                return fn0.apply(fn6, arguments);
              }
              if (arguments.length === len1 && test10(arg0) && test11(arg1)) {
                return fn1.apply(fn6, arguments);
              }
              if (arguments.length === len2 && test20(arg0) && test21(arg1)) {
                return fn2.apply(fn6, arguments);
              }
              if (arguments.length === len3 && test30(arg0) && test31(arg1)) {
                return fn3.apply(fn6, arguments);
              }
              if (arguments.length === len4 && test40(arg0) && test41(arg1)) {
                return fn4.apply(fn6, arguments);
              }
              if (arguments.length === len5 && test50(arg0) && test51(arg1)) {
                return fn5.apply(fn6, arguments);
              }
              return generic.apply(fn6, arguments);
            };
            try {
              Object.defineProperty(fn, "name", { value: name86 });
            } catch (err) {
            }
            fn.signatures = createSignaturesMap(signatures);
            return fn;
          }
          function _onMismatch(name86, args, signatures) {
            throw createError(name86, args, signatures);
          }
          function notIgnore(typeName) {
            return typed2.ignore.indexOf(typeName) === -1;
          }
          function trim(str) {
            return str.trim();
          }
          function notEmpty(str) {
            return !!str;
          }
          function notNull(value) {
            return value !== null;
          }
          function isInvalidParam(param) {
            return param.types.length === 0;
          }
          function initial(arr) {
            return arr.slice(0, arr.length - 1);
          }
          function last(arr) {
            return arr[arr.length - 1];
          }
          function slice(arr, start, end) {
            return Array.prototype.slice.call(arr, start, end);
          }
          function contains(array, item) {
            return array.indexOf(item) !== -1;
          }
          function hasOverlap(array1, array2) {
            for (var i = 0; i < array1.length; i++) {
              if (contains(array2, array1[i])) {
                return true;
              }
            }
            return false;
          }
          function findInArray(arr, test) {
            for (var i = 0; i < arr.length; i++) {
              if (test(arr[i])) {
                return arr[i];
              }
            }
            return void 0;
          }
          function uniq(arr) {
            var entries = {};
            for (var i = 0; i < arr.length; i++) {
              entries[arr[i]] = true;
            }
            return Object.keys(entries);
          }
          function flatMap(arr, callback) {
            return Array.prototype.concat.apply([], arr.map(callback));
          }
          function getName(fns) {
            var name86 = "";
            for (var i = 0; i < fns.length; i++) {
              var fn = fns[i];
              if ((typeof fn.signatures === "object" || typeof fn.signature === "string") && fn.name !== "") {
                if (name86 === "") {
                  name86 = fn.name;
                } else if (name86 !== fn.name) {
                  var err = new Error("Function names do not match (expected: " + name86 + ", actual: " + fn.name + ")");
                  err.data = {
                    actual: fn.name,
                    expected: name86
                  };
                  throw err;
                }
              }
            }
            return name86;
          }
          function extractSignatures(fns) {
            var err;
            var signaturesMap = {};
            function validateUnique(_signature, _fn) {
              if (signaturesMap.hasOwnProperty(_signature) && _fn !== signaturesMap[_signature]) {
                err = new Error('Signature "' + _signature + '" is defined twice');
                err.data = { signature: _signature };
                throw err;
              }
            }
            for (var i = 0; i < fns.length; i++) {
              var fn = fns[i];
              if (typeof fn.signatures === "object") {
                for (var signature in fn.signatures) {
                  if (fn.signatures.hasOwnProperty(signature)) {
                    validateUnique(signature, fn.signatures[signature]);
                    signaturesMap[signature] = fn.signatures[signature];
                  }
                }
              } else if (typeof fn.signature === "string") {
                validateUnique(fn.signature, fn);
                signaturesMap[fn.signature] = fn;
              } else {
                err = new TypeError("Function is no typed-function (index: " + i + ")");
                err.data = { index: i };
                throw err;
              }
            }
            return signaturesMap;
          }
          typed2 = createTypedFunction("typed", {
            "string, Object": createTypedFunction,
            "Object": function(signaturesMap) {
              var fns = [];
              for (var signature in signaturesMap) {
                if (signaturesMap.hasOwnProperty(signature)) {
                  fns.push(signaturesMap[signature]);
                }
              }
              var name86 = getName(fns);
              return createTypedFunction(name86, signaturesMap);
            },
            "...Function": function(fns) {
              return createTypedFunction(getName(fns), extractSignatures(fns));
            },
            "string, ...Function": function(name86, fns) {
              return createTypedFunction(name86, extractSignatures(fns));
            }
          });
          typed2.create = create;
          typed2.types = _types;
          typed2.conversions = _conversions;
          typed2.ignore = _ignore;
          typed2.onMismatch = _onMismatch;
          typed2.throwMismatchError = _onMismatch;
          typed2.createError = createError;
          typed2.convert = convert;
          typed2.find = find;
          typed2.addType = function(type, beforeObjectTest) {
            if (!type || typeof type.name !== "string" || typeof type.test !== "function") {
              throw new TypeError("Object with properties {name: string, test: function} expected");
            }
            if (beforeObjectTest !== false) {
              for (var i = 0; i < typed2.types.length; i++) {
                if (typed2.types[i].name === "Object") {
                  typed2.types.splice(i, 0, type);
                  return;
                }
              }
            }
            typed2.types.push(type);
          };
          typed2.addConversion = function(conversion) {
            if (!conversion || typeof conversion.from !== "string" || typeof conversion.to !== "string" || typeof conversion.convert !== "function") {
              throw new TypeError("Object with properties {from: string, to: string, convert: function} expected");
            }
            typed2.conversions.push(conversion);
          };
          return typed2;
        }
        return create();
      });
    }
  });

  // node_modules/@chemistry/elements/dist/chem-elements.js
  var require_chem_elements = __commonJS({
    "node_modules/@chemistry/elements/dist/chem-elements.js"(exports, module) {
      !(function(o, s) {
        "object" == typeof exports && "object" == typeof module ? module.exports = s() : "function" == typeof define && define.amd ? define("chem-elements", [], s) : "object" == typeof exports ? exports["chem-elements"] = s() : o["chem-elements"] = s();
      })("undefined" != typeof self ? self : exports, (function() {
        return (function(o) {
          var s = {};
          function m(l) {
            if (s[l]) return s[l].exports;
            var a = s[l] = { i: l, l: false, exports: {} };
            return o[l].call(a.exports, a, a.exports, m), a.l = true, a.exports;
          }
          return m.m = o, m.c = s, m.d = function(o2, s2, l) {
            m.o(o2, s2) || Object.defineProperty(o2, s2, { enumerable: true, get: l });
          }, m.r = function(o2) {
            "undefined" != typeof Symbol && Symbol.toStringTag && Object.defineProperty(o2, Symbol.toStringTag, { value: "Module" }), Object.defineProperty(o2, "__esModule", { value: true });
          }, m.t = function(o2, s2) {
            if (1 & s2 && (o2 = m(o2)), 8 & s2) return o2;
            if (4 & s2 && "object" == typeof o2 && o2 && o2.__esModule) return o2;
            var l = /* @__PURE__ */ Object.create(null);
            if (m.r(l), Object.defineProperty(l, "default", { enumerable: true, value: o2 }), 2 & s2 && "string" != typeof o2) for (var a in o2) m.d(l, a, function(s3) {
              return o2[s3];
            }.bind(null, a));
            return l;
          }, m.n = function(o2) {
            var s2 = o2 && o2.__esModule ? function() {
              return o2.default;
            } : function() {
              return o2;
            };
            return m.d(s2, "a", s2), s2;
          }, m.o = function(o2, s2) {
            return Object.prototype.hasOwnProperty.call(o2, s2);
          }, m.p = "", m(m.s = 1);
        })([function(o, s, m) {
          "use strict";
          Object.defineProperty(s, "__esModule", { value: true }), s.ChemElementData = [{ id: 0, symbol: "Q", RCow: 0.77, RVdW: 0, maxBonds: 0, mass: 0, name: "Dummy", posX: 1, posY: 7, color: "#FFFFFF", color2: "#808080" }, { id: 1, symbol: "H", RCow: 0.37, RVdW: 1.2, maxBonds: 1, mass: 1.00794, name: "Hydrogen", posX: 1, posY: 1, color: "#FFFFFF", color2: "#808080" }, { id: 1, symbol: "D", RCow: 0.37, RVdW: 1.2, maxBonds: 1, mass: 2, name: "Diyterium", posX: 1, posY: 8, color: "#FFFFFF", color2: "#808080" }, { id: 2, symbol: "He", RCow: 0.32, RVdW: 1.4, maxBonds: 0, mass: 4.002602, name: "Helium", posX: 1, posY: 18, color: "#D9FFFF", color2: "#849B9B" }, { id: 3, symbol: "Li", RCow: 1.34, RVdW: 2.2, maxBonds: 1, mass: 6.941, name: "Lithium", posX: 2, posY: 1, color: "#CC80FF", color2: "#C87EFA" }, { id: 4, symbol: "Be", RCow: 0.9, RVdW: 1.9, maxBonds: 2, mass: 9.012182, name: "Beryllium", posX: 2, posY: 2, color: "#C2FF00", color2: "#82AB00" }, { id: 5, symbol: "B", RCow: 0.82, RVdW: 1.8, maxBonds: 3, mass: 10.811, name: "Boron", posX: 2, posY: 13, color: "#FFB5B5", color2: "#F090A0" }, { id: 6, symbol: "C", RCow: 0.77, RVdW: 1.7, maxBonds: 4, mass: 12.0107, name: "Carbon", posX: 2, posY: 14, color: "#909090", color2: "#000000" }, { id: 7, symbol: "N", RCow: 0.75, RVdW: 1.6, maxBonds: 4, mass: 14.0067, name: "Nitrogen", posX: 2, posY: 15, color: "#3050F8", color2: "#304FF7" }, { id: 8, symbol: "O", RCow: 0.73, RVdW: 1.55, maxBonds: 2, mass: 15.9994, name: "Oxygen", posX: 2, posY: 16, color: "#FF0D0D", color2: "#FF0D0D" }, { id: 9, symbol: "F", RCow: 0.71, RVdW: 1.5, maxBonds: 1, mass: 18.9984032, name: "Fluorine", posX: 2, posY: 17, color: "#90E050", color2: "#228B22" }, { id: 10, symbol: "Ne", RCow: 0.69, RVdW: 1.54, maxBonds: 0, mass: 20.1797, name: "Neon", posX: 2, posY: 18, color: "#B3E3F5", color2: "#7B9CA8" }, { id: 11, symbol: "Na", RCow: 1.54, RVdW: 2.4, maxBonds: 1, mass: 22.98977, name: "Sodium", posX: 3, posY: 1, color: "#AB5CF2", color2: "#AB5CF2" }, { id: 12, symbol: "Mg", RCow: 1.3, RVdW: 2.2, maxBonds: 2, mass: 24.305, name: "Magnesium", posX: 3, posY: 2, color: "#8AFF00", color2: "#61B400" }, { id: 13, symbol: "Al", RCow: 1.18, RVdW: 2.1, maxBonds: 6, mass: 26.981538, name: "Aluminium", posX: 3, posY: 13, color: "#BFA6A6", color2: "#A79191" }, { id: 14, symbol: "Si", RCow: 1.11, RVdW: 2.1, maxBonds: 6, mass: 28.0855, name: "Silicon", posX: 3, posY: 14, color: "#F0C8A0", color2: "#B09276" }, { id: 15, symbol: "P", RCow: 1.06, RVdW: 1.95, maxBonds: 5, mass: 30.973761, name: "Phosphorus", posX: 3, posY: 15, color: "#FF8000", color2: "#FF8000" }, { id: 16, symbol: "S", RCow: 1.02, RVdW: 1.8, maxBonds: 6, mass: 32.065, name: "Sulfur", posX: 3, posY: 16, color: "#FFFF30", color2: "#FFC832" }, { id: 17, symbol: "Cl", RCow: 0.99, RVdW: 1.8, maxBonds: 1, mass: 35.453, name: "Chlorine", posX: 3, posY: 17, color: "#1FF01F", color2: "#1DC51D" }, { id: 18, symbol: "Ar", RCow: 0.97, RVdW: 1.88, maxBonds: 0, mass: 39.948, name: "Argon", posX: 3, posY: 18, color: "#80D1E3", color2: "#63A2B0" }, { id: 19, symbol: "K", RCow: 1.96, RVdW: 2.8, maxBonds: 1, mass: 39.0983, name: "Potassium", posX: 4, posY: 1, color: "#8F40D4", color2: "#8F40D4" }, { id: 20, symbol: "Ca", RCow: 1.74, RVdW: 2.4, maxBonds: 2, mass: 40.078, name: "Calcium", posX: 4, posY: 2, color: "#3DFF00", color2: "#2FC300" }, { id: 21, symbol: "Sc", RCow: 1.44, RVdW: 2.3, maxBonds: 6, mass: 44.95591, name: "Scandium", posX: 4, posY: 3, color: "#E6E6E6", color2: "#969696" }, { id: 22, symbol: "Ti", RCow: 1.36, RVdW: 2.15, maxBonds: 6, mass: 47.867, name: "Titanium", posX: 4, posY: 4, color: "#BFC2C7", color2: "#94969A" }, { id: 23, symbol: "V", RCow: 1.25, RVdW: 2.05, maxBonds: 6, mass: 50.9415, name: "Vanadium", posX: 4, posY: 5, color: "#A6A6AB", color2: "#96969A" }, { id: 24, symbol: "Cr", RCow: 1.27, RVdW: 2.05, maxBonds: 6, mass: 51.9961, name: "Chromium", posX: 4, posY: 6, color: "#8A99C7", color2: "#8796C3" }, { id: 25, symbol: "Mn", RCow: 1.39, RVdW: 2.05, maxBonds: 8, mass: 54.938049, name: "Manganese", posX: 4, posY: 7, color: "#9C7AC7", color2: "#9C7AC7" }, { id: 26, symbol: "Fe", RCow: 1.25, RVdW: 2.05, maxBonds: 6, mass: 55.845, name: "Iron", posX: 4, posY: 8, color: "#E06633", color2: "#E06633" }, { id: 27, symbol: "Co", RCow: 1.26, RVdW: 2, maxBonds: 6, mass: 58.9332, name: "Cobalt", posX: 4, posY: 9, color: "#F090A0", color2: "#DB8293" }, { id: 28, symbol: "Ni", RCow: 1.21, RVdW: 2, maxBonds: 6, mass: 58.6934, name: "Nickel", posX: 4, posY: 10, color: "#50D050", color2: "#45B645" }, { id: 29, symbol: "Cu", RCow: 1.38, RVdW: 2, maxBonds: 6, mass: 63.546, name: "Copper", posX: 4, posY: 11, color: "#C88033", color2: "#C78033" }, { id: 30, symbol: "Zn", RCow: 1.31, RVdW: 2.1, maxBonds: 6, mass: 65.409, name: "Zinc", posX: 4, posY: 12, color: "#7D80B0", color2: "#7D80B0" }, { id: 31, symbol: "Ga", RCow: 1.26, RVdW: 2.1, maxBonds: 3, mass: 69.723, name: "Gallium", posX: 4, posY: 13, color: "#C28F8F", color2: "#BD8C8C" }, { id: 32, symbol: "Ge", RCow: 1.22, RVdW: 2.1, maxBonds: 4, mass: 72.64, name: "Germanium", posX: 4, posY: 14, color: "#668F8F", color2: "#668F8F" }, { id: 33, symbol: "As", RCow: 1.19, RVdW: 2.05, maxBonds: 3, mass: 74.9216, name: "Arsenic", posX: 4, posY: 15, color: "#BD80E3", color2: "#BD80E3" }, { id: 34, symbol: "Se", RCow: 1.16, RVdW: 1.9, maxBonds: 2, mass: 78.96, name: "Selenium", posX: 4, posY: 16, color: "#FFA100", color2: "#E28F00" }, { id: 35, symbol: "Br", RCow: 1.14, RVdW: 1.9, maxBonds: 1, mass: 79.904, name: "Bromine", posX: 4, posY: 17, color: "#A62929", color2: "#A62929" }, { id: 36, symbol: "Kr", RCow: 1.1, RVdW: 2.02, maxBonds: 0, mass: 83.798, name: "Krypton", posX: 4, posY: 18, color: "#5CB8D1", color2: "#53A6BC" }, { id: 37, symbol: "Rb", RCow: 2.11, RVdW: 2.9, maxBonds: 1, mass: 85.4678, name: "Rubidium", posX: 5, posY: 1, color: "#702EB0", color2: "#702EB0" }, { id: 38, symbol: "Sr", RCow: 1.92, RVdW: 2.55, maxBonds: 2, mass: 87.62, name: "Strontium", posX: 5, posY: 2, color: "#00FF00", color2: "#00D000" }, { id: 39, symbol: "Y", RCow: 1.62, RVdW: 2.4, maxBonds: 6, mass: 88.90585, name: "Yttrium", posX: 5, posY: 3, color: "#94FFFF", color2: "#5FA4A4" }, { id: 40, symbol: "Zr", RCow: 1.48, RVdW: 2.3, maxBonds: 6, mass: 91.224, name: "Zirconium", posX: 5, posY: 4, color: "#94E0E0", color2: "#6BA2A2" }, { id: 41, symbol: "Nb", RCow: 1.37, RVdW: 2.15, maxBonds: 6, mass: 92.90638, name: "Niobium", posX: 5, posY: 5, color: "#73C2C9", color2: "#61A4A9" }, { id: 42, symbol: "Mo", RCow: 1.45, RVdW: 2.1, maxBonds: 6, mass: 95.94, name: "Molybdenum", posX: 5, posY: 6, color: "#54B5B5", color2: "#4EA9A9" }, { id: 43, symbol: "Tc", RCow: 1.56, RVdW: 2.05, maxBonds: 6, mass: 98, name: "Technetium", posX: 5, posY: 7, color: "#3B9E9E", color2: "#4EA9A9" }, { id: 44, symbol: "Ru", RCow: 1.26, RVdW: 2.05, maxBonds: 6, mass: 101.07, name: "Ruthenium", posX: 5, posY: 8, color: "#248F8F", color2: "#248F8F" }, { id: 45, symbol: "Rh", RCow: 1.35, RVdW: 2, maxBonds: 6, mass: 102.9055, name: "Rhodium", posX: 5, posY: 9, color: "#0A7D8C", color2: "#0A7D8C" }, { id: 46, symbol: "Pd", RCow: 1.31, RVdW: 2.05, maxBonds: 6, mass: 106.42, name: "Palladium", posX: 5, posY: 10, color: "#006985", color2: "#006985" }, { id: 47, symbol: "Ag", RCow: 1.53, RVdW: 2.1, maxBonds: 6, mass: 107.8682, name: "Silver", posX: 5, posY: 11, color: "#C0C0C0", color2: "#969696" }, { id: 48, symbol: "Cd", RCow: 1.48, RVdW: 2.2, maxBonds: 6, mass: 112.411, name: "Cadmium", posX: 5, posY: 12, color: "#FFD98F", color2: "#AE9462" }, { id: 49, symbol: "In", RCow: 1.44, RVdW: 2.2, maxBonds: 3, mass: 114.818, name: "Indium", posX: 5, posY: 13, color: "#A67573", color2: "#A67573" }, { id: 50, symbol: "Sn", RCow: 1.41, RVdW: 2.25, maxBonds: 4, mass: 118.71, name: "Tin", posX: 5, posY: 14, color: "#668080", color2: "#668080" }, { id: 51, symbol: "Sb", RCow: 1.38, RVdW: 2.2, maxBonds: 3, mass: 121.76, name: "Antimony", posX: 5, posY: 15, color: "#9E63B5", color2: "#9E63B5" }, { id: 52, symbol: "Te", RCow: 1.35, RVdW: 2.1, maxBonds: 2, mass: 127.6, name: "Tellurium", posX: 5, posY: 16, color: "#D47A00", color2: "#D47A00" }, { id: 53, symbol: "I", RCow: 1.33, RVdW: 2.1, maxBonds: 1, mass: 126.90447, name: "Iodine", posX: 5, posY: 17, color: "#940094", color2: "#940094" }, { id: 54, symbol: "Xe", RCow: 1.3, RVdW: 2.16, maxBonds: 0, mass: 131.293, name: "Xenon", posX: 5, posY: 18, color: "#429EB0", color2: "#429EB0" }, { id: 55, symbol: "Cs", RCow: 2.25, RVdW: 3, maxBonds: 1, mass: 132.90545, name: "Cesium", posX: 6, posY: 1, color: "#57178F", color2: "#57178F" }, { id: 56, symbol: "Ba", RCow: 1.98, RVdW: 2.7, maxBonds: 2, mass: 137.327, name: "Barium", posX: 6, posY: 2, color: "#00C900", color2: "#00C900" }, { id: 57, symbol: "La", RCow: 1.69, RVdW: 2.5, maxBonds: 12, mass: 138.9055, name: "Lanthanum", posX: 9, posY: 3, color: "#70D4FF", color2: "#57A4C5" }, { id: 58, symbol: "Ce", RCow: 1.6, RVdW: 2.48, maxBonds: 6, mass: 140.116, name: "Cerium", posX: 9, posY: 4, color: "#FFFFC7", color2: "#989877" }, { id: 59, symbol: "Pr", RCow: 1.6, RVdW: 2.47, maxBonds: 6, mass: 140.90765, name: "Praseodymium", posX: 9, posY: 5, color: "#D9FFC7", color2: "#869D7B" }, { id: 60, symbol: "Nd", RCow: 1.6, RVdW: 2.45, maxBonds: 6, mass: 144.24, name: "Neodymium", posX: 9, posY: 6, color: "#C7FFC7", color2: "#7DA07D" }, { id: 61, symbol: "Pm", RCow: 1.6, RVdW: 2.43, maxBonds: 6, mass: 145, name: "Promethium", posX: 9, posY: 7, color: "#A3FFC7", color2: "#69A581" }, { id: 62, symbol: "Sm", RCow: 1.6, RVdW: 2.42, maxBonds: 6, mass: 150.36, name: "Samarium", posX: 9, posY: 8, color: "#8FFFC7", color2: "#5EA883" }, { id: 63, symbol: "Eu", RCow: 1.6, RVdW: 2.4, maxBonds: 6, mass: 151.964, name: "Europium", posX: 9, posY: 9, color: "#61FFC7", color2: "#43B089" }, { id: 64, symbol: "Gd", RCow: 1.6, RVdW: 2.38, maxBonds: 6, mass: 157.25, name: "Gadolinium", posX: 9, posY: 10, color: "#45FFC7", color2: "#31B48D" }, { id: 65, symbol: "Tb", RCow: 1.6, RVdW: 2.37, maxBonds: 6, mass: 158.92534, name: "Terbium", posX: 9, posY: 11, color: "#30FFC7", color2: "#23B890" }, { id: 66, symbol: "Dy", RCow: 1.6, RVdW: 2.35, maxBonds: 6, mass: 162.5, name: "Dysprosium", posX: 9, posY: 12, color: "#1FFFC7", color2: "#17BB92" }, { id: 67, symbol: "Ho", RCow: 1.6, RVdW: 2.33, maxBonds: 6, mass: 164.93032, name: "Holmium", posX: 9, posY: 13, color: "#00FF9C", color2: "#00C578" }, { id: 68, symbol: "Er", RCow: 1.6, RVdW: 2.32, maxBonds: 6, mass: 167.259, name: "Erbium", posX: 9, posY: 14, color: "#00E675", color2: "#00C765" }, { id: 69, symbol: "Tm", RCow: 1.6, RVdW: 2.3, maxBonds: 6, mass: 168.93421, name: "Thulium", posX: 9, posY: 15, color: "#00D452", color2: "#00C94E" }, { id: 70, symbol: "Yb", RCow: 1.6, RVdW: 2.28, maxBonds: 6, mass: 173.04, name: "Ytterbium", posX: 9, posY: 16, color: "#00BF38", color2: "#00BF38" }, { id: 71, symbol: "Lu", RCow: 1.6, RVdW: 2.27, maxBonds: 6, mass: 174.967, name: "Lutetium", posX: 9, posY: 17, color: "#00AB24", color2: "#00AB24" }, { id: 72, symbol: "Hf", RCow: 1.5, RVdW: 2.25, maxBonds: 6, mass: 178.49, name: "Hafnium", posX: 6, posY: 4, color: "#4DC2FF", color2: "#42A8DC" }, { id: 73, symbol: "Ta", RCow: 1.38, RVdW: 2.2, maxBonds: 6, mass: 180.9479, name: "Tantalum", posX: 6, posY: 5, color: "#4DA6FF", color2: "#4BA2F9" }, { id: 74, symbol: "W", RCow: 1.46, RVdW: 2.1, maxBonds: 6, mass: 183.84, name: "Tungsten", posX: 6, posY: 6, color: "#2194D6", color2: "#2194D6" }, { id: 75, symbol: "Re", RCow: 1.59, RVdW: 2.05, maxBonds: 6, mass: 186.207, name: "Rhenium", posX: 6, posY: 7, color: "#267DAB", color2: "#267DAB" }, { id: 76, symbol: "Os", RCow: 1.28, RVdW: 2, maxBonds: 6, mass: 190.23, name: "Osmium", posX: 6, posY: 8, color: "#266696", color2: "#266696" }, { id: 77, symbol: "Ir", RCow: 1.37, RVdW: 2, maxBonds: 6, mass: 192.217, name: "Iridium", posX: 6, posY: 9, color: "#175487", color2: "#175487" }, { id: 78, symbol: "Pt", RCow: 1.28, RVdW: 2.05, maxBonds: 6, mass: 195.078, name: "Platinum", posX: 6, posY: 10, color: "#D0D0E0", color2: "#9595A0" }, { id: 79, symbol: "Au", RCow: 1.44, RVdW: 2.1, maxBonds: 6, mass: 196.96655, name: "Gold", posX: 6, posY: 11, color: "#FFD123", color2: "#B9981A" }, { id: 80, symbol: "Hg", RCow: 1.49, RVdW: 2.05, maxBonds: 6, mass: 200.59, name: "Mercury", posX: 6, posY: 12, color: "#B8B8D0", color2: "#9595A9" }, { id: 81, symbol: "Tl", RCow: 1.48, RVdW: 2.2, maxBonds: 3, mass: 204.3833, name: "Thallium", posX: 6, posY: 13, color: "#A6544D", color2: "#A6544D" }, { id: 82, symbol: "Pb", RCow: 1.47, RVdW: 2.3, maxBonds: 4, mass: 207.2, name: "Lead", posX: 6, posY: 14, color: "#575961", color2: "#575961" }, { id: 83, symbol: "Bi", RCow: 1.46, RVdW: 2.3, maxBonds: 3, mass: 208.98038, name: "Bismuth", posX: 6, posY: 15, color: "#9E4FB5", color2: "#9E4FB5" }, { id: 84, symbol: "Po", RCow: 1.6, RVdW: 2, maxBonds: 2, mass: 209, name: "Polonium", posX: 6, posY: 16, color: "#AB5C00", color2: "#AB5C00" }, { id: 85, symbol: "At", RCow: 1.6, RVdW: 2, maxBonds: 1, mass: 210, name: "Astatine", posX: 6, posY: 17, color: "#754F45", color2: "#754F45" }, { id: 86, symbol: "Rn", RCow: 1.45, RVdW: 2, maxBonds: 0, mass: 222, name: "Radon", posX: 6, posY: 18, color: "#428296", color2: "#428296" }, { id: 87, symbol: "Fr", RCow: 1.6, RVdW: 2, maxBonds: 1, mass: 223, name: "Francium", posX: 7, posY: 1, color: "#420066", color2: "#420066" }, { id: 88, symbol: "Ra", RCow: 1.6, RVdW: 2, maxBonds: 2, mass: 226, name: "Radium", posX: 7, posY: 2, color: "#007D00", color2: "#007D00" }, { id: 89, symbol: "Ac", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 227, name: "Actinium", posX: 10, posY: 3, color: "#70ABFA", color2: "#669CE4" }, { id: 90, symbol: "Th", RCow: 1.6, RVdW: 2.4, maxBonds: 6, mass: 232.0381, name: "Thorium", posX: 10, posY: 4, color: "#00BAFF", color2: "#00B8FC" }, { id: 91, symbol: "Pa", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 231.03588, name: "Protactinium", posX: 10, posY: 5, color: "#00A1FF", color2: "#00A1FF" }, { id: 92, symbol: "U", RCow: 1.6, RVdW: 2.3, maxBonds: 6, mass: 238.02891, name: "Uranium", posX: 10, posY: 6, color: "#008FFF", color2: "#008FFF" }, { id: 93, symbol: "Np", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 237, name: "Neptunium", posX: 10, posY: 7, color: "#0080FF", color2: "#0080FF" }, { id: 94, symbol: "Pu", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 244, name: "Plutonium", posX: 10, posY: 8, color: "#006BFF", color2: "#006BFF" }, { id: 95, symbol: "Am", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 243, name: "Americium", posX: 10, posY: 9, color: "#545CF2", color2: "#545CF2" }, { id: 96, symbol: "Cm", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 247, name: "Curium", posX: 10, posY: 10, color: "#785CE3", color2: "#785CE3" }, { id: 97, symbol: "Bk", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 247, name: "Berkelium", posX: 10, posY: 11, color: "#8A4FE3", color2: "#8A4FE3" }, { id: 98, symbol: "Cf", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 251, name: "Californium", posX: 10, posY: 12, color: "#A136D4", color2: "#A136D4" }, { id: 99, symbol: "Es", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 252, name: "Einsteinium", posX: 10, posY: 13, color: "#B31FD4", color2: "#B31FD4" }, { id: 100, symbol: "Fm", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 257, name: "Fermium", posX: 10, posY: 14, color: "#B31FBA", color2: "#B31FBA" }, { id: 101, symbol: "Md", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 258, name: "Mendelevium", posX: 10, posY: 15, color: "#B30DA6", color2: "#B30DA6" }, { id: 102, symbol: "No", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 259, name: "Nobelium", posX: 10, posY: 16, color: "#BD0D87", color2: "#BD0D87" }, { id: 103, symbol: "Lr", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 262, name: "Lawrencium", posX: 10, posY: 17, color: "#C70066", color2: "#C70066" }, { id: 104, symbol: "Rf", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 261, name: "Rutherfordium", posX: 7, posY: 4, color: "#CC0059", color2: "#42A8DC" }, { id: 105, symbol: "Db", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 262, name: "Dubnium", posX: 7, posY: 5, color: "#D1004F", color2: "#4BA2F9" }, { id: 106, symbol: "Sg", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 266, name: "Seaborgium", posX: 7, posY: 6, color: "#D90045", color2: "#2194D6" }, { id: 107, symbol: "Bh", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 264, name: "Bohrium", posX: 7, posY: 7, color: "#E00038", color2: "#267DAB" }, { id: 108, symbol: "Hs", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 277, name: "Hassium", posX: 7, posY: 8, color: "#E6002E", color2: "#266696" }, { id: 109, symbol: "Mt", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 268, name: "Meitnerium", posX: 7, posY: 9, color: "#EB0026", color2: "#175487" }, { id: 110, symbol: "Ds", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 281, name: "Darmstadtium", posX: 7, posY: 10, color: "#FF1493", color2: "#9595A0" }, { id: 111, symbol: "Rg", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 272, name: "Roentgenium", posX: 7, posY: 11, color: "#FF1494", color2: "#B9981A" }, { id: 112, symbol: "Cn", RCow: 1.6, RVdW: 2, maxBonds: 6, mass: 277, name: "Copernicium", posX: 7, posY: 12, color: "#FF1495", color2: "#9595A9" }];
        }, function(o, s, m) {
          "use strict";
          function l(o2) {
            for (var m2 in o2) s.hasOwnProperty(m2) || (s[m2] = o2[m2]);
          }
          Object.defineProperty(s, "__esModule", { value: true }), l(m(2)), l(m(0));
        }, function(o, s, m) {
          "use strict";
          Object.defineProperty(s, "__esModule", { value: true });
          var l = m(0), a = (function() {
            function o2() {
            }
            return o2.getById = function(o3) {
              for (var s2 = 0, m2 = l.ChemElementData; s2 < m2.length; s2++) {
                var a2 = m2[s2];
                if (a2.id === o3) return a2;
              }
              return null;
            }, o2.getBySymbol = function(o3) {
              for (var s2 = (o3 || "").replace(/[^a-z]/gim, "").toLowerCase(), m2 = s2.charAt(0).toUpperCase() + s2.slice(1), a2 = 0, n = l.ChemElementData; a2 < n.length; a2++) {
                var d = n[a2];
                if (d.symbol === m2) return d;
              }
              return null;
            }, o2.getAll = function() {
              return l.ChemElementData.filter((function(o3) {
                return "Q" !== o3.symbol && "D" !== o3.symbol;
              }));
            }, o2.getAllSymbols = function() {
              return o2.getAll().map((function(o3) {
                return o3.symbol;
              }));
            }, o2;
          })();
          s.ChemElements = a;
        }]);
      }));
    }
  });

  // src/utils.js
  var assert = __toESM(require_assert(), 1);
  var Fractions = Object.freeze({
    MOLE: "mole",
    MASS: "mass"
  });
  var Parameters = Object.freeze({
    R: 8314,
    pi: 3.141592653589793,
    k: 1.3806488,
    referencePressure: 1e5
  });
  function UniqueArray(value, index2, self2) {
    return self2.indexOf(value) === index2;
  }
  function AsaliError(message) {
    console.log(message);
    alert(message);
    exit();
  }

  // src/thermo.js
  var thermoDict = {
    "AC3H4": [
      6.64430238,
      0.0114987825,
      -468099585e-14,
      962334222e-18,
      -824360065e-22,
      20713.1189,
      -13.5744541,
      1.21562918,
      0.0235625008,
      -147340944e-13,
      468570404e-17,
      -599570704e-21,
      22667.4413,
      15.8066578
    ],
    "ACETOL": [
      9.43106557,
      0.0186879303,
      -729283976e-14,
      139932581e-17,
      -108736168e-21,
      -48738.9994,
      -20.836048,
      1.41553145,
      0.0365002283,
      -221364215e-13,
      689694866e-17,
      -872294898e-21,
      -45853.4071,
      22.5456947
    ],
    "ALDEST": [
      17.9608805,
      0.0327577303,
      -129904809e-13,
      25001368e-16,
      -193431386e-21,
      -74898.3193,
      -59.9171462,
      5.24137808,
      0.0610232913,
      -36545115e-12,
      112240754e-16,
      -140508952e-20,
      -70319.2984,
      8.92345431
    ],
    "ALDINS": [
      84.4295858,
      0.04931704,
      -28626835e-12,
      886979917e-17,
      -100373619e-20,
      -89426.5291,
      -412.065762,
      -11.8024916,
      0.263166101,
      -206834386e-12,
      748725957e-16,
      -101707913e-19,
      -54782.9813,
      108.762316
    ],
    "AR": [
      2.5,
      740336223e-23,
      -556967416e-26,
      173924876e-29,
      -192673709e-33,
      -745.375,
      4.366,
      2.5,
      -40745516e-22,
      598527266e-26,
      -343074982e-29,
      674775716e-33,
      -745.375,
      4.366
    ],
    "BENZYNE": [
      10.9465819,
      0.0150373246,
      -527844959e-14,
      814607581e-18,
      -449073366e-22,
      50330.1418,
      -35.3782934,
      -3.73796173,
      0.0569931634,
      -502311341e-13,
      222206478e-16,
      -386741452e-20,
      54441.814,
      40.4070822
    ],
    "BIN1A": [
      -3.241736,
      0.1582229,
      -9461835e-11,
      2818431e-14,
      -356131e-17,
      21786.99,
      30.08253,
      -3.241736,
      0.1582229,
      -9461835e-11,
      2818431e-14,
      -356131e-17,
      21786.99,
      30.08253
    ],
    "BIN1B": [
      -5.702567,
      0.1434323,
      -8807247e-11,
      2767992e-14,
      -3522899e-18,
      27780.89,
      43.44812,
      -5.702567,
      0.1434323,
      -8807247e-11,
      2767992e-14,
      -3522899e-18,
      27780.89,
      43.44812
    ],
    "BIPHENYL": [
      26.7692078,
      0.0281611415,
      -605667723e-14,
      -369378426e-18,
      167249382e-21,
      9266.92468,
      -121.306413,
      -10.5625108,
      0.131145193,
      -112591903e-12,
      486123345e-16,
      -827787353e-20,
      20093.1231,
      72.6686556
    ],
    "BZFUR": [
      16.4578334,
      0.0237623567,
      -852218599e-14,
      13612371e-16,
      -797159891e-22,
      -5905.96972,
      -65.9480381,
      -8.70136947,
      0.0966875823,
      -877887356e-13,
      396542562e-16,
      -701685714e-20,
      1037.97027,
      63.5339364
    ],
    "C": [
      2.48989675,
      514965671e-13,
      -737912415e-16,
      375721674e-19,
      -486583734e-23,
      85452.7782,
      4.8178327,
      2.55088394,
      -29700164e-11,
      672990632e-15,
      -673648664e-18,
      249141603e-21,
      85444.24,
      4.54535738
    ],
    "C10H10": [
      18.2592698,
      0.0415934216,
      -183631832e-13,
      388491136e-17,
      -327420808e-21,
      4396.87821,
      -82.3923218,
      -11.4588964,
      0.107633791,
      -733968243e-13,
      242677414e-16,
      -315836942e-20,
      15095.418,
      78.4485932
    ],
    "C10H6CH3": [
      21.2659882,
      0.034442943,
      -139605695e-13,
      272496148e-17,
      -212674976e-21,
      32850.7521,
      -91.1529083,
      -1.92673037,
      0.0859823175,
      -569100482e-13,
      186321758e-16,
      -24220103e-19,
      41200.1308,
      34.3709226
    ],
    "C10H7": [
      18.6034915,
      0.0284557463,
      -751492092e-14,
      859843958e-19,
      131843536e-21,
      38917.5328,
      -79.66716,
      -8.11601745,
      0.102676605,
      -848283149e-13,
      358792224e-16,
      -608226028e-20,
      46612.7513,
      58.9821104
    ],
    "C10H7CH2": [
      16.2958766,
      0.0454296741,
      -213529357e-13,
      477934912e-17,
      -418010504e-21,
      25510.0815,
      -64.7739136,
      -5.20583638,
      0.104338477,
      -818756782e-13,
      324153046e-16,
      -515019466e-20,
      31788.5817,
      47.096454
    ],
    "C10H7CH3": [
      15.9718633,
      0.048465609,
      -227123224e-13,
      509437338e-17,
      -447432797e-21,
      5324.12011,
      -63.5417268,
      -7.85505905,
      0.11654253,
      -956518805e-13,
      398274963e-16,
      -664977617e-20,
      11995.6584,
      59.426498
    ],
    "C10H7CHO": [
      27.6873866,
      0.0265153545,
      -98523069e-13,
      173492056e-17,
      -121699947e-21,
      -10892.6269,
      -125.645702,
      -1.80645208,
      0.0920572182,
      -644705267e-13,
      219638908e-16,
      -293127915e-20,
      -274.844971,
      33.9811053
    ],
    "C10H7O": [
      26.0845785,
      0.0224488808,
      -786244785e-14,
      125147148e-17,
      -755452008e-22,
      1361.68392,
      -117.834769,
      -2.53985295,
      0.0860587284,
      -608706542e-13,
      208841405e-16,
      -280230479e-20,
      11666.4792,
      37.0866255
    ],
    "C10H7OH": [
      26.1818224,
      0.0247079229,
      -875472975e-14,
      141213209e-17,
      -861580367e-22,
      -15833.8687,
      -119.314317,
      -3.09194614,
      0.0923929369,
      -674411581e-13,
      240273261e-16,
      -335424965e-20,
      -5705.14482,
      37.9602738
    ],
    "C10H8": [
      15.1184828,
      0.0389675576,
      -178248659e-13,
      392092279e-17,
      -339215689e-21,
      10112.1562,
      -60.9041102,
      -8.71832426,
      0.108564074,
      -940254318e-13,
      410014902e-16,
      -710574258e-20,
      16643.4413,
      61.5987876
    ],
    "C11H12O4": [
      29.8957517,
      0.0473870505,
      -211603212e-13,
      460350399e-17,
      -396349099e-21,
      -70211.9467,
      -121.160681,
      -3.09348688,
      0.150478421,
      -141970521e-12,
      675254832e-16,
      -126857982e-19,
      -61766.7016,
      46.1370519
    ],
    "C12H18": [
      84.4295858,
      0.04931704,
      -28626835e-12,
      886979917e-17,
      -100373619e-20,
      -89426.5291,
      -412.065762,
      -11.8024916,
      0.263166101,
      -206834386e-12,
      748725957e-16,
      -101707913e-19,
      -54782.9813,
      108.762316
    ],
    "C12H22": [
      36.0687856,
      0.0493531801,
      -168932777e-13,
      264866878e-17,
      -156934744e-21,
      -22929.1143,
      -158.689972,
      -2.71855262,
      0.137506222,
      -920237107e-13,
      311071661e-16,
      -419933494e-20,
      -9275.97128,
      50.3635315
    ],
    "C12H7": [
      12.3349807,
      0.0516907682,
      -272404819e-13,
      685858162e-17,
      -67201893e-20,
      53039.4981,
      -42.5244963,
      -8.02968441,
      0.116857696,
      -105440796e-12,
      485654157e-16,
      -901338574e-20,
      58130.6643,
      60.2674845
    ],
    "C12H8": [
      25.9652189,
      0.024250119,
      -481412894e-14,
      -421078741e-18,
      147447105e-21,
      19077.8575,
      -118.254954,
      -9.28199067,
      0.122843712,
      -108233982e-12,
      47793305e-15,
      -828164096e-20,
      29158.5594,
      64.399484
    ],
    "C14H10": [
      31.3141255,
      0.0289528714,
      -55767099e-13,
      -589662906e-18,
      188202945e-21,
      10646.0191,
      -148.101025,
      -12.1905872,
      0.150644375,
      -133225141e-12,
      58920095e-15,
      -102156009e-19,
      23088.3669,
      77.3445897
    ],
    "C14H9": [
      31.3141255,
      0.0289528714,
      -55767099e-13,
      -589662906e-18,
      188202945e-21,
      40656.0892,
      -148.101025,
      -12.1905872,
      0.150644375,
      -133225141e-12,
      58920095e-15,
      -102156009e-19,
      53098.437,
      77.3445897
    ],
    "C16H10": [
      35.5205969,
      0.0297059226,
      -518577408e-14,
      -774976601e-18,
      205764301e-21,
      11399.8034,
      -172.584653,
      -14.3149515,
      0.169106058,
      -151409692e-12,
      673946823e-16,
      -117120082e-19,
      25652.7702,
      85.6679628
    ],
    "C16H9": [
      16.1933977,
      0.0696117135,
      -371054121e-13,
      943826014e-17,
      -93251588e-20,
      46100.8358,
      -65.4256237,
      -13.3382684,
      0.164875153,
      -152343443e-12,
      713941909e-16,
      -13423631e-18,
      53424.689,
      83.400192
    ],
    "C2-OOQOOH": [
      12.4323243,
      0.0162358927,
      -684260319e-14,
      139267431e-17,
      -112911127e-21,
      -18764.1105,
      -29.0906767,
      5.81911522,
      0.0309319129,
      -190892866e-13,
      5928483e-15,
      -742884555e-21,
      -16383.3552,
      6.70139036
    ],
    "C2-OQOOH": [
      10.6961666,
      0.0125934013,
      -532391821e-14,
      108565058e-17,
      -8806712e-20,
      -34200.023,
      -24.3964294,
      5.53941294,
      0.024052854,
      -148734621e-13,
      462251869e-17,
      -579298801e-21,
      -32343.5917,
      3.51299738
    ],
    "C2-QOOH": [
      7.85685775,
      0.0167911217,
      -77962172e-13,
      17378247e-16,
      -151982948e-21,
      720.248835,
      -10.6887184,
      0.824295798,
      0.0389409231,
      -339574e-10,
      154707291e-16,
      -285531058e-20,
      2506.51957,
      24.920229
    ],
    "C2H": [
      2.62706056,
      0.00561439161,
      -233738366e-14,
      429433761e-18,
      -292352464e-22,
      67383.62,
      9.73315238,
      4.71151838,
      903752455e-12,
      165468342e-14,
      -107416966e-17,
      183138118e-21,
      66645.722,
      -1.51333448
    ],
    "C2H2": [
      4.61193612,
      0.00501498204,
      -165253694e-14,
      249922532e-18,
      -130568636e-22,
      25604.3843,
      -3.75517096,
      1.83812159,
      0.0164533925,
      -193408005e-13,
      124068047e-16,
      -314627391e-20,
      26142.5043,
      9.54239252
    ],
    "C2H2O2": [
      9.83116579,
      0.00487360532,
      -1694433e-12,
      265361078e-18,
      -154439841e-22,
      -29627.3239,
      -26.6407027,
      1.89947966,
      0.0235363962,
      -181616014e-13,
      672307419e-17,
      -965107677e-21,
      -26930.5506,
      15.8338747
    ],
    "C2H3": [
      0.70509423,
      0.0153761148,
      -891788178e-14,
      251340905e-17,
      -27056165e-20,
      33618.951,
      19.6531878,
      2.74606708,
      0.00371341276,
      160736225e-13,
      -212880236e-16,
      822995002e-20,
      33333.2148,
      10.5346375
    ],
    "C2H3CHO": [
      6.7051776,
      0.0161222451,
      -757298869e-14,
      170307233e-17,
      -149924851e-21,
      -13361.8589,
      -9.88613663,
      0.340917666,
      0.035120036,
      -288391725e-13,
      122832633e-16,
      -212384107e-20,
      -11656.2372,
      22.6803642
    ],
    "C2H4": [
      4.49333672,
      0.0100335105,
      -362601388e-14,
      597613541e-18,
      -365481279e-22,
      3932.20822,
      -3.3519202,
      0.266161697,
      0.0194272328,
      -114541158e-13,
      349691054e-17,
      -439228267e-21,
      5453.99123,
      19.5264329
    ],
    "C2H4CHO": [
      2.15579434,
      0.0257531407,
      -133069384e-13,
      328122872e-17,
      -312828174e-21,
      -731.459492,
      19.4816815,
      3.58641615,
      0.0182235522,
      155409151e-14,
      -975476244e-17,
      397532681e-20,
      -948.914007,
      12.9723736
    ],
    "C2H4O": [
      4.77217531,
      0.0129608883,
      -419608017e-14,
      33285947e-17,
      297428516e-22,
      -8910.54882,
      -2.99568268,
      -1.76683146,
      0.031124796,
      -231168173e-13,
      909246001e-17,
      -149102113e-20,
      -7027.31487,
      30.9356489
    ],
    "C2H4O2": [
      3.4061401,
      0.0202613044,
      -103463461e-13,
      253497107e-17,
      -240436915e-21,
      -38806.0356,
      12.0569218,
      4.64403525,
      0.0138306802,
      218084389e-14,
      -831108086e-17,
      328100852e-20,
      -38996.6715,
      6.40833543
    ],
    "C2H4OH": [
      6.43071837,
      0.0130529032,
      -504234033e-14,
      94242188e-17,
      -706192378e-22,
      -6842.54175,
      -6.4064397,
      1.19058412,
      0.024697646,
      -147462926e-13,
      453647829e-17,
      -569793739e-21,
      -4956.09342,
      21.95426
    ],
    "C2H5": [
      -1.10489358,
      0.0243511913,
      -139613152e-13,
      389870297e-17,
      -41728512e-20,
      13503.0749,
      30.0146907,
      4.99501831,
      -0.010505448,
      607314834e-13,
      -672372957e-16,
      249884287e-19,
      12649.0872,
      2.76182763
    ],
    "C2H5CHO": [
      -3.19796156,
      0.0417401347,
      -222156952e-13,
      537596466e-17,
      -49560124e-20,
      -23145.7657,
      44.3385409,
      4.65967589,
      0.014169477,
      14061486e-12,
      -158387612e-16,
      415675092e-20,
      -24937.3071,
      5.40040975
    ],
    "C2H5OH": [
      4.8295947,
      0.0177552121,
      -6211121e-12,
      658265206e-18,
      160136692e-22,
      -30865.8494,
      0.543180378,
      0.248921589,
      0.0310325255,
      -206429833e-13,
      763017938e-17,
      -124701426e-20,
      -29601.5836,
      24.1176395
    ],
    "C2H5OO": [
      4.82335647,
      0.0206819188,
      -967611879e-14,
      217589519e-17,
      -191914821e-21,
      -4751.56327,
      3.93765088,
      1.82119985,
      0.0302125747,
      -210221378e-13,
      817907984e-17,
      -138302289e-20,
      -3995.0198,
      19.1151548
    ],
    "C2H5OOH": [
      11.5652199,
      0.0102216474,
      -186630047e-14,
      -255692055e-18,
      726211298e-22,
      -24732.8137,
      -34.2112965,
      1.46294225,
      0.0356361824,
      -258422768e-13,
      979712822e-17,
      -150801099e-20,
      -21520.2894,
      19.2111233
    ],
    "C2H6": [
      4.39373503,
      0.0152684734,
      -582725051e-14,
      110377088e-17,
      -860486537e-22,
      -12726.9866,
      -3.21997495,
      -0.274461309,
      0.025642243,
      -144720586e-13,
      430555164e-17,
      -530740425e-21,
      -11046.436,
      22.0452775
    ],
    "C3-OQOOH": [
      11.2132537,
      0.0234709018,
      -113098317e-13,
      259008079e-17,
      -230885268e-21,
      -39128.9882,
      -26.6260028,
      0.846220448,
      0.0541880374,
      -454399824e-13,
      194444762e-16,
      -33520696e-19,
      -36329.8893,
      26.5001343
    ],
    "C3H2": [
      6.27665898,
      0.00558433105,
      -245857473e-14,
      541223006e-18,
      -483608105e-22,
      63105.5207,
      -4.75111128,
      4.26055345,
      0.0171049341,
      -271455812e-13,
      240526578e-16,
      -84453018e-19,
      63387.7755,
      4.25633816
    ],
    "C3H3": [
      10.9930471,
      779714852e-12,
      173957383e-14,
      -795864951e-18,
      969732207e-22,
      37462.7231,
      -34.0822737,
      3.56039712,
      0.0180649474,
      -133347569e-13,
      504689889e-17,
      -75226571e-20,
      40019.5547,
      5.80687271
    ],
    "C3H4O2": [
      10.2920429,
      0.01388713,
      -612561993e-14,
      130548845e-17,
      -109965765e-21,
      -35702.6988,
      -26.9350036,
      0.117378045,
      0.0467086294,
      -458290467e-13,
      226514168e-16,
      -441358036e-20,
      -33179.382,
      24.3405589
    ],
    "C3H4O3": [
      13.724281,
      0.010881111,
      -370124855e-14,
      57890144e-17,
      -343205818e-22,
      -57780.2807,
      -39.9570073,
      2.17563103,
      0.037895497,
      -273980784e-13,
      981743159e-17,
      -138498288e-20,
      -53830.6424,
      21.9543274
    ],
    "C3H5CHO": [
      9.36564259,
      0.0199394689,
      -824714277e-14,
      163840913e-17,
      -129181894e-21,
      -14429.3663,
      -20.7054,
      0.240474771,
      0.0426106933,
      -293694015e-13,
      10384686e-15,
      -148729943e-20,
      -11491.0622,
      27.6639767
    ],
    "C3H5OH": [
      2.45863176,
      0.0266446458,
      -124879759e-13,
      292198798e-17,
      -271872686e-21,
      -17223.9991,
      18.3830345,
      4.24999286,
      0.0179062989,
      349680492e-14,
      -100737688e-16,
      369024828e-20,
      -17517.7823,
      10.09625
    ],
    "C3H5OO": [
      7.6923011,
      0.0205361077,
      -961589847e-14,
      215332094e-17,
      -188909485e-21,
      6214.84234,
      -10.4053755,
      2.96424215,
      0.0310429054,
      -183715632e-13,
      539615972e-17,
      -639303761e-21,
      7916.94356,
      15.1838658
    ],
    "C3H5OOH": [
      12.1377197,
      0.0168585481,
      -694275126e-14,
      1369589e-15,
      -10742746e-20,
      -12526.5904,
      -35.7194708,
      2.24651097,
      0.0388390118,
      -252598044e-13,
      815368275e-17,
      -10496627e-19,
      -8965.75529,
      17.8138141
    ],
    "C3H6": [
      9.21549195,
      0.0110096151,
      -272165887e-14,
      16930112e-17,
      125058839e-22,
      -2150.28535,
      -27.5773224,
      -0.261886761,
      0.0320704567,
      -202723602e-13,
      666956086e-17,
      -890307969e-21,
      1261.57099,
      23.7162283
    ],
    "C3H6O": [
      6.42754902,
      0.0200818525,
      -655464685e-14,
      484306793e-18,
      568893699e-22,
      -14803.5725,
      -9.71995026,
      -0.0999780843,
      0.0352621481,
      -197932767e-13,
      561555868e-17,
      -688932126e-21,
      -12558.1031,
      25.3116313
    ],
    "C3H6O2": [
      10.8721654,
      0.0163593216,
      -608637842e-14,
      11013085e-16,
      -802911326e-22,
      -45527.2952,
      -27.074852,
      2.66105929,
      0.0346062241,
      -212921305e-13,
      673306853e-17,
      -862480026e-21,
      -42571.297,
      17.3653673
    ],
    "C3H7CHO": [
      -0.977279434,
      0.0524983747,
      -309762338e-13,
      832680251e-17,
      -83815652e-20,
      -27076.7712,
      32.7194912,
      3.71554492,
      0.0256822356,
      264869216e-13,
      -464000121e-16,
      187071344e-19,
      -27733.7666,
      11.7531393
    ],
    "C3H7OOH": [
      12.0273024,
      0.022366933,
      -925510611e-14,
      183134653e-17,
      -143510571e-21,
      -28787.8078,
      -34.3698022,
      1.14029559,
      0.0484435961,
      -326772586e-13,
      111815072e-16,
      -154323522e-20,
      -25151.5476,
      23.7368269
    ],
    "C3H8": [
      10.8596364,
      0.0135766563,
      -319926248e-14,
      141615801e-18,
      235898562e-22,
      -18088.4704,
      -36.9486914,
      -1.25512725,
      0.0404983533,
      -256340099e-13,
      845078153e-17,
      -113046094e-20,
      -13727.1555,
      28.6189366
    ],
    "C4H2": [
      8.50275797,
      0.00697445022,
      -253297106e-14,
      433287765e-18,
      -293611469e-22,
      53172.7553,
      -20.8807943,
      2.90907865,
      0.0282837048,
      -329747633e-13,
      197614098e-16,
      -463129497e-20,
      54347.4279,
      6.37839155
    ],
    "C4H3": [
      13.0208969,
      0.00153590365,
      180568199e-14,
      -930237202e-18,
      118077197e-21,
      60181.1751,
      -42.57915,
      2.34662667,
      0.0283894138,
      -235278181e-13,
      969177542e-17,
      -155205057e-20,
      63575.593,
      13.868056
    ],
    "C4H3O": [
      8.44125905,
      0.0162911136,
      -834126436e-14,
      201436766e-17,
      -187394603e-21,
      19453.5776,
      -22.7855078,
      -5.90872253,
      0.0625813767,
      -643375505e-13,
      321198978e-16,
      -625705794e-20,
      23012.373,
      49.5317026
    ],
    "C4H4": [
      6.36293592,
      0.016661,
      -75422085e-13,
      159521425e-17,
      -128415834e-21,
      31313.724,
      -8.19255288,
      0.403184847,
      0.0366937767,
      -327936077e-13,
      157416564e-16,
      -310035746e-20,
      32732.1448,
      21.5965194
    ],
    "C4H4O": [
      8.37486466,
      0.0195634451,
      -990167121e-14,
      237694382e-17,
      -220517698e-21,
      -9418.1758,
      -25.2053384,
      -7.59507781,
      0.070667261,
      -712262503e-13,
      35083386e-15,
      -676180613e-20,
      -5425.69018,
      55.4039922
    ],
    "C4H5": [
      19.0192654,
      -0.00191794385,
      488814513e-14,
      -191833948e-17,
      224139237e-21,
      34859.274,
      -77.0423351,
      -0.201742307,
      0.0407954066,
      -307063136e-13,
      112647934e-16,
      -160685144e-20,
      41778.8367,
      26.9857683
    ],
    "C4H6": [
      9.55395345,
      0.0151364811,
      -478509457e-14,
      614955374e-18,
      -223809938e-22,
      8632.84693,
      -27.7966685,
      -1.04533857,
      0.0424894928,
      -31255751e-12,
      12000184e-15,
      -185870818e-20,
      11918.6275,
      27.9839806
    ],
    "C4H6O2": [
      7.01919581,
      0.0289919962,
      -139811163e-13,
      322750474e-17,
      -29088881e-20,
      -43605.571,
      -7.4784694,
      0.915158242,
      0.0425565241,
      -252848896e-13,
      741408744e-17,
      -872358628e-21,
      -41408.1175,
      25.5578553
    ],
    "C4H7OH": [
      10.0981665,
      0.0215734935,
      -674008418e-14,
      916825971e-18,
      -416200161e-22,
      -23729.0909,
      -24.5741592,
      -0.255531336,
      0.0499397889,
      -358835384e-13,
      142243393e-16,
      -232030381e-20,
      -20705.8111,
      29.2946643
    ],
    "C4H8O": [
      11.2815996,
      0.0248463701,
      -1132347e-11,
      247069946e-17,
      -212413507e-21,
      -20375.6688,
      -38.4267373,
      -2.94845122,
      0.0564687053,
      -37675416e-12,
      122306795e-16,
      -156796629e-20,
      -15252.8505,
      38.5892666
    ],
    "C4H9CHO": [
      -1.78433179,
      0.0631204386,
      -360836198e-13,
      94832192e-16,
      -939522544e-21,
      -29711.3508,
      39.2478712,
      5.53299014,
      0.024608218,
      399273421e-13,
      -571930632e-16,
      209934651e-19,
      -30823.5837,
      5.9541654
    ],
    "C4H9OOH": [
      17.3966948,
      0.0230088698,
      -834646932e-14,
      13988319e-16,
      -901677555e-22,
      -33861.4042,
      -62.3628946,
      1.1289512,
      0.0595655969,
      -391527e-10,
      12936746e-15,
      -171066131e-20,
      -28070.0874,
      25.4997628
    ],
    "C5EN-OO": [
      10.0840321,
      0.0369913036,
      -17421618e-12,
      393130749e-17,
      -347257402e-21,
      -898.415155,
      -19.6513637,
      0.409897281,
      0.0672229749,
      -528493577e-13,
      223832553e-16,
      -395115346e-20,
      1578.16336,
      29.4089022
    ],
    "C5EN-OOQOOH-35": [
      13.6699765,
      0.0421231935,
      -215503712e-13,
      521806336e-17,
      -487293014e-21,
      -14235.4804,
      -33.5883364,
      0.524578583,
      0.0874521518,
      -801654035e-13,
      389048635e-16,
      -774737926e-20,
      -11185.748,
      31.7816498
    ],
    "C5EN-OQOOH-35": [
      16.9833146,
      0.0273095032,
      -119226853e-13,
      248166925e-17,
      -203420392e-21,
      -35123.452,
      -55.804178,
      1.44561329,
      0.0666454559,
      -492669442e-13,
      182387405e-16,
      -269662788e-20,
      -30213.5384,
      26.26358
    ],
    "C5EN-QOOH": [
      12.8791275,
      0.0332930454,
      -155378924e-13,
      346674396e-17,
      -302869803e-21,
      3230.11716,
      -33.8507184,
      1.34404411,
      0.0657862381,
      -498616876e-13,
      195812018e-16,
      -313992224e-20,
      6506.08085,
      25.8442475
    ],
    "C5H4O2": [
      10.5158962,
      0.0223224229,
      -109267096e-13,
      256683236e-17,
      -234844997e-21,
      -23330.3219,
      -29.4000374,
      -1.81996644,
      0.0568283325,
      -471217197e-13,
      194409629e-16,
      -318486782e-20,
      -19802.2652,
      34.5255921
    ],
    "C5H5O": [
      10.580139,
      0.0213128784,
      -963052935e-14,
      209384798e-17,
      -179321204e-21,
      16254.3411,
      -32.6154734,
      -4.01979397,
      0.0615885556,
      -51295023e-12,
      21249937e-15,
      -348209517e-20,
      20488.3217,
      43.2455666
    ],
    "C5H7": [
      7.72404525,
      0.0256072196,
      -876350316e-14,
      866193959e-18,
      33041665e-21,
      23080.8142,
      -16.9352935,
      0.231765047,
      0.0465646468,
      -307468184e-13,
      111148258e-16,
      -175867718e-20,
      25223.6063,
      21.8904247
    ],
    "C5H8": [
      8.95829159,
      0.0251033002,
      -843679234e-14,
      819905621e-18,
      311426511e-22,
      4679.533,
      -24.0439628,
      1.19183502,
      0.0468276543,
      -312245763e-13,
      114435811e-16,
      -182614328e-20,
      6900.73958,
      16.2025638
    ],
    "C5H8O": [
      6.70800688,
      0.0365243775,
      -177765821e-13,
      415639148e-17,
      -379163309e-21,
      -5527.71782,
      -9.67918417,
      -5.12640161,
      0.0721165834,
      -579181678e-13,
      242774871e-16,
      -416132413e-20,
      -2379.76516,
      50.7899199
    ],
    "C5H8O4": [
      11.9601536,
      0.0399450843,
      -195947373e-13,
      460940117e-17,
      -42230229e-20,
      -82638.5858,
      -29.1875208,
      -6.95683231,
      0.101463738,
      -946174851e-13,
      452721371e-16,
      -868708602e-20,
      -77985.0073,
      65.9920851
    ],
    "C5H9CHO": [
      10.8416239,
      0.0420296686,
      -200742994e-13,
      457927363e-17,
      -408519043e-21,
      -35963.1714,
      -38.0017802,
      -6.51363638,
      0.0805969136,
      -522136702e-13,
      164827443e-16,
      -206177886e-20,
      -29715.2777,
      55.9285088
    ],
    "C6H10O5": [
      15.4889718,
      0.0496354387,
      -245944509e-13,
      582332585e-17,
      -535665863e-21,
      -109180.509,
      -48.1819837,
      -7.95116461,
      0.126488345,
      -119085729e-12,
      574579042e-16,
      -111165221e-19,
      -103461.116,
      69.5642163
    ],
    "C6H2": [
      12.0007067,
      0.00935747205,
      -345039279e-14,
      596931921e-18,
      -408067421e-22,
      81079.7696,
      -36.163061,
      4.40206371,
      0.0369889013,
      -411296144e-13,
      234328238e-16,
      -523078218e-20,
      82751.471,
      1.22022725
    ],
    "C6H3": [
      11.9194523,
      0.0116137832,
      -419264523e-14,
      684693072e-18,
      -417887568e-22,
      82628.076,
      -32.9876543,
      4.4660145,
      0.0341999583,
      -298587533e-13,
      136473739e-16,
      -249684195e-20,
      84595.7836,
      5.04018537
    ],
    "C6H4": [
      17.4447675,
      0.00621306708,
      -980963858e-15,
      800594635e-19,
      -28832077e-22,
      54956.8894,
      -65.9208082,
      -1.1730561,
      0.0609713718,
      -613761529e-13,
      296855443e-16,
      -544506791e-20,
      60020.9374,
      29.6241244
    ],
    "C6H4C2H": [
      32.1415686,
      -0.0198168404,
      264282529e-13,
      -109843473e-16,
      150630597e-20,
      54496.4091,
      -147.026437,
      -4.78252619,
      0.0793082463,
      -73362103e-12,
      336645815e-16,
      -598512503e-20,
      65499.7893,
      45.8354239
    ],
    "C6H4CH3": [
      12.3344954,
      0.0238147082,
      -701721971e-14,
      358622104e-18,
      792842393e-22,
      29709.1697,
      -39.4240761,
      -4.14387803,
      0.0692722902,
      -540423045e-13,
      219793508e-16,
      -36484276e-19,
      34487.898,
      46.1973136
    ],
    "C6H4O2": [
      17.4929577,
      0.0129021286,
      -202976642e-14,
      -372417846e-18,
      859745727e-22,
      -22210.0459,
      -64.9015838,
      -5.23446578,
      0.077377089,
      -706201498e-13,
      320580235e-16,
      -566410367e-20,
      -15800.9124,
      52.5540058
    ],
    "C6H5": [
      23.7494889,
      -0.00374826288,
      722829016e-14,
      -269927706e-17,
      310032681e-21,
      29357.1719,
      -107.010346,
      -4.30972117,
      0.0626640688,
      -517175663e-13,
      205535263e-16,
      -312973113e-20,
      38841.1849,
      43.0825907
    ],
    "C6H5C2H": [
      13.6301627,
      0.0267826138,
      -118276978e-13,
      25680725e-16,
      -221616638e-21,
      30438.1476,
      -48.3434869,
      -3.73085925,
      0.0789962135,
      -707152163e-13,
      320856256e-16,
      -577002888e-20,
      35056.1794,
      40.364406
    ],
    "C6H5C2H2": [
      17.71556,
      0.0219043174,
      -807391246e-14,
      139474201e-17,
      -941524347e-22,
      38139.4494,
      -70.1114193,
      -2.50848763,
      0.0697718858,
      -505599199e-13,
      181545083e-16,
      -25734078e-19,
      44975.1775,
      38.0700548
    ],
    "C6H5C2H3": [
      15.7612121,
      0.025134473,
      -708348959e-14,
      312355848e-18,
      82298579e-21,
      10134.6894,
      -59.5859946,
      -4.61890423,
      0.0825432514,
      -677265654e-13,
      287832834e-16,
      -493018867e-20,
      15922.6425,
      45.8827137
    ],
    "C6H5C2H4C6H5": [
      22.9999925,
      0.0523551496,
      -162023052e-13,
      106346924e-17,
      148747565e-21,
      3201.31872,
      -91.8704227,
      -10.5589612,
      0.145574466,
      -113305759e-12,
      460187721e-16,
      -765599251e-20,
      12866.2974,
      82.2691715
    ],
    "C6H5C2H5": [
      15.399243,
      0.0311284429,
      -932920034e-14,
      529654938e-18,
      971609974e-22,
      -4327.25762,
      -57.749174,
      -6.11786341,
      0.0908981829,
      -715893461e-13,
      293537965e-16,
      -490703025e-20,
      1869.66902,
      53.9044909
    ],
    "C6H5CH2C6H5": [
      23.660026,
      0.0420961068,
      -118756749e-13,
      402369975e-18,
      168531444e-21,
      4508.9773,
      -97.6688099,
      -11.8613481,
      0.140766591,
      -114657429e-12,
      479865153e-16,
      -80926049e-19,
      14739.1331,
      86.6539117
    ],
    "C6H5CH2OH": [
      12.5818443,
      0.0264134519,
      -793799879e-14,
      438368241e-18,
      864078959e-22,
      -18782.8963,
      -38.1332333,
      -6.02884975,
      0.0777532977,
      -61048184e-12,
      248568442e-16,
      -412367417e-20,
      -13385.795,
      58.5676633
    ],
    "C6H5CHO": [
      27.358848,
      0.00245725463,
      541130341e-14,
      -258531717e-17,
      321649872e-21,
      -17642.9542,
      -123.608292,
      -6.5570598,
      0.079103374,
      -595430351e-13,
      218795937e-16,
      -313384602e-20,
      -5636.72287,
      59.3816475
    ],
    "C6H5O": [
      13.4428169,
      0.0179658729,
      -667332779e-14,
      112237517e-17,
      -710809502e-22,
      407.68382,
      -47.250052,
      -4.80707078,
      0.0732685627,
      -695172935e-13,
      328617518e-16,
      -608232652e-20,
      5225.65416,
      45.8618544
    ],
    "C6H5OCH3": [
      12.5085136,
      0.0349906122,
      -163096082e-13,
      364836832e-17,
      -319988393e-21,
      -15203.8795,
      -42.0406499,
      -5.29461551,
      0.0865938851,
      -724001222e-13,
      30745235e-15,
      -522884105e-20,
      -10290.2159,
      49.5832512
    ],
    "C6H5OH": [
      13.9867712,
      0.0202277643,
      -7365995e-12,
      121196288e-17,
      -746105018e-22,
      -18054.2263,
      -50.8485811,
      -5.47325435,
      0.0787541571,
      -733732049e-13,
      342982836e-16,
      -629384372e-20,
      -12877.8595,
      48.584383
    ],
    "C6H6": [
      15.7365829,
      0.0124444139,
      -208242468e-14,
      -190555168e-18,
      56093865e-21,
      2375.38837,
      -66.0380946,
      -6.33361145,
      0.0693997541,
      -572004958e-13,
      235161421e-16,
      -376756698e-20,
      9217.1486,
      50.1102066
    ],
    "C6H6O3": [
      19.8638073,
      0.0179335016,
      -595408859e-14,
      893593939e-18,
      -49545988e-21,
      -49526.4845,
      -74.4496694,
      0.710718582,
      0.061217318,
      -426352889e-13,
      147094886e-16,
      -200094354e-20,
      -42746.291,
      28.8889342
    ],
    "C6H8O4": [
      15.8073709,
      0.0377998882,
      -177241312e-13,
      397560136e-17,
      -34900986e-20,
      -77878.8467,
      -51.5128322,
      -4.55493836,
      0.100453147,
      -900163533e-13,
      410485358e-16,
      -747842033e-20,
      -72584.6463,
      52.0658817
    ],
    "C7DIONE": [
      -0.755853587,
      0.0824536116,
      -458824665e-13,
      118274999e-16,
      -11580794e-19,
      -36754.679,
      26.4722477,
      3.52180397,
      0.0580098541,
      649701379e-14,
      -380577194e-16,
      166580704e-19,
      -37353.551,
      7.360756
    ],
    "C7H15COCHO": [
      30.2050983,
      0.0384107591,
      -130454122e-13,
      202881682e-17,
      -119348346e-21,
      -66795.645,
      -125.747051,
      0.359041588,
      0.105480549,
      -695648985e-13,
      231971638e-16,
      -309243078e-20,
      -56170.4488,
      35.4525548
    ],
    "C7H7": [
      15.5564029,
      0.0197467971,
      -490102499e-14,
      -10674605e-18,
      916513058e-22,
      16709.8727,
      -61.5086686,
      -4.40172355,
      0.0748036976,
      -618564392e-13,
      261757227e-16,
      -442324479e-20,
      22497.7294,
      42.1934668
    ],
    "C7H8": [
      12.5818443,
      0.0264134519,
      -793799879e-14,
      438368241e-18,
      864078959e-22,
      -564.471283,
      -44.5247833,
      -6.02884975,
      0.0777532977,
      -61048184e-12,
      248568442e-16,
      -412367417e-20,
      4832.63,
      52.1761133
    ],
    "C7KETONE": [
      18.2994273,
      0.0414393597,
      -171834162e-13,
      342714287e-17,
      -272037363e-21,
      -42784.8802,
      -65.9785823,
      -0.229236271,
      0.0826141675,
      -514957561e-13,
      161354169e-16,
      -203707542e-20,
      -36114.5614,
      34.30241
    ],
    "C8H10O3": [
      29.8957517,
      0.0473870505,
      -211603212e-13,
      460350399e-17,
      -396349099e-21,
      -70211.9467,
      -121.160681,
      -3.09348688,
      0.150478421,
      -141970521e-12,
      675254832e-16,
      -126857982e-19,
      -61766.7016,
      46.1370519
    ],
    "C8H2": [
      16.2719352,
      0.00999874492,
      -29303708e-13,
      289537341e-18,
      252405898e-24,
      107885.46,
      -58.9733614,
      0.187361722,
      0.0706952484,
      -888216494e-13,
      543092094e-16,
      -127402363e-19,
      111295.389,
      19.5626382
    ],
    "C8H9": [
      24.5973914,
      0.0120503967,
      566754133e-15,
      -110955314e-17,
      15730831e-20,
      16594.873,
      -106.442126,
      -5.12604623,
      0.0877789001,
      -717853192e-13,
      296131956e-16,
      -473484913e-20,
      25928.0324,
      50.3637968
    ],
    "C9H10O2": [
      26.4048781,
      0.0284903123,
      -103289369e-13,
      178607618e-17,
      -122280426e-21,
      -37143.9509,
      -110.770565,
      -2.04331024,
      0.0987327525,
      -753682334e-13,
      285512188e-16,
      -425270367e-20,
      -27926.7379,
      40.1996488
    ],
    "CH": [
      1.56762354,
      0.00335441204,
      -129971595e-14,
      240500907e-18,
      -178141164e-22,
      71168.6733,
      12.7712404,
      3.85901271,
      -0.00197439999,
      334750385e-14,
      -156074708e-17,
      243995183e-21,
      70380.4355,
      0.473936215
    ],
    "CH2": [
      3.24505871,
      0.00275395076,
      -768471343e-15,
      823040037e-19,
      -18990025e-22,
      45479.458,
      4.28187007,
      3.99717917,
      -588806826e-12,
      480279129e-14,
      -404455721e-17,
      114445133e-20,
      45344.0763,
      0.732567433
    ],
    "CH2C3H5": [
      8.45916998,
      0.0193968541,
      -599075606e-14,
      382147973e-18,
      573994806e-22,
      19898.8324,
      -18.0212793,
      -0.329329051,
      0.0423733221,
      -285167051e-13,
      101973763e-16,
      -1546396e-18,
      22588.1131,
      28.1156134
    ],
    "CH2CCH3": [
      10.0124373,
      0.00755815802,
      -117096962e-14,
      -201794819e-18,
      472987983e-22,
      27864.1947,
      -27.5169832,
      0.61051202,
      0.0284513252,
      -185819423e-13,
      624671358e-17,
      -848327368e-21,
      31248.8878,
      23.3681976
    ],
    "CH2CCHCHO": [
      10.585855,
      0.0129956017,
      -476361255e-14,
      749449815e-18,
      -396847802e-22,
      3105.13348,
      -29.3262371,
      1.05972039,
      0.0369607201,
      -273722149e-13,
      102289476e-16,
      -153017186e-20,
      6134.44428,
      21.0494483
    ],
    "CH2CH2CH2CH2OH": [
      11.7572858,
      0.0241574264,
      -972976868e-14,
      189143875e-17,
      -146945289e-21,
      -14567.216,
      -31.4377946,
      0.893764133,
      0.0482985857,
      -298474014e-13,
      934241382e-17,
      -118180294e-20,
      -10656.3482,
      27.3578508
    ],
    "CH2CH2CH2OH": [
      9.49770379,
      0.0177061096,
      -668456978e-14,
      120981994e-17,
      -873179586e-22,
      -10797.62,
      -20.7829255,
      1.04629052,
      0.0364870279,
      -223353351e-13,
      700639969e-17,
      -892398479e-21,
      -7755.11123,
      24.9578861
    ],
    "CH2CH2CHOHCH3": [
      13.9333095,
      0.0207599768,
      -756097165e-14,
      127900113e-17,
      -837238502e-22,
      -17489.7435,
      -44.6134901,
      0.911733056,
      0.0496968134,
      -316750021e-13,
      102101235e-16,
      -132415752e-20,
      -12801.976,
      25.8619981
    ],
    "CH2CHCH2": [
      13.1270112,
      0.00337812631,
      130787951e-14,
      -872502093e-18,
      113779857e-21,
      13856.911,
      -47.1985703,
      0.145788193,
      0.0322252886,
      -227314224e-13,
      803094306e-17,
      -112280975e-20,
      18530.1513,
      23.0585168
    ],
    "CH2CHCH2OHCH3": [
      13.8129918,
      0.0202819032,
      -70337278e-13,
      11243986e-16,
      -686002896e-22,
      -16404.5579,
      -44.2517079,
      0.2324526,
      0.050799969,
      -327511989e-13,
      107564103e-16,
      -142141092e-20,
      -11569.886,
      29.0972641
    ],
    "CH2CHO": [
      3.6650252,
      0.0144768244,
      -723266377e-14,
      170580456e-17,
      -156345856e-21,
      -36.8579193,
      5.9234185,
      0.215742069,
      0.0278720987,
      -267403448e-13,
      143321353e-16,
      -322098924e-20,
      673.694406,
      22.6661724
    ],
    "CH2CHOHCH3": [
      6.3269443,
      0.023876249,
      -107376178e-13,
      233737032e-17,
      -201069469e-21,
      -11421.7376,
      -3.956905,
      0.640756935,
      0.0403579515,
      -286525118e-13,
      109919085e-16,
      -176892059e-20,
      -9852.34986,
      25.3070892
    ],
    "CH2CHOOHCHO": [
      10.9154411,
      0.0211069264,
      -104347901e-13,
      243633157e-17,
      -220224944e-21,
      -13544.6352,
      -24.2468452,
      1.81101363,
      0.0491205495,
      -427582013e-13,
      190124399e-16,
      -340793808e-20,
      -11177.4841,
      22.0654311
    ],
    "CH2CN": [
      4.41880974,
      0.00983430327,
      -498991807e-14,
      122319871e-17,
      -117396557e-21,
      29239.0343,
      2.0276926,
      2.71162977,
      0.0168023848,
      -156553489e-13,
      847859386e-17,
      -196826267e-20,
      29573.6416,
      10.2293594
    ],
    "CH2CO": [
      6.03578795,
      0.00581722422,
      -193206512e-14,
      283140054e-18,
      -150051612e-22,
      -8584.2238,
      -7.6450506,
      2.49197065,
      0.0158706066,
      -126271528e-13,
      533991909e-17,
      -911597189e-21,
      -7584.86732,
      10.6694385
    ],
    "CH2O": [
      1.06639253,
      0.0106960337,
      -554447373e-14,
      136053696e-17,
      -128442554e-21,
      -14632.4373,
      17.4071779,
      3.13463322,
      0.00180037482,
      880336316e-14,
      -892465077e-17,
      263639286e-20,
      -15017.1301,
      7.5792058
    ],
    "CH2OH": [
      7.61004151,
      0.00140239019,
      105265418e-14,
      -561972284e-18,
      711209072e-22,
      -5049.85629,
      -15.5757586,
      1.95857131,
      0.0156199253,
      -123601148e-13,
      506183022e-17,
      -813124769e-21,
      -3252.68877,
      14.3100973
    ],
    "CH2OOCH2CHO": [
      10.6998539,
      0.0242793089,
      -134097218e-13,
      342673974e-17,
      -332159552e-21,
      -21412.6656,
      -24.8508794,
      2.93009251,
      0.0415454454,
      -277981689e-13,
      875579421e-17,
      -107230601e-20,
      -18615.5515,
      17.2006902
    ],
    "CH2OOCHOOHCHO": [
      21.4549192,
      0.0108256409,
      -375393277e-14,
      588014009e-18,
      -347282962e-22,
      -35990.021,
      -79.3559883,
      5.41191662,
      0.0464767576,
      -334631967e-13,
      115914451e-16,
      -156298261e-20,
      -30214.5401,
      7.47208818
    ],
    "CH2OOHCHCHO": [
      1.848167,
      0.0399042619,
      -238947704e-13,
      648850081e-17,
      -65762829e-20,
      -14899.1977,
      21.5340498,
      5.4432667,
      0.019360835,
      201268587e-13,
      -354368602e-16,
      143157149e-19,
      -15402.5117,
      5.47205385
    ],
    "CH2OOHCHOOCHO": [
      21.4549192,
      0.0108256409,
      -375393277e-14,
      588014009e-18,
      -347282962e-22,
      -35990.021,
      -79.3559883,
      5.41191662,
      0.0464767576,
      -334631967e-13,
      115914451e-16,
      -156298261e-20,
      -30214.5401,
      7.47208818
    ],
    "CH2S": [
      2.57518275,
      0.00411179659,
      -168232435e-14,
      344404948e-18,
      -293085968e-22,
      50195.85,
      6.99914504,
      4.62572654,
      -0.0050017314,
      13506889e-12,
      -109068642e-16,
      309604394e-20,
      49826.7521,
      -2.67749711
    ],
    "CH3": [
      2.57723974,
      0.00662601164,
      -254906392e-14,
      467320141e-18,
      -334867663e-22,
      16548.8693,
      6.94195966,
      3.53327401,
      0.00361488008,
      100739068e-14,
      -139958516e-17,
      334014277e-21,
      16306.0366,
      2.1011386
    ],
    "CH3C10H6O": [
      26.0936624,
      0.0324954978,
      -130480618e-13,
      252260906e-17,
      -195492396e-21,
      -2873.96993,
      -114.905139,
      -1.85059487,
      0.0945938472,
      -647966864e-13,
      216887663e-16,
      -285745868e-20,
      7185.96268,
      36.3350107
    ],
    "CH3C10H6OH": [
      29.1191869,
      0.0286451308,
      -980098219e-14,
      151374083e-17,
      -872237944e-22,
      -21362.6711,
      -132.660114,
      -1.76841814,
      0.0972842531,
      -670002508e-13,
      226986551e-16,
      -3029573e-18,
      -10243.1333,
      34.5100483
    ],
    "CH3CCH2OHCH3": [
      2.02076663,
      0.0409903683,
      -206486866e-13,
      500507647e-17,
      -471523451e-21,
      -14071.8373,
      21.5880986,
      3.53447938,
      0.0323405812,
      -211342851e-14,
      -126475503e-16,
      583298611e-20,
      -14283.7571,
      14.825213
    ],
    "CH3CH2CH2CH2O": [
      11.609338,
      0.0256981798,
      -109676558e-13,
      225993093e-17,
      -185313976e-21,
      -13194.8148,
      -34.3573902,
      0.0590549372,
      0.0513654755,
      -323570689e-13,
      101819358e-16,
      -128559243e-20,
      -9036.71291,
      28.1551514
    ],
    "CH3CH2CH2CHOH": [
      13.0151659,
      0.0221750012,
      -849156594e-14,
      154860371e-17,
      -112013678e-21,
      -17908.122,
      -40.1994427,
      1.75489331,
      0.0471978292,
      -293439226e-13,
      927169878e-17,
      -118466577e-20,
      -13854.4238,
      20.7435017
    ],
    "CH3CH2CH2O": [
      9.07749584,
      0.0196975457,
      -818089073e-14,
      164328968e-17,
      -131786153e-21,
      -9310.61125,
      -22.1687275,
      0.291958855,
      0.0392209612,
      -244504037e-13,
      766903521e-17,
      -968695255e-21,
      -6147.81793,
      25.3804314
    ],
    "CH3CH2CHCH2OH": [
      11.5124775,
      0.0241072597,
      -986401997e-14,
      198674692e-17,
      -162119892e-21,
      -15899.1633,
      -30.3580006,
      0.15345735,
      0.0493495266,
      -308992425e-13,
      977757006e-17,
      -124417866e-20,
      -11809.916,
      31.1193861
    ],
    "CH3CH2CHOCH3": [
      13.0434362,
      0.0238164771,
      -982552432e-14,
      193897534e-17,
      -151918988e-21,
      -15853.8336,
      -43.5088383,
      0.0417731726,
      0.0527090615,
      -33902678e-12,
      108564397e-16,
      -13904557e-19,
      -11173.2349,
      26.8588742
    ],
    "CH3CH2CHOH": [
      8.28181025,
      0.0200744959,
      -821041648e-14,
      162349331e-17,
      -127917758e-21,
      -13049.2834,
      -15.6179098,
      1.73835403,
      0.0362311779,
      -231703072e-13,
      777982697e-17,
      -107796925e-20,
      -10929.2035,
      19.1072184
    ],
    "CH3CH2CHOHCH2": [
      13.9333095,
      0.0207599768,
      -756097165e-14,
      127900113e-17,
      -837238502e-22,
      -17489.7435,
      -44.6134901,
      0.911733056,
      0.0496968134,
      -316750021e-13,
      102101235e-16,
      -132415752e-20,
      -12801.976,
      25.8619981
    ],
    "CH3CH2COHCH3": [
      8.72382272,
      0.030434283,
      -139185549e-13,
      306043861e-17,
      -264689231e-21,
      -18066.1273,
      -17.1435098,
      1.27395834,
      0.0512730645,
      -357774166e-13,
      132510501e-16,
      -204626467e-20,
      -15935.4661,
      21.4624055
    ],
    "CH3CH3-C5H6": [
      15.3755546,
      0.0327318283,
      -105955708e-13,
      15210263e-16,
      -769415914e-22,
      -6196.8293,
      -53.7226046,
      -1.29247813,
      0.0836265847,
      -688720094e-13,
      31178247e-15,
      -573671653e-20,
      -1829.80473,
      31.1918393
    ],
    "CH3CHCH2CH2OH": [
      11.5124775,
      0.0241072597,
      -986401997e-14,
      198674692e-17,
      -162119892e-21,
      -15899.1633,
      -30.3580006,
      0.15345735,
      0.0493495266,
      -308992425e-13,
      977757006e-17,
      -124417866e-20,
      -11809.916,
      31.1193861
    ],
    "CH3CHCH2OCH3": [
      13.8488385,
      0.0214834842,
      -803028843e-14,
      142167056e-17,
      -995437051e-22,
      -15124.944,
      -48.2209549,
      -0.469026374,
      0.0533009618,
      -345448531e-13,
      112418797e-16,
      -146346164e-20,
      -9970.51265,
      29.2703168
    ],
    "CH3CHCH2OH": [
      7.64501934,
      0.0206996931,
      -877824684e-14,
      184245353e-17,
      -155992331e-21,
      -11505.0426,
      -10.8131884,
      0.539035202,
      0.036490769,
      -219374767e-13,
      671624238e-17,
      -832907449e-21,
      -8946.88828,
      27.6458802
    ],
    "CH3CHCH3CHOH": [
      8.91411879,
      0.0294184843,
      -130488503e-13,
      281020956e-17,
      -23974981e-20,
      -17114.5335,
      -18.5255698,
      0.616106328,
      0.0523095531,
      -367292664e-13,
      136977572e-16,
      -211691319e-20,
      -14708.1099,
      24.5907827
    ],
    "CH3CHCHOHCH3": [
      11.1524016,
      0.0252912378,
      -105179486e-13,
      21239265e-16,
      -171553011e-21,
      -17809.541,
      -29.420972,
      0.676902371,
      0.0485701251,
      -299170213e-13,
      930876825e-17,
      -11694477e-19,
      -14038.3613,
      27.2746153
    ],
    "CH3CHO": [
      6.27018126,
      0.0106201871,
      -382264672e-14,
      656340789e-18,
      -460549581e-22,
      -22979.4782,
      -8.60119259,
      0.991751377,
      0.0223500313,
      -135975169e-13,
      427666307e-17,
      -548877497e-21,
      -21079.2434,
      19.9667711
    ],
    "CH3CHOH": [
      1.00303702,
      0.0230237358,
      -119372743e-13,
      298274467e-17,
      -288183748e-21,
      -6177.51011,
      23.9401608,
      1.83915526,
      0.0182459173,
      -169909177e-14,
      -676790535e-17,
      319419126e-20,
      -6294.56667,
      20.2045961
    ],
    "CH3CHOOCHO": [
      15.8771657,
      0.0128699615,
      -529703385e-14,
      104001953e-17,
      -812487153e-22,
      -23888.7629,
      -54.4666587,
      3.38301196,
      0.0406347476,
      -284343556e-13,
      960939795e-17,
      -127144016e-20,
      -19390.8676,
      13.1543077
    ],
    "CH3CN": [
      2.02660925,
      0.0164402545,
      -854290907e-14,
      213740318e-17,
      -208581596e-21,
      8618.23027,
      13.1030643,
      2.36621609,
      0.014499644,
      -438445795e-14,
      -182302645e-17,
      120585756e-20,
      8570.68531,
      11.5857868
    ],
    "CH3CO": [
      5.59449005,
      0.00895063669,
      -342706569e-14,
      639554414e-18,
      -491680987e-22,
      -5319.3122,
      -3.4646616,
      1.83189171,
      0.0173119663,
      -103948404e-13,
      322021171e-17,
      -407592723e-21,
      -3964.7768,
      16.8993055
    ],
    "CH3CO3": [
      14.0469381,
      0.00248483421,
      165900438e-14,
      -855133987e-18,
      982287242e-22,
      -27375.6816,
      -43.6816972,
      2.64892548,
      0.0283894083,
      -204187576e-13,
      750765465e-17,
      -108966739e-20,
      -23363.5811,
      17.7505788
    ],
    "CH3CO3H": [
      15.4960865,
      0.00158758106,
      224425901e-14,
      -974237206e-18,
      103773065e-21,
      -46965.5432,
      -51.8401164,
      3.62388957,
      0.0285698467,
      -207519902e-13,
      773646324e-17,
      -113354234e-20,
      -42786.5299,
      12.1478877
    ],
    "CH3COCH2": [
      9.24187097,
      0.0134946785,
      -523722666e-14,
      972748882e-18,
      -719834442e-22,
      -8045.71079,
      -22.4258259,
      1.8262086,
      0.0299739283,
      -189699348e-13,
      605893707e-17,
      -77839847e-20,
      -5376.07233,
      17.7092859
    ],
    "CH3COCH3": [
      0.822157368,
      0.0318964631,
      -168324056e-13,
      420706053e-17,
      -404124926e-21,
      -27473.7271,
      21.7873546,
      1.03654018,
      0.0306714184,
      -142073099e-13,
      170696939e-17,
      488764769e-21,
      -27503.7407,
      20.8295464
    ],
    "CH3COHCH3": [
      6.71652579,
      0.0235306498,
      -106144747e-13,
      231761627e-17,
      -19988632e-20,
      -14417.5086,
      -7.90476332,
      1.21649821,
      0.0408535713,
      -310746182e-13,
      130578491e-16,
      -231410538e-20,
      -13020.5016,
      19.94429
    ],
    "CH3COOH": [
      7.8349162,
      0.0112357063,
      -31355807e-13,
      159502818e-18,
      30135756e-21,
      -55741.4981,
      -15.3809923,
      0.313168541,
      0.0325739975,
      -258358905e-13,
      108925098e-16,
      -187287967e-20,
      -53620.3653,
      23.4914872
    ],
    "CH3NO": [
      1.73828229,
      0.0165479495,
      -869271695e-14,
      21700276e-16,
      -208463444e-21,
      8364.73513,
      17.4966005,
      2.23451684,
      0.0142398818,
      -466701756e-14,
      -950669597e-18,
      698715974e-21,
      8279.38279,
      15.1773992
    ],
    "CH3NO2": [
      5.94771391,
      0.0122319078,
      -498716389e-14,
      973177561e-18,
      -754873508e-22,
      -11469.1242,
      -2.73415041,
      -0.205952276,
      0.0274261453,
      -190559023e-13,
      676278185e-17,
      -968944802e-21,
      -9475.3364,
      29.9224212
    ],
    "CH3O": [
      0.688420582,
      0.0144971301,
      -759068052e-14,
      192522389e-17,
      -190011116e-21,
      1183.30404,
      19.5838279,
      2.13962537,
      0.0062045313,
      10179174e-12,
      -149984471e-16,
      585415708e-20,
      980.135371,
      13.100212
    ],
    "CH3OCH2": [
      2.76373432,
      0.0209427776,
      -103906311e-13,
      245853855e-17,
      -225935821e-21,
      -659.718889,
      12.3154396,
      2.98724171,
      0.0197507382,
      -800655224e-14,
      339357381e-18,
      480457902e-21,
      -693.244997,
      11.3014447
    ],
    "CH3OCH3": [
      0.815389478,
      0.02726754,
      -140181429e-13,
      343685384e-17,
      -325542356e-21,
      -23174.5898,
      19.9239256,
      1.74097325,
      0.0219784899,
      -2684464e-12,
      -735712603e-17,
      352945045e-20,
      -23304.1715,
      15.7886515
    ],
    "CH3OCHO": [
      2.1476974,
      0.0246740524,
      -135238094e-13,
      344782067e-17,
      -334980467e-21,
      -44037.2636,
      16.9024645,
      3.51192337,
      0.0168784755,
      318099831e-14,
      -1246152e-14,
      534692693e-20,
      -44228.2552,
      10.807448
    ],
    "CH3OCO": [
      2.57527318,
      0.0211166692,
      -120149822e-13,
      31484939e-16,
      -31141102e-20,
      -20708.551,
      15.9117693,
      4.66126893,
      0.00968655554,
      114715528e-13,
      -183003965e-16,
      703409939e-20,
      -21013.1064,
      6.50453092
    ],
    "CH3OH": [
      0.934193,
      0.0160266556,
      -800101466e-14,
      197129714e-17,
      -191599484e-21,
      -25097.9789,
      19.1008457,
      2.88895785,
      0.00485657077,
      159348814e-13,
      -208247943e-16,
      794986176e-20,
      -25371.646,
      10.3674509
    ],
    "CH3ONO": [
      8.58034518,
      0.00890954082,
      -335922089e-14,
      618588139e-18,
      -468096982e-22,
      -11556.9624,
      -19.7194056,
      1.99249583,
      0.023549206,
      -155589419e-13,
      513700333e-17,
      -674367363e-21,
      -9185.33663,
      15.9354094
    ],
    "CH3ONO2": [
      10.7457798,
      0.0103362024,
      -439539782e-14,
      895959797e-18,
      -726862027e-22,
      -18103.109,
      -30.8875015,
      1.3515539,
      0.03121226,
      -217921125e-13,
      733918744e-17,
      -967578931e-21,
      -14721.1877,
      19.9560088
    ],
    "CH3OO": [
      3.4652197,
      0.0123938518,
      -559614682e-14,
      122616716e-17,
      -106238815e-21,
      686.982281,
      10.4298931,
      4.30117244,
      0.00982168948,
      -262826727e-14,
      -295822349e-18,
      186451475e-21,
      469.634569,
      6.17758023
    ],
    "CH3OOH": [
      5.50146514,
      0.0113975421,
      -382130848e-14,
      43870491e-17,
      -290617476e-23,
      -17978.4234,
      -0.465581411,
      5.93430876,
      0.0104356674,
      -301974623e-14,
      141830001e-18,
      383264515e-22,
      -18134.2471,
      -2.80822136
    ],
    "CH4": [
      -0.282321416,
      0.0142739336,
      -677628877e-14,
      155380951e-17,
      -139473841e-21,
      -9363.83584,
      20.3507024,
      2.85765313,
      2535711e-9,
      967916346e-14,
      -86988087e-16,
      22559977e-19,
      -10035.7904,
      4.98969392
    ],
    "CHCHCH3": [
      10.0124373,
      0.00755815802,
      -117096962e-14,
      -201794819e-18,
      472987983e-22,
      27864.1947,
      -27.5169832,
      0.61051202,
      0.0284513252,
      -185819423e-13,
      624671358e-17,
      -848327368e-21,
      31248.8878,
      23.3681976
    ],
    "CN": [
      2.73859606,
      0.00223580966,
      -133797023e-14,
      434996429e-18,
      -505222621e-22,
      51456.8835,
      8.20480076,
      4.08532688,
      -0.00441471288,
      109778123e-13,
      -970145006e-17,
      30780106e-19,
      51238.7131,
      1.99138758
    ],
    "CO": [
      2.68595014,
      0.00212486373,
      -104548608e-14,
      245538864e-18,
      -222550981e-22,
      -14142.3615,
      7.96579426,
      3.81890943,
      -0.00240697343,
      575226966e-14,
      -42862983e-16,
      111070419e-20,
      -14368.9533,
      2.4999206
    ],
    "CO2": [
      5.07830985,
      0.00205366041,
      -594311265e-15,
      538675131e-19,
      166346855e-23,
      -49244.2103,
      -4.4781529,
      2.44892797,
      0.00854596135,
      -660570102e-14,
      252769046e-17,
      -380099332e-21,
      -48392.2906,
      9.47557732
    ],
    "CRESOL": [
      12.2673687,
      0.0334155283,
      -138949871e-13,
      256768166e-17,
      -171519559e-21,
      -21718.7243,
      -39.5715124,
      -4.41843936,
      0.0843645604,
      -722335735e-13,
      322565297e-16,
      -583733025e-20,
      -17347.0426,
      45.4334869
    ],
    "CYC5H4O": [
      6.34459579,
      0.0239841575,
      -832755388e-14,
      847127653e-18,
      286249484e-22,
      3086.59308,
      -9.73181554,
      -5.14379339,
      0.0604552342,
      -517455024e-13,
      238195872e-16,
      -452940274e-20,
      5981.66715,
      48.3481227
    ],
    "CYC5H5": [
      4.01652575,
      0.0268451891,
      -126423018e-13,
      278092332e-17,
      -235299436e-21,
      29111.0159,
      1.44025794,
      -2.58737408,
      0.0645817595,
      -935063814e-13,
      797943325e-16,
      -277400884e-19,
      30035.5619,
      30.9448116
    ],
    "CYC5H6": [
      1.70141558,
      0.0379065957,
      -219495256e-13,
      612706526e-17,
      -663672518e-21,
      13848.4401,
      12.2453451,
      -6.32922867,
      0.0693993183,
      -682623529e-13,
      36396887e-15,
      -808274648e-20,
      15486.6915,
      51.1475893
    ],
    "CYC5H8": [
      8.43099915,
      0.0271082714,
      -107932862e-13,
      195387666e-17,
      -131111174e-21,
      -1098.62538,
      -23.7608447,
      -6.5686398,
      0.0682031726,
      -530140751e-13,
      212327757e-16,
      -343229252e-20,
      3281.2692,
      54.2801525
    ],
    "CYC6-OO": [
      18.7814621,
      0.0354361927,
      -149718784e-13,
      304328287e-17,
      -246478319e-21,
      -19525.283,
      -78.7240875,
      -6.50623568,
      0.0916310766,
      -618009483e-13,
      203873828e-16,
      -265538109e-20,
      -10421.7118,
      58.1382079
    ],
    "CYC6-OOQOOH-2": [
      29.3742215,
      0.02678588,
      -956345992e-14,
      154085681e-17,
      -931283791e-22,
      -35549.9047,
      -129.752781,
      -4.99061953,
      0.104446538,
      -753775765e-13,
      263296013e-16,
      -359436348e-20,
      -23384.751,
      55.6593329
    ],
    "CYC6-OOQOOH-3": [
      29.3742215,
      0.02678588,
      -956345992e-14,
      154085681e-17,
      -931283791e-22,
      -35549.9047,
      -129.752781,
      -4.99061953,
      0.104446538,
      -753775765e-13,
      263296013e-16,
      -359436348e-20,
      -23384.751,
      55.6593329
    ],
    "CYC6-OOQOOH-4": [
      29.3742215,
      0.02678588,
      -956345992e-14,
      154085681e-17,
      -931283791e-22,
      -35549.9047,
      -130.447295,
      -4.99061953,
      0.104446538,
      -753775765e-13,
      263296013e-16,
      -359436348e-20,
      -23384.751,
      54.9648189
    ],
    "CYC6-OQOOH-2": [
      11.7655243,
      0.0367451404,
      -142717448e-13,
      274140449e-17,
      -213135508e-21,
      -35990.3393,
      -51.0812501,
      -10.6696444,
      0.098211356,
      -774219664e-13,
      315771221e-16,
      -515075839e-20,
      -29439.27,
      65.6457555
    ],
    "CYC6-OQOOH-3": [
      11.6022418,
      0.0357303662,
      -134415883e-13,
      250437459e-17,
      -189510289e-21,
      -36382.1557,
      -49.1587814,
      -8.02402159,
      0.0895009509,
      -686853396e-13,
      277298318e-16,
      -45089379e-19,
      -30651.2867,
      52.9538877
    ],
    "CYC6-OQOOH-4": [
      11.6022418,
      0.0357303662,
      -134415883e-13,
      250437459e-17,
      -189510289e-21,
      -36382.1557,
      -49.8532958,
      -8.02402159,
      0.0895009509,
      -686853396e-13,
      277298318e-16,
      -45089379e-19,
      -30651.2867,
      52.2593733
    ],
    "CYC6-QOOH-2": [
      19.1384147,
      0.0364873063,
      -163612962e-13,
      353264562e-17,
      -302111689e-21,
      -14329.4351,
      -78.638364,
      -4.87015408,
      0.0898396814,
      -608216088e-13,
      199994281e-16,
      -258916481e-20,
      -5686.35037,
      51.3010187
    ],
    "CYC6-QOOH-3": [
      20.9300723,
      0.0328719793,
      -140160778e-13,
      289193638e-17,
      -238539838e-21,
      -15299.4543,
      -88.9349636,
      -7.04914219,
      0.0950480115,
      -65829438e-12,
      220820698e-16,
      -290383614e-20,
      -5226.93704,
      62.4943819
    ],
    "CYC6-QOOH-4": [
      20.9300723,
      0.0328719793,
      -140160778e-13,
      289193638e-17,
      -238539838e-21,
      -15299.4543,
      -88.9349636,
      -7.04914219,
      0.0950480115,
      -65829438e-12,
      220820698e-16,
      -290383614e-20,
      -5226.93704,
      62.4943819
    ],
    "CYC6H10": [
      15.1624858,
      0.0276360017,
      -105259858e-13,
      189586361e-17,
      -135054773e-21,
      -9299.85245,
      -62.5064559,
      -6.01517655,
      0.0746974737,
      -497438791e-13,
      164210093e-16,
      -215243611e-20,
      -1675.89399,
      52.1114707
    ],
    "CYC6H10-O-12": [
      22.9323176,
      0.0220056554,
      -735242348e-14,
      107816406e-17,
      -564635915e-22,
      -27980.62,
      -110.525204,
      -10.5629257,
      0.0964395294,
      -693806518e-13,
      24051582e-15,
      -324721608e-20,
      -15922.3324,
      70.7580407
    ],
    "CYC6H10-O-13": [
      21.8028612,
      0.0241377428,
      -873118284e-14,
      146035609e-17,
      -95186687e-21,
      -28738.7454,
      -106.217525,
      -12.5990095,
      0.100586344,
      -724383509e-13,
      250556035e-16,
      -337230438e-20,
      -16354.0719,
      79.9725758
    ],
    "CYC6H10-O-14": [
      21.4079592,
      0.0250825461,
      -938039634e-14,
      164525432e-17,
      -11424764e-20,
      -38974.1817,
      -105.728233,
      -14.5960517,
      0.105091459,
      -760544907e-13,
      263393633e-16,
      -3543985e-18,
      -26012.7378,
      89.1329846
    ],
    "CYC6H10-ONE": [
      11.5965428,
      0.0402887933,
      -186685839e-13,
      415568433e-17,
      -364030709e-21,
      -36222.1493,
      -42.7468434,
      -6.46490379,
      0.0804253413,
      -521157073e-13,
      165435078e-16,
      -208456175e-20,
      -29720.0285,
      55.0054734
    ],
    "CYC6H11": [
      11.287919,
      0.0394798364,
      -180474738e-13,
      397976998e-17,
      -347933573e-21,
      469.934406,
      -41.5743644,
      -9.20200373,
      0.0850129981,
      -559917752e-13,
      18033215e-15,
      -229980093e-20,
      7846.30661,
      69.3213721
    ],
    "CYC6H12": [
      11.2578097,
      0.0434354098,
      -202455774e-13,
      454245292e-17,
      -40119517e-20,
      -23043.9963,
      -44.7863376,
      -9.43363126,
      0.0894163897,
      -585630607e-13,
      187341134e-16,
      -237225913e-20,
      -15595.0776,
      67.2000574
    ],
    "CYC6H8": [
      8.6677226,
      0.0345074855,
      -16384678e-12,
      369260975e-17,
      -324421026e-21,
      5740.22139,
      -27.3566208,
      -6.91358136,
      0.0763364895,
      -584944135e-13,
      225336547e-16,
      -348567018e-20,
      10383.45,
      54.027616
    ],
    "CYC6H9": [
      14.1670463,
      0.0275651338,
      -113337615e-13,
      223021652e-17,
      -174683445e-21,
      7938.66332,
      -58.5441979,
      -6.48639356,
      0.0734616669,
      -495808724e-13,
      163958131e-16,
      -214212742e-20,
      15373.9017,
      53.2365273
    ],
    "DCYC5": [
      27.0110296,
      0.0468748172,
      -16389549e-12,
      262563687e-17,
      -159789734e-21,
      -37922.6289,
      -135.167747,
      -14.5870783,
      0.141956207,
      -978878828e-13,
      336726212e-16,
      -459507321e-20,
      -23363.2912,
      88.7980358
    ],
    "DECALIN": [
      27.0110296,
      0.0468748172,
      -16389549e-12,
      262563687e-17,
      -159789734e-21,
      -37922.6289,
      -135.167747,
      -14.5870783,
      0.141956207,
      -978878828e-13,
      336726212e-16,
      -459507321e-20,
      -23363.2912,
      88.7980358
    ],
    "DIBZFUR": [
      24.9525256,
      0.0324730728,
      -115459374e-13,
      179679054e-17,
      -997833662e-22,
      -5307.53651,
      -113.355893,
      -11.6970901,
      0.136443614,
      -122152896e-12,
      540932248e-16,
      -937220078e-20,
      5027.6551,
      76.0497478
    ],
    "DIFENET": [
      17.1548107,
      0.0525374196,
      -245657222e-13,
      558244776e-17,
      -499409896e-21,
      -3297.04394,
      -64.9985669,
      -8.57458099,
      0.124507746,
      -100059071e-12,
      407774824e-16,
      -665238798e-20,
      4061.56207,
      68.3336207
    ],
    "DIPE": [
      11.1573928,
      0.0499175659,
      -225561386e-13,
      438444843e-17,
      -306549364e-21,
      -45935.7929,
      -30.6117763,
      -2.50745274,
      0.0895258138,
      -65608582e-12,
      251827303e-16,
      -407435404e-20,
      -42164.2955,
      39.7144256
    ],
    "DME-OO": [
      3.58974575,
      0.0280960123,
      -149224205e-13,
      371355557e-17,
      -353703711e-21,
      -19335.2293,
      14.7278303,
      5.41345468,
      0.0197111437,
      -465750394e-15,
      -736435253e-17,
      282960321e-20,
      -19652.5546,
      6.18346241
    ],
    "DME-OOQOOH": [
      9.57989146,
      0.0253360331,
      -113706887e-13,
      245690684e-17,
      -209295699e-21,
      -34819.9648,
      -11.6031904,
      7.85487749,
      0.0291693975,
      -145651591e-13,
      3640044e-15,
      -373620304e-21,
      -34198.9598,
      -2.26705495
    ],
    "DME-OQOOH": [
      15.4960865,
      0.00158758106,
      224425901e-14,
      -974237206e-18,
      103773065e-21,
      -46965.5432,
      -51.8401164,
      3.62388957,
      0.0285698467,
      -207519902e-13,
      773646324e-17,
      -113354234e-20,
      -42786.5299,
      12.1478877
    ],
    "DME-QOOH": [
      9.52551493,
      0.0189562856,
      -92755733e-13,
      215192754e-17,
      -19390568e-20,
      -17253.7528,
      -17.4698518,
      5.12252607,
      0.0287407053,
      -174292564e-13,
      517181016e-17,
      -613333823e-21,
      -15668.6768,
      6.36004246
    ],
    "DMF": [
      13.8889506,
      0.0249736923,
      -898421021e-14,
      142738238e-17,
      -797717945e-22,
      -22087.2034,
      -49.4041109,
      -2.31533181,
      0.0657391826,
      -474422199e-13,
      17552334e-15,
      -261514155e-20,
      -16934.2416,
      36.2866615
    ],
    "DMF-3YL": [
      14.1703395,
      0.0218230092,
      -769511407e-14,
      1178913e-15,
      -612376638e-22,
      11955.7792,
      -48.6583489,
      -1.12307984,
      0.0595845385,
      -42659493e-12,
      155675463e-16,
      -228170577e-20,
      16910.8471,
      32.5015043
    ],
    "ERC4H8CHO": [
      -0.304813054,
      0.0567977502,
      -324057642e-13,
      850471985e-17,
      -84176329e-20,
      -5214.20511,
      34.1933259,
      6.22525332,
      0.0219707295,
      372482771e-13,
      -534099835e-16,
      197964712e-19,
      -6193.71507,
      4.56811339
    ],
    "ETBE": [
      11.6559136,
      0.0467933987,
      -193342014e-13,
      35918514e-16,
      -245564975e-21,
      -46032.2114,
      -33.8084939,
      -3.48005604,
      0.0940933039,
      -747637778e-13,
      324614225e-16,
      -588415307e-20,
      -42157.4031,
      42.950277
    ],
    "ETC3H4O2": [
      10.2920429,
      0.01388713,
      -612561993e-14,
      130548845e-17,
      -109965765e-21,
      -35702.6988,
      -26.9350036,
      0.117378045,
      0.0467086294,
      -458290467e-13,
      226514168e-16,
      -441358036e-20,
      -33179.382,
      24.3405589
    ],
    "ETEROMD": [
      41.4249213,
      0.0451122053,
      -156530088e-13,
      249214075e-17,
      -150324737e-21,
      -89558.1279,
      -184.296546,
      -0.124327962,
      0.139542317,
      -961332178e-13,
      329770684e-16,
      -448057014e-20,
      -74932.7921,
      39.6429285
    ],
    "ETEROMPA": [
      43.2126695,
      0.0917256499,
      -302788098e-13,
      453882493e-17,
      -250045022e-21,
      -106117.741,
      -175.617618,
      -8.73011664,
      0.250329577,
      -21188636e-11,
      969599701e-16,
      -178876681e-19,
      -92508.7311,
      89.0022613
    ],
    "ETMB583": [
      17.5630365,
      0.0235383857,
      -756913166e-14,
      105837457e-17,
      -495698273e-22,
      -62736.9638,
      -61.5054259,
      -4.60165685,
      0.0933484435,
      -900219559e-13,
      44340697e-15,
      -856971204e-20,
      -57107.1317,
      50.7241435
    ],
    "FLUORENE": [
      29.1248872,
      0.0285362024,
      -566199729e-14,
      -567026725e-18,
      191134972e-21,
      9751.19358,
      -137.159218,
      -14.346512,
      0.149290089,
      -131447296e-12,
      576669078e-16,
      -99189231e-19,
      22270.9565,
      88.4167006
    ],
    "GLIET": [
      6.66621468,
      0.0187459315,
      -766039208e-14,
      153874843e-17,
      -124203245e-21,
      -49595.912,
      -6.016719,
      0.946220545,
      0.0343105414,
      -235426471e-13,
      874158516e-17,
      -134917548e-20,
      -47914.2337,
      23.7826449
    ],
    "GLYCEROL": [
      11.4796489,
      0.0236292461,
      -898384419e-14,
      170355137e-17,
      -131527258e-21,
      -74178.1076,
      -25.6707288,
      0.197850806,
      0.0586115658,
      -496609601e-13,
      227253167e-16,
      -420551279e-20,
      -71267.4037,
      31.6302477
    ],
    "H": [
      2.5,
      740336223e-23,
      -556967416e-26,
      173924876e-29,
      -192673709e-33,
      25471.62,
      -0.4601176,
      2.5,
      -40745516e-22,
      598527266e-26,
      -343074982e-29,
      674775716e-33,
      25471.62,
      -0.4601176
    ],
    "H2": [
      3.73110902,
      -886706214e-12,
      112286897e-14,
      -374349782e-18,
      417963674e-22,
      -1088.51547,
      -5.35285855,
      3.08866003,
      0.00253968841,
      -572992027e-14,
      571701843e-17,
      -19886597e-19,
      -992.148124,
      -2.43823459
    ],
    "H2CN": [
      5.2211132,
      0.00342647499,
      -836137799e-15,
      47483303e-18,
      42815335e-22,
      27531.2364,
      -4.80262216,
      1.81354567,
      0.0109988473,
      -714644805e-14,
      238463525e-17,
      -320322903e-21,
      28757.9607,
      13.6398442
    ],
    "H2NO": [
      1.43405821,
      0.00901333883,
      -338828321e-14,
      428655869e-18,
      -236936075e-23,
      7273.41661,
      17.9341864,
      2.78935895,
      0.00449566971,
      225880318e-14,
      -270861435e-17,
      651228601e-21,
      6948.14443,
      11.1485432
    ],
    "H2O": [
      2.30940463,
      0.00365433887,
      -122983871e-14,
      211931683e-18,
      -150333493e-22,
      -29729.4901,
      8.92765177,
      4.03530937,
      -687559833e-12,
      286629214e-14,
      -15055236e-16,
      25500679e-20,
      -30278.3278,
      -0.199201641
    ],
    "H2O2": [
      4.56163072,
      0.00435560969,
      -148694629e-14,
      238275424e-18,
      -146610352e-22,
      -18001.6693,
      0.566597119,
      2.91896355,
      0.00992397296,
      -856537418e-14,
      423738723e-17,
      -861930485e-21,
      -17613.9998,
      8.76340177
    ],
    "HCCO": [
      7.44900312,
      0.0010117783,
      302918165e-15,
      -213909391e-18,
      281815208e-22,
      18645.8955,
      -13.0987733,
      4.44514163,
      0.00768702606,
      -52597883e-13,
      184635226e-17,
      -257965931e-21,
      19727.2856,
      3.15875175
    ],
    "HCN": [
      3.481521,
      0.0038174841,
      -153642929e-14,
      30229115e-17,
      -235861473e-22,
      15042.7831,
      3.30702298,
      2.53139665,
      0.00828865751,
      -942673531e-14,
      649076646e-17,
      -184372594e-20,
      15204.3042,
      7.73641055
    ],
    "HCNO": [
      7.12423974,
      0.00161853378,
      231339437e-15,
      -253211924e-18,
      363453797e-22,
      16756.7928,
      -14.8886865,
      2.20954024,
      0.0161806064,
      -159487412e-13,
      773695136e-17,
      -144331449e-20,
      18083.7616,
      10.2968215
    ],
    "HCO": [
      2.44772078,
      0.00565570555,
      -301329556e-14,
      757702524e-18,
      -726129631e-22,
      4311.4916,
      11.5871953,
      3.74218864,
      275844059e-13,
      616298892e-14,
      -589177898e-17,
      173431136e-20,
      4073.30951,
      5.4500709
    ],
    "HCO3": [
      5.04067718,
      0.00866656109,
      -428958277e-14,
      100563376e-17,
      -913599886e-22,
      -17790.2136,
      5.78191516,
      3.79300672,
      0.0114391621,
      -660008362e-14,
      186137482e-17,
      -210212913e-21,
      -17341.0522,
      12.534568
    ],
    "HCO3H": [
      10.0230668,
      0.00443563253,
      -156188514e-14,
      243424395e-18,
      -138391379e-22,
      -38131.3332,
      -23.3590722,
      2.47434199,
      0.0216898607,
      -163512235e-13,
      587745807e-17,
      -818701091e-21,
      -35489.2796,
      17.283547
    ],
    "HCOOH": [
      5.80573302,
      0.00682017393,
      -295480608e-14,
      61434006e-17,
      -506753135e-22,
      -48053.4416,
      -6.42993389,
      1.36256505,
      0.0166938805,
      -111828949e-13,
      366178037e-17,
      -473930912e-21,
      -46453.9011,
      17.617418
    ],
    "HE": [
      2.5,
      740336223e-23,
      -556967416e-26,
      173924876e-29,
      -192673709e-33,
      -745.375,
      0.928723974,
      2.5,
      -40745516e-22,
      598527266e-26,
      -343074982e-29,
      674775716e-33,
      -745.375,
      0.928723974
    ],
    "HNCO": [
      7.29502452,
      488032844e-12,
      874568316e-15,
      -409105701e-18,
      501959355e-22,
      -15272.2297,
      -14.1696888,
      2.99127956,
      0.0108585026,
      -849633812e-14,
      335431054e-17,
      -516583618e-21,
      -13843.3864,
      8.77460657
    ],
    "HNNO": [
      4.88500308,
      0.00560936901,
      -260717829e-14,
      593839036e-18,
      -541495114e-22,
      25892.6738,
      0.601980007,
      2.29344827,
      0.013231589,
      -110140386e-13,
      4714849e-15,
      -811688108e-21,
      26597.5767,
      13.9015974
    ],
    "HNO": [
      2.72673666,
      0.00506770488,
      -261122761e-14,
      638493559e-18,
      -601581004e-22,
      10976.9405,
      9.63912842,
      3.40204752,
      0.0020663233,
      239107502e-14,
      -30669158e-16,
      969122277e-21,
      10855.3846,
      6.45229501
    ],
    "HNO2": [
      3.30359406,
      0.00774006618,
      -391474332e-14,
      947112178e-18,
      -888494507e-22,
      -8657.02544,
      7.10072496,
      1.68890715,
      0.0113282593,
      -690490427e-14,
      20545792e-16,
      -242664314e-21,
      -8075.73815,
      15.8397474
    ],
    "HO2": [
      4.16318067,
      0.00199798265,
      -489192086e-15,
      771153172e-19,
      -730772104e-23,
      44.1348948,
      2.95517985,
      2.85241381,
      0.00540257188,
      -380535043e-14,
      15126817e-16,
      -240354212e-21,
      447.851086,
      9.84483831
    ],
    "HOCN": [
      6.92286755,
      177083687e-12,
      106417841e-14,
      -455819441e-18,
      543563991e-22,
      -3773.75638,
      -10.8544042,
      3.05788784,
      0.00896112848,
      -642222341e-14,
      237993882e-17,
      -348450172e-21,
      -2413.28352,
      9.97681509
    ],
    "HONO": [
      5.88742112,
      0.00349329101,
      -117730803e-14,
      165569378e-18,
      -687715202e-23,
      -11438.6309,
      -5.23866548,
      2.37883184,
      0.0133766411,
      -116174666e-13,
      506705227e-17,
      -86981428e-20,
      -10442.1916,
      12.9185606
    ],
    "HONO2": [
      5.20949091,
      0.0099712344,
      -550725421e-14,
      139250696e-17,
      -133157469e-21,
      -17446.4288,
      -1.35430787,
      0.88570604,
      0.0231736309,
      -206245022e-13,
      908576291e-17,
      -160133609e-20,
      -16313.5971,
      20.672994
    ],
    "IC16-OOQOOH": [
      42.1122112,
      0.111834123,
      -511978482e-13,
      112541459e-16,
      -972533984e-21,
      -78934.3498,
      -180.49557,
      -6.54289827,
      0.248890769,
      -195975996e-12,
      792251073e-16,
      -129392525e-19,
      -65116.2987,
      71.298457
    ],
    "IC16-OQOOH": [
      50.3105902,
      0.0885535013,
      -363077668e-13,
      713747183e-17,
      -556692148e-21,
      -101978.074,
      -230.341253,
      -5.93668664,
      0.230056085,
      -16980077e-11,
      631093809e-16,
      -935730677e-20,
      -84091.4402,
      67.1031189
    ],
    "IC16-QOOH": [
      42.2439745,
      0.102589738,
      -454459633e-13,
      970909447e-17,
      -819911243e-21,
      -62665.4622,
      -186.283114,
      -7.7932336,
      0.239677979,
      -186290047e-12,
      740214614e-16,
      -118323028e-19,
      -48054.5975,
      74.0533932
    ],
    "IC16H33": [
      51.1453588,
      0.0753296743,
      -279263242e-13,
      492908201e-17,
      -344364401e-21,
      -56193.8874,
      -243.048234,
      -8.95216175,
      0.221020633,
      -160372651e-12,
      584427492e-16,
      -845249579e-20,
      -36361.7056,
      76.9829165
    ],
    "IC16H33-OO": [
      39.4749769,
      0.106211481,
      -474108472e-13,
      10202937e-15,
      -867107397e-21,
      -68195.4459,
      -173.182708,
      -7.55515778,
      0.235061165,
      -17979066e-11,
      706503399e-16,
      -112176901e-19,
      -54462.6465,
      71.5084222
    ],
    "IC16H34": [
      47.25246,
      0.0854680758,
      -336612723e-13,
      638202029e-17,
      -482094887e-21,
      -77874.4143,
      -224.18295,
      -9.9361225,
      0.229338723,
      -169388298e-12,
      632906266e-16,
      -942998897e-20,
      -59688.445,
      78.2391931
    ],
    "IC16T-OOQOOH": [
      40.776911,
      0.115135971,
      -536319133e-13,
      119826916e-16,
      -104989886e-20,
      -81682.124,
      -174.509322,
      -7.08781179,
      0.254886986,
      -206643974e-12,
      864411154e-16,
      -146372025e-19,
      -68567.1899,
      71.4786263
    ],
    "IC16T-QOOH": [
      50.3537527,
      0.0872534729,
      -355849544e-13,
      699643634e-17,
      -547405935e-21,
      -68613.4004,
      -232.227161,
      -7.33743336,
      0.235179591,
      -177821606e-12,
      677813303e-16,
      -102885748e-19,
      -50613.7504,
      71.7539151
    ],
    "IC3-OOQOOH": [
      12.3035624,
      0.0279964883,
      -13348291e-12,
      303524083e-17,
      -269271163e-21,
      -22578.4829,
      -27.8550798,
      1.73143843,
      0.06265919,
      -559663668e-13,
      263238068e-16,
      -504151829e-20,
      -19998.8847,
      25.2515831
    ],
    "IC3-QOOH": [
      10.4498043,
      0.022949098,
      -105757759e-13,
      234172678e-17,
      -203669153e-21,
      -5222.99426,
      -24.0008692,
      -0.17111088,
      0.0564007993,
      -500856593e-13,
      230818231e-16,
      -428636527e-20,
      -2525.28181,
      29.7774852
    ],
    "IC3H5CHO": [
      8.9660576,
      0.0220962385,
      -100901145e-13,
      222139279e-17,
      -191792264e-21,
      -17992.0102,
      -21.1939239,
      0.692941977,
      0.0462513206,
      -365372847e-13,
      15091062e-15,
      -254027204e-20,
      -15725.1765,
      21.3235423
    ],
    "IC3H7": [
      8.4877979,
      0.0153259253,
      -476474417e-14,
      392065263e-18,
      24711152e-21,
      5505.07422,
      -21.2719618,
      0.273725246,
      0.0354831588,
      -233143455e-13,
      797881429e-17,
      -113890066e-20,
      8182.8619,
      22.3694223
    ],
    "IC3H7CHO": [
      12.5375038,
      0.0206759832,
      -790606663e-14,
      144761601e-17,
      -105776578e-21,
      -32236.3635,
      -41.0505202,
      -0.344732114,
      0.0493031741,
      -317620591e-13,
      102831688e-16,
      -133293668e-20,
      -27598.7585,
      28.6708279
    ],
    "IC3H7OH": [
      6.28069615,
      0.0259370043,
      -105350747e-13,
      19292136e-16,
      -130183993e-21,
      -36376.8639,
      -6.66341882,
      -0.30057406,
      0.0460324859,
      -335451681e-13,
      136391848e-16,
      -236491132e-20,
      -34652.5711,
      26.8645272
    ],
    "IC3H7OO": [
      7.34738699,
      0.026825233,
      -124179691e-13,
      276645854e-17,
      -24214735e-20,
      -10648.4855,
      -8.92587196,
      1.07341266,
      0.0467426118,
      -361291344e-13,
      153120486e-16,
      -273135173e-20,
      -9067.44395,
      22.7924165
    ],
    "IC4-OQOOH": [
      15.1567879,
      0.0257227734,
      -111020451e-13,
      228943519e-17,
      -18626953e-20,
      -43065.8407,
      -45.9845002,
      0.96927934,
      0.061869292,
      -456369355e-13,
      169539322e-16,
      -252138051e-20,
      -38610.963,
      28.8616666
    ],
    "IC4H10": [
      5.51955794,
      0.0323747266,
      -118655436e-13,
      137455178e-17,
      157073476e-22,
      -19702.581,
      -6.34483422,
      -1.85965328,
      0.055800794,
      -39753719e-12,
      161302002e-16,
      -291200067e-20,
      -17843.0198,
      30.9610166
    ],
    "IC4H7": [
      1.18177121,
      0.0367769036,
      -177031336e-13,
      374786262e-17,
      -29219128e-20,
      13121.4242,
      20.0120538,
      3.86129991,
      0.021465311,
      15107422e-12,
      -275002856e-16,
      108678616e-19,
      12746.2902,
      8.04059744
    ],
    "IC4H8": [
      7.63433967,
      0.0247722696,
      -105415828e-13,
      218152373e-17,
      -180119594e-21,
      -6213.85768,
      -17.2949366,
      0.717301598,
      0.0401434653,
      -233509125e-13,
      692571993e-17,
      -839035734e-21,
      -3723.72397,
      20.1415164
    ],
    "IC4H9OH": [
      14.4537517,
      0.0220810695,
      -75795931e-13,
      11953367e-16,
      -716167606e-22,
      -41582.281,
      -51.3315495,
      -0.545479447,
      0.0554126942,
      -35355947e-12,
      114828752e-16,
      -150044155e-20,
      -36182.5578,
      29.8474183
    ],
    "IC4H9P": [
      7.95880517,
      0.0255088283,
      -862221491e-14,
      809648923e-18,
      402033219e-22,
      3377.59298,
      -16.1084037,
      -1.15582376,
      0.0510042938,
      -353657102e-13,
      132774789e-16,
      -213948724e-20,
      5984.37685,
      31.124482
    ],
    "IC4H9P-OO": [
      8.54295826,
      0.0345220773,
      -159311943e-13,
      353852672e-17,
      -308950056e-21,
      -12953.2173,
      -13.9825068,
      0.700555201,
      0.0572536803,
      -406394585e-13,
      154748862e-16,
      -247133403e-20,
      -10788.714,
      26.3784632
    ],
    "IC4H9T": [
      7.90871688,
      0.025526445,
      -86528405e-13,
      824419704e-18,
      380550653e-22,
      835.470581,
      -17.3299272,
      -1.29900233,
      0.0518342142,
      -36839736e-12,
      142467509e-16,
      -235878979e-20,
      3413.63196,
      30.1901373
    ],
    "IC4H9T-OO": [
      9.11667611,
      0.0341757258,
      -158797345e-13,
      354686464e-17,
      -310976548e-21,
      -16459.1648,
      -19.6564028,
      0.484069009,
      0.0615808277,
      -485048558e-13,
      208088336e-16,
      -373597039e-20,
      -14283.7478,
      23.986033
    ],
    "IC4P-OOQOOH": [
      13.0518446,
      0.0365484801,
      -174274782e-13,
      396741952e-17,
      -352552034e-21,
      -24709.6139,
      -30.4334702,
      1.64511788,
      0.0719181753,
      -585550308e-13,
      252219686e-16,
      -44716507e-19,
      -21766.6784,
      27.5020267
    ],
    "IC4P-QOOH": [
      11.4809469,
      0.0308095616,
      -14193936e-12,
      314755455e-17,
      -274422165e-21,
      -7452.68236,
      -28.0879239,
      -0.193281563,
      0.0653998681,
      -526276099e-13,
      221271466e-16,
      -378916143e-20,
      -4300.64068,
      31.7369695
    ],
    "IC4T-OOQOOH": [
      13.9939782,
      0.0354845222,
      -168915059e-13,
      383671077e-17,
      -340131614e-21,
      -28361.4519,
      -37.0531088,
      1.55094393,
      0.0756233424,
      -654465303e-13,
      299415626e-16,
      -560320657e-20,
      -25275.5794,
      25.6539769
    ],
    "IC4T-QOOH": [
      12.0890742,
      0.0303954175,
      -140883982e-13,
      313822121e-17,
      -274437748e-21,
      -10970.5556,
      -32.8537329,
      -0.426302143,
      0.0698139255,
      -606456912e-13,
      275777451e-16,
      -508536764e-20,
      -7791.65002,
      30.5171096
    ],
    "IC5H10": [
      21.3459841,
      0.00888367161,
      159648418e-14,
      -131808203e-17,
      174600856e-21,
      -12662.0076,
      -89.4699897,
      -1.59634535,
      0.0598666259,
      -40889311e-12,
      144173977e-16,
      -201088244e-20,
      -4402.76906,
      34.6986831
    ],
    "IC8-OOQOOH": [
      34.8314225,
      0.0398146097,
      -143978345e-13,
      242273589e-17,
      -157988116e-21,
      -50122.738,
      -145.334518,
      1.76391327,
      0.117165508,
      -822495e-10,
      288756269e-16,
      -402536985e-20,
      -38813.6498,
      31.9375985
    ],
    "IC8-OQOOH": [
      33.3140926,
      0.0348304479,
      -119632189e-13,
      185711682e-17,
      -107309433e-21,
      -68827.6671,
      -140.834098,
      0.55514898,
      0.108861959,
      -747017874e-13,
      254874628e-16,
      -344492892e-20,
      -57231.0011,
      35.9135548
    ],
    "IC8-QOOH": [
      25.9202581,
      0.0465574275,
      -191478836e-13,
      378861311e-17,
      -297862012e-21,
      -29133.1926,
      -100.455337,
      -0.992411236,
      0.115564272,
      -855006187e-13,
      321444828e-16,
      -48420719e-19,
      -20736.4398,
      41.350418
    ],
    "IC8H16": [
      18.8616063,
      0.0414292819,
      -128170544e-13,
      166806736e-17,
      -658961711e-22,
      -22468.4067,
      -73.8514296,
      -5.35586581,
      0.110622059,
      -869521729e-13,
      369705048e-16,
      -636990285e-20,
      -15687.5145,
      51.1323811
    ],
    "IC8H16O": [
      29.2525449,
      0.0342835226,
      -116024061e-13,
      177291874e-17,
      -100401812e-21,
      -49282.4114,
      -133.818841,
      -8.05235857,
      0.120537635,
      -863892084e-13,
      305924957e-16,
      -426508057e-20,
      -36374.9148,
      66.6033697
    ],
    "IC8H17": [
      26.510423,
      0.0301796816,
      -582184991e-14,
      14208586e-18,
      760110759e-22,
      -18037.3025,
      -114.981197,
      -3.32961207,
      0.108192845,
      -823053435e-13,
      333403496e-16,
      -53694368e-19,
      -8906.25182,
      41.6697269
    ],
    "IC8H17-OO": [
      24.3863221,
      0.0479091863,
      -196116165e-13,
      385759153e-17,
      -301446048e-21,
      -35180.904,
      -93.1491997,
      -0.710506923,
      0.110651259,
      -784323095e-13,
      283662136e-16,
      -413091825e-20,
      -27149.9187,
      39.7240936
    ],
    "IC8H18": [
      20.6155885,
      0.0443694094,
      -135968858e-13,
      175327622e-17,
      -68309088e-21,
      -37658.0614,
      -84.2148793,
      -5.96912081,
      0.12087217,
      -961538217e-13,
      413489289e-16,
      -718982936e-20,
      -30267.5122,
      52.7954202
    ],
    "IC8T-QOOH": [
      25.9202581,
      0.0465574275,
      -191478836e-13,
      378861311e-17,
      -297862012e-21,
      -29133.1926,
      -100.455337,
      -0.992411236,
      0.115564272,
      -855006187e-13,
      321444828e-16,
      -48420719e-19,
      -20736.4398,
      41.350418
    ],
    "INDENE": [
      16.5348693,
      0.0281361431,
      -782674558e-14,
      233936401e-18,
      115234436e-21,
      11327.8665,
      -66.6478053,
      -7.32592199,
      0.0939590155,
      -759193723e-13,
      315408912e-16,
      -528251639e-20,
      18247.496,
      57.3325203
    ],
    "INDENYL": [
      16.3412613,
      0.0301210631,
      -129067938e-13,
      263187626e-17,
      -211554314e-21,
      29105.4096,
      -68.1510017,
      -5.8171482,
      0.0855170869,
      -648405661e-13,
      242709481e-16,
      -359265929e-20,
      36196.1007,
      49.1650485
    ],
    "KEA3B3": [
      15.6495498,
      0.0147904715,
      -684032429e-14,
      149167145e-17,
      -126830372e-21,
      -47421.3138,
      -49.2482738,
      1.41905665,
      0.0527384532,
      -44788306e-12,
      183574411e-16,
      -293779198e-20,
      -43152.1659,
      25.175598
    ],
    "KEA3G2": [
      15.2972938,
      0.0147507483,
      -665907582e-14,
      142291765e-17,
      -11902751e-20,
      -50322.8961,
      -47.1892678,
      2.76516864,
      0.0473017226,
      -383645703e-13,
      151482399e-16,
      -234716424e-20,
      -46463.0015,
      18.6821429
    ],
    "KEHYBU1": [
      15.0812003,
      0.0299746636,
      -137944087e-13,
      303171375e-17,
      -260935208e-21,
      -63417.8095,
      -42.7051069,
      -4.53521777,
      0.0953627237,
      -955294839e-13,
      484400888e-16,
      -972101335e-20,
      -58709.8692,
      55.5092666
    ],
    "KEHYMB": [
      12.8585854,
      0.0305267697,
      -105263784e-13,
      170287735e-17,
      -106411281e-21,
      -60491.5273,
      -34.2459469,
      -2.28352158,
      0.0810004596,
      -736184908e-13,
      367540509e-16,
      -74087391e-19,
      -56857.4216,
      41.5666988
    ],
    "KHDECA": [
      11.6022418,
      0.0357303662,
      -134415883e-13,
      250437459e-17,
      -189510289e-21,
      -36382.1557,
      -49.8532958,
      -8.02402159,
      0.0895009509,
      -686853396e-13,
      277298318e-16,
      -45089379e-19,
      -30651.2867,
      52.2593733
    ],
    "KHMLIN1": [
      61.8941987,
      0.0822994739,
      -310180668e-13,
      538913026e-17,
      -362606874e-21,
      -97997.466,
      -272.2775,
      -3.09268744,
      0.236114589,
      -167540358e-12,
      592440776e-16,
      -832931507e-20,
      -76031.8984,
      75.3471329
    ],
    "LC6H5": [
      12.3076076,
      0.0168261952,
      -651181371e-14,
      121158891e-17,
      -899428218e-22,
      58942.5072,
      -35.5373248,
      0.167614175,
      0.0594226632,
      -62559798e-12,
      339881879e-16,
      -727779348e-20,
      61710.4257,
      24.6218079
    ],
    "LC6H6": [
      12.8863876,
      0.0190072461,
      -730992558e-14,
      131482495e-17,
      -921385789e-22,
      35536.4843,
      -40.9021933,
      -1.05889383,
      0.0636321466,
      -608598062e-13,
      298747613e-16,
      -580412585e-20,
      39022.8046,
      29.4875281
    ],
    "MACRIL": [
      9.14034166,
      0.0210870489,
      -742259222e-14,
      125044332e-17,
      -83306406e-21,
      -41282.7789,
      -15.0267978,
      -1.13135763,
      0.0581021815,
      -574430417e-13,
      312927553e-16,
      -684959289e-20,
      -39002.4617,
      35.6001684
    ],
    "MB": [
      12.4284224,
      0.0357133446,
      -161592883e-13,
      352094113e-17,
      -302693515e-21,
      -60770.2348,
      -36.522069,
      2.7783132,
      0.0571580318,
      -340298609e-13,
      101396717e-16,
      -122196165e-20,
      -57296.1955,
      15.7063351
    ],
    "MCPTD": [
      11.4154101,
      0.0270830264,
      -113419491e-13,
      230157826e-17,
      -186056675e-21,
      6230.40748,
      -41.0347479,
      -6.52219774,
      0.0736742157,
      -567229776e-13,
      219470452e-16,
      -337525585e-20,
      11755.1907,
      53.2489849
    ],
    "MCROT": [
      11.3738847,
      0.0261318034,
      -874855171e-14,
      135831508e-17,
      -80017502e-21,
      -46306.2146,
      -25.4801461,
      0.272064727,
      0.0610981657,
      -500474047e-13,
      23037503e-15,
      -434757418e-20,
      -43486.3523,
      30.7332406
    ],
    "MCYC6": [
      16.7194568,
      0.0436180644,
      -187773363e-13,
      392059023e-17,
      -326702984e-21,
      -29186.63,
      -74.0611877,
      -10.1006358,
      0.10321827,
      -684441744e-13,
      223157154e-16,
      -288158149e-20,
      -19531.3967,
      71.0947481
    ],
    "MCYC6-OOQOOH": [
      31.4587613,
      0.0312961497,
      -106604211e-13,
      162769455e-17,
      -915073605e-22,
      -40852.6671,
      -140.718316,
      -4.29317081,
      0.112091476,
      -791310369e-13,
      274170037e-16,
      -373406515e-20,
      -28196.4832,
      52.1777121
    ],
    "MCYC6-OQOOH": [
      28.9245833,
      0.0289702632,
      -100807411e-13,
      160861341e-17,
      -981376976e-22,
      -59285.8085,
      -129.605491,
      -5.14358533,
      0.104677305,
      -731699422e-13,
      249749842e-16,
      -334346697e-20,
      -47021.2678,
      54.7785441
    ],
    "MCYC6-QOOH": [
      29.3659891,
      0.0265374271,
      -830522001e-14,
      112153176e-17,
      -523348938e-22,
      -22859.9204,
      -133.867706,
      -7.82169678,
      0.109176729,
      -771713049e-13,
      266274891e-16,
      -359482897e-20,
      -9472.35352,
      67.3998075
    ],
    "MCYC6T-OOQOOH": [
      31.4587613,
      0.0312961497,
      -106604211e-13,
      162769455e-17,
      -915073605e-22,
      -40852.6671,
      -140.718316,
      -4.29317081,
      0.112091476,
      -791310369e-13,
      274170037e-16,
      -373406515e-20,
      -28196.4832,
      52.1777121
    ],
    "MCYC6T-QOOH": [
      29.3659891,
      0.0265374271,
      -830522001e-14,
      112153176e-17,
      -523348938e-22,
      -22859.9204,
      -133.867706,
      -7.82169678,
      0.109176729,
      -771713049e-13,
      266274891e-16,
      -359482897e-20,
      -9472.35352,
      67.3998075
    ],
    "MD": [
      33.2942906,
      0.0602278032,
      -243433721e-13,
      477523421e-17,
      -375629873e-21,
      -86153.8195,
      -140.508531,
      1.40263274,
      0.131098154,
      -834019977e-13,
      266487992e-16,
      -341362502e-20,
      -74672.8226,
      32.095774
    ],
    "MDKETO": [
      29.8411867,
      0.0716595718,
      -312595573e-13,
      671204593e-17,
      -57352212e-20,
      -108207.342,
      -107.784039,
      3.72296254,
      0.145232034,
      -108976947e-12,
      431990835e-16,
      -699729634e-20,
      -100789.766,
      27.3798301
    ],
    "MEFU2": [
      5.16398169,
      0.032952908,
      -168209195e-13,
      403716052e-17,
      -355511369e-21,
      -13184.167,
      -2.6761671,
      -3.74149804,
      0.0612242723,
      -504773055e-13,
      218447722e-16,
      -388876765e-20,
      -10939.9861,
      42.3457855
    ],
    "MEK": [
      10.0996674,
      0.0222850926,
      -824112797e-14,
      142760366e-17,
      -977654881e-22,
      -34027.0944,
      -25.5002808,
      1.67138626,
      0.0410146063,
      -23849056e-12,
      720831776e-17,
      -900642446e-21,
      -30992.9132,
      20.115335
    ],
    "MEOLE": [
      59.943101,
      0.0858698597,
      -29767597e-12,
      464267973e-17,
      -270021412e-21,
      -105323.856,
      -271.321378,
      -0.024034261,
      0.21913016,
      -140817847e-12,
      457724021e-16,
      -598248285e-20,
      -83735.6873,
      53.2332675
    ],
    "MLIN1": [
      60.2396272,
      0.0758944997,
      -257645248e-13,
      383449043e-17,
      -203418185e-21,
      -77446.8689,
      -275.096818,
      -2.53501097,
      0.216173021,
      -143316358e-12,
      476154339e-16,
      -631807509e-20,
      -54973.5485,
      64.3028989
    ],
    "MLINO": [
      60.5955674,
      0.0800185064,
      -272219227e-13,
      409057977e-17,
      -22203654e-20,
      -91617.5365,
      -276.065905,
      -1.22142744,
      0.217389606,
      -141697839e-12,
      464890673e-16,
      -611071537e-20,
      -69363.4183,
      58.5005668
    ],
    "MPA": [
      47.6347765,
      0.0891363271,
      -314080949e-13,
      473916072e-17,
      -233379401e-21,
      -108404.908,
      -213.800451,
      -6.71212905,
      0.227599781,
      -163698019e-12,
      60913226e-15,
      -917829426e-20,
      -91339.9797,
      72.9065166
    ],
    "MSTEA": [
      55.7521885,
      0.0944092844,
      -321197984e-13,
      465296638e-17,
      -212922185e-21,
      -117225.837,
      -254.579461,
      -7.5235356,
      0.253593496,
      -182293583e-12,
      676189138e-16,
      -101132284e-19,
      -97104.1567,
      80.0324369
    ],
    "MSTEAKETO": [
      61.3348222,
      0.0980436966,
      -377033724e-13,
      680817282e-17,
      -483388457e-21,
      -142870.185,
      -270.834349,
      -0.417722454,
      0.249583683,
      -177157348e-12,
      638445637e-16,
      -923130116e-20,
      -122738.855,
      57.2570421
    ],
    "MTBE": [
      9.85250854,
      0.0401896195,
      -166704212e-13,
      310158953e-17,
      -211537799e-21,
      -40927.4217,
      -26.1941109,
      -1.85856423,
      0.0756777188,
      -569978068e-13,
      23468956e-15,
      -406899357e-20,
      -37835.6985,
      33.556411
    ],
    "MTBE-O": [
      15.1388759,
      0.029997938,
      -122799224e-13,
      2461008e-15,
      -197690794e-21,
      -53987.9921,
      -55.7113238,
      -5.03717524,
      0.0830928094,
      -64676177e-12,
      254418214e-16,
      -397742985e-20,
      -47854.4725,
      50.0743811
    ],
    "MTBE-OO": [
      16.4806404,
      0.0348147986,
      -147688716e-13,
      300165535e-17,
      -241352124e-21,
      -35967.854,
      -50.2874924,
      2.84930352,
      0.0678604638,
      -448103854e-13,
      151396407e-16,
      -208044082e-20,
      -31469.5128,
      22.302065
    ],
    "MTBE-OOQOOH": [
      17.0053287,
      0.0431260455,
      -199573148e-13,
      444658587e-17,
      -389314847e-21,
      -46430.2952,
      -46.1328184,
      4.65469152,
      0.0794514489,
      -600220979e-13,
      240861854e-16,
      -399953536e-20,
      -43070.9219,
      17.2494984
    ],
    "MTBE-OQOOH": [
      26.0727575,
      0.0216561735,
      -750837024e-14,
      118094191e-17,
      -695946679e-22,
      -66076.2157,
      -103.020582,
      2.39248713,
      0.0757825058,
      -539023694e-13,
      188548464e-16,
      -259443816e-20,
      -57788.1211,
      24.4748876
    ],
    "MTBE-QOOH": [
      15.4436171,
      0.0366620452,
      -153964703e-13,
      318866664e-17,
      -264826209e-21,
      -28618.7067,
      -42.5445321,
      1.39866729,
      0.0792224991,
      -637606224e-13,
      276150061e-16,
      -489102686e-20,
      -24910.8399,
      29.1135557
    ],
    "N": [
      2.43583682,
      127743369e-12,
      -858132365e-16,
      21326814e-18,
      -123433516e-23,
      56123.6145,
      4.53259076,
      2.50515554,
      -262982346e-13,
      425547663e-16,
      -262168907e-19,
      536895716e-23,
      56098.6597,
      4.15742338
    ],
    "N1C4H9OH": [
      11.9078661,
      0.0267959929,
      -107944841e-13,
      210106148e-17,
      -163536607e-21,
      -39522.1179,
      -35.7389868,
      0.0773360084,
      0.0530860597,
      -32702873e-12,
      102152796e-16,
      -129051135e-20,
      -35263.1271,
      28.2903098
    ],
    "N2": [
      2.71287897,
      0.00190359754,
      -854297556e-15,
      184170938e-18,
      -154715988e-22,
      -840.225273,
      7.15926558,
      3.85321336,
      -0.00244053349,
      535160392e-14,
      -375608397e-17,
      92268433e-20,
      -1079.6955,
      1.60217419
    ],
    "N2C4H9OH": [
      13.9850075,
      0.023576822,
      -873106106e-14,
      151546163e-17,
      -102847459e-21,
      -42405.3999,
      -48.370285,
      0.111912948,
      0.0544059211,
      -34421977e-12,
      110306157e-16,
      -142439663e-20,
      -37411.0858,
      26.713797
    ],
    "N2H2": [
      1.94872574,
      0.00902206572,
      -448167913e-14,
      107159624e-17,
      -996387287e-22,
      24685.0174,
      12.7074554,
      2.44745784,
      0.0068769814,
      -102186571e-14,
      -140855675e-17,
      567069064e-21,
      24592.2533,
      10.3375547
    ],
    "N2H3": [
      5.06961797,
      0.00618061831,
      -187909018e-14,
      233273638e-18,
      -803110073e-23,
      16347.7734,
      -4.00218491,
      1.71415249,
      0.0145171785,
      -964607174e-14,
      344941507e-17,
      -507431944e-21,
      17428.2333,
      13.7839838
    ],
    "N2H4": [
      4.91914378,
      0.00971187969,
      -362925367e-14,
      636530934e-18,
      -428508947e-22,
      9363.04606,
      -2.64395648,
      0.360425651,
      0.0254315974,
      -239564748e-13,
      123188419e-16,
      -256059034e-20,
      10420.6687,
      20.0258283
    ],
    "N2O": [
      5.52129143,
      0.00146645965,
      -304694075e-15,
      -187106858e-19,
      850389041e-23,
      7813.12268,
      -6.17451657,
      2.68521969,
      0.00834178508,
      -655498992e-14,
      250666137e-17,
      -374128239e-21,
      8749.02635,
      8.9281248
    ],
    "NC10-OOQOOH": [
      40.8087723,
      0.0496339543,
      -181420129e-13,
      312006732e-17,
      -211175642e-21,
      -56543.2959,
      -173.81102,
      2.62701325,
      0.134482308,
      -88848974e-12,
      293078307e-16,
      -3848365e-18,
      -42797.8627,
      32.8366249
    ],
    "NC10-OQOOH": [
      29.9089271,
      0.0587016386,
      -237959516e-13,
      463914804e-17,
      -359659107e-21,
      -70724.6459,
      -114.602343,
      2.87865509,
      0.124229571,
      -83366799e-12,
      287081773e-16,
      -400648172e-20,
      -61804.6561,
      29.3391873
    ],
    "NC10-QOOH": [
      36.7714538,
      0.0456787199,
      -156929249e-13,
      249979255e-17,
      -153467299e-21,
      -37289.7414,
      -154.708984,
      0.846533635,
      0.125511876,
      -822205548e-13,
      271396555e-16,
      -357567048e-20,
      -24356.7701,
      39.7241784
    ],
    "NC10H19": [
      9.8828739,
      0.028627535,
      -123662428e-13,
      258308509e-17,
      -214520963e-21,
      7142.11639,
      -28.1379758,
      -0.961360661,
      0.0527258341,
      -324481586e-13,
      100208317e-16,
      -124754133e-20,
      11046.0408,
      30.5532839
    ],
    "NC10H20": [
      28.2971791,
      0.0489478938,
      -182737062e-13,
      323575201e-17,
      -226811843e-21,
      -31253.4582,
      -116.784058,
      -2.3141771,
      0.11697313,
      -749614029e-13,
      242311952e-16,
      -314284562e-20,
      -20233.37,
      48.8909878
    ],
    "NC10H21": [
      26.3212692,
      0.0552219738,
      -221266526e-13,
      433498891e-17,
      -342316503e-21,
      -21017.5171,
      -103.192977,
      -1.81057271,
      0.117737178,
      -742226562e-13,
      23629805e-15,
      -302215208e-20,
      -10890.054,
      49.0624204
    ],
    "NC10H21-OO": [
      32.377983,
      0.0524885367,
      -193370131e-13,
      335369674e-17,
      -228448799e-21,
      -40644.7276,
      -132.098961,
      1.67478189,
      0.120717872,
      -761947929e-13,
      244121337e-16,
      -315323171e-20,
      -29591.5752,
      34.0731686
    ],
    "NC10H22": [
      29.2878918,
      0.052992099,
      -198404553e-13,
      35561637e-16,
      -254281184e-21,
      -45623.2379,
      -122.752047,
      -2.17870143,
      0.122917862,
      -781119243e-13,
      251381893e-16,
      -325178473e-20,
      -34295.2643,
      47.55172
    ],
    "NC10MOOH": [
      27.3219585,
      0.0355870996,
      -124650774e-13,
      200089265e-17,
      -121997682e-21,
      -48463.4178,
      -112.262056,
      1.16215154,
      0.0940447688,
      -61451951e-12,
      202455383e-16,
      -267013255e-20,
      -39098.2069,
      29.1745387
    ],
    "NC12-OOQOOH": [
      46.8889668,
      0.0584439691,
      -20949158e-12,
      349897609e-17,
      -227324946e-21,
      -64548.7872,
      -203.262107,
      2.75932352,
      0.156509843,
      -10267072e-11,
      337662211e-16,
      -443110898e-20,
      -48662.1157,
      35.5767286
    ],
    "NC12-OQOOH": [
      28.976254,
      0.085193506,
      -432222039e-13,
      103184896e-16,
      -952873634e-21,
      -76678.4457,
      -107.151303,
      4.95723376,
      0.138569107,
      -87701871e-12,
      267924404e-16,
      -324092235e-20,
      -68031.5984,
      22.8446447
    ],
    "NC12-QOOH": [
      42.8763735,
      0.0551011626,
      -190602563e-13,
      305791504e-17,
      -189217484e-21,
      -45397.3988,
      -184.606456,
      0.527389362,
      0.149210016,
      -974843011e-13,
      321038575e-16,
      -422337617e-20,
      -30151.7645,
      44.5950809
    ],
    "NC12H25": [
      31.7005579,
      0.0661544325,
      -266295229e-13,
      521804509e-17,
      -410998518e-21,
      -28852.5898,
      -131.607624,
      -2.06085145,
      0.141179787,
      -891506513e-13,
      283740186e-16,
      -362710595e-20,
      -16698.4825,
      51.116166
    ],
    "NC12H25-OO": [
      38.2754174,
      0.0623046009,
      -229785783e-13,
      399220438e-17,
      -272630412e-21,
      -48670.3034,
      -160.846136,
      1.39669302,
      0.144257322,
      -912725124e-13,
      29286254e-15,
      -378569287e-20,
      -35393.9626,
      38.7492139
    ],
    "NC12H26": [
      36.1414095,
      0.0611045883,
      -224641073e-13,
      39318244e-16,
      -273349362e-21,
      -54035.9186,
      -156.83196,
      -2.66627705,
      0.147343892,
      -943301934e-13,
      305488933e-16,
      -397016449e-20,
      -40065.1514,
      53.203335
    ],
    "NC16-OOQOOH": [
      58.3925916,
      0.0787490301,
      -28698724e-12,
      490944e-14,
      -329403315e-21,
      -80506.1539,
      -259.209019,
      2.14519035,
      0.203743255,
      -132860578e-12,
      434879045e-16,
      -568752339e-20,
      -60257.0894,
      45.2136503
    ],
    "NC16-OQOOH": [
      48.8441297,
      0.0847833151,
      -317577492e-13,
      556702742e-17,
      -382331487e-21,
      -95080.8904,
      -207.202631,
      1.75040694,
      0.196247748,
      -130690678e-12,
      445938236e-16,
      -615552619e-20,
      -79163.2121,
      44.7087787
    ],
    "NC16-QOOH": [
      54.9634696,
      0.0774662171,
      -271265902e-13,
      436953904e-17,
      -268719606e-21,
      -84994.9222,
      -246.825964,
      0.0802842616,
      0.199428851,
      -128762119e-12,
      420123273e-16,
      -549688464e-20,
      -65236.9755,
      50.2132837
    ],
    "NC16H33": [
      46.6278372,
      0.0800212238,
      -303236333e-13,
      555903616e-17,
      -409822553e-21,
      -46154.521,
      -204.019481,
      -3.22413374,
      0.190803381,
      -122642098e-12,
      397510601e-16,
      -515871477e-20,
      -28207.8115,
      65.7897858
    ],
    "NC16H33-OO": [
      50.0344484,
      0.0820070153,
      -303042993e-13,
      5280167e-15,
      -36202284e-20,
      -64704.5872,
      -218.137205,
      0.865096715,
      0.191272241,
      -121358654e-12,
      390040022e-16,
      -504588884e-20,
      -47003.6206,
      47.9775838
    ],
    "NC16H34": [
      49.8210237,
      0.0773881688,
      -277557896e-13,
      469678103e-17,
      -312959243e-21,
      -70851.4664,
      -224.842855,
      -3.64057977,
      0.196191732,
      -126758759e-12,
      413645475e-16,
      -540570458e-20,
      -51605.2891,
      64.5024955
    ],
    "NC3-OOQOOH": [
      11.1683562,
      0.0295822139,
      -142526305e-13,
      327126849e-17,
      -292476812e-21,
      -20028.1219,
      -20.6289848,
      2.57588692,
      0.0568598942,
      -467260594e-13,
      204529769e-16,
      -370154594e-20,
      -17862.8196,
      22.8105329
    ],
    "NC3-QOOH": [
      12.9748618,
      0.017643387,
      -716935406e-14,
      142696153e-17,
      -114477043e-21,
      -5864.11825,
      -36.7690498,
      1.55643299,
      0.0430176732,
      -283145926e-13,
      925853134e-17,
      -120219507e-20,
      -1753.48388,
      25.0298688
    ],
    "NC3H7": [
      8.44692954,
      0.0152881013,
      -472394213e-14,
      372053769e-18,
      277825399e-22,
      7244.99466,
      -19.7652064,
      0.540130268,
      0.0344560996,
      -221493951e-13,
      741264082e-17,
      -103897307e-20,
      9854.23842,
      22.3400592
    ],
    "NC3H7O": [
      9.66226461,
      0.0180582994,
      -68075258e-13,
      122634214e-17,
      -879552073e-22,
      -9729.42766,
      -25.5365895,
      -0.552121379,
      0.0407569349,
      -257230554e-13,
      823209384e-17,
      -106097628e-20,
      -6052.2487,
      29.7457983
    ],
    "NC3H7OH": [
      10.3578665,
      0.01878345,
      -654155125e-14,
      106792692e-17,
      -67910158e-21,
      -36005.4458,
      -28.9224528,
      0.234636347,
      0.0412795171,
      -252882738e-13,
      80111575e-16,
      -103224774e-20,
      -32361.0829,
      25.8665808
    ],
    "NC3H7OO": [
      9.25591855,
      0.0227563801,
      -954934453e-14,
      192559464e-17,
      -15394667e-20,
      -9340.05086,
      -18.6388081,
      1.92964396,
      0.0405170458,
      -256954042e-13,
      844925513e-17,
      -114238008e-20,
      -6922.38025,
      20.3750491
    ],
    "NC4-OOQOOH": [
      15.1474113,
      0.0337812811,
      -158996825e-13,
      357608795e-17,
      -314486517e-21,
      -28569.8876,
      -42.4732203,
      1.10123476,
      0.079459904,
      -716053202e-13,
      337688455e-16,
      -645122586e-20,
      -25114.5282,
      28.1992197
    ],
    "NC4-OQOOH": [
      11.8153445,
      0.0320093755,
      -153334981e-13,
      350316407e-17,
      -312136547e-21,
      -42766.0549,
      -27.3083214,
      2.519466,
      0.0599669047,
      -468645461e-13,
      193082006e-16,
      -328300808e-20,
      -40293.3512,
      20.1899074
    ],
    "NC4-QOOH": [
      18.3774568,
      0.0183354725,
      -62392338e-13,
      966797421e-18,
      -561281943e-22,
      -12913.5491,
      -65.5986639,
      1.19976578,
      0.0573756794,
      -395121374e-13,
      1357017e-14,
      -184637998e-20,
      -6867.00189,
      26.9845517
    ],
    "NC4H10": [
      15.4355362,
      0.0156272553,
      -314852e-11,
      -594424182e-19,
      532964635e-22,
      -22845.5262,
      -60.2417835,
      -1.20836758,
      0.0526137081,
      -33970564e-12,
      113561294e-16,
      -153219963e-20,
      -16853.7208,
      29.8384958
    ],
    "NC4H8": [
      2.98709814,
      0.0325282541,
      -146250479e-13,
      294136385e-17,
      -214960813e-21,
      -2501.11901,
      10.3971909,
      -1.05707773,
      0.0463544964,
      -323509995e-13,
      130416212e-16,
      -237313546e-20,
      -1554.78186,
      30.5429525
    ],
    "NC4H9-OO": [
      8.96630114,
      0.0341074657,
      -157641e-10,
      350715782e-17,
      -306662916e-21,
      -14084.7395,
      -15.8347447,
      0.944281655,
      0.0584166156,
      -433881341e-13,
      174586902e-16,
      -294899859e-20,
      -11966.9263,
      25.0940293
    ],
    "NC4H9P": [
      3.94763005,
      0.0316286394,
      -112984867e-13,
      111637452e-17,
      554031592e-22,
      6055.54723,
      7.76350069,
      -0.276188363,
      0.049413138,
      -393792739e-13,
      208221901e-16,
      -513033778e-20,
      6858.07273,
      27.9243294
    ],
    "NC4H9S": [
      3.40122925,
      0.0320901864,
      -112255471e-13,
      971712129e-18,
      830726251e-22,
      4662.83102,
      10.529164,
      0.236336476,
      0.0469837994,
      -375083937e-13,
      215857094e-16,
      -597986776e-20,
      5200.86279,
      25.2835872
    ],
    "NC5-OOQOOH": [
      15.4638476,
      0.0430531975,
      -204284728e-13,
      463174721e-17,
      -410271992e-21,
      -31741.3365,
      -43.1406917,
      1.43265566,
      0.087245928,
      -726246113e-13,
      32031295e-15,
      -580388375e-20,
      -28177.4138,
      27.9053907
    ],
    "NC5-OQOOH": [
      14.217263,
      0.0377707683,
      -176257936e-13,
      393443034e-17,
      -343954252e-21,
      -46506.105,
      -38.5369191,
      2.52749929,
      0.0709332187,
      -529049961e-13,
      206149043e-16,
      -33014851e-19,
      -43209.5916,
      21.8759162
    ],
    "NC5-QOOH": [
      13.6538194,
      0.037786002,
      -175151081e-13,
      390394425e-17,
      -34170856e-20,
      -14387.9859,
      -39.4678819,
      -0.574283055,
      0.0815647789,
      -680290814e-13,
      29808546e-15,
      -532336273e-20,
      -10688.6793,
      32.9074336
    ],
    "NC5H10": [
      11.1929736,
      0.0282582223,
      -113863841e-13,
      222526491e-17,
      -174280993e-21,
      -10248.3443,
      -33.9253533,
      -0.689551964,
      0.0546638348,
      -333910611e-13,
      103751453e-16,
      -130620882e-20,
      -5970.63504,
      30.3853541
    ],
    "NC5H10-O": [
      14.0073101,
      0.0304405284,
      -135854526e-13,
      290305354e-17,
      -244985844e-21,
      -25545.5866,
      -52.5239383,
      -3.79263098,
      0.069995953,
      -465483064e-13,
      151115179e-16,
      -19406059e-19,
      -19137.6078,
      43.8130562
    ],
    "NC5H11": [
      6.93193785,
      0.0375440987,
      -165478566e-13,
      353633643e-17,
      -299976701e-21,
      -1730.87074,
      -8.8871067,
      -3.57520449,
      0.0608933039,
      -360055276e-13,
      107428812e-16,
      -13008857e-19,
      2051.7005,
      47.9797395
    ],
    "NC5H11OOH": [
      16.6988185,
      0.0344172712,
      -143139761e-13,
      285300849e-17,
      -225350876e-21,
      -37375.5763,
      -57.5775303,
      0.0624289371,
      0.0752427671,
      -518834508e-13,
      182188468e-16,
      -258207455e-20,
      -31952.1133,
      30.8116402
    ],
    "NC5H12": [
      21.2559082,
      0.0149866375,
      -156738312e-14,
      -484518435e-18,
      900436509e-22,
      -28066.8702,
      -90.5497671,
      -1.97000865,
      0.0665997861,
      -445783403e-13,
      154454657e-16,
      -212245414e-20,
      -19705.5401,
      35.1537401
    ],
    "NC5H12OO": [
      10.6544848,
      0.0416170555,
      -193382868e-13,
      432113942e-17,
      -379088223e-21,
      -19865.2039,
      -25.0234586,
      0.31966488,
      0.0734165014,
      -560299551e-13,
      231373796e-16,
      -399759595e-20,
      -17178.1508,
      27.5475609
    ],
    "NC5H9-3": [
      9.8828739,
      0.028627535,
      -123662428e-13,
      258308509e-17,
      -214520963e-21,
      7142.11639,
      -28.1379758,
      -0.961360661,
      0.0527258341,
      -324481586e-13,
      100208317e-16,
      -124754133e-20,
      11046.0408,
      30.5532839
    ],
    "NC6H12": [
      28.0951654,
      0.00524635942,
      643208138e-14,
      -319131389e-17,
      401093698e-21,
      -17976.7847,
      -124.497292,
      -1.85358315,
      0.0725469181,
      -502818725e-13,
      180498673e-16,
      -258221827e-20,
      -7315.03024,
      37.2569567
    ],
    "NC7-OOQOOH": [
      22.4694069,
      0.0429307086,
      -168910162e-13,
      318431082e-17,
      -238592446e-21,
      -45896.294,
      -79.3472401,
      2.87430503,
      0.0893096479,
      -580557552e-13,
      194228666e-16,
      -264074567e-20,
      -39273.1495,
      25.4699082
    ],
    "NC7-OQOOH": [
      22.7584121,
      0.0425741258,
      -17795001e-12,
      355398722e-17,
      -280791799e-21,
      -59532.9656,
      -81.9251639,
      2.24997334,
      0.0916961348,
      -61916566e-12,
      211673864e-16,
      -29175282e-19,
      -52683.147,
      27.53341
    ],
    "NC7-QOOH": [
      36.7777501,
      0.0243465392,
      -165378817e-13,
      522869888e-17,
      -585107382e-21,
      -28454.9794,
      -165.05964,
      -2.87358792,
      0.112460624,
      -899662853e-13,
      324244039e-16,
      -436228864e-20,
      -14180.4977,
      49.541673
    ],
    "NC7H13": [
      9.8828739,
      0.028627535,
      -123662428e-13,
      258308509e-17,
      -214520963e-21,
      7142.11639,
      -28.1379758,
      -0.961360661,
      0.0527258341,
      -324481586e-13,
      100208317e-16,
      -124754133e-20,
      11046.0408,
      30.5532839
    ],
    "NC7H13OOH": [
      27.3219585,
      0.0355870996,
      -124650774e-13,
      200089265e-17,
      -121997682e-21,
      -48463.4178,
      -112.262056,
      1.16215154,
      0.0940447688,
      -61451951e-12,
      202455383e-16,
      -267013255e-20,
      -39098.2069,
      29.1745387
    ],
    "NC7H14": [
      18.2668105,
      0.035960789,
      -137346402e-13,
      25222905e-16,
      -18524824e-20,
      -18749.7345,
      -69.2309265,
      -1.22797309,
      0.0792825302,
      -498360912e-13,
      158931983e-16,
      -204231877e-20,
      -11731.6124,
      36.2789089
    ],
    "NC7H14O": [
      13.7609323,
      0.0499379374,
      -221152348e-13,
      472010363e-17,
      -398160014e-21,
      -39791.7916,
      -46.7908592,
      -7.39181743,
      0.106723843,
      -792822536e-13,
      302981881e-16,
      -468978493e-20,
      -33488.2722,
      63.6941424
    ],
    "NC7H15": [
      15.8938298,
      0.0432851195,
      -183429598e-13,
      381524632e-17,
      -318291961e-21,
      -8335.89206,
      -53.4387877,
      -1.03213606,
      0.080898377,
      -496873411e-13,
      154242764e-16,
      -193065725e-20,
      -2242.54435,
      38.1680705
    ],
    "NC7H15-OO": [
      26.8006146,
      0.0335780866,
      -117982179e-13,
      189992229e-17,
      -116218734e-21,
      -23338.892,
      -106.550436,
      1.92333992,
      0.0894820746,
      -589083201e-13,
      195441553e-16,
      -259434135e-20,
      -14482.5822,
      27.8126029
    ],
    "NC7H15OOH": [
      27.3219585,
      0.0355870996,
      -124650774e-13,
      200089265e-17,
      -121997682e-21,
      -48463.4178,
      -112.262056,
      1.16215154,
      0.0940447688,
      -61451951e-12,
      202455383e-16,
      -267013255e-20,
      -39098.2069,
      29.1745387
    ],
    "NC7H16": [
      31.069612,
      0.0173458864,
      -457663884e-15,
      -106280964e-17,
      159098857e-21,
      -37654.1592,
      -140.920497,
      -2.76912812,
      0.0925430866,
      -631219974e-13,
      221462028e-16,
      -306437509e-20,
      -25472.2127,
      42.221823
    ],
    "NCO": [
      5.80612871,
      0.00129457396,
      -296387145e-15,
      -445669057e-20,
      600806513e-23,
      17005.3704,
      -6.33800183,
      2.87969597,
      0.00818029805,
      -637202605e-14,
      23781468e-16,
      -344374801e-21,
      18000.3575,
      9.33319238
    ],
    "NEOC5-OOQOOH": [
      25.3088279,
      0.0246008468,
      -83858487e-13,
      128446216e-17,
      -72549202e-21,
      -35266.2111,
      -98.869315,
      2.93992987,
      0.0743095092,
      -49809734e-12,
      166266419e-16,
      -22034075e-19,
      -27213.4078,
      22.1958278
    ],
    "NEOC5-OQOOH": [
      22.4459936,
      0.0237621277,
      -883881473e-14,
      153830075e-17,
      -104514815e-21,
      -50388.0249,
      -87.7405631,
      1.27283562,
      0.0738761111,
      -533186817e-13,
      190845993e-16,
      -270012112e-20,
      -43231.4975,
      25.517845
    ],
    "NEOC5-QOOH": [
      18.619753,
      0.0285111424,
      -113969334e-13,
      218137254e-17,
      -165768942e-21,
      -15039.1446,
      -67.4883738,
      1.4807031,
      0.0705701605,
      -501015514e-13,
      180114821e-16,
      -259369986e-20,
      -9451.81437,
      23.5714319
    ],
    "NEOC5H10-O": [
      12.9296103,
      0.0316150611,
      -135584975e-13,
      281753187e-17,
      -232686285e-21,
      -23793.3924,
      -48.8968548,
      -6.91462638,
      0.0856129839,
      -686584188e-13,
      278061583e-16,
      -448245268e-20,
      -17959.1868,
      54.4853542
    ],
    "NEOC5H11": [
      14.3276289,
      0.0266845577,
      -102158264e-13,
      186929104e-17,
      -135803312e-21,
      -2942.16421,
      -51.5145769,
      -1.29689709,
      0.064108572,
      -438302105e-13,
      152882069e-16,
      -214462305e-20,
      2276.42747,
      31.8773552
    ],
    "NEOC5H11-OO": [
      16.9989732,
      0.0301601499,
      -119254896e-13,
      225822367e-17,
      -169878947e-21,
      -21046.4569,
      -61.4617731,
      1.07910948,
      0.0685212672,
      -465891499e-13,
      161793724e-16,
      -226643749e-20,
      -15761.0621,
      23.4108339
    ],
    "NEOC5H12": [
      15.8220811,
      0.0273824077,
      -101392581e-13,
      177707009e-17,
      -122756971e-21,
      -28519.701,
      -66.2488521,
      -2.6246346,
      0.0707864446,
      -484369376e-13,
      16795768e-15,
      -233138901e-20,
      -22247.8177,
      32.5342362
    ],
    "NH": [
      2.53691464,
      0.00174532708,
      -666818142e-15,
      134160653e-18,
      -104190033e-22,
      42182.1879,
      7.12732805,
      3.75007687,
      -0.00138541418,
      236293147e-14,
      -116895746e-17,
      199761337e-21,
      41806.1076,
      0.742847188
    ],
    "NH2": [
      2.67687765,
      0.00348484078,
      -12857082e-13,
      27209163e-17,
      -236034281e-22,
      22030.3372,
      7.34730162,
      4.18313061,
      -0.00189463407,
      591894562e-14,
      -401639279e-17,
      933647558e-21,
      21692.9365,
      -0.0901998745
    ],
    "NH3": [
      2.21117984,
      0.00652182453,
      -230931532e-14,
      398907128e-18,
      -280385645e-22,
      -6390.09604,
      8.86905603,
      3.21689186,
      0.0031971567,
      181217371e-14,
      -187188573e-17,
      441133513e-21,
      -6633.47835,
      3.82536772
    ],
    "NNH": [
      2.67540125,
      0.0053566868,
      -29499045e-13,
      77854124e-17,
      -791413867e-22,
      28474.6064,
      10.3028707,
      3.9682359,
      -0.00182572793,
      120134595e-13,
      -130764254e-16,
      473161093e-20,
      28288.4383,
      4.49039228
    ],
    "NO": [
      2.69775018,
      0.00239887133,
      -1316447e-12,
      338235813e-18,
      -32939489e-21,
      9998.54348,
      9.40230813,
      3.91290193,
      -0.00261206371,
      643242163e-14,
      -498744709e-17,
      13396592e-19,
      9762.80404,
      3.57691592
    ],
    "NO2": [
      5.25673685,
      0.00164343307,
      -624197948e-15,
      10706515e-17,
      -688584753e-23,
      1953.63563,
      -2.35827568,
      2.61409592,
      0.00751596848,
      -551797745e-14,
      191957608e-17,
      -258623476e-21,
      2904.98637,
      11.9442483
    ],
    "NO3": [
      7.66391925,
      0.00228165967,
      -816241554e-15,
      111367864e-18,
      -338429715e-23,
      5629.75022,
      -15.1899442,
      0.406541943,
      0.0241083583,
      -25432819e-12,
      124505044e-16,
      -232277087e-20,
      7560.21258,
      21.8923574
    ],
    "NPBENZ": [
      18.8963371,
      0.0380090295,
      -152789389e-13,
      295630099e-17,
      -227699217e-21,
      -8966.05283,
      -76.2711275,
      -5.58650157,
      0.0992161261,
      -72660592e-12,
      268653231e-16,
      -396348393e-20,
      -1131.54446,
      53.3514397
    ],
    "O": [
      2.5731836,
      -895609984e-13,
      405096303e-16,
      -839812674e-20,
      943621991e-24,
      29219.1409,
      4.74952023,
      2.9520033,
      -0.00168459131,
      255897854e-14,
      -177574473e-17,
      466034833e-21,
      29147.1652,
      2.94136507
    ],
    "O2": [
      2.81750648,
      0.00249838007,
      -152493521e-14,
      450547608e-18,
      -487702792e-22,
      -931.713392,
      7.94729337,
      3.4603508,
      -885011121e-12,
      515281056e-14,
      -540712413e-17,
      187809542e-20,
      -1029.42573,
      5.02236126
    ],
    "ODECAL": [
      28.2109941,
      0.0474108396,
      -182963852e-13,
      342084161e-17,
      -257817125e-21,
      -26835.523,
      -131.410203,
      -10.2710769,
      0.132926553,
      -895594797e-13,
      298145803e-16,
      -392361417e-20,
      -12981.9774,
      76.862793
    ],
    "OH": [
      3.62538436,
      -502165281e-12,
      836958463e-15,
      -295714531e-18,
      330350486e-22,
      3413.8011,
      1.5541944,
      3.37995109,
      613440526e-12,
      -106464235e-14,
      114489214e-17,
      -376228211e-21,
      3456.99735,
      2.70689352
    ],
    "PC3H4": [
      3.0415659,
      0.0180732925,
      -919849468e-14,
      229161583e-17,
      -225689445e-21,
      20621.4251,
      7.37493873,
      1.35943188,
      0.0253869187,
      -211228852e-13,
      109324785e-16,
      -257374996e-20,
      20930.9378,
      15.350004
    ],
    "QBU1OOX": [
      9.44680463,
      0.0140890825,
      -670668585e-14,
      151288685e-17,
      -132818576e-21,
      19133.2917,
      -28.1812927,
      -5.88861871,
      0.0623896285,
      -637545748e-13,
      314592852e-16,
      -602777889e-20,
      23028.4892,
      49.4686856
    ],
    "QDECOOH": [
      17.2379174,
      0.0376978745,
      -166331315e-13,
      354555182e-17,
      -300284988e-21,
      -19202.7471,
      -70.1676462,
      -6.00367537,
      0.0893458584,
      -596731181e-13,
      194862876e-16,
      -251427606e-20,
      -10835.7738,
      55.6207021
    ],
    "QMBOOX": [
      24.6557066,
      0.0160203243,
      -233018024e-14,
      -209432791e-18,
      596256606e-22,
      -58731.8865,
      -92.8197844,
      -3.02577545,
      0.0980395304,
      -934626315e-13,
      447942468e-16,
      -827438909e-20,
      -51257.8864,
      49.034705
    ],
    "QMDOOH": [
      37.7681786,
      0.0605584838,
      -266377343e-13,
      563139231e-17,
      -471383628e-21,
      -76826.3296,
      -155.143375,
      4.12866858,
      0.13531295,
      -889331232e-13,
      287037586e-16,
      -367587894e-20,
      -64716.106,
      26.9206708
    ],
    "QMEOLEOOH": [
      66.6288425,
      0.0844466273,
      -289700155e-13,
      440900507e-17,
      -244932292e-21,
      -150877.986,
      -300.442019,
      -0.998790182,
      0.234730256,
      -154206372e-12,
      507928409e-16,
      -668713172e-20,
      -126532.038,
      65.5728373
    ],
    "QMLIN1OOX": [
      56.6825541,
      0.0903049166,
      -359434818e-13,
      672610917e-17,
      -495506768e-21,
      -67492.3687,
      -244.60178,
      -2.71828911,
      0.237884651,
      -173440129e-12,
      636605386e-16,
      -933625668e-20,
      -48365.2972,
      70.2616632
    ],
    "QMLINOOX": [
      68.1309948,
      0.0745379902,
      -247878007e-13,
      355693559e-17,
      -175307126e-21,
      -82947.4454,
      -308.878538,
      0.0176458104,
      0.229341056,
      -156722232e-12,
      535320989e-16,
      -727405191e-20,
      -58971.5465,
      58.2344142
    ],
    "QMPAOOH": [
      37.7681786,
      0.0605584838,
      -266377343e-13,
      563139231e-17,
      -471383628e-21,
      -76826.3296,
      -155.143375,
      4.12866858,
      0.13531295,
      -889331232e-13,
      287037586e-16,
      -367587894e-20,
      -64716.106,
      26.9206708
    ],
    "QMSTEAOOH": [
      -130.612117,
      0.600365422,
      -485197519e-12,
      158690698e-15,
      -180918283e-19,
      12404.5727,
      712.083761,
      21.555453,
      0.105511535,
      118282831e-12,
      -168398923e-15,
      483898018e-19,
      -25028.6496,
      -53.537647
    ],
    "RALD3B": [
      -6.08013768,
      0.0460180077,
      -26169672e-12,
      665382129e-17,
      -635305356e-21,
      -2149.66002,
      59.0959839,
      7.04072885,
      -201204277e-13,
      344068124e-13,
      -287710234e-16,
      713330094e-20,
      -5141.21758,
      -5.92381683
    ],
    "RALD3G": [
      -2.96412172,
      0.0383579385,
      -208581719e-13,
      51259356e-16,
      -477571609e-21,
      1720.28134,
      45.8634919,
      6.34826535,
      6246259e-9,
      206655517e-13,
      -187382733e-16,
      466557687e-20,
      -440.192456,
      -0.44553717
    ],
    "RALDEST": [
      11.7688624,
      0.041658631,
      -202330626e-13,
      468126751e-17,
      -421941087e-21,
      -49100.7178,
      -22.7507735,
      5.76645054,
      0.054997324,
      -313486401e-13,
      879814806e-17,
      -993730052e-21,
      -46939.8496,
      9.7355316
    ],
    "RBIPHENYL": [
      26.7692078,
      0.0281611415,
      -605667723e-14,
      -369378426e-18,
      167249382e-21,
      39276.9947,
      -121.306413,
      -10.5625108,
      0.131145193,
      -112591903e-12,
      486123345e-16,
      -827787353e-20,
      50103.1931,
      72.6686556
    ],
    "RBU1OOX": [
      14.5390319,
      0.0269797332,
      -109312485e-13,
      212602294e-17,
      -164284673e-21,
      -35689.3368,
      -42.2613629,
      3.26237571,
      0.0539896881,
      -351916871e-13,
      118108288e-16,
      -16141059e-19,
      -31922.9337,
      17.9249204
    ],
    "RC9H11": [
      19.4777671,
      0.0352558917,
      -14249323e-12,
      276058348e-17,
      -213045169e-21,
      6109.38819,
      -79.4713741,
      -1.83523003,
      0.0826181075,
      -537178363e-13,
      173785513e-16,
      -224331848e-20,
      13782.0672,
      35.8790126
    ],
    "RCRESOLC": [
      13.1541709,
      0.0250657189,
      -532353914e-14,
      -212687585e-18,
      125840459e-21,
      -3380.86418,
      -42.2339552,
      -6.42956805,
      0.0931830717,
      -941722601e-13,
      512938173e-16,
      -110712258e-19,
      1123.39577,
      54.9833259
    ],
    "RCRESOLO": [
      12.7824813,
      0.0240796407,
      -451347946e-14,
      -425076334e-18,
      144988488e-21,
      -3977.04754,
      -40.0543783,
      -6.60757189,
      0.0915233042,
      -924834752e-13,
      505720227e-16,
      -109413374e-19,
      482.664709,
      56.2014116
    ],
    "RDECALIN": [
      28.5620333,
      0.0411366392,
      -13602411e-12,
      201592783e-17,
      -109376626e-21,
      -15302.5063,
      -139.641687,
      -13.9601308,
      0.135630337,
      -923471594e-13,
      311806495e-16,
      -416003241e-20,
      5.47278088,
      90.4971362
    ],
    "RDECOO": [
      17.2379174,
      0.0376978745,
      -166331315e-13,
      354555182e-17,
      -300284988e-21,
      -19202.7471,
      -70.1676462,
      -6.00367537,
      0.0893458584,
      -596731181e-13,
      194862876e-16,
      -251427606e-20,
      -10835.7738,
      55.6207021
    ],
    "RDIPE": [
      16.9549494,
      0.0345118423,
      -131342732e-13,
      236150213e-17,
      -167133125e-21,
      -27814.7477,
      -55.4607975,
      0.691787207,
      0.0706522027,
      -432512401e-13,
      135159343e-16,
      -171635982e-20,
      -21960.0093,
      32.5588287
    ],
    "RMBOOX": [
      24.6557066,
      0.0160203243,
      -233018024e-14,
      -209432791e-18,
      596256606e-22,
      -58731.8865,
      -92.8197844,
      -3.02577545,
      0.0980395304,
      -934626315e-13,
      447942468e-16,
      -827438909e-20,
      -51257.8864,
      49.034705
    ],
    "RMBX": [
      15.4924702,
      0.0280794103,
      -120573254e-13,
      249322401e-17,
      -204812728e-21,
      -39720.1864,
      -54.1810445,
      2.13573311,
      0.0577610483,
      -367920237e-13,
      116542234e-16,
      -147717375e-20,
      -34911.761,
      18.1084031
    ],
    "RMCROTA": [
      15.7189282,
      0.0169463336,
      -446708252e-14,
      566631307e-18,
      -276621493e-22,
      -32321.9582,
      -49.4508733,
      0.147581476,
      0.0605025483,
      -501554196e-13,
      218665554e-16,
      -375142509e-20,
      -27868.553,
      31.2413465
    ],
    "RMCYC6": [
      17.3339062,
      0.0385260822,
      -158310821e-13,
      315191459e-17,
      -253163787e-21,
      -5899.5798,
      -73.3836419,
      -9.95790329,
      0.0991745477,
      -663714701e-13,
      218705768e-16,
      -285297798e-20,
      3925.47162,
      74.3253244
    ],
    "RMCYC6-OO": [
      22.7624311,
      0.0377290665,
      -150512076e-13,
      288934934e-17,
      -222140396e-21,
      -25374.0824,
      -99.0983226,
      -6.71698823,
      0.103238887,
      -696427248e-13,
      231084298e-16,
      -303034602e-20,
      -14761.4915,
      60.4504445
    ],
    "RMDOOX": [
      39.6894034,
      0.0538225057,
      -202775001e-13,
      364793874e-17,
      -261216335e-21,
      -83847.2341,
      -167.546736,
      4.70466765,
      0.131566363,
      -850640479e-13,
      276429564e-16,
      -359385768e-20,
      -71252.7292,
      21.797952
    ],
    "RMDX": [
      25.1620868,
      0.0714154614,
      -328250989e-13,
      727501997e-17,
      -635222696e-21,
      -59598.7259,
      -92.3572595,
      1.85440015,
      0.123210321,
      -759874815e-13,
      232610876e-16,
      -285550987e-20,
      -51207.9587,
      33.7888029
    ],
    "RME7": [
      24.0410392,
      0.0426053894,
      -171372001e-13,
      334440554e-17,
      -261909734e-21,
      -48992.9735,
      -92.0931877,
      2.93892065,
      0.0894989861,
      -562151974e-13,
      178177379e-16,
      -227209478e-20,
      -41396.2109,
      22.1158799
    ],
    "RMEOLEA": [
      56.5772245,
      0.089880597,
      -34228816e-12,
      624735813e-17,
      -455216117e-21,
      -80688.5447,
      -249.965378,
      -0.157106282,
      0.215956888,
      -139292391e-12,
      451597935e-16,
      -585972103e-20,
      -60264.1856,
      57.0926555
    ],
    "RMEOLEOOX": [
      56.828843,
      0.0987024571,
      -387236246e-13,
      719531442e-17,
      -531279781e-21,
      -123280.985,
      -244.956753,
      2.29713937,
      0.219884021,
      -139708261e-12,
      445970316e-16,
      -572596272e-20,
      -103649.572,
      50.180203
    ],
    "RMEOLES": [
      56.5772245,
      0.089880597,
      -34228816e-12,
      624735813e-17,
      -455216117e-21,
      -80688.5447,
      -249.965378,
      -0.157106282,
      0.215956888,
      -139292391e-12,
      451597935e-16,
      -585972103e-20,
      -60264.1856,
      57.0926555
    ],
    "RMLIN1A": [
      59.5150691,
      0.0742461115,
      -253824843e-13,
      382833735e-17,
      -208614643e-21,
      -48286.3749,
      -269.048825,
      -0.91252423,
      0.208529652,
      -137285435e-12,
      452738746e-16,
      -596493926e-20,
      -26532.4413,
      57.9979154
    ],
    "RMLIN1OOX": [
      54.8798863,
      0.090584384,
      -354321193e-13,
      650176029e-17,
      -469049023e-21,
      -71322.9393,
      -234.809039,
      -1.47497564,
      0.227202231,
      -159630162e-12,
      566827877e-16,
      -807223499e-20,
      -52725.8349,
      65.2917158
    ],
    "RMLIN1X": [
      59.5150691,
      0.0742461115,
      -253824843e-13,
      382833735e-17,
      -208614643e-21,
      -48286.3749,
      -269.048825,
      -0.91252423,
      0.208529652,
      -137285435e-12,
      452738746e-16,
      -596493926e-20,
      -26532.4413,
      57.9979154
    ],
    "RMLINA": [
      57.1954712,
      0.0840022248,
      -315645422e-13,
      564019755e-17,
      -400096883e-21,
      -66957.4846,
      -254.485602,
      -1.30856133,
      0.214011186,
      -139905343e-12,
      457664202e-16,
      -597318336e-20,
      -45896.0329,
      62.1504271
    ],
    "RMLINOOX": [
      63.2132444,
      0.0805239356,
      -278197745e-13,
      427200724e-17,
      -239927804e-21,
      -87723.8917,
      -282.700411,
      1.99661323,
      0.218089399,
      -143745727e-12,
      476899669e-16,
      -633795584e-20,
      -65930.771,
      47.9327752
    ],
    "RMLINX": [
      57.1954712,
      0.0840022248,
      -315645422e-13,
      564019755e-17,
      -400096883e-21,
      -66957.4846,
      -254.485602,
      -1.30856133,
      0.214011186,
      -139905343e-12,
      457664202e-16,
      -597318336e-20,
      -45896.0329,
      62.1504271
    ],
    "RMP3": [
      9.46731146,
      0.0278903391,
      -131079861e-13,
      294998316e-17,
      -260075548e-21,
      -31826.4551,
      -19.3081295,
      3.6747287,
      0.0407627453,
      -238349912e-13,
      692294802e-17,
      -811876222e-21,
      -29741.1253,
      12.0425368
    ],
    "RMPAOOX": [
      39.6894034,
      0.0538225057,
      -202775001e-13,
      364793874e-17,
      -261216335e-21,
      -83847.2341,
      -167.546736,
      4.70466765,
      0.131566363,
      -850640479e-13,
      276429564e-16,
      -359385768e-20,
      -71252.7292,
      21.797952
    ],
    "RMPAX": [
      46.5991944,
      0.0879958559,
      -311818152e-13,
      472867036e-17,
      -23413393e-20,
      -88675.0528,
      -203.460488,
      -5.53001427,
      0.220809126,
      -158073475e-12,
      586104792e-16,
      -881403979e-20,
      -72306.4813,
      71.5470253
    ],
    "RMSTEAOOX": [
      -120.700825,
      0.567736647,
      -452750605e-12,
      147317719e-15,
      -16752875e-18,
      10203.973,
      660.02401,
      19.1170969,
      0.120319297,
      841502162e-13,
      -139029386e-15,
      405165459e-19,
      -24750.5076,
      -45.7161098
    ],
    "RMTBE": [
      10.9269229,
      0.0374766266,
      -173062474e-13,
      386241414e-17,
      -339119741e-21,
      -18800.7827,
      -25.356368,
      -0.181069448,
      0.0699087211,
      -528158399e-13,
      211420212e-16,
      -349233271e-20,
      -15757.1928,
      31.7301895
    ],
    "RODECA": [
      28.5620333,
      0.0411366392,
      -13602411e-12,
      201592783e-17,
      -109376626e-21,
      -15302.5063,
      -139.641687,
      -13.9601308,
      0.135630337,
      -923471594e-13,
      311806495e-16,
      -416003241e-20,
      5.47278088,
      90.4971362
    ],
    "RSTEAX": [
      54.6335802,
      0.0934230719,
      -319964312e-13,
      467181818e-17,
      -216706943e-21,
      -97461.7261,
      -243.777088,
      -6.34709308,
      0.246833571,
      -176723317e-12,
      653539506e-16,
      -975792273e-20,
      -78069.872,
      78.6982236
    ],
    "RTC4H8OH": [
      8.66823484,
      0.0301271731,
      -135256253e-13,
      294117291e-17,
      -252822189e-21,
      -17347.8965,
      -16.802372,
      0.0013990132,
      0.0552484364,
      -408313463e-13,
      161323424e-16,
      -264252681e-20,
      -14955.8499,
      27.8015457
    ],
    "RTC4H9O": [
      11.6852527,
      0.0257155374,
      -107539562e-13,
      215924613e-17,
      -171897014e-21,
      -17260.7591,
      -37.3085633,
      -0.294435988,
      0.055478739,
      -384836472e-13,
      136415198e-16,
      -195485877e-20,
      -13403.2994,
      26.1916467
    ],
    "RTETRALIN": [
      29.2428061,
      0.0267835937,
      -917249482e-14,
      142952536e-17,
      -846466186e-22,
      3956.46504,
      -144.54061,
      -10.9331575,
      0.116063513,
      -835724273e-13,
      289850559e-16,
      -391180364e-20,
      18419.8119,
      72.9000859
    ],
    "RTETRAOO": [
      53.4619031,
      -0.00789283132,
      109697206e-13,
      -38948983e-16,
      438586293e-21,
      -17692.4159,
      -271.823424,
      -13.6343924,
      0.141210048,
      -113282678e-12,
      421245088e-16,
      -595299802e-20,
      6462.25047,
      91.3157248
    ],
    "RUME10": [
      23.5916369,
      0.0652041736,
      -268467537e-13,
      544034955e-17,
      -442864735e-21,
      -35867.2705,
      -82.7430018,
      1.64400814,
      0.125749356,
      -894797013e-13,
      34237107e-15,
      -540782293e-20,
      -29502.4582,
      31.2965588
    ],
    "RUME16": [
      56.2816009,
      0.071435558,
      -243272135e-13,
      365699376e-17,
      -198260551e-21,
      -75340.9955,
      -253.924384,
      0.994524607,
      0.194982097,
      -127857833e-12,
      422158836e-16,
      -558358037e-20,
      -55548.2222,
      44.9927995
    ],
    "RUME7": [
      18.5903431,
      0.0463199659,
      -212076343e-13,
      467919597e-17,
      -406994657e-21,
      -32918.3962,
      -60.763783,
      2.6615872,
      0.0817172013,
      -507053305e-13,
      156042686e-16,
      -192436586e-20,
      -27184.044,
      25.445967
    ],
    "RXYLENE": [
      9.50606195,
      0.0415939315,
      -179471777e-13,
      341861978e-17,
      -236020443e-21,
      14696.906,
      -25.9567399,
      -2.8092046,
      0.0772903563,
      -567476394e-13,
      221628042e-16,
      -363170602e-20,
      18095.9195,
      37.4238465
    ],
    "SC4H7": [
      8.33017753,
      0.0198466503,
      -637614062e-14,
      528652771e-18,
      38110373e-21,
      11953.385,
      -18.3767118,
      -1.12550124,
      0.0464823652,
      -345124591e-13,
      13738192e-15,
      -228751273e-20,
      14638.7978,
      30.5571711
    ],
    "TAME": [
      11.3309761,
      0.0474280944,
      -196957502e-13,
      36686075e-16,
      -250688228e-21,
      -44274.5214,
      -31.7952394,
      -2.12836721,
      0.0882139832,
      -660433511e-13,
      270764868e-16,
      -468399869e-20,
      -40721.2548,
      36.8750527
    ],
    "TC4H9OH": [
      9.08150387,
      0.0322201837,
      -141979352e-13,
      303249263e-17,
      -256658356e-21,
      -42391.7231,
      -23.6263218,
      -0.699999563,
      0.0593910266,
      -425008966e-13,
      161357155e-16,
      -253152343e-20,
      -39574.6501,
      27.1305359
    ],
    "TETRALIN": [
      24.0250678,
      0.034503169,
      -126565536e-13,
      220632462e-17,
      -151941206e-21,
      -9853.1433,
      -111.161769,
      -10.0807336,
      0.1171839,
      -878208542e-13,
      32575739e-15,
      -475336763e-20,
      1401.77116,
      70.4583499
    ],
    "TMBENZ": [
      14.7576861,
      0.0450315825,
      -197554195e-13,
      421197817e-17,
      -357314917e-21,
      -10902.5839,
      -53.5378398,
      -2.75522789,
      0.0839491691,
      -521867417e-13,
      16223579e-15,
      -202559281e-20,
      -4597.93488,
      41.245704
    ],
    "U2ME10": [
      23.6788649,
      0.0640632046,
      -276021386e-13,
      583270375e-17,
      -491952687e-21,
      -53911.8596,
      -85.7548642,
      0.322839337,
      0.128941053,
      -95183231e-12,
      371202465e-16,
      -592381775e-20,
      -47185.3243,
      35.4410717
    ],
    "U2ME12": [
      31.2799449,
      0.0715415882,
      -301181538e-13,
      608643201e-17,
      -487334868e-21,
      -62826.81,
      -124.478592,
      1.1265072,
      0.146456961,
      -999150853e-13,
      349878529e-16,
      -497513315e-20,
      -53117.403,
      35.3544123
    ],
    "UME10": [
      34.8566736,
      0.0508631615,
      -19002741e-12,
      339432106e-17,
      -241664061e-21,
      -72733.4602,
      -148.477392,
      1.08700033,
      0.12590688,
      -815391729e-13,
      265559625e-16,
      -345855871e-20,
      -60576.3778,
      34.2911241
    ],
    "UME16": [
      45.2339702,
      0.0865152352,
      -305153342e-13,
      460674378e-17,
      -226752205e-21,
      -92204.6847,
      -194.026893,
      -6.34895832,
      0.217104928,
      -15449289e-11,
      569179489e-16,
      -850384163e-20,
      -75904.4793,
      78.4262324
    ],
    "UME7": [
      25.8473842,
      0.0362113327,
      -13312403e-12,
      232937526e-17,
      -161944568e-21,
      -59127.4188,
      -103.960065,
      2.21977808,
      0.0887171241,
      -570672292e-13,
      185348664e-16,
      -241270723e-20,
      -50621.4805,
      23.9174684
    ],
    "XYLENE": [
      17.2256243,
      0.02835656,
      -690689954e-14,
      -357091403e-18,
      209419626e-21,
      -6872.39337,
      -69.7341599,
      -5.12303971,
      0.0828654966,
      -567626342e-13,
      199094674e-16,
      -287999483e-20,
      457.968429,
      49.1410252
    ],
    "ZBU1OOX": [
      17.1509971,
      0.0321642995,
      -14526525e-12,
      316055984e-17,
      -271089893e-21,
      -48716.7967,
      -49.4521678,
      4.90929016,
      0.0668925461,
      -514714682e-13,
      206286181e-16,
      -336826334e-20,
      -45264.6353,
      13.8131161
    ],
    "ZDECA": [
      17.2379174,
      0.0376978745,
      -166331315e-13,
      354555182e-17,
      -300284988e-21,
      -19202.7471,
      -70.1676462,
      -6.00367537,
      0.0893458584,
      -596731181e-13,
      194862876e-16,
      -251427606e-20,
      -10835.7738,
      55.6207021
    ],
    "ZMBOOX": [
      29.4016942,
      0.0157346453,
      -21056567e-13,
      -230310175e-18,
      580528651e-22,
      -70363.7113,
      -109.596841,
      -1.66570869,
      0.110596944,
      -11072661e-11,
      550475284e-16,
      -10491153e-18,
      -62224.0518,
      48.6744607
    ],
    "ZMDOOH": [
      48.9601122,
      0.0469646617,
      -161477773e-13,
      258757356e-17,
      -158080023e-21,
      -99631.3675,
      -211.22653,
      6.91495056,
      0.141448171,
      -957687121e-13,
      324081484e-16,
      -4346363e-18,
      -84663.2899,
      15.8608722
    ],
    "ZMEOLEOOX": [
      57.4950108,
      0.0992606422,
      -335004082e-13,
      508063679e-17,
      -2822403e-19,
      -109648.465,
      -238.315353,
      2.38451828,
      0.242404779,
      -172926515e-12,
      654382588e-16,
      -100805556e-19,
      -92674.4334,
      51.3566583
    ],
    "ZMLIN1OOX": [
      66.1920071,
      0.0818444133,
      -303706056e-13,
      517171152e-17,
      -339000627e-21,
      -88310.4294,
      -293.138255,
      0.795447186,
      0.236629171,
      -167753526e-12,
      593661575e-16,
      -835593051e-20,
      -66206.3921,
      56.6777851
    ],
    "ZMLINOOX": [
      61.4087077,
      0.0858331824,
      -298017595e-13,
      463939709e-17,
      -265661024e-21,
      -96591.421,
      -281.173958,
      1.31186651,
      0.242949107,
      -18383698e-11,
      717571402e-16,
      -112326125e-19,
      -78201.7876,
      34.3158089
    ],
    "ZMPAOOH": [
      48.9601122,
      0.0469646617,
      -161477773e-13,
      258757356e-17,
      -158080023e-21,
      -99631.3675,
      -211.22653,
      6.91495056,
      0.141448171,
      -957687121e-13,
      324081484e-16,
      -4346363e-18,
      -84663.2899,
      15.8608722
    ],
    "ZMSTEAOOH": [
      -62.2995292,
      0.341575945,
      -269706994e-12,
      871969173e-16,
      -987435445e-20,
      15716.0052,
      357.020399,
      16.1954271,
      0.0903920846,
      317136382e-13,
      -735607531e-16,
      222771796e-19,
      -3907.7339,
      -39.1880337
    ]
  };
  function ThermoParameter() {
    let _thermoDict = thermoDict;
    function getHighTemperatureCoefficients(gasSpecieName) {
      try {
        return _thermoDict[gasSpecieName].slice(0, 7);
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getLowTemperatureCoefficients(gasSpecieName) {
      try {
        return _thermoDict[gasSpecieName].slice(7, 14);
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    return {
      getHighTemperatureCoefficients,
      getLowTemperatureCoefficients
    };
  }

  // src/transport.js
  var transportDict = {
    "AC3H4": [
      1,
      252,
      4.76,
      0,
      0,
      0,
      40.0648
    ],
    "CH3COOH": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      60.0526
    ],
    "CH3COCH3": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      58.08
    ],
    "C2H3CHO": [
      2,
      443.2,
      4.12,
      0,
      0,
      1,
      56.0642
    ],
    "C2H5CHO": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      58.08
    ],
    "C4H9CHO": [
      2,
      500,
      5.64,
      0,
      0,
      1,
      86.1338
    ],
    "CH2CHCH2": [
      2,
      316,
      4.22,
      0,
      0,
      1,
      41.0727
    ],
    "CHCHCH3": [
      2,
      316,
      4.22,
      0,
      0,
      1,
      41.0727
    ],
    "CH2CCH3": [
      2,
      316,
      4.22,
      0,
      0,
      1,
      41.0727
    ],
    "AR": [
      0,
      136.5,
      3.33,
      0,
      0,
      0,
      39.948
    ],
    "C6H5CH2OH": [
      2,
      622.4,
      5.53,
      0,
      0,
      1,
      108.14
    ],
    "C6H4O2": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      108.097
    ],
    "C6H6": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      78.1136
    ],
    "C6H5CHO": [
      2,
      622.4,
      5.53,
      0,
      0,
      1,
      106.124
    ],
    "C6H5C2H4C6H5": [
      2,
      783.8,
      6.64,
      0,
      0,
      1,
      182.265
    ],
    "NC4H8": [
      2,
      355,
      4.65,
      0,
      0,
      1,
      56.1075
    ],
    "C4H6": [
      2,
      357,
      5.18,
      0,
      0,
      1,
      54.0916
    ],
    "C": [
      0,
      71.4,
      3.298,
      0,
      0,
      0,
      12.011
    ],
    "C12H8": [
      2,
      689.8,
      6.5,
      0,
      0,
      1,
      152.196
    ],
    "C2H": [
      1,
      209,
      4.1,
      0,
      0,
      2.5,
      25.0299
    ],
    "C2H2": [
      1,
      209,
      4.1,
      0,
      0,
      2.5,
      26.0379
    ],
    "C2H4": [
      2,
      280.8,
      3.971,
      0,
      0,
      1.5,
      28.0538
    ],
    "C2H5": [
      2,
      252.3,
      4.302,
      0,
      0,
      1.5,
      29.0617
    ],
    "C2H6": [
      2,
      252.3,
      4.302,
      0,
      0,
      1.5,
      30.0696
    ],
    "C3H2": [
      2,
      209,
      4.1,
      0,
      0,
      1,
      38.0489
    ],
    "C3H3": [
      2,
      252,
      4.76,
      0,
      0,
      1,
      39.0568
    ],
    "C3H6": [
      2,
      307.8,
      4.14,
      0,
      0,
      1,
      42.0806
    ],
    "C3H8": [
      2,
      303.4,
      4.81,
      0,
      0,
      1,
      44.0965
    ],
    "NC3H7O": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      59.088
    ],
    "C3H7OOH": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      76.0953
    ],
    "C4H2": [
      1,
      357,
      5.18,
      0,
      0,
      1,
      50.0599
    ],
    "C4H3": [
      1,
      357,
      5.18,
      0,
      0,
      1,
      51.0678
    ],
    "C4H4": [
      2,
      357,
      5.18,
      0,
      0,
      1,
      52.0758
    ],
    "C4H5": [
      2,
      357,
      5.18,
      0,
      0,
      1,
      53.0837
    ],
    "CH2C3H5": [
      2,
      355,
      4.65,
      0,
      0,
      1,
      55.0996
    ],
    "SC4H7": [
      2,
      355,
      4.65,
      0,
      0,
      1,
      55.0996
    ],
    "C4H9OOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      90.1222
    ],
    "CYC5H4O": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      80.0862
    ],
    "C5H7": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      67.1106
    ],
    "NC5H11OOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      104.149
    ],
    "C6H5": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      77.1057
    ],
    "C6H5O": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      93.1051
    ],
    "LC6H6": [
      2,
      412.3,
      5.349,
      0,
      0,
      1,
      78.1136
    ],
    "CYC6H10-ONE": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      98.1448
    ],
    "C7H7": [
      2,
      495.3,
      5.68,
      0,
      0,
      1,
      91.1326
    ],
    "NC7H15OOH": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      132.203
    ],
    "CYC5H8": [
      1,
      408,
      5.2,
      0,
      0,
      1,
      68.1185
    ],
    "CYC6H8": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      80.1295
    ],
    "CYC6H12": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      84.1613
    ],
    "CYC6H10": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      82.1454
    ],
    "CH": [
      1,
      80,
      2.75,
      0,
      0,
      0,
      13.0189
    ],
    "CH2": [
      1,
      144,
      3.8,
      0,
      0,
      0,
      14.0269
    ],
    "CH2CO": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      42.0373
    ],
    "CH2O": [
      2,
      498,
      3.59,
      0,
      0,
      2,
      30.0263
    ],
    "CH2OH": [
      2,
      417,
      3.69,
      1.7,
      0,
      2,
      31.0342
    ],
    "CH2S": [
      1,
      144,
      3.8,
      0,
      0,
      0,
      14.0269
    ],
    "CH3": [
      1,
      144,
      3.8,
      0,
      0,
      0,
      15.0348
    ],
    "CH3CO": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      43.0452
    ],
    "CH3O": [
      2,
      417,
      3.69,
      1.7,
      0,
      2,
      31.0342
    ],
    "CH3OH": [
      2,
      481.8,
      3.626,
      0,
      0,
      1,
      32.0422
    ],
    "CH4": [
      2,
      141.4,
      3.746,
      0,
      2.6,
      13,
      16.0428
    ],
    "CO": [
      1,
      98.1,
      3.65,
      0,
      1.95,
      1.8,
      28.0104
    ],
    "CO2": [
      1,
      244,
      3.763,
      0,
      2.65,
      2.1,
      44.0098
    ],
    "CYC5H6": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      66.1026
    ],
    "MCPTD": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      80.1295
    ],
    "CRESOL": [
      2,
      621.1,
      5.64,
      0,
      0,
      1,
      108.14
    ],
    "NC10H20": [
      2,
      540.98,
      7.15,
      0,
      0,
      1,
      140.269
    ],
    "C6H5CH2C6H5": [
      2,
      712.6,
      6.89,
      0,
      0,
      1,
      168.238
    ],
    "DIPE": [
      2,
      432,
      6,
      0,
      0,
      1,
      102.177
    ],
    "MTBE-O": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      102.133
    ],
    "CH3OCH3": [
      2,
      303.4,
      4.81,
      0,
      0,
      1,
      46.069
    ],
    "CH3CH3-C5H6": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      96.1723
    ],
    "C6H5C2H5": [
      2,
      523.6,
      5.96,
      0,
      0,
      1,
      106.167
    ],
    "NC7H14": [
      2,
      459.98,
      6.31,
      0,
      0,
      1,
      98.1882
    ],
    "NC6H12": [
      2,
      412.3,
      5.349,
      0,
      0,
      1,
      84.1613
    ],
    "C5H9CHO": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      98.1448
    ],
    "ETBE": [
      2,
      432,
      6,
      0,
      0,
      1,
      102.177
    ],
    "NEOC5H10-O": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      86.1338
    ],
    "C4H8O": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      72.1069
    ],
    "NC5H10-O": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      86.1338
    ],
    "NC7H14O": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      114.188
    ],
    "IC8H16O": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      128.214
    ],
    "C2H5OH": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      46.069
    ],
    "C2H5OO": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      61.0605
    ],
    "C2H5OOH": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      62.0684
    ],
    "C2H4O": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      44.0532
    ],
    "C6H5C2H": [
      2,
      534.3,
      5.71,
      0.77,
      0,
      1,
      102.136
    ],
    "BIPHENYL": [
      2,
      676.5,
      6.31,
      0,
      0,
      1,
      154.211
    ],
    "C14H10": [
      2,
      772,
      6.96,
      0,
      38.8,
      1,
      178.233
    ],
    "C6H5OH": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      94.113
    ],
    "FLUORENE": [
      2,
      712.6,
      6.89,
      0,
      0,
      1,
      166.222
    ],
    "C10H8": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      128.174
    ],
    "H": [
      0,
      145,
      2.05,
      0,
      0,
      0,
      1.00794
    ],
    "H2": [
      1,
      38,
      2.92,
      0,
      0.79,
      280,
      2.01588
    ],
    "H2O": [
      2,
      572.4,
      2.605,
      1.844,
      0,
      4,
      18.0153
    ],
    "H2O2": [
      2,
      107.4,
      3.458,
      0,
      0,
      3.8,
      34.0147
    ],
    "HCCO": [
      2,
      150,
      2.5,
      0,
      0,
      1,
      41.0293
    ],
    "HCO": [
      2,
      498,
      3.59,
      0,
      0,
      0,
      29.0183
    ],
    "HCO3": [
      2,
      498,
      3.59,
      0,
      0,
      0,
      61.0171
    ],
    "HE": [
      0,
      10.2,
      2.576,
      0,
      0,
      0,
      4.0026
    ],
    "HO2": [
      2,
      107.4,
      3.458,
      0,
      0,
      1,
      33.0067
    ],
    "IC4H8": [
      2,
      355,
      4.65,
      0,
      0,
      1,
      56.1075
    ],
    "IC3H7CHO": [
      2,
      455,
      4.65,
      0,
      0,
      1,
      72.1069
    ],
    "IC4H9P": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      57.1155
    ],
    "IC4H9P-OO": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "IC4H9T": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      57.1155
    ],
    "IC4H9T-OO": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "IC4H10": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      58.1234
    ],
    "IC16H34": [
      2,
      650,
      8.35,
      0,
      0,
      1,
      226.446
    ],
    "IC4H7": [
      2,
      355,
      4.65,
      0,
      0,
      1,
      55.0996
    ],
    "IC8H18": [
      2,
      494,
      6.17,
      0,
      0,
      1,
      114.231
    ],
    "INDENE": [
      2,
      588.6,
      5.96,
      0.65,
      0,
      1,
      116.163
    ],
    "IC3H7": [
      2,
      303.4,
      4.81,
      0,
      0,
      1,
      43.0886
    ],
    "IC3H7OH": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      60.0959
    ],
    "IC3H7OO": [
      2,
      468.3,
      4.76,
      0,
      0,
      1,
      75.0874
    ],
    "IC3-QOOH": [
      2,
      468.3,
      4.76,
      0,
      0,
      1,
      75.0874
    ],
    "IC3-OOQOOH": [
      2,
      468.3,
      4.76,
      0,
      0,
      1,
      107.086
    ],
    "IC5H10": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      70.1344
    ],
    "NEOC5-OQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      118.133
    ],
    "IC4-OQOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      104.106
    ],
    "C3-OQOOH": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      90.0788
    ],
    "NC4-OQOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      104.106
    ],
    "NC5-OQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      118.133
    ],
    "NC7-OQOOH": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      146.186
    ],
    "IC8-OQOOH": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      160.213
    ],
    "DME-OQOOH": [
      2,
      403.4,
      4.81,
      0,
      0,
      1,
      92.0514
    ],
    "NC10-OQOOH": [
      2,
      640.98,
      7.15,
      0,
      0,
      1,
      188.267
    ],
    "NC12-OQOOH": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      216.321
    ],
    "IC16-OQOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      272.428
    ],
    "MCYC6-OQOOH": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      144.17
    ],
    "MTBE-OQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      134.132
    ],
    "IC3H5CHO": [
      2,
      357,
      5.18,
      0,
      0,
      1,
      70.091
    ],
    "MCYC6": [
      2,
      495.3,
      5.68,
      0.43,
      12.3,
      1,
      98.1882
    ],
    "CH3CHO": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      44.0532
    ],
    "CH3CO3": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      75.044
    ],
    "C10H7CH3": [
      2,
      660,
      6.35,
      0,
      0,
      1,
      142.2
    ],
    "CH3OO": [
      2,
      417,
      3.69,
      1.7,
      0,
      2,
      47.0336
    ],
    "CH3OOH": [
      2,
      481.8,
      3.626,
      0,
      0,
      1,
      48.0416
    ],
    "MTBE": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      88.1497
    ],
    "N2": [
      1,
      97.53,
      3.621,
      0,
      1.76,
      4,
      28.0135
    ],
    "C10H7OH": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      144.173
    ],
    "C10H7CHO": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      156.184
    ],
    "CH3C10H6OH": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      158.2
    ],
    "CH3C10H6O": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      157.192
    ],
    "NC4H9P": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      57.1155
    ],
    "NC4H9S": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      57.1155
    ],
    "NC4H10": [
      2,
      352,
      5.24,
      0,
      0,
      1,
      58.1234
    ],
    "NC10H22": [
      2,
      540.98,
      7.15,
      0,
      0,
      1,
      142.285
    ],
    "NC12H26": [
      2,
      580,
      7.6,
      0,
      0,
      1,
      170.338
    ],
    "NC5H12": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      72.1503
    ],
    "NC7H16": [
      2,
      459.98,
      6.31,
      0,
      0,
      1,
      100.204
    ],
    "NEOC5H12": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      72.1503
    ],
    "NC3H7": [
      2,
      303.4,
      4.81,
      0,
      0,
      1,
      43.0886
    ],
    "NC3H7OO": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      75.0874
    ],
    "NC3-QOOH": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      75.0874
    ],
    "NC3-OOQOOH": [
      2,
      487.9,
      4.82,
      0,
      0,
      1,
      107.086
    ],
    "O": [
      0,
      80,
      2.75,
      0,
      0,
      0,
      15.9994
    ],
    "O2": [
      1,
      107.4,
      3.458,
      0,
      1.6,
      3.8,
      31.9988
    ],
    "OH": [
      1,
      80,
      2.75,
      0,
      0,
      0,
      17.0073
    ],
    "IC8H16": [
      2,
      494,
      6.17,
      0,
      0,
      1,
      112.215
    ],
    "NC5H10": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      70.1344
    ],
    "PC3H4": [
      1,
      252,
      4.76,
      0,
      0,
      1,
      40.0648
    ],
    "CH3CO3H": [
      2,
      443.2,
      4.12,
      0,
      0,
      1,
      76.052
    ],
    "HCO3H": [
      2,
      443.2,
      4.12,
      0,
      0,
      1,
      62.0251
    ],
    "C3H6O": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      58.08
    ],
    "C5H8": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      68.1185
    ],
    "C16H10": [
      2,
      834.9,
      7.24,
      0,
      45,
      1,
      202.255
    ],
    "NC10-QOOH": [
      2,
      640.98,
      7.15,
      0,
      0,
      1,
      173.276
    ],
    "NC12-QOOH": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      201.329
    ],
    "C2-QOOH": [
      2,
      470.6,
      4.41,
      0,
      0,
      1.5,
      61.0605
    ],
    "C2-OOQOOH": [
      2,
      470.6,
      4.41,
      0,
      0,
      1.5,
      93.0593
    ],
    "C2-OQOOH": [
      2,
      470.6,
      4.41,
      0,
      0,
      1.5,
      76.052
    ],
    "NC4-QOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "NC5-QOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      103.141
    ],
    "NC7-QOOH": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      131.195
    ],
    "DME-QOOH": [
      2,
      403.4,
      4.81,
      0,
      0,
      1,
      77.0599
    ],
    "IC16-QOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      257.437
    ],
    "IC16T-QOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      257.437
    ],
    "IC8-QOOH": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      145.222
    ],
    "IC4P-QOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "IC4T-QOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "MCYC6-QOOH": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      129.179
    ],
    "MTBE-QOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      119.141
    ],
    "NEOC5-QOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      103.141
    ],
    "IC8T-QOOH": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      145.222
    ],
    "MCYC6T-QOOH": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      129.179
    ],
    "NC10H21": [
      2,
      540.98,
      7.15,
      0,
      0,
      1,
      141.277
    ],
    "NC10H21-OO": [
      2,
      640.98,
      7.15,
      0,
      0,
      1,
      173.276
    ],
    "NC12H25": [
      2,
      580,
      7.6,
      0,
      0,
      1,
      169.331
    ],
    "NC12H25-OO": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      201.329
    ],
    "C2H4OH": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      45.0611
    ],
    "CH2CHO": [
      2,
      436,
      3.97,
      0,
      0,
      2,
      43.0452
    ],
    "CH3CHOH": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      45.0611
    ],
    "NC4H9-OO": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      89.1143
    ],
    "NC5H11": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      71.1423
    ],
    "NC5H12OO": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      103.141
    ],
    "NC7H15": [
      2,
      459.98,
      6.31,
      0,
      0,
      1,
      99.1961
    ],
    "NC7H15-OO": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      131.195
    ],
    "C12H7": [
      2,
      693.1,
      6.47,
      0,
      18,
      1,
      151.188
    ],
    "CH3COCH2": [
      2,
      424.6,
      4.82,
      0,
      0,
      1,
      57.0721
    ],
    "C2H4CHO": [
      2,
      424.6,
      4.82,
      0,
      0,
      1,
      57.0721
    ],
    "CYC6-OO": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      115.152
    ],
    "CYC6H11": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      83.1533
    ],
    "CYC6H9": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      81.1375
    ],
    "CYC5H5": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      65.0947
    ],
    "RDIPE": [
      2,
      432,
      6,
      0,
      0,
      1,
      101.169
    ],
    "CH3OCH2": [
      2,
      303.4,
      4.81,
      0,
      0,
      1,
      45.0611
    ],
    "DME-OO": [
      2,
      403.4,
      4.81,
      0,
      0,
      1,
      77.0599
    ],
    "C6H4C2H": [
      2,
      535.6,
      5.72,
      0.77,
      12,
      1,
      101.128
    ],
    "RBIPHENYL": [
      2,
      676.5,
      6.31,
      0,
      0,
      1,
      153.203
    ],
    "C14H9": [
      2,
      772,
      6.96,
      0,
      38.8,
      1,
      177.225
    ],
    "C10H7": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      127.166
    ],
    "IC16H33-OO": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      257.437
    ],
    "IC16H33": [
      2,
      650,
      8.35,
      0,
      0,
      1,
      225.438
    ],
    "IC8H17": [
      2,
      494,
      6.17,
      0,
      0,
      1,
      113.223
    ],
    "IC8H17-OO": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      145.222
    ],
    "INDENYL": [
      2,
      588.6,
      5.96,
      0,
      0,
      1,
      115.155
    ],
    "RMCYC6-OO": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      129.179
    ],
    "RMCYC6": [
      2,
      495.3,
      5.68,
      0.43,
      12.3,
      1,
      97.1802
    ],
    "C10H7CH2": [
      2,
      660,
      6.35,
      0,
      0,
      1,
      141.192
    ],
    "C10H6CH3": [
      2,
      660,
      6.35,
      0,
      0,
      1,
      141.192
    ],
    "C6H4CH3": [
      2,
      495.3,
      5.68,
      0,
      0,
      1,
      91.1326
    ],
    "RMTBE": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      87.1417
    ],
    "MTBE-OO": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      119.141
    ],
    "C10H7O": [
      2,
      630.4,
      6.18,
      0,
      0,
      1,
      143.165
    ],
    "NEOC5H11": [
      2,
      392,
      5.64,
      0,
      0,
      1,
      71.1423
    ],
    "NEOC5H11-OO": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      103.141
    ],
    "C16H9": [
      2,
      834.9,
      7.24,
      0,
      45,
      1,
      201.247
    ],
    "C6H5C2H2": [
      2,
      546.2,
      6,
      0,
      0,
      1,
      103.144
    ],
    "RXYLENE": [
      2,
      523.6,
      5.96,
      0,
      0,
      1,
      105.159
    ],
    "C6H5C2H3": [
      2,
      546.2,
      6,
      0.13,
      15,
      1,
      104.152
    ],
    "TAME": [
      2,
      432,
      6,
      0,
      0,
      1,
      102.177
    ],
    "TETRALIN": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      132.205
    ],
    "DECALIN": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      138.253
    ],
    "RDECALIN": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      137.245
    ],
    "C7H8": [
      2,
      495.3,
      5.68,
      0.43,
      12.3,
      1,
      92.1405
    ],
    "C2H3": [
      2,
      209,
      4.1,
      0,
      0,
      1,
      27.0458
    ],
    "XYLENE": [
      2,
      523.6,
      5.96,
      0,
      0,
      1,
      106.167
    ],
    "NC10-OOQOOH": [
      2,
      640.98,
      7.15,
      0,
      0,
      1,
      205.274
    ],
    "NC12-OOQOOH": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      233.328
    ],
    "NC4-OOQOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      121.113
    ],
    "NC5-OOQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      135.14
    ],
    "NC7-OOQOOH": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      163.194
    ],
    "DME-OOQOOH": [
      2,
      403.4,
      4.81,
      0,
      0,
      1,
      109.059
    ],
    "IC16-OOQOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      289.436
    ],
    "IC16T-OOQOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      289.436
    ],
    "IC8-OOQOOH": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      177.221
    ],
    "IC4P-OOQOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      121.113
    ],
    "IC4T-OOQOOH": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      121.113
    ],
    "MCYC6-OOQOOH": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      161.178
    ],
    "MTBE-OOQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      151.139
    ],
    "NEOC5-OOQOOH": [
      2,
      492,
      5.64,
      0,
      0,
      1,
      135.14
    ],
    "MCYC6T-OOQOOH": [
      2,
      595.3,
      5.68,
      0.43,
      12.3,
      1,
      161.178
    ],
    "NC16H34": [
      2,
      650,
      8.35,
      0,
      0,
      1,
      226.446
    ],
    "NC16H33": [
      2,
      650,
      8.35,
      0,
      0,
      1,
      225.438
    ],
    "NC16H33-OO": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      257.437
    ],
    "NC16-QOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      257.437
    ],
    "NC16-OOQOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      289.436
    ],
    "NC16-OQOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      272.428
    ],
    "CN": [
      1,
      75,
      3.856,
      0,
      0,
      1,
      26.0177
    ],
    "H2CN": [
      1,
      569,
      3.63,
      0,
      0,
      1,
      28.0336
    ],
    "H2NO": [
      2,
      116.7,
      3.492,
      0,
      0,
      1,
      32.022
    ],
    "HCN": [
      1,
      569,
      3.63,
      0,
      0,
      1,
      27.0257
    ],
    "HCNO": [
      2,
      232.4,
      3.828,
      0,
      0,
      1,
      43.0251
    ],
    "HOCN": [
      2,
      232.4,
      3.828,
      0,
      0,
      1,
      43.0251
    ],
    "HNCO": [
      2,
      232.4,
      3.828,
      0,
      0,
      1,
      43.0251
    ],
    "HNNO": [
      2,
      232.4,
      3.828,
      0,
      0,
      1,
      45.0208
    ],
    "HNO": [
      2,
      116.7,
      3.492,
      0,
      0,
      1,
      31.0141
    ],
    "N": [
      0,
      71.4,
      3.298,
      0,
      0,
      0,
      14.0067
    ],
    "N2H2": [
      2,
      71.4,
      3.798,
      0,
      0,
      1,
      30.0294
    ],
    "N2H3": [
      2,
      200,
      3.9,
      0,
      0,
      1,
      31.0373
    ],
    "N2H4": [
      2,
      205,
      4.23,
      0,
      4.26,
      1.5,
      32.0452
    ],
    "N2O": [
      1,
      232.4,
      3.828,
      0,
      0,
      1,
      44.0129
    ],
    "NCO": [
      1,
      232.4,
      3.828,
      0,
      0,
      1,
      42.0171
    ],
    "NH": [
      1,
      80,
      2.65,
      0,
      0,
      4,
      15.0147
    ],
    "NH2": [
      2,
      80,
      2.65,
      0,
      2.26,
      4,
      16.0226
    ],
    "NH3": [
      2,
      481,
      2.92,
      1.47,
      0,
      10,
      17.0306
    ],
    "NNH": [
      2,
      71.4,
      3.798,
      0,
      0,
      1,
      29.0214
    ],
    "NO": [
      1,
      97.5,
      3.621,
      0,
      1.76,
      4,
      30.0061
    ],
    "NO2": [
      2,
      200,
      3.5,
      0,
      0,
      1,
      46.0055
    ],
    "HONO": [
      2,
      200,
      3.5,
      0,
      0,
      1,
      47.0135
    ],
    "HNO2": [
      2,
      200,
      3.5,
      0,
      0,
      1,
      47.0135
    ],
    "NO3": [
      2,
      300,
      3.5,
      0,
      0,
      1,
      62.0049
    ],
    "HONO2": [
      2,
      300,
      3.5,
      0,
      0,
      1,
      63.0129
    ],
    "CH3CN": [
      1,
      500,
      4.63,
      0,
      0,
      1,
      41.0526
    ],
    "CH3NO2": [
      2,
      200,
      4.5,
      0,
      0,
      1,
      61.0404
    ],
    "CH3ONO": [
      2,
      200,
      4.5,
      0,
      0,
      1,
      61.0404
    ],
    "CH3NO": [
      1,
      97.5,
      3.621,
      0,
      1.76,
      4,
      45.041
    ],
    "CH3ONO2": [
      2,
      300,
      4.5,
      0,
      0,
      1,
      77.0398
    ],
    "CH2CN": [
      1,
      232.4,
      3.828,
      0,
      0,
      1,
      40.0446
    ],
    "BIN1A": [
      2,
      951.685,
      8.471,
      0,
      0,
      1,
      256.347
    ],
    "BIN1B": [
      2,
      951.685,
      8.471,
      0,
      0,
      1,
      250.299
    ],
    "CYC6-QOOH-2": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      115.152
    ],
    "CYC6-QOOH-3": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      115.152
    ],
    "CYC6-QOOH-4": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      115.152
    ],
    "CYC6-OOQOOH-2": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      147.151
    ],
    "CYC6-OOQOOH-3": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      147.151
    ],
    "CYC6-OOQOOH-4": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      147.151
    ],
    "CYC6-OQOOH-2": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      130.144
    ],
    "CYC6-OQOOH-3": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      130.144
    ],
    "CYC6-OQOOH-4": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      130.144
    ],
    "CYC6H10-O-12": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      98.1448
    ],
    "CYC6H10-O-13": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      98.1448
    ],
    "CYC6H10-O-14": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      98.1448
    ],
    "C3H5OOH": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      74.0794
    ],
    "C5EN-OQOOH-35": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      116.117
    ],
    "C5H8O": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      84.1179
    ],
    "NC5H9-3": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      69.1265
    ],
    "C3H5OO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      73.0715
    ],
    "C5EN-OO": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      101.125
    ],
    "C5EN-QOOH": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      101.125
    ],
    "C5EN-OOQOOH-35": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      133.124
    ],
    "NC3H7OH": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      60.0959
    ],
    "N1C4H9OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      74.1228
    ],
    "N2C4H9OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      74.1228
    ],
    "CH3CH2CHOHCH2": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CH2CHOCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CH2COHCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CHCHOHCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH2CH2CHOHCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "MEK": [
      2,
      454,
      5.413,
      3.3,
      0,
      1,
      72.1069
    ],
    "TC4H9OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      74.1228
    ],
    "IC4H9OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      74.1228
    ],
    "CH3CH2CH2CH2O": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "C3H7CHO": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      72.1069
    ],
    "CH3CH2CHOH": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      59.088
    ],
    "CH3CHCH2OH": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      59.088
    ],
    "CH2CH2CH2OH": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      59.088
    ],
    "CH3CH2CH2O": [
      2,
      482.146548,
      5.008549665,
      1.66,
      6.74,
      1,
      59.088
    ],
    "CH3COHCH3": [
      2,
      468.3,
      4.76,
      0,
      0,
      1,
      59.088
    ],
    "CH2CHOHCH3": [
      2,
      468.3,
      4.76,
      0,
      0,
      1,
      59.088
    ],
    "CH3CH2CH2CHOH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CH2CHCH2OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CHCH2CH2OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH2CH2CH2CH2OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "RTC4H8OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "RTC4H9O": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CHCH2OCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CHCH3CHOH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH3CCH2OHCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "CH2CHCH2OHCH3": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      73.1149
    ],
    "C4H7OH": [
      2,
      503.0722524,
      5.339941638,
      1.67,
      8.88,
      1,
      72.1069
    ],
    "C3H5OH": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      58.08
    ],
    "RCRESOLO": [
      2,
      621.1,
      5.64,
      0,
      0,
      1,
      107.132
    ],
    "RCRESOLC": [
      2,
      621.1,
      5.64,
      0,
      0,
      1,
      107.132
    ],
    "C10H10": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      130.189
    ],
    "BZFUR": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      118.135
    ],
    "ODECAL": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      138.253
    ],
    "RTETRALIN": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      131.197
    ],
    "RTETRAOO": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      163.196
    ],
    "TMBENZ": [
      2,
      523.6,
      5.96,
      0,
      0,
      1,
      120.194
    ],
    "NPBENZ": [
      2,
      495.3,
      5.68,
      0.43,
      12.3,
      1,
      120.194
    ],
    "RC9H11": [
      2,
      523.6,
      5.96,
      0,
      0,
      1,
      119.186
    ],
    "C6H5OCH3": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      108.14
    ],
    "MB": [
      2,
      468,
      5.85,
      0,
      0,
      0,
      102.133
    ],
    "RMBX": [
      2,
      468.5,
      5.23,
      0,
      0,
      1,
      101.125
    ],
    "MCROT": [
      2,
      468.5,
      5.23,
      0,
      0,
      1,
      100.117
    ],
    "MACRIL": [
      2,
      430.1,
      5.833,
      0,
      0,
      1,
      86.0904
    ],
    "RMP3": [
      2,
      430.1,
      5.833,
      0,
      0,
      1,
      87.0984
    ],
    "CH3OCO": [
      2,
      395,
      4.037,
      1.3,
      0,
      1,
      59.0446
    ],
    "ETMB583": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      116.117
    ],
    "KEHYMB": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      148.116
    ],
    "DIBZFUR": [
      2,
      676.5,
      6.31,
      0,
      0,
      1,
      168.195
    ],
    "DIFENET": [
      2,
      676.5,
      6.31,
      0,
      0,
      1,
      170.211
    ],
    "RMBOOX": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      133.124
    ],
    "QMBOOX": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      133.124
    ],
    "ZMBOOX": [
      2,
      508,
      5.2,
      0,
      0,
      1,
      165.123
    ],
    "KHDECA": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      184.235
    ],
    "QDECOOH": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      169.244
    ],
    "RDECOO": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      169.244
    ],
    "ZDECA": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      201.243
    ],
    "RMCROTA": [
      2,
      468.5,
      5.23,
      0,
      0,
      1,
      99.1094
    ],
    "MD": [
      2,
      604.4,
      7.305,
      1.7,
      0,
      1,
      186.294
    ],
    "RMDX": [
      2,
      604.4,
      7.305,
      1.7,
      0,
      1,
      185.287
    ],
    "CH3OCHO": [
      2,
      395,
      4.037,
      1.3,
      0,
      1,
      60.0526
    ],
    "ETEROMD": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      200.278
    ],
    "MDKETO": [
      2,
      680,
      7.6,
      0,
      0,
      1,
      232.277
    ],
    "C7H15COCHO": [
      2,
      594,
      6.17,
      0,
      0,
      1,
      156.225
    ],
    "RMDOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      217.285
    ],
    "QMDOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      217.285
    ],
    "ZMDOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      249.284
    ],
    "U2ME10": [
      2,
      604.4,
      7.305,
      2,
      0,
      1,
      182.263
    ],
    "UME10": [
      2,
      604.4,
      7.305,
      2,
      0,
      1,
      184.279
    ],
    "UME7": [
      2,
      556.82,
      6.41,
      1.7,
      16.14,
      1,
      142.198
    ],
    "C12H22": [
      2,
      580,
      7.6,
      0,
      0,
      1,
      166.307
    ],
    "DCYC5": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      136.237
    ],
    "UME16": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      268.44
    ],
    "ETEROMPA": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      284.439
    ],
    "MPA": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      270.456
    ],
    "KHMLIN1": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      338.444
    ],
    "MLIN1": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      292.462
    ],
    "MLINO": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      294.478
    ],
    "MEOLE": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      296.494
    ],
    "MSTEA": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      298.51
    ],
    "RUME7": [
      2,
      556.82,
      6.41,
      1.7,
      16.14,
      1,
      141.19
    ],
    "RME7": [
      2,
      556.82,
      6.41,
      1.7,
      16.14,
      1,
      143.206
    ],
    "RUME10": [
      2,
      604.4,
      7.305,
      2,
      0,
      1,
      183.271
    ],
    "RMPAX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      269.448
    ],
    "QMPAOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      301.447
    ],
    "RMPAOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      301.447
    ],
    "ZMPAOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      333.445
    ],
    "RMLIN1A": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      291.454
    ],
    "RMLIN1X": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      291.454
    ],
    "RMLIN1OOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      323.453
    ],
    "QMLIN1OOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      323.453
    ],
    "ZMLIN1OOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      355.452
    ],
    "RMLINA": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      293.47
    ],
    "RMLINX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      293.47
    ],
    "RMLINOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      325.469
    ],
    "QMLINOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      325.469
    ],
    "ZMLINOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      357.467
    ],
    "RMEOLEA": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      295.486
    ],
    "RMEOLES": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      295.486
    ],
    "RMEOLEOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      327.484
    ],
    "QMEOLEOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      327.484
    ],
    "ZMEOLEOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      359.483
    ],
    "RSTEAX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      297.502
    ],
    "RMSTEAOOX": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      329.5
    ],
    "QMSTEAOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      329.5
    ],
    "ZMSTEAOOH": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      361.499
    ],
    "U2ME12": [
      2,
      620,
      8,
      0,
      0,
      1,
      210.316
    ],
    "ALDEST": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      130.144
    ],
    "RALDEST": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      129.136
    ],
    "C12H18": [
      2,
      620,
      8,
      0,
      0,
      1,
      162.275
    ],
    "RODECA": [
      2,
      630.4,
      6.18,
      0,
      16.5,
      1,
      137.245
    ],
    "ALDINS": [
      2,
      620,
      8,
      0,
      0,
      1,
      192.301
    ],
    "RUME16": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      267.432
    ],
    "NC10H19": [
      2,
      540.98,
      7.15,
      0,
      0,
      1,
      139.261
    ],
    "C8H9": [
      2,
      546.2,
      6,
      0,
      0,
      1,
      105.159
    ],
    "NC7H13OOH": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      130.187
    ],
    "NC7H13": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      97.1802
    ],
    "LC6H5": [
      2,
      412.3,
      5.349,
      0,
      0,
      1,
      77.1057
    ],
    "C6H2": [
      1,
      357,
      5.18,
      0,
      0,
      1,
      74.0819
    ],
    "C8H2": [
      1,
      495.3,
      5.68,
      0.43,
      12.3,
      1,
      98.1039
    ],
    "C6H3": [
      1,
      357,
      5.18,
      0,
      0,
      1,
      75.0898
    ],
    "C6H4": [
      2,
      412.3,
      5.349,
      0,
      0,
      1,
      76.0978
    ],
    "BENZYNE": [
      2,
      468.5,
      5.23,
      0,
      10.3,
      1,
      76.0978
    ],
    "NC10MOOH": [
      2,
      640.98,
      7.15,
      0,
      0,
      1,
      172.268
    ],
    "MSTEAKETO": [
      2,
      750,
      8.35,
      0,
      0,
      1,
      344.492
    ],
    "C5H5O": [
      2,
      450,
      5.5,
      0,
      0,
      1,
      81.0941
    ],
    "C2H2O2": [
      2,
      470.6,
      4.41,
      0,
      0,
      1.5,
      58.0367
    ],
    "C2H4O2": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      60.0526
    ],
    "GLIET": [
      2,
      470.6,
      4.41,
      0,
      0,
      1.5,
      62.0684
    ],
    "C3H4O2": [
      2,
      435.2,
      4.662,
      2.7,
      0,
      1,
      72.0636
    ],
    "C3H4O3": [
      2,
      435.2,
      4.662,
      2.7,
      0,
      1,
      88.063
    ],
    "C3H6O2": [
      2,
      503.072,
      5.339,
      1.67,
      7.016,
      1,
      74.0794
    ],
    "C4H6O2": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      86.0904
    ],
    "C5H4O2": [
      2,
      524.69,
      5.653,
      0,
      0,
      1,
      96.0856
    ],
    "C5H8O4": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      132.116
    ],
    "C6H6O3": [
      2,
      567.841,
      5.915,
      0,
      0,
      1,
      126.112
    ],
    "C6H8O4": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      144.127
    ],
    "C6H10O5": [
      2,
      568.5,
      5.23,
      0,
      10.3,
      1,
      162.142
    ],
    "C8H10O3": [
      2,
      621.1,
      5.64,
      0,
      0,
      1,
      154.166
    ],
    "C9H10O2": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      150.177
    ],
    "C11H12O4": [
      2,
      663.45,
      6.362,
      0,
      0,
      1,
      208.214
    ],
    "C4H3O": [
      2,
      425.929,
      5.015,
      0,
      0,
      1,
      67.0672
    ],
    "HCOOH": [
      2,
      470.6,
      3.855,
      0,
      0,
      1,
      46.0257
    ],
    "ACETOL": [
      2,
      503.072,
      5.339,
      1.67,
      7.016,
      1,
      74.0794
    ],
    "GLYCEROL": [
      2,
      748.365,
      5.2,
      1.93,
      9.43,
      1,
      92.0947
    ],
    "CH2CCHCHO": [
      2,
      362.6,
      4.53,
      0,
      0,
      1.5,
      68.0752
    ],
    "KEHYBU1": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      120.105
    ],
    "RBU1OOX": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      105.114
    ],
    "QBU1OOX": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      105.114
    ],
    "ZBU1OOX": [
      2,
      496,
      5.2,
      0,
      0,
      1,
      137.112
    ],
    "DMF": [
      2,
      524.828,
      5.653,
      0,
      0,
      1,
      96.1289
    ],
    "DMF-3YL": [
      2,
      521.629,
      5.634,
      0,
      0,
      1,
      95.121
    ],
    "MEFU2": [
      2,
      478.946,
      5.364,
      0,
      0,
      1,
      82.102
    ],
    "C4H4O": [
      2,
      429.63,
      5.04,
      0,
      0,
      1,
      68.0752
    ],
    "ETC3H4O2": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      72.0636
    ],
    "KEA3B3": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      104.062
    ],
    "KEA3G2": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      104.062
    ],
    "RALD3G": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      57.0721
    ],
    "RALD3B": [
      2,
      411,
      4.82,
      0,
      0,
      1,
      57.0721
    ],
    "C3H5CHO": [
      2,
      357,
      5.18,
      0,
      0,
      1,
      70.091
    ],
    "C7DIONE": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      128.171
    ],
    "C7KETONE": [
      2,
      559.98,
      6.31,
      0,
      0,
      1,
      114.188
    ],
    "CH2OOHCHCHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      89.0709
    ],
    "CH2OOCH2CHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      89.0709
    ],
    "CH2CHOOHCHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      89.0709
    ],
    "CH3CHOOCHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      89.0709
    ],
    "CH2OOHCHOOCHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      121.07
    ],
    "CH2OOCHOOHCHO": [
      2,
      407.8,
      4.14,
      0,
      0,
      1,
      121.07
    ],
    "ERC4H8CHO": [
      2,
      408,
      5.2,
      0,
      0,
      1,
      85.1259
    ]
  };
  function TransportParameters() {
    let _transportDict = transportDict;
    function getGeometry(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][0];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getLJpotential(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][1];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getLJdiameter(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][2];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getDipole(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][3];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getPolar(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][4];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getCollision(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][5];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    function getMolecularWeight(gasSpecieName) {
      try {
        return _transportDict[gasSpecieName][6];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName);
      }
    }
    return {
      getGeometry,
      getLJpotential,
      getLJdiameter,
      getDipole,
      getPolar,
      getCollision,
      getMolecularWeight
    };
  }

  // src/omega.js
  var omegaDict = {
    "11": {
      "d": [
        0,
        0.25,
        0.5,
        0.75,
        1,
        1.5,
        2,
        2.5
      ],
      "t": [
        0.1,
        0.2,
        0.3,
        0.4,
        0.5,
        0.6,
        0.7,
        0.8,
        0.9,
        1,
        1.2,
        1.4,
        1.6,
        1.8,
        2,
        2.5,
        3,
        3.5,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        12,
        14,
        16,
        18,
        20,
        25,
        30,
        35,
        40,
        50,
        75,
        100
      ],
      "matrix": [
        [
          4.0079171146515495,
          4.001876172607879,
          4.65606936416185,
          5.521153846153846,
          6.451581975071909,
          8.213333333333333,
          9.828897338403042,
          11.31303520456708
        ],
        [
          3.129892555640829,
          3.1626794258373208,
          3.354961832061069,
          3.720532319391635,
          4.197916666666666,
          5.230046948356808,
          6.22607879924953,
          7.159774436090226
        ],
        [
          2.6494075939919766,
          2.6579194001874415,
          2.769811320754717,
          3.002843601895735,
          3.3185255198487713,
          4.053370786516854,
          4.786181139122316,
          5.484593837535014
        ],
        [
          2.314374542794441,
          2.3201471941122356,
          2.401114206128134,
          2.5715622076707203,
          2.8127340823970037,
          3.386046511627907,
          3.9721706864564004,
          4.540816326530612
        ],
        [
          2.0661358907084053,
          2.0737704918032787,
          2.140625,
          2.2777777777777777,
          2.472170686456401,
          2.9454713493530496,
          3.4381918819188186,
          3.9197416974169736
        ],
        [
          1.876621037463977,
          1.884963768115942,
          1.9434306569343063,
          2.0596877869605144,
          2.225598526703499,
          2.628099173553719,
          3.0541284403669726,
          3.473394495412844
        ],
        [
          1.729350368904085,
          1.7380307136404698,
          1.7909090909090908,
          1.8922374429223745,
          2.0356816102470265,
          2.387214611872146,
          2.762773722627737,
          3.136986301369863
        ],
        [
          1.6122118155619596,
          1.6214995483288166,
          1.6696914700544463,
          1.759781619654231,
          1.885245901639344,
          2.197272727272727,
          2.534545454545454,
          2.8717015468607827
        ],
        [
          1.5174995489806962,
          1.527124773960217,
          1.572595281306715,
          1.6530426884650318,
          1.7656675749318802,
          2.043438914027149,
          2.349321266968326,
          2.656702898550724
        ],
        [
          1.4398445268010485,
          1.4501811594202898,
          1.4904805077062555,
          1.5639165911151407,
          1.664855072463768,
          1.9169675090252707,
          2.1956717763751126,
          2.478339350180505
        ],
        [
          1.3204174228675136,
          1.3294010889292196,
          1.3635539437896647,
          1.4244343891402715,
          1.5085817524841916,
          1.720323741007194,
          1.9560538116591928,
          2.198206278026906
        ],
        [
          1.2335912608101958,
          1.2420382165605095,
          1.2715712988192551,
          1.3233695652173914,
          1.3935018050541514,
          1.5730941704035875,
          1.7774798927613942,
          1.9892857142857143
        ],
        [
          1.167883211678832,
          1.1760948905109487,
          1.2020018198362148,
          1.245693563009973,
          1.305956678700361,
          1.4605734767025087,
          1.639607493309545,
          1.826512455516014
        ],
        [
          1.116604221876999,
          1.1242009132420092,
          1.1455868971792538,
          1.1851179673321233,
          1.236462093862816,
          1.3715308863025963,
          1.5298308103294747,
          1.6980461811722913
        ],
        [
          1.0752698006219132,
          1.0822669104204752,
          1.1020966271649955,
          1.1352087114337566,
          1.1806684733514001,
          1.300179211469534,
          1.4407836153161175,
          1.5913120567375887
        ],
        [
          1.0006406736225517,
          1.0054844606946984,
          1.0200546946216955,
          1.046405823475887,
          1.079638009049774,
          1.169506726457399,
          1.2778272484416742,
          1.3964601769911507
        ],
        [
          0.9500640204865557,
          0.9534246575342467,
          0.9653600729261622,
          0.9854413102820746,
          1.0117753623188406,
          1.0817610062893082,
          1.1675579322638145,
          1.2648361381753763
        ],
        [
          0.9130708805261235,
          0.9160583941605839,
          0.9253187613843351,
          0.9409090909090908,
          0.9628286491387127,
          1.018884892086331,
          1.0902591599642537,
          1.1703637976929901
        ],
        [
          0.8845234838121294,
          0.8871467639015497,
          0.8944494995450409,
          0.9074477747502271,
          0.92481884057971,
          0.9720720720720719,
          1.0313059033989265,
          1.0976909413854352
        ],
        [
          0.8427389287987634,
          0.8446363636363636,
          0.8501362397820165,
          0.8596188747731397,
          0.8713122171945702,
          0.9054054054054053,
          0.9480286738351255,
          0.9982190560997328
        ],
        [
          0.812843537414966,
          0.814052583862194,
          0.8179347826086956,
          0.8247963800904977,
          0.8345388788426763,
          0.8599099099099099,
          0.8928251121076234,
          0.9313113291703836
        ],
        [
          0.7897918552036199,
          0.7910407239819005,
          0.7938517179023508,
          0.7990063233965673,
          0.8064079422382671,
          0.8263726372637265,
          0.8524663677130045,
          0.8833035714285713
        ],
        [
          0.7711253612716764,
          0.77226738934056,
          0.7743682310469313,
          0.7790613718411551,
          0.784761045987376,
          0.8004496402877697,
          0.8218834080717489,
          0.8473637176050045
        ],
        [
          0.7555224957172482,
          0.7563570784490532,
          0.7587015329125338,
          0.7618018018018018,
          0.7664266426642664,
          0.7796945193171608,
          0.7977578475336322,
          0.8185880250223414
        ],
        [
          0.7421896101557577,
          0.7426642664266426,
          0.7446444644464447,
          0.7477947794779478,
          0.7514388489208632,
          0.7623877917414722,
          0.7774193548387096,
          0.7954423592493297
        ],
        [
          0.7202371328482889,
          0.7202872531418312,
          0.7222821203953279,
          0.7239676840215439,
          0.7271992818671454,
          0.7355156950672647,
          0.7463742166517457,
          0.759964253798034
        ],
        [
          0.7025551371705219,
          0.7031390134529149,
          0.703584229390681,
          0.7053763440860215,
          0.7077956989247312,
          0.7140555058191584,
          0.7228085867620752,
          0.7332142857142857
        ],
        [
          0.6877372001432153,
          0.6881826320501343,
          0.6889883616830796,
          0.6898032200357781,
          0.6916815742397137,
          0.6971377459749551,
          0.7040214477211796,
          0.7127678571428571
        ],
        [
          0.6751117468263901,
          0.6750670241286862,
          0.6757819481680072,
          0.6769436997319035,
          0.6784629133154603,
          0.6829311885612154,
          0.6884821428571428,
          0.6955396966993755
        ],
        [
          0.6640235735333512,
          0.6641071428571428,
          0.6647321428571429,
          0.665625,
          0.6669642857142857,
          0.6701159678858162,
          0.6752007136485281,
          0.6811051693404634
        ],
        [
          0.6413793103448275,
          0.641711229946524,
          0.6420677361853833,
          0.10793226381461675,
          0.6435828877005346,
          0.6455921638468388,
          0.6490650044523597,
          0.6529359430604982
        ],
        [
          0.6234723828159743,
          0.6237544483985764,
          0.6240213523131672,
          0.6244661921708184,
          0.6250889679715302,
          0.6269572953736654,
          0.6289777777777777,
          0.6321777777777778
        ],
        [
          0.6088018474109602,
          0.6087921847246892,
          0.6090586145648312,
          0.6093250444049735,
          0.6098579040852576,
          0.6112788632326821,
          0.6132326820603908,
          0.6156305506216697
        ],
        [
          0.5963984742304622,
          0.5966282165039929,
          0.5968056787932564,
          0.5969831410825199,
          0.5974267968056788,
          0.59849157054126,
          0.6,
          0.6014184397163121
        ],
        [
          0.5762503319465345,
          0.5761061946902656,
          0.576283185840708,
          0.5763716814159292,
          0.5766371681415929,
          0.5773451327433629,
          0.5782300884955752,
          0.5798051372896368
        ],
        [
          0.541467501543346,
          0.5415343915343915,
          0.5417107583774251,
          0.541409691629956,
          0.5415859030837005,
          0.5421516754850089,
          0.5421516754850089,
          0.5430212014134276
        ],
        [
          0.5180394227384724,
          0.5179419525065962,
          0.5183817062445031,
          0.5184534270650264,
          0.5182616330114136,
          0.5185413005272408,
          0.5184696569920845,
          0.5185022026431718
        ]
      ]
    },
    "22": {
      "d": [
        0,
        0.25,
        0.5,
        0.75,
        1,
        1.5,
        2,
        2.5
      ],
      "t": [
        0.1,
        0.2,
        0.3,
        0.4,
        0.5,
        0.6,
        0.7,
        0.8,
        0.9,
        1,
        1.2,
        1.4,
        1.6,
        1.8,
        2,
        2.5,
        3,
        3.5,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        12,
        14,
        16,
        18,
        20,
        25,
        30,
        35,
        40,
        50,
        75,
        100
      ],
      "matrix": [
        [
          4.1005,
          4.266,
          4.833,
          5.742,
          6.729,
          8.624,
          10.34,
          11.89
        ],
        [
          3.2626,
          3.305,
          3.516,
          3.914,
          4.433,
          5.57,
          6.637,
          7.618
        ],
        [
          2.8399,
          2.836,
          2.936,
          3.168,
          3.511,
          4.329,
          5.126,
          5.874
        ],
        [
          2.531,
          2.522,
          2.586,
          2.749,
          3.004,
          3.64,
          4.282,
          4.895
        ],
        [
          2.2837,
          2.277,
          2.329,
          2.46,
          2.665,
          3.187,
          3.727,
          4.249
        ],
        [
          2.0838,
          2.081,
          2.13,
          2.243,
          2.417,
          2.862,
          3.329,
          3.786
        ],
        [
          1.922,
          1.924,
          1.97,
          2.072,
          2.225,
          2.614,
          3.028,
          3.435
        ],
        [
          1.7902,
          1.795,
          1.84,
          1.934,
          2.07,
          2.417,
          2.788,
          3.156
        ],
        [
          1.6823,
          1.689,
          1.733,
          1.82,
          1.944,
          2.258,
          2.596,
          2.933
        ],
        [
          1.5929,
          1.601,
          1.644,
          1.725,
          1.838,
          2.124,
          2.435,
          2.746
        ],
        [
          1.4551,
          1.465,
          1.504,
          1.574,
          1.67,
          1.913,
          2.181,
          2.451
        ],
        [
          1.3551,
          1.365,
          1.4,
          1.461,
          1.544,
          1.754,
          1.989,
          2.228
        ],
        [
          1.28,
          1.289,
          1.321,
          1.374,
          1.447,
          1.63,
          1.838,
          2.053
        ],
        [
          1.2219,
          1.231,
          1.259,
          1.306,
          1.37,
          1.532,
          1.718,
          1.912
        ],
        [
          1.1757,
          1.184,
          1.209,
          1.251,
          1.307,
          1.451,
          1.618,
          1.795
        ],
        [
          1.0933,
          1.1,
          1.119,
          1.15,
          1.193,
          1.304,
          1.435,
          1.578
        ],
        [
          1.0388,
          1.044,
          1.059,
          1.083,
          1.117,
          1.204,
          1.31,
          1.428
        ],
        [
          0.99963,
          1.004,
          1.016,
          1.035,
          1.062,
          1.133,
          1.22,
          1.319
        ],
        [
          0.96988,
          0.9732,
          0.983,
          0.9991,
          1.021,
          1.079,
          1.153,
          1.236
        ],
        [
          0.92676,
          0.9291,
          0.936,
          0.9473,
          0.9628,
          1.005,
          1.058,
          1.121
        ],
        [
          0.89616,
          0.8979,
          0.903,
          0.9114,
          0.923,
          0.9545,
          0.9955,
          1.044
        ],
        [
          0.87272,
          0.8741,
          0.878,
          0.8845,
          0.8935,
          0.9181,
          0.9505,
          0.9893
        ],
        [
          0.85379,
          0.8549,
          0.858,
          0.8632,
          0.8703,
          0.8901,
          0.9164,
          0.9482
        ],
        [
          0.83795,
          0.8388,
          0.8414,
          0.8456,
          0.8515,
          0.8678,
          0.8895,
          0.916
        ],
        [
          0.82435,
          0.8251,
          0.8273,
          0.8308,
          0.8356,
          0.8493,
          0.8676,
          0.8901
        ],
        [
          0.80184,
          0.8024,
          0.8039,
          0.8065,
          0.8101,
          0.8201,
          0.8337,
          0.8504
        ],
        [
          0.78363,
          0.784,
          0.7852,
          0.7872,
          0.7899,
          0.7976,
          0.8081,
          0.8212
        ],
        [
          0.76834,
          0.7687,
          0.7696,
          0.7712,
          0.7733,
          0.7794,
          0.7878,
          0.7983
        ],
        [
          0.75518,
          0.7554,
          0.7562,
          0.7575,
          0.7592,
          0.7642,
          0.7711,
          0.7797
        ],
        [
          0.74364,
          0.7438,
          0.7445,
          0.7455,
          0.747,
          0.7512,
          0.7569,
          0.7642
        ],
        [
          0.71982,
          0.72,
          0.7204,
          0.1211,
          0.7221,
          0.725,
          0.7289,
          0.7339
        ],
        [
          0.70097,
          0.7011,
          0.7014,
          0.7019,
          0.7026,
          0.7047,
          0.7076,
          0.7112
        ],
        [
          0.68545,
          0.6855,
          0.6858,
          0.6861,
          0.6867,
          0.6883,
          0.6905,
          0.6932
        ],
        [
          0.67232,
          0.6724,
          0.6726,
          0.6728,
          0.6733,
          0.6745,
          0.6762,
          0.6784
        ],
        [
          0.65099,
          0.651,
          0.6512,
          0.6513,
          0.6516,
          0.6524,
          0.6534,
          0.6546
        ],
        [
          0.61397,
          0.6141,
          0.6143,
          0.6145,
          0.6147,
          0.6148,
          0.6148,
          0.6147
        ],
        [
          0.5887,
          0.5889,
          0.5894,
          0.59,
          0.5903,
          0.5901,
          0.5895,
          0.5885
        ]
      ]
    }
  };
  function findLowerAndUpperIndex(value, array) {
    if (value < array[0]) {
      return [0, 1];
    } else if (value > array[array.length - 1]) {
      return [array.length - 2, array.length - 1];
    } else {
      for (let i = 0; i < array.length - 1; i++) {
        if (value >= array[i] && value < array[i + 1]) {
          return [i, i + 1];
        }
      }
    }
  }
  function collisionIntegralsEvaluation(omega, tr, dr) {
    let Ta = 0;
    let Tb = 0;
    let da = 0;
    let db = 0;
    [Ta, Tb] = findLowerAndUpperIndex(tr, omega.t);
    [da, db] = findLowerAndUpperIndex(dr, omega.d);
    let b = [0, 0, 0, 0];
    b[0] = omega.matrix[Ta][da];
    b[1] = omega.matrix[Ta][db];
    b[2] = omega.matrix[Tb][da];
    b[3] = omega.matrix[Tb][db];
    let x = [0, 0, 0, 0];
    x[3] = (b[0] - b[1] - b[2] + b[3]) / (omega.t[Ta] * omega.d[da] - omega.t[Ta] * omega.d[db] - omega.t[Tb] * omega.d[da] + omega.t[Tb] * omega.d[db]);
    x[2] = (-x[3] * (omega.t[Ta] * omega.d[da] - omega.t[Ta] * omega.d[db]) - b[1] + b[0]) / (omega.d[da] - omega.d[db]);
    x[1] = (-x[3] * (omega.t[Ta] * omega.d[da] - omega.t[Tb] * omega.d[da]) - b[2] + b[0]) / (omega.t[Ta] - omega.t[Tb]);
    x[0] = -x[1] * omega.t[Ta] - x[2] * omega.d[da] - x[3] * omega.t[Ta] * omega.d[da] + b[0];
    return x[0] + x[1] * tr + x[2] * dr + x[3] * tr * dr;
  }
  function CollisionIntegral11(tr, dr) {
    return collisionIntegralsEvaluation(omegaDict["11"], tr, dr);
  }
  function CollisionIntegral22(tr, dr) {
    return collisionIntegralsEvaluation(omegaDict["22"], tr, dr);
  }

  // node_modules/@babel/runtime/helpers/esm/extends.js
  function _extends() {
    return _extends = Object.assign ? Object.assign.bind() : function(n) {
      for (var e = 1; e < arguments.length; e++) {
        var t = arguments[e];
        for (var r in t) ({}).hasOwnProperty.call(t, r) && (n[r] = t[r]);
      }
      return n;
    }, _extends.apply(null, arguments);
  }

  // node_modules/mathjs/lib/esm/core/config.js
  var DEFAULT_CONFIG = {
    // minimum relative difference between two compared values,
    // used by all comparison functions
    epsilon: 1e-12,
    // type of default matrix output. Choose 'matrix' (default) or 'array'
    matrix: "Matrix",
    // type of default number output. Choose 'number' (default) 'BigNumber', or 'Fraction
    number: "number",
    // number of significant digits in BigNumbers
    precision: 64,
    // predictable output type of functions. When true, output type depends only
    // on the input types. When false (default), output type can vary depending
    // on input values. For example `math.sqrt(-4)` returns `complex('2i')` when
    // predictable is false, and returns `NaN` when true.
    predictable: false,
    // random seed for seeded pseudo random number generation
    // null = randomly seed
    randomSeed: null
  };

  // node_modules/mathjs/lib/esm/utils/is.js
  function isNumber(x) {
    return typeof x === "number";
  }
  function isBigNumber(x) {
    if (!x || typeof x !== "object" || typeof x.constructor !== "function") {
      return false;
    }
    if (x.isBigNumber === true && typeof x.constructor.prototype === "object" && x.constructor.prototype.isBigNumber === true) {
      return true;
    }
    if (typeof x.constructor.isDecimal === "function" && x.constructor.isDecimal(x) === true) {
      return true;
    }
    return false;
  }
  function isComplex(x) {
    return x && typeof x === "object" && Object.getPrototypeOf(x).isComplex === true || false;
  }
  function isFraction(x) {
    return x && typeof x === "object" && Object.getPrototypeOf(x).isFraction === true || false;
  }
  function isUnit(x) {
    return x && x.constructor.prototype.isUnit === true || false;
  }
  function isString(x) {
    return typeof x === "string";
  }
  var isArray = Array.isArray;
  function isMatrix(x) {
    return x && x.constructor.prototype.isMatrix === true || false;
  }
  function isCollection(x) {
    return Array.isArray(x) || isMatrix(x);
  }
  function isDenseMatrix(x) {
    return x && x.isDenseMatrix && x.constructor.prototype.isMatrix === true || false;
  }
  function isSparseMatrix(x) {
    return x && x.isSparseMatrix && x.constructor.prototype.isMatrix === true || false;
  }
  function isRange(x) {
    return x && x.constructor.prototype.isRange === true || false;
  }
  function isIndex(x) {
    return x && x.constructor.prototype.isIndex === true || false;
  }
  function isBoolean(x) {
    return typeof x === "boolean";
  }
  function isResultSet(x) {
    return x && x.constructor.prototype.isResultSet === true || false;
  }
  function isHelp(x) {
    return x && x.constructor.prototype.isHelp === true || false;
  }
  function isFunction(x) {
    return typeof x === "function";
  }
  function isDate(x) {
    return x instanceof Date;
  }
  function isRegExp(x) {
    return x instanceof RegExp;
  }
  function isObject(x) {
    return !!(x && typeof x === "object" && x.constructor === Object && !isComplex(x) && !isFraction(x));
  }
  function isNull(x) {
    return x === null;
  }
  function isUndefined(x) {
    return x === void 0;
  }
  function isAccessorNode(x) {
    return x && x.isAccessorNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isArrayNode(x) {
    return x && x.isArrayNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isAssignmentNode(x) {
    return x && x.isAssignmentNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isBlockNode(x) {
    return x && x.isBlockNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isConditionalNode(x) {
    return x && x.isConditionalNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isConstantNode(x) {
    return x && x.isConstantNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isFunctionAssignmentNode(x) {
    return x && x.isFunctionAssignmentNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isFunctionNode(x) {
    return x && x.isFunctionNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isIndexNode(x) {
    return x && x.isIndexNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isNode(x) {
    return x && x.isNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isObjectNode(x) {
    return x && x.isObjectNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isOperatorNode(x) {
    return x && x.isOperatorNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isParenthesisNode(x) {
    return x && x.isParenthesisNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isRangeNode(x) {
    return x && x.isRangeNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isSymbolNode(x) {
    return x && x.isSymbolNode === true && x.constructor.prototype.isNode === true || false;
  }
  function isChain(x) {
    return x && x.constructor.prototype.isChain === true || false;
  }
  function typeOf(x) {
    var t = typeof x;
    if (t === "object") {
      if (x === null) return "null";
      if (Array.isArray(x)) return "Array";
      if (x instanceof Date) return "Date";
      if (x instanceof RegExp) return "RegExp";
      if (isBigNumber(x)) return "BigNumber";
      if (isComplex(x)) return "Complex";
      if (isFraction(x)) return "Fraction";
      if (isMatrix(x)) return "Matrix";
      if (isUnit(x)) return "Unit";
      if (isIndex(x)) return "Index";
      if (isRange(x)) return "Range";
      if (isResultSet(x)) return "ResultSet";
      if (isNode(x)) return x.type;
      if (isChain(x)) return "Chain";
      if (isHelp(x)) return "Help";
      return "Object";
    }
    if (t === "function") return "Function";
    return t;
  }

  // node_modules/mathjs/lib/esm/utils/object.js
  function clone(x) {
    var type = typeof x;
    if (type === "number" || type === "string" || type === "boolean" || x === null || x === void 0) {
      return x;
    }
    if (typeof x.clone === "function") {
      return x.clone();
    }
    if (Array.isArray(x)) {
      return x.map(function(value) {
        return clone(value);
      });
    }
    if (x instanceof Date) return new Date(x.valueOf());
    if (isBigNumber(x)) return x;
    if (x instanceof RegExp) throw new TypeError("Cannot clone " + x);
    return mapObject(x, clone);
  }
  function mapObject(object, callback) {
    var clone3 = {};
    for (var key in object) {
      if (hasOwnProperty(object, key)) {
        clone3[key] = callback(object[key]);
      }
    }
    return clone3;
  }
  function extend(a, b) {
    for (var prop in b) {
      if (hasOwnProperty(b, prop)) {
        a[prop] = b[prop];
      }
    }
    return a;
  }
  function deepStrictEqual(a, b) {
    var prop, i, len;
    if (Array.isArray(a)) {
      if (!Array.isArray(b)) {
        return false;
      }
      if (a.length !== b.length) {
        return false;
      }
      for (i = 0, len = a.length; i < len; i++) {
        if (!deepStrictEqual(a[i], b[i])) {
          return false;
        }
      }
      return true;
    } else if (typeof a === "function") {
      return a === b;
    } else if (a instanceof Object) {
      if (Array.isArray(b) || !(b instanceof Object)) {
        return false;
      }
      for (prop in a) {
        if (!(prop in b) || !deepStrictEqual(a[prop], b[prop])) {
          return false;
        }
      }
      for (prop in b) {
        if (!(prop in a)) {
          return false;
        }
      }
      return true;
    } else {
      return a === b;
    }
  }
  function hasOwnProperty(object, property) {
    return object && Object.hasOwnProperty.call(object, property);
  }
  function pickShallow(object, properties) {
    var copy = {};
    for (var i = 0; i < properties.length; i++) {
      var key = properties[i];
      var value = object[key];
      if (value !== void 0) {
        copy[key] = value;
      }
    }
    return copy;
  }

  // node_modules/mathjs/lib/esm/core/function/config.js
  var MATRIX_OPTIONS = ["Matrix", "Array"];
  var NUMBER_OPTIONS = ["number", "BigNumber", "Fraction"];

  // node_modules/mathjs/lib/esm/entry/configReadonly.js
  var config = function config2(options) {
    if (options) {
      throw new Error("The global config is readonly. \nPlease create a mathjs instance if you want to change the default configuration. \nExample:\n\n  import { create, all } from 'mathjs';\n  const mathjs = create(all);\n  mathjs.config({ number: 'BigNumber' });\n");
    }
    return Object.freeze(DEFAULT_CONFIG);
  };
  _extends(config, DEFAULT_CONFIG, {
    MATRIX_OPTIONS,
    NUMBER_OPTIONS
  });

  // node_modules/mathjs/lib/esm/core/function/typed.js
  var import_typed_function = __toESM(require_typed_function(), 1);

  // node_modules/mathjs/lib/esm/utils/number.js
  function isInteger(value) {
    if (typeof value === "boolean") {
      return true;
    }
    return isFinite(value) ? value === Math.round(value) : false;
  }
  var sign = Math.sign || function(x) {
    if (x > 0) {
      return 1;
    } else if (x < 0) {
      return -1;
    } else {
      return 0;
    }
  };
  var log2 = Math.log2 || function log22(x) {
    return Math.log(x) / Math.LN2;
  };
  var log10 = Math.log10 || function log102(x) {
    return Math.log(x) / Math.LN10;
  };
  var log1p = Math.log1p || function(x) {
    return Math.log(x + 1);
  };
  var cbrt = Math.cbrt || function cbrt2(x) {
    if (x === 0) {
      return x;
    }
    var negate = x < 0;
    var result;
    if (negate) {
      x = -x;
    }
    if (isFinite(x)) {
      result = Math.exp(Math.log(x) / 3);
      result = (x / (result * result) + 2 * result) / 3;
    } else {
      result = x;
    }
    return negate ? -result : result;
  };
  var expm1 = Math.expm1 || function expm12(x) {
    return x >= 2e-4 || x <= -2e-4 ? Math.exp(x) - 1 : x + x * x / 2 + x * x * x / 6;
  };
  function formatNumberToBase(n, base, size2) {
    var prefixes = {
      2: "0b",
      8: "0o",
      16: "0x"
    };
    var prefix = prefixes[base];
    var suffix = "";
    if (size2) {
      if (size2 < 1) {
        throw new Error("size must be in greater than 0");
      }
      if (!isInteger(size2)) {
        throw new Error("size must be an integer");
      }
      if (n > 2 ** (size2 - 1) - 1 || n < -(2 ** (size2 - 1))) {
        throw new Error("Value must be in range [-2^".concat(size2 - 1, ", 2^").concat(size2 - 1, "-1]"));
      }
      if (!isInteger(n)) {
        throw new Error("Value must be an integer");
      }
      if (n < 0) {
        n = n + 2 ** size2;
      }
      suffix = "i".concat(size2);
    }
    var sign4 = "";
    if (n < 0) {
      n = -n;
      sign4 = "-";
    }
    return "".concat(sign4).concat(prefix).concat(n.toString(base)).concat(suffix);
  }
  function format(value, options) {
    if (typeof options === "function") {
      return options(value);
    }
    if (value === Infinity) {
      return "Infinity";
    } else if (value === -Infinity) {
      return "-Infinity";
    } else if (isNaN(value)) {
      return "NaN";
    }
    var notation = "auto";
    var precision;
    var wordSize;
    if (options) {
      if (options.notation) {
        notation = options.notation;
      }
      if (isNumber(options)) {
        precision = options;
      } else if (isNumber(options.precision)) {
        precision = options.precision;
      }
      if (options.wordSize) {
        wordSize = options.wordSize;
        if (typeof wordSize !== "number") {
          throw new Error('Option "wordSize" must be a number');
        }
      }
    }
    switch (notation) {
      case "fixed":
        return toFixed(value, precision);
      case "exponential":
        return toExponential(value, precision);
      case "engineering":
        return toEngineering(value, precision);
      case "bin":
        return formatNumberToBase(value, 2, wordSize);
      case "oct":
        return formatNumberToBase(value, 8, wordSize);
      case "hex":
        return formatNumberToBase(value, 16, wordSize);
      case "auto":
        return toPrecision(value, precision, options && options).replace(/((\.\d*?)(0+))($|e)/, function() {
          var digits2 = arguments[2];
          var e = arguments[4];
          return digits2 !== "." ? digits2 + e : e;
        });
      default:
        throw new Error('Unknown notation "' + notation + '". Choose "auto", "exponential", "fixed", "bin", "oct", or "hex.');
    }
  }
  function splitNumber(value) {
    var match = String(value).toLowerCase().match(/^0*?(-?)(\d+\.?\d*)(e([+-]?\d+))?$/);
    if (!match) {
      throw new SyntaxError("Invalid number " + value);
    }
    var sign4 = match[1];
    var digits2 = match[2];
    var exponent = parseFloat(match[4] || "0");
    var dot2 = digits2.indexOf(".");
    exponent += dot2 !== -1 ? dot2 - 1 : digits2.length - 1;
    var coefficients = digits2.replace(".", "").replace(/^0*/, function(zeros3) {
      exponent -= zeros3.length;
      return "";
    }).replace(/0*$/, "").split("").map(function(d) {
      return parseInt(d);
    });
    if (coefficients.length === 0) {
      coefficients.push(0);
      exponent++;
    }
    return {
      sign: sign4,
      coefficients,
      exponent
    };
  }
  function toEngineering(value, precision) {
    if (isNaN(value) || !isFinite(value)) {
      return String(value);
    }
    var split = splitNumber(value);
    var rounded = roundDigits(split, precision);
    var e = rounded.exponent;
    var c = rounded.coefficients;
    var newExp = e % 3 === 0 ? e : e < 0 ? e - 3 - e % 3 : e - e % 3;
    if (isNumber(precision)) {
      while (precision > c.length || e - newExp + 1 > c.length) {
        c.push(0);
      }
    } else {
      var missingZeros = Math.abs(e - newExp) - (c.length - 1);
      for (var i = 0; i < missingZeros; i++) {
        c.push(0);
      }
    }
    var expDiff = Math.abs(e - newExp);
    var decimalIdx = 1;
    while (expDiff > 0) {
      decimalIdx++;
      expDiff--;
    }
    var decimals = c.slice(decimalIdx).join("");
    var decimalVal = isNumber(precision) && decimals.length || decimals.match(/[1-9]/) ? "." + decimals : "";
    var str = c.slice(0, decimalIdx).join("") + decimalVal + "e" + (e >= 0 ? "+" : "") + newExp.toString();
    return rounded.sign + str;
  }
  function toFixed(value, precision) {
    if (isNaN(value) || !isFinite(value)) {
      return String(value);
    }
    var splitValue = splitNumber(value);
    var rounded = typeof precision === "number" ? roundDigits(splitValue, splitValue.exponent + 1 + precision) : splitValue;
    var c = rounded.coefficients;
    var p = rounded.exponent + 1;
    var pp = p + (precision || 0);
    if (c.length < pp) {
      c = c.concat(zeros(pp - c.length));
    }
    if (p < 0) {
      c = zeros(-p + 1).concat(c);
      p = 1;
    }
    if (p < c.length) {
      c.splice(p, 0, p === 0 ? "0." : ".");
    }
    return rounded.sign + c.join("");
  }
  function toExponential(value, precision) {
    if (isNaN(value) || !isFinite(value)) {
      return String(value);
    }
    var split = splitNumber(value);
    var rounded = precision ? roundDigits(split, precision) : split;
    var c = rounded.coefficients;
    var e = rounded.exponent;
    if (c.length < precision) {
      c = c.concat(zeros(precision - c.length));
    }
    var first = c.shift();
    return rounded.sign + first + (c.length > 0 ? "." + c.join("") : "") + "e" + (e >= 0 ? "+" : "") + e;
  }
  function toPrecision(value, precision, options) {
    if (isNaN(value) || !isFinite(value)) {
      return String(value);
    }
    var lowerExp = options && options.lowerExp !== void 0 ? options.lowerExp : -3;
    var upperExp = options && options.upperExp !== void 0 ? options.upperExp : 5;
    var split = splitNumber(value);
    var rounded = precision ? roundDigits(split, precision) : split;
    if (rounded.exponent < lowerExp || rounded.exponent >= upperExp) {
      return toExponential(value, precision);
    } else {
      var c = rounded.coefficients;
      var e = rounded.exponent;
      if (c.length < precision) {
        c = c.concat(zeros(precision - c.length));
      }
      c = c.concat(zeros(e - c.length + 1 + (c.length < precision ? precision - c.length : 0)));
      c = zeros(-e).concat(c);
      var dot2 = e > 0 ? e : 0;
      if (dot2 < c.length - 1) {
        c.splice(dot2 + 1, 0, ".");
      }
      return rounded.sign + c.join("");
    }
  }
  function roundDigits(split, precision) {
    var rounded = {
      sign: split.sign,
      coefficients: split.coefficients,
      exponent: split.exponent
    };
    var c = rounded.coefficients;
    while (precision <= 0) {
      c.unshift(0);
      rounded.exponent++;
      precision++;
    }
    if (c.length > precision) {
      var removed = c.splice(precision, c.length - precision);
      if (removed[0] >= 5) {
        var i = precision - 1;
        c[i]++;
        while (c[i] === 10) {
          c.pop();
          if (i === 0) {
            c.unshift(0);
            rounded.exponent++;
            i++;
          }
          i--;
          c[i]++;
        }
      }
    }
    return rounded;
  }
  function zeros(length) {
    var arr = [];
    for (var i = 0; i < length; i++) {
      arr.push(0);
    }
    return arr;
  }
  function digits(value) {
    return value.toExponential().replace(/e.*$/, "").replace(/^0\.?0*|\./, "").length;
  }
  var DBL_EPSILON = Number.EPSILON || 2220446049250313e-31;
  function nearlyEqual(x, y, epsilon) {
    if (epsilon === null || epsilon === void 0) {
      return x === y;
    }
    if (x === y) {
      return true;
    }
    if (isNaN(x) || isNaN(y)) {
      return false;
    }
    if (isFinite(x) && isFinite(y)) {
      var diff = Math.abs(x - y);
      if (diff < DBL_EPSILON) {
        return true;
      } else {
        return diff <= Math.max(Math.abs(x), Math.abs(y)) * epsilon;
      }
    }
    return false;
  }

  // node_modules/mathjs/lib/esm/utils/bignumber/formatter.js
  function formatBigNumberToBase(n, base, size2) {
    var BigNumberCtor = n.constructor;
    var big2 = new BigNumberCtor(2);
    var suffix = "";
    if (size2) {
      if (size2 < 1) {
        throw new Error("size must be in greater than 0");
      }
      if (!isInteger(size2)) {
        throw new Error("size must be an integer");
      }
      if (n.greaterThan(big2.pow(size2 - 1).sub(1)) || n.lessThan(big2.pow(size2 - 1).mul(-1))) {
        throw new Error("Value must be in range [-2^".concat(size2 - 1, ", 2^").concat(size2 - 1, "-1]"));
      }
      if (!n.isInteger()) {
        throw new Error("Value must be an integer");
      }
      if (n.lessThan(0)) {
        n = n.add(big2.pow(size2));
      }
      suffix = "i".concat(size2);
    }
    switch (base) {
      case 2:
        return "".concat(n.toBinary()).concat(suffix);
      case 8:
        return "".concat(n.toOctal()).concat(suffix);
      case 16:
        return "".concat(n.toHexadecimal()).concat(suffix);
      default:
        throw new Error("Base ".concat(base, " not supported "));
    }
  }
  function format2(value, options) {
    if (typeof options === "function") {
      return options(value);
    }
    if (!value.isFinite()) {
      return value.isNaN() ? "NaN" : value.gt(0) ? "Infinity" : "-Infinity";
    }
    var notation = "auto";
    var precision;
    var wordSize;
    if (options !== void 0) {
      if (options.notation) {
        notation = options.notation;
      }
      if (typeof options === "number") {
        precision = options;
      } else if (options.precision) {
        precision = options.precision;
      }
      if (options.wordSize) {
        wordSize = options.wordSize;
        if (typeof wordSize !== "number") {
          throw new Error('Option "wordSize" must be a number');
        }
      }
    }
    switch (notation) {
      case "fixed":
        return toFixed2(value, precision);
      case "exponential":
        return toExponential2(value, precision);
      case "engineering":
        return toEngineering2(value, precision);
      case "bin":
        return formatBigNumberToBase(value, 2, wordSize);
      case "oct":
        return formatBigNumberToBase(value, 8, wordSize);
      case "hex":
        return formatBigNumberToBase(value, 16, wordSize);
      case "auto": {
        var lowerExp = options && options.lowerExp !== void 0 ? options.lowerExp : -3;
        var upperExp = options && options.upperExp !== void 0 ? options.upperExp : 5;
        if (value.isZero()) return "0";
        var str;
        var rounded = value.toSignificantDigits(precision);
        var exp2 = rounded.e;
        if (exp2 >= lowerExp && exp2 < upperExp) {
          str = rounded.toFixed();
        } else {
          str = toExponential2(value, precision);
        }
        return str.replace(/((\.\d*?)(0+))($|e)/, function() {
          var digits2 = arguments[2];
          var e = arguments[4];
          return digits2 !== "." ? digits2 + e : e;
        });
      }
      default:
        throw new Error('Unknown notation "' + notation + '". Choose "auto", "exponential", "fixed", "bin", "oct", or "hex.');
    }
  }
  function toEngineering2(value, precision) {
    var e = value.e;
    var newExp = e % 3 === 0 ? e : e < 0 ? e - 3 - e % 3 : e - e % 3;
    var valueWithoutExp = value.mul(Math.pow(10, -newExp));
    var valueStr = valueWithoutExp.toPrecision(precision);
    if (valueStr.indexOf("e") !== -1) {
      valueStr = valueWithoutExp.toString();
    }
    return valueStr + "e" + (e >= 0 ? "+" : "") + newExp.toString();
  }
  function toExponential2(value, precision) {
    if (precision !== void 0) {
      return value.toExponential(precision - 1);
    } else {
      return value.toExponential();
    }
  }
  function toFixed2(value, precision) {
    return value.toFixed(precision);
  }

  // node_modules/mathjs/lib/esm/utils/string.js
  function format3(value, options) {
    if (typeof value === "number") {
      return format(value, options);
    }
    if (isBigNumber(value)) {
      return format2(value, options);
    }
    if (looksLikeFraction(value)) {
      if (!options || options.fraction !== "decimal") {
        return value.s * value.n + "/" + value.d;
      } else {
        return value.toString();
      }
    }
    if (Array.isArray(value)) {
      return formatArray(value, options);
    }
    if (isString(value)) {
      return '"' + value + '"';
    }
    if (typeof value === "function") {
      return value.syntax ? String(value.syntax) : "function";
    }
    if (value && typeof value === "object") {
      if (typeof value.format === "function") {
        return value.format(options);
      } else if (value && value.toString(options) !== {}.toString()) {
        return value.toString(options);
      } else {
        var entries = Object.keys(value).map((key) => {
          return '"' + key + '": ' + format3(value[key], options);
        });
        return "{" + entries.join(", ") + "}";
      }
    }
    return String(value);
  }
  function formatArray(array, options) {
    if (Array.isArray(array)) {
      var str = "[";
      var len = array.length;
      for (var i = 0; i < len; i++) {
        if (i !== 0) {
          str += ", ";
        }
        str += formatArray(array[i], options);
      }
      str += "]";
      return str;
    } else {
      return format3(array, options);
    }
  }
  function looksLikeFraction(value) {
    return value && typeof value === "object" && typeof value.s === "number" && typeof value.n === "number" && typeof value.d === "number" || false;
  }

  // node_modules/mathjs/lib/esm/error/DimensionError.js
  function DimensionError(actual, expected, relation) {
    if (!(this instanceof DimensionError)) {
      throw new SyntaxError("Constructor must be called with the new operator");
    }
    this.actual = actual;
    this.expected = expected;
    this.relation = relation;
    this.message = "Dimension mismatch (" + (Array.isArray(actual) ? "[" + actual.join(", ") + "]" : actual) + " " + (this.relation || "!=") + " " + (Array.isArray(expected) ? "[" + expected.join(", ") + "]" : expected) + ")";
    this.stack = new Error().stack;
  }
  DimensionError.prototype = new RangeError();
  DimensionError.prototype.constructor = RangeError;
  DimensionError.prototype.name = "DimensionError";
  DimensionError.prototype.isDimensionError = true;

  // node_modules/mathjs/lib/esm/error/IndexError.js
  function IndexError(index2, min2, max2) {
    if (!(this instanceof IndexError)) {
      throw new SyntaxError("Constructor must be called with the new operator");
    }
    this.index = index2;
    if (arguments.length < 3) {
      this.min = 0;
      this.max = min2;
    } else {
      this.min = min2;
      this.max = max2;
    }
    if (this.min !== void 0 && this.index < this.min) {
      this.message = "Index out of range (" + this.index + " < " + this.min + ")";
    } else if (this.max !== void 0 && this.index >= this.max) {
      this.message = "Index out of range (" + this.index + " > " + (this.max - 1) + ")";
    } else {
      this.message = "Index out of range (" + this.index + ")";
    }
    this.stack = new Error().stack;
  }
  IndexError.prototype = new RangeError();
  IndexError.prototype.constructor = RangeError;
  IndexError.prototype.name = "IndexError";
  IndexError.prototype.isIndexError = true;

  // node_modules/mathjs/lib/esm/utils/array.js
  function arraySize(x) {
    var s = [];
    while (Array.isArray(x)) {
      s.push(x.length);
      x = x[0];
    }
    return s;
  }
  function _validate(array, size2, dim) {
    var i;
    var len = array.length;
    if (len !== size2[dim]) {
      throw new DimensionError(len, size2[dim]);
    }
    if (dim < size2.length - 1) {
      var dimNext = dim + 1;
      for (i = 0; i < len; i++) {
        var child = array[i];
        if (!Array.isArray(child)) {
          throw new DimensionError(size2.length - 1, size2.length, "<");
        }
        _validate(array[i], size2, dimNext);
      }
    } else {
      for (i = 0; i < len; i++) {
        if (Array.isArray(array[i])) {
          throw new DimensionError(size2.length + 1, size2.length, ">");
        }
      }
    }
  }
  function validate(array, size2) {
    var isScalar = size2.length === 0;
    if (isScalar) {
      if (Array.isArray(array)) {
        throw new DimensionError(array.length, 0);
      }
    } else {
      _validate(array, size2, 0);
    }
  }
  function validateIndex(index2, length) {
    if (!isNumber(index2) || !isInteger(index2)) {
      throw new TypeError("Index must be an integer (value: " + index2 + ")");
    }
    if (index2 < 0 || typeof length === "number" && index2 >= length) {
      throw new IndexError(index2, length);
    }
  }
  function resize(array, size2, defaultValue) {
    if (!Array.isArray(array) || !Array.isArray(size2)) {
      throw new TypeError("Array expected");
    }
    if (size2.length === 0) {
      throw new Error("Resizing to scalar is not supported");
    }
    size2.forEach(function(value) {
      if (!isNumber(value) || !isInteger(value) || value < 0) {
        throw new TypeError("Invalid size, must contain positive integers (size: " + format3(size2) + ")");
      }
    });
    var _defaultValue = defaultValue !== void 0 ? defaultValue : 0;
    _resize(array, size2, 0, _defaultValue);
    return array;
  }
  function _resize(array, size2, dim, defaultValue) {
    var i;
    var elem;
    var oldLen = array.length;
    var newLen = size2[dim];
    var minLen = Math.min(oldLen, newLen);
    array.length = newLen;
    if (dim < size2.length - 1) {
      var dimNext = dim + 1;
      for (i = 0; i < minLen; i++) {
        elem = array[i];
        if (!Array.isArray(elem)) {
          elem = [elem];
          array[i] = elem;
        }
        _resize(elem, size2, dimNext, defaultValue);
      }
      for (i = minLen; i < newLen; i++) {
        elem = [];
        array[i] = elem;
        _resize(elem, size2, dimNext, defaultValue);
      }
    } else {
      for (i = 0; i < minLen; i++) {
        while (Array.isArray(array[i])) {
          array[i] = array[i][0];
        }
      }
      for (i = minLen; i < newLen; i++) {
        array[i] = defaultValue;
      }
    }
  }
  function reshape(array, sizes) {
    var flatArray = flatten(array);
    var currentLength = flatArray.length;
    if (!Array.isArray(array) || !Array.isArray(sizes)) {
      throw new TypeError("Array expected");
    }
    if (sizes.length === 0) {
      throw new DimensionError(0, currentLength, "!=");
    }
    sizes = processSizesWildcard(sizes, currentLength);
    var newLength = product(sizes);
    if (currentLength !== newLength) {
      throw new DimensionError(newLength, currentLength, "!=");
    }
    try {
      return _reshape(flatArray, sizes);
    } catch (e) {
      if (e instanceof DimensionError) {
        throw new DimensionError(newLength, currentLength, "!=");
      }
      throw e;
    }
  }
  function processSizesWildcard(sizes, currentLength) {
    var newLength = product(sizes);
    var processedSizes = sizes.slice();
    var WILDCARD = -1;
    var wildCardIndex = sizes.indexOf(WILDCARD);
    var isMoreThanOneWildcard = sizes.indexOf(WILDCARD, wildCardIndex + 1) >= 0;
    if (isMoreThanOneWildcard) {
      throw new Error("More than one wildcard in sizes");
    }
    var hasWildcard = wildCardIndex >= 0;
    var canReplaceWildcard = currentLength % newLength === 0;
    if (hasWildcard) {
      if (canReplaceWildcard) {
        processedSizes[wildCardIndex] = -currentLength / newLength;
      } else {
        throw new Error("Could not replace wildcard, since " + currentLength + " is no multiple of " + -newLength);
      }
    }
    return processedSizes;
  }
  function product(array) {
    return array.reduce((prev, curr) => prev * curr, 1);
  }
  function _reshape(array, sizes) {
    var tmpArray = array;
    var tmpArray2;
    for (var sizeIndex = sizes.length - 1; sizeIndex > 0; sizeIndex--) {
      var size2 = sizes[sizeIndex];
      tmpArray2 = [];
      var length = tmpArray.length / size2;
      for (var i = 0; i < length; i++) {
        tmpArray2.push(tmpArray.slice(i * size2, (i + 1) * size2));
      }
      tmpArray = tmpArray2;
    }
    return tmpArray;
  }
  function unsqueeze(array, dims, outer, size2) {
    var s = size2 || arraySize(array);
    if (outer) {
      for (var i = 0; i < outer; i++) {
        array = [array];
        s.unshift(1);
      }
    }
    array = _unsqueeze(array, dims, 0);
    while (s.length < dims) {
      s.push(1);
    }
    return array;
  }
  function _unsqueeze(array, dims, dim) {
    var i, ii;
    if (Array.isArray(array)) {
      var next = dim + 1;
      for (i = 0, ii = array.length; i < ii; i++) {
        array[i] = _unsqueeze(array[i], dims, next);
      }
    } else {
      for (var d = dim; d < dims; d++) {
        array = [array];
      }
    }
    return array;
  }
  function flatten(array) {
    if (!Array.isArray(array)) {
      return array;
    }
    var flat = [];
    array.forEach(function callback(value) {
      if (Array.isArray(value)) {
        value.forEach(callback);
      } else {
        flat.push(value);
      }
    });
    return flat;
  }
  function getArrayDataType(array, typeOf2) {
    var type;
    var length = 0;
    for (var i = 0; i < array.length; i++) {
      var item = array[i];
      var isArray2 = Array.isArray(item);
      if (i === 0 && isArray2) {
        length = item.length;
      }
      if (isArray2 && item.length !== length) {
        return void 0;
      }
      var itemType = isArray2 ? getArrayDataType(item, typeOf2) : typeOf2(item);
      if (type === void 0) {
        type = itemType;
      } else if (type !== itemType) {
        return "mixed";
      } else {
      }
    }
    return type;
  }

  // node_modules/mathjs/lib/esm/utils/factory.js
  function factory(name86, dependencies87, create, meta) {
    function assertAndCreate(scope) {
      var deps = pickShallow(scope, dependencies87.map(stripOptionalNotation));
      assertDependencies(name86, dependencies87, scope);
      return create(deps);
    }
    assertAndCreate.isFactory = true;
    assertAndCreate.fn = name86;
    assertAndCreate.dependencies = dependencies87.slice().sort();
    if (meta) {
      assertAndCreate.meta = meta;
    }
    return assertAndCreate;
  }
  function assertDependencies(name86, dependencies87, scope) {
    var allDefined = dependencies87.filter((dependency) => !isOptionalDependency(dependency)).every((dependency) => scope[dependency] !== void 0);
    if (!allDefined) {
      var missingDependencies = dependencies87.filter((dependency) => scope[dependency] === void 0);
      throw new Error('Cannot create function "'.concat(name86, '", ') + "some dependencies are missing: ".concat(missingDependencies.map((d) => '"'.concat(d, '"')).join(", "), "."));
    }
  }
  function isOptionalDependency(dependency) {
    return dependency && dependency[0] === "?";
  }
  function stripOptionalNotation(dependency) {
    return dependency && dependency[0] === "?" ? dependency.slice(1) : dependency;
  }

  // node_modules/mathjs/lib/esm/utils/customs.js
  function getSafeProperty(object, prop) {
    if (isPlainObject(object) && isSafeProperty(object, prop)) {
      return object[prop];
    }
    if (typeof object[prop] === "function" && isSafeMethod(object, prop)) {
      throw new Error('Cannot access method "' + prop + '" as a property');
    }
    throw new Error('No access to property "' + prop + '"');
  }
  function setSafeProperty(object, prop, value) {
    if (isPlainObject(object) && isSafeProperty(object, prop)) {
      object[prop] = value;
      return value;
    }
    throw new Error('No access to property "' + prop + '"');
  }
  function hasSafeProperty(object, prop) {
    return prop in object;
  }
  function isSafeProperty(object, prop) {
    if (!object || typeof object !== "object") {
      return false;
    }
    if (hasOwnProperty(safeNativeProperties, prop)) {
      return true;
    }
    if (prop in Object.prototype) {
      return false;
    }
    if (prop in Function.prototype) {
      return false;
    }
    return true;
  }
  function isSafeMethod(object, method) {
    if (object === null || object === void 0 || typeof object[method] !== "function") {
      return false;
    }
    if (hasOwnProperty(object, method) && Object.getPrototypeOf && method in Object.getPrototypeOf(object)) {
      return false;
    }
    if (hasOwnProperty(safeNativeMethods, method)) {
      return true;
    }
    if (method in Object.prototype) {
      return false;
    }
    if (method in Function.prototype) {
      return false;
    }
    return true;
  }
  function isPlainObject(object) {
    return typeof object === "object" && object && object.constructor === Object;
  }
  var safeNativeProperties = {
    length: true,
    name: true
  };
  var safeNativeMethods = {
    toString: true,
    valueOf: true,
    toLocaleString: true
  };

  // node_modules/mathjs/lib/esm/utils/map.js
  var ObjectWrappingMap = class {
    constructor(object) {
      this.wrappedObject = object;
    }
    keys() {
      return Object.keys(this.wrappedObject);
    }
    get(key) {
      return getSafeProperty(this.wrappedObject, key);
    }
    set(key, value) {
      setSafeProperty(this.wrappedObject, key, value);
      return this;
    }
    has(key) {
      return hasSafeProperty(this.wrappedObject, key);
    }
  };
  function isMap(object) {
    if (!object) {
      return false;
    }
    return object instanceof Map || object instanceof ObjectWrappingMap || typeof object.set === "function" && typeof object.get === "function" && typeof object.keys === "function" && typeof object.has === "function";
  }

  // node_modules/mathjs/lib/esm/core/function/typed.js
  var _createTyped2 = function _createTyped() {
    _createTyped2 = import_typed_function.default.create;
    return import_typed_function.default;
  };
  var dependencies = ["?BigNumber", "?Complex", "?DenseMatrix", "?Fraction"];
  var createTyped = /* @__PURE__ */ factory("typed", dependencies, function createTyped2(_ref) {
    var {
      BigNumber: BigNumber2,
      Complex: Complex3,
      DenseMatrix: DenseMatrix2,
      Fraction: Fraction3
    } = _ref;
    var typed2 = _createTyped2();
    typed2.types = [
      {
        name: "number",
        test: isNumber
      },
      {
        name: "Complex",
        test: isComplex
      },
      {
        name: "BigNumber",
        test: isBigNumber
      },
      {
        name: "Fraction",
        test: isFraction
      },
      {
        name: "Unit",
        test: isUnit
      },
      {
        name: "string",
        test: isString
      },
      {
        name: "Chain",
        test: isChain
      },
      {
        name: "Array",
        test: isArray
      },
      {
        name: "Matrix",
        test: isMatrix
      },
      {
        name: "DenseMatrix",
        test: isDenseMatrix
      },
      {
        name: "SparseMatrix",
        test: isSparseMatrix
      },
      {
        name: "Range",
        test: isRange
      },
      {
        name: "Index",
        test: isIndex
      },
      {
        name: "boolean",
        test: isBoolean
      },
      {
        name: "ResultSet",
        test: isResultSet
      },
      {
        name: "Help",
        test: isHelp
      },
      {
        name: "function",
        test: isFunction
      },
      {
        name: "Date",
        test: isDate
      },
      {
        name: "RegExp",
        test: isRegExp
      },
      {
        name: "null",
        test: isNull
      },
      {
        name: "undefined",
        test: isUndefined
      },
      {
        name: "AccessorNode",
        test: isAccessorNode
      },
      {
        name: "ArrayNode",
        test: isArrayNode
      },
      {
        name: "AssignmentNode",
        test: isAssignmentNode
      },
      {
        name: "BlockNode",
        test: isBlockNode
      },
      {
        name: "ConditionalNode",
        test: isConditionalNode
      },
      {
        name: "ConstantNode",
        test: isConstantNode
      },
      {
        name: "FunctionNode",
        test: isFunctionNode
      },
      {
        name: "FunctionAssignmentNode",
        test: isFunctionAssignmentNode
      },
      {
        name: "IndexNode",
        test: isIndexNode
      },
      {
        name: "Node",
        test: isNode
      },
      {
        name: "ObjectNode",
        test: isObjectNode
      },
      {
        name: "OperatorNode",
        test: isOperatorNode
      },
      {
        name: "ParenthesisNode",
        test: isParenthesisNode
      },
      {
        name: "RangeNode",
        test: isRangeNode
      },
      {
        name: "SymbolNode",
        test: isSymbolNode
      },
      {
        name: "Map",
        test: isMap
      },
      {
        name: "Object",
        test: isObject
      }
      // order 'Object' last, it matches on other classes too
    ];
    typed2.conversions = [{
      from: "number",
      to: "BigNumber",
      convert: function convert(x) {
        if (!BigNumber2) {
          throwNoBignumber(x);
        }
        if (digits(x) > 15) {
          throw new TypeError("Cannot implicitly convert a number with >15 significant digits to BigNumber (value: " + x + "). Use function bignumber(x) to convert to BigNumber.");
        }
        return new BigNumber2(x);
      }
    }, {
      from: "number",
      to: "Complex",
      convert: function convert(x) {
        if (!Complex3) {
          throwNoComplex(x);
        }
        return new Complex3(x, 0);
      }
    }, {
      from: "number",
      to: "string",
      convert: function convert(x) {
        return x + "";
      }
    }, {
      from: "BigNumber",
      to: "Complex",
      convert: function convert(x) {
        if (!Complex3) {
          throwNoComplex(x);
        }
        return new Complex3(x.toNumber(), 0);
      }
    }, {
      from: "Fraction",
      to: "BigNumber",
      convert: function convert(x) {
        throw new TypeError("Cannot implicitly convert a Fraction to BigNumber or vice versa. Use function bignumber(x) to convert to BigNumber or fraction(x) to convert to Fraction.");
      }
    }, {
      from: "Fraction",
      to: "Complex",
      convert: function convert(x) {
        if (!Complex3) {
          throwNoComplex(x);
        }
        return new Complex3(x.valueOf(), 0);
      }
    }, {
      from: "number",
      to: "Fraction",
      convert: function convert(x) {
        if (!Fraction3) {
          throwNoFraction(x);
        }
        var f = new Fraction3(x);
        if (f.valueOf() !== x) {
          throw new TypeError("Cannot implicitly convert a number to a Fraction when there will be a loss of precision (value: " + x + "). Use function fraction(x) to convert to Fraction.");
        }
        return f;
      }
    }, {
      // FIXME: add conversion from Fraction to number, for example for `sqrt(fraction(1,3))`
      //  from: 'Fraction',
      //  to: 'number',
      //  convert: function (x) {
      //    return x.valueOf()
      //  }
      // }, {
      from: "string",
      to: "number",
      convert: function convert(x) {
        var n = Number(x);
        if (isNaN(n)) {
          throw new Error('Cannot convert "' + x + '" to a number');
        }
        return n;
      }
    }, {
      from: "string",
      to: "BigNumber",
      convert: function convert(x) {
        if (!BigNumber2) {
          throwNoBignumber(x);
        }
        try {
          return new BigNumber2(x);
        } catch (err) {
          throw new Error('Cannot convert "' + x + '" to BigNumber');
        }
      }
    }, {
      from: "string",
      to: "Fraction",
      convert: function convert(x) {
        if (!Fraction3) {
          throwNoFraction(x);
        }
        try {
          return new Fraction3(x);
        } catch (err) {
          throw new Error('Cannot convert "' + x + '" to Fraction');
        }
      }
    }, {
      from: "string",
      to: "Complex",
      convert: function convert(x) {
        if (!Complex3) {
          throwNoComplex(x);
        }
        try {
          return new Complex3(x);
        } catch (err) {
          throw new Error('Cannot convert "' + x + '" to Complex');
        }
      }
    }, {
      from: "boolean",
      to: "number",
      convert: function convert(x) {
        return +x;
      }
    }, {
      from: "boolean",
      to: "BigNumber",
      convert: function convert(x) {
        if (!BigNumber2) {
          throwNoBignumber(x);
        }
        return new BigNumber2(+x);
      }
    }, {
      from: "boolean",
      to: "Fraction",
      convert: function convert(x) {
        if (!Fraction3) {
          throwNoFraction(x);
        }
        return new Fraction3(+x);
      }
    }, {
      from: "boolean",
      to: "string",
      convert: function convert(x) {
        return String(x);
      }
    }, {
      from: "Array",
      to: "Matrix",
      convert: function convert(array) {
        if (!DenseMatrix2) {
          throwNoMatrix();
        }
        return new DenseMatrix2(array);
      }
    }, {
      from: "Matrix",
      to: "Array",
      convert: function convert(matrix2) {
        return matrix2.valueOf();
      }
    }];
    return typed2;
  });
  function throwNoBignumber(x) {
    throw new Error("Cannot convert value ".concat(x, " into a BigNumber: no class 'BigNumber' provided"));
  }
  function throwNoComplex(x) {
    throw new Error("Cannot convert value ".concat(x, " into a Complex number: no class 'Complex' provided"));
  }
  function throwNoMatrix() {
    throw new Error("Cannot convert array into a Matrix: no class 'DenseMatrix' provided");
  }
  function throwNoFraction(x) {
    throw new Error("Cannot convert value ".concat(x, " into a Fraction, no class 'Fraction' provided."));
  }

  // node_modules/decimal.js/decimal.mjs
  var EXP_LIMIT = 9e15;
  var MAX_DIGITS = 1e9;
  var NUMERALS = "0123456789abcdef";
  var LN10 = "2.3025850929940456840179914546843642076011014886287729760333279009675726096773524802359972050895982983419677840422862486334095254650828067566662873690987816894829072083255546808437998948262331985283935053089653777326288461633662222876982198867465436674744042432743651550489343149393914796194044002221051017141748003688084012647080685567743216228355220114804663715659121373450747856947683463616792101806445070648000277502684916746550586856935673420670581136429224554405758925724208241314695689016758940256776311356919292033376587141660230105703089634572075440370847469940168269282808481184289314848524948644871927809676271275775397027668605952496716674183485704422507197965004714951050492214776567636938662976979522110718264549734772662425709429322582798502585509785265383207606726317164309505995087807523710333101197857547331541421808427543863591778117054309827482385045648019095610299291824318237525357709750539565187697510374970888692180205189339507238539205144634197265287286965110862571492198849978748873771345686209167058";
  var PI = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989380952572010654858632789";
  var DEFAULTS = {
    // These values must be integers within the stated ranges (inclusive).
    // Most of these values can be changed at run-time using the `Decimal.config` method.
    // The maximum number of significant digits of the result of a calculation or base conversion.
    // E.g. `Decimal.config({ precision: 20 });`
    precision: 20,
    // 1 to MAX_DIGITS
    // The rounding mode used when rounding to `precision`.
    //
    // ROUND_UP         0 Away from zero.
    // ROUND_DOWN       1 Towards zero.
    // ROUND_CEIL       2 Towards +Infinity.
    // ROUND_FLOOR      3 Towards -Infinity.
    // ROUND_HALF_UP    4 Towards nearest neighbour. If equidistant, up.
    // ROUND_HALF_DOWN  5 Towards nearest neighbour. If equidistant, down.
    // ROUND_HALF_EVEN  6 Towards nearest neighbour. If equidistant, towards even neighbour.
    // ROUND_HALF_CEIL  7 Towards nearest neighbour. If equidistant, towards +Infinity.
    // ROUND_HALF_FLOOR 8 Towards nearest neighbour. If equidistant, towards -Infinity.
    //
    // E.g.
    // `Decimal.rounding = 4;`
    // `Decimal.rounding = Decimal.ROUND_HALF_UP;`
    rounding: 4,
    // 0 to 8
    // The modulo mode used when calculating the modulus: a mod n.
    // The quotient (q = a / n) is calculated according to the corresponding rounding mode.
    // The remainder (r) is calculated as: r = a - n * q.
    //
    // UP         0 The remainder is positive if the dividend is negative, else is negative.
    // DOWN       1 The remainder has the same sign as the dividend (JavaScript %).
    // FLOOR      3 The remainder has the same sign as the divisor (Python %).
    // HALF_EVEN  6 The IEEE 754 remainder function.
    // EUCLID     9 Euclidian division. q = sign(n) * floor(a / abs(n)). Always positive.
    //
    // Truncated division (1), floored division (3), the IEEE 754 remainder (6), and Euclidian
    // division (9) are commonly used for the modulus operation. The other rounding modes can also
    // be used, but they may not give useful results.
    modulo: 1,
    // 0 to 9
    // The exponent value at and beneath which `toString` returns exponential notation.
    // JavaScript numbers: -7
    toExpNeg: -7,
    // 0 to -EXP_LIMIT
    // The exponent value at and above which `toString` returns exponential notation.
    // JavaScript numbers: 21
    toExpPos: 21,
    // 0 to EXP_LIMIT
    // The minimum exponent value, beneath which underflow to zero occurs.
    // JavaScript numbers: -324  (5e-324)
    minE: -EXP_LIMIT,
    // -1 to -EXP_LIMIT
    // The maximum exponent value, above which overflow to Infinity occurs.
    // JavaScript numbers: 308  (1.7976931348623157e+308)
    maxE: EXP_LIMIT,
    // 1 to EXP_LIMIT
    // Whether to use cryptographically-secure random number generation, if available.
    crypto: false
    // true/false
  };
  var inexact;
  var quadrant;
  var external = true;
  var decimalError = "[DecimalError] ";
  var invalidArgument = decimalError + "Invalid argument: ";
  var precisionLimitExceeded = decimalError + "Precision limit exceeded";
  var cryptoUnavailable = decimalError + "crypto unavailable";
  var tag = "[object Decimal]";
  var mathfloor = Math.floor;
  var mathpow = Math.pow;
  var isBinary = /^0b([01]+(\.[01]*)?|\.[01]+)(p[+-]?\d+)?$/i;
  var isHex = /^0x([0-9a-f]+(\.[0-9a-f]*)?|\.[0-9a-f]+)(p[+-]?\d+)?$/i;
  var isOctal = /^0o([0-7]+(\.[0-7]*)?|\.[0-7]+)(p[+-]?\d+)?$/i;
  var isDecimal = /^(\d+(\.\d*)?|\.\d+)(e[+-]?\d+)?$/i;
  var BASE = 1e7;
  var LOG_BASE = 7;
  var MAX_SAFE_INTEGER = 9007199254740991;
  var LN10_PRECISION = LN10.length - 1;
  var PI_PRECISION = PI.length - 1;
  var P = { toStringTag: tag };
  P.absoluteValue = P.abs = function() {
    var x = new this.constructor(this);
    if (x.s < 0) x.s = 1;
    return finalise(x);
  };
  P.ceil = function() {
    return finalise(new this.constructor(this), this.e + 1, 2);
  };
  P.clampedTo = P.clamp = function(min2, max2) {
    var k, x = this, Ctor = x.constructor;
    min2 = new Ctor(min2);
    max2 = new Ctor(max2);
    if (!min2.s || !max2.s) return new Ctor(NaN);
    if (min2.gt(max2)) throw Error(invalidArgument + max2);
    k = x.cmp(min2);
    return k < 0 ? min2 : x.cmp(max2) > 0 ? max2 : new Ctor(x);
  };
  P.comparedTo = P.cmp = function(y) {
    var i, j, xdL, ydL, x = this, xd = x.d, yd = (y = new x.constructor(y)).d, xs = x.s, ys = y.s;
    if (!xd || !yd) {
      return !xs || !ys ? NaN : xs !== ys ? xs : xd === yd ? 0 : !xd ^ xs < 0 ? 1 : -1;
    }
    if (!xd[0] || !yd[0]) return xd[0] ? xs : yd[0] ? -ys : 0;
    if (xs !== ys) return xs;
    if (x.e !== y.e) return x.e > y.e ^ xs < 0 ? 1 : -1;
    xdL = xd.length;
    ydL = yd.length;
    for (i = 0, j = xdL < ydL ? xdL : ydL; i < j; ++i) {
      if (xd[i] !== yd[i]) return xd[i] > yd[i] ^ xs < 0 ? 1 : -1;
    }
    return xdL === ydL ? 0 : xdL > ydL ^ xs < 0 ? 1 : -1;
  };
  P.cosine = P.cos = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (!x.d) return new Ctor(NaN);
    if (!x.d[0]) return new Ctor(1);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + Math.max(x.e, x.sd()) + LOG_BASE;
    Ctor.rounding = 1;
    x = cosine(Ctor, toLessThanHalfPi(Ctor, x));
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return finalise(quadrant == 2 || quadrant == 3 ? x.neg() : x, pr, rm, true);
  };
  P.cubeRoot = P.cbrt = function() {
    var e, m, n, r, rep, s, sd, t, t3, t3plusx, x = this, Ctor = x.constructor;
    if (!x.isFinite() || x.isZero()) return new Ctor(x);
    external = false;
    s = x.s * mathpow(x.s * x, 1 / 3);
    if (!s || Math.abs(s) == 1 / 0) {
      n = digitsToString(x.d);
      e = x.e;
      if (s = (e - n.length + 1) % 3) n += s == 1 || s == -2 ? "0" : "00";
      s = mathpow(n, 1 / 3);
      e = mathfloor((e + 1) / 3) - (e % 3 == (e < 0 ? -1 : 2));
      if (s == 1 / 0) {
        n = "5e" + e;
      } else {
        n = s.toExponential();
        n = n.slice(0, n.indexOf("e") + 1) + e;
      }
      r = new Ctor(n);
      r.s = x.s;
    } else {
      r = new Ctor(s.toString());
    }
    sd = (e = Ctor.precision) + 3;
    for (; ; ) {
      t = r;
      t3 = t.times(t).times(t);
      t3plusx = t3.plus(x);
      r = divide(t3plusx.plus(x).times(t), t3plusx.plus(t3), sd + 2, 1);
      if (digitsToString(t.d).slice(0, sd) === (n = digitsToString(r.d)).slice(0, sd)) {
        n = n.slice(sd - 3, sd + 1);
        if (n == "9999" || !rep && n == "4999") {
          if (!rep) {
            finalise(t, e + 1, 0);
            if (t.times(t).times(t).eq(x)) {
              r = t;
              break;
            }
          }
          sd += 4;
          rep = 1;
        } else {
          if (!+n || !+n.slice(1) && n.charAt(0) == "5") {
            finalise(r, e + 1, 1);
            m = !r.times(r).times(r).eq(x);
          }
          break;
        }
      }
    }
    external = true;
    return finalise(r, e, Ctor.rounding, m);
  };
  P.decimalPlaces = P.dp = function() {
    var w, d = this.d, n = NaN;
    if (d) {
      w = d.length - 1;
      n = (w - mathfloor(this.e / LOG_BASE)) * LOG_BASE;
      w = d[w];
      if (w) for (; w % 10 == 0; w /= 10) n--;
      if (n < 0) n = 0;
    }
    return n;
  };
  P.dividedBy = P.div = function(y) {
    return divide(this, new this.constructor(y));
  };
  P.dividedToIntegerBy = P.divToInt = function(y) {
    var x = this, Ctor = x.constructor;
    return finalise(divide(x, new Ctor(y), 0, 1, 1), Ctor.precision, Ctor.rounding);
  };
  P.equals = P.eq = function(y) {
    return this.cmp(y) === 0;
  };
  P.floor = function() {
    return finalise(new this.constructor(this), this.e + 1, 3);
  };
  P.greaterThan = P.gt = function(y) {
    return this.cmp(y) > 0;
  };
  P.greaterThanOrEqualTo = P.gte = function(y) {
    var k = this.cmp(y);
    return k == 1 || k === 0;
  };
  P.hyperbolicCosine = P.cosh = function() {
    var k, n, pr, rm, len, x = this, Ctor = x.constructor, one = new Ctor(1);
    if (!x.isFinite()) return new Ctor(x.s ? 1 / 0 : NaN);
    if (x.isZero()) return one;
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + Math.max(x.e, x.sd()) + 4;
    Ctor.rounding = 1;
    len = x.d.length;
    if (len < 32) {
      k = Math.ceil(len / 3);
      n = (1 / tinyPow(4, k)).toString();
    } else {
      k = 16;
      n = "2.3283064365386962890625e-10";
    }
    x = taylorSeries(Ctor, 1, x.times(n), new Ctor(1), true);
    var cosh2_x, i = k, d8 = new Ctor(8);
    for (; i--; ) {
      cosh2_x = x.times(x);
      x = one.minus(cosh2_x.times(d8.minus(cosh2_x.times(d8))));
    }
    return finalise(x, Ctor.precision = pr, Ctor.rounding = rm, true);
  };
  P.hyperbolicSine = P.sinh = function() {
    var k, pr, rm, len, x = this, Ctor = x.constructor;
    if (!x.isFinite() || x.isZero()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + Math.max(x.e, x.sd()) + 4;
    Ctor.rounding = 1;
    len = x.d.length;
    if (len < 3) {
      x = taylorSeries(Ctor, 2, x, x, true);
    } else {
      k = 1.4 * Math.sqrt(len);
      k = k > 16 ? 16 : k | 0;
      x = x.times(1 / tinyPow(5, k));
      x = taylorSeries(Ctor, 2, x, x, true);
      var sinh2_x, d5 = new Ctor(5), d16 = new Ctor(16), d20 = new Ctor(20);
      for (; k--; ) {
        sinh2_x = x.times(x);
        x = x.times(d5.plus(sinh2_x.times(d16.times(sinh2_x).plus(d20))));
      }
    }
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return finalise(x, pr, rm, true);
  };
  P.hyperbolicTangent = P.tanh = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (!x.isFinite()) return new Ctor(x.s);
    if (x.isZero()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + 7;
    Ctor.rounding = 1;
    return divide(x.sinh(), x.cosh(), Ctor.precision = pr, Ctor.rounding = rm);
  };
  P.inverseCosine = P.acos = function() {
    var x = this, Ctor = x.constructor, k = x.abs().cmp(1), pr = Ctor.precision, rm = Ctor.rounding;
    if (k !== -1) {
      return k === 0 ? x.isNeg() ? getPi(Ctor, pr, rm) : new Ctor(0) : new Ctor(NaN);
    }
    if (x.isZero()) return getPi(Ctor, pr + 4, rm).times(0.5);
    Ctor.precision = pr + 6;
    Ctor.rounding = 1;
    x = new Ctor(1).minus(x).div(x.plus(1)).sqrt().atan();
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return x.times(2);
  };
  P.inverseHyperbolicCosine = P.acosh = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (x.lte(1)) return new Ctor(x.eq(1) ? 0 : NaN);
    if (!x.isFinite()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + Math.max(Math.abs(x.e), x.sd()) + 4;
    Ctor.rounding = 1;
    external = false;
    x = x.times(x).minus(1).sqrt().plus(x);
    external = true;
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return x.ln();
  };
  P.inverseHyperbolicSine = P.asinh = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (!x.isFinite() || x.isZero()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + 2 * Math.max(Math.abs(x.e), x.sd()) + 6;
    Ctor.rounding = 1;
    external = false;
    x = x.times(x).plus(1).sqrt().plus(x);
    external = true;
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return x.ln();
  };
  P.inverseHyperbolicTangent = P.atanh = function() {
    var pr, rm, wpr, xsd, x = this, Ctor = x.constructor;
    if (!x.isFinite()) return new Ctor(NaN);
    if (x.e >= 0) return new Ctor(x.abs().eq(1) ? x.s / 0 : x.isZero() ? x : NaN);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    xsd = x.sd();
    if (Math.max(xsd, pr) < 2 * -x.e - 1) return finalise(new Ctor(x), pr, rm, true);
    Ctor.precision = wpr = xsd - x.e;
    x = divide(x.plus(1), new Ctor(1).minus(x), wpr + pr, 1);
    Ctor.precision = pr + 4;
    Ctor.rounding = 1;
    x = x.ln();
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return x.times(0.5);
  };
  P.inverseSine = P.asin = function() {
    var halfPi, k, pr, rm, x = this, Ctor = x.constructor;
    if (x.isZero()) return new Ctor(x);
    k = x.abs().cmp(1);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    if (k !== -1) {
      if (k === 0) {
        halfPi = getPi(Ctor, pr + 4, rm).times(0.5);
        halfPi.s = x.s;
        return halfPi;
      }
      return new Ctor(NaN);
    }
    Ctor.precision = pr + 6;
    Ctor.rounding = 1;
    x = x.div(new Ctor(1).minus(x.times(x)).sqrt().plus(1)).atan();
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return x.times(2);
  };
  P.inverseTangent = P.atan = function() {
    var i, j, k, n, px, t, r, wpr, x2, x = this, Ctor = x.constructor, pr = Ctor.precision, rm = Ctor.rounding;
    if (!x.isFinite()) {
      if (!x.s) return new Ctor(NaN);
      if (pr + 4 <= PI_PRECISION) {
        r = getPi(Ctor, pr + 4, rm).times(0.5);
        r.s = x.s;
        return r;
      }
    } else if (x.isZero()) {
      return new Ctor(x);
    } else if (x.abs().eq(1) && pr + 4 <= PI_PRECISION) {
      r = getPi(Ctor, pr + 4, rm).times(0.25);
      r.s = x.s;
      return r;
    }
    Ctor.precision = wpr = pr + 10;
    Ctor.rounding = 1;
    k = Math.min(28, wpr / LOG_BASE + 2 | 0);
    for (i = k; i; --i) x = x.div(x.times(x).plus(1).sqrt().plus(1));
    external = false;
    j = Math.ceil(wpr / LOG_BASE);
    n = 1;
    x2 = x.times(x);
    r = new Ctor(x);
    px = x;
    for (; i !== -1; ) {
      px = px.times(x2);
      t = r.minus(px.div(n += 2));
      px = px.times(x2);
      r = t.plus(px.div(n += 2));
      if (r.d[j] !== void 0) for (i = j; r.d[i] === t.d[i] && i--; ) ;
    }
    if (k) r = r.times(2 << k - 1);
    external = true;
    return finalise(r, Ctor.precision = pr, Ctor.rounding = rm, true);
  };
  P.isFinite = function() {
    return !!this.d;
  };
  P.isInteger = P.isInt = function() {
    return !!this.d && mathfloor(this.e / LOG_BASE) > this.d.length - 2;
  };
  P.isNaN = function() {
    return !this.s;
  };
  P.isNegative = P.isNeg = function() {
    return this.s < 0;
  };
  P.isPositive = P.isPos = function() {
    return this.s > 0;
  };
  P.isZero = function() {
    return !!this.d && this.d[0] === 0;
  };
  P.lessThan = P.lt = function(y) {
    return this.cmp(y) < 0;
  };
  P.lessThanOrEqualTo = P.lte = function(y) {
    return this.cmp(y) < 1;
  };
  P.logarithm = P.log = function(base) {
    var isBase10, d, denominator, k, inf, num, sd, r, arg = this, Ctor = arg.constructor, pr = Ctor.precision, rm = Ctor.rounding, guard = 5;
    if (base == null) {
      base = new Ctor(10);
      isBase10 = true;
    } else {
      base = new Ctor(base);
      d = base.d;
      if (base.s < 0 || !d || !d[0] || base.eq(1)) return new Ctor(NaN);
      isBase10 = base.eq(10);
    }
    d = arg.d;
    if (arg.s < 0 || !d || !d[0] || arg.eq(1)) {
      return new Ctor(d && !d[0] ? -1 / 0 : arg.s != 1 ? NaN : d ? 0 : 1 / 0);
    }
    if (isBase10) {
      if (d.length > 1) {
        inf = true;
      } else {
        for (k = d[0]; k % 10 === 0; ) k /= 10;
        inf = k !== 1;
      }
    }
    external = false;
    sd = pr + guard;
    num = naturalLogarithm(arg, sd);
    denominator = isBase10 ? getLn10(Ctor, sd + 10) : naturalLogarithm(base, sd);
    r = divide(num, denominator, sd, 1);
    if (checkRoundingDigits(r.d, k = pr, rm)) {
      do {
        sd += 10;
        num = naturalLogarithm(arg, sd);
        denominator = isBase10 ? getLn10(Ctor, sd + 10) : naturalLogarithm(base, sd);
        r = divide(num, denominator, sd, 1);
        if (!inf) {
          if (+digitsToString(r.d).slice(k + 1, k + 15) + 1 == 1e14) {
            r = finalise(r, pr + 1, 0);
          }
          break;
        }
      } while (checkRoundingDigits(r.d, k += 10, rm));
    }
    external = true;
    return finalise(r, pr, rm);
  };
  P.minus = P.sub = function(y) {
    var d, e, i, j, k, len, pr, rm, xd, xe, xLTy, yd, x = this, Ctor = x.constructor;
    y = new Ctor(y);
    if (!x.d || !y.d) {
      if (!x.s || !y.s) y = new Ctor(NaN);
      else if (x.d) y.s = -y.s;
      else y = new Ctor(y.d || x.s !== y.s ? x : NaN);
      return y;
    }
    if (x.s != y.s) {
      y.s = -y.s;
      return x.plus(y);
    }
    xd = x.d;
    yd = y.d;
    pr = Ctor.precision;
    rm = Ctor.rounding;
    if (!xd[0] || !yd[0]) {
      if (yd[0]) y.s = -y.s;
      else if (xd[0]) y = new Ctor(x);
      else return new Ctor(rm === 3 ? -0 : 0);
      return external ? finalise(y, pr, rm) : y;
    }
    e = mathfloor(y.e / LOG_BASE);
    xe = mathfloor(x.e / LOG_BASE);
    xd = xd.slice();
    k = xe - e;
    if (k) {
      xLTy = k < 0;
      if (xLTy) {
        d = xd;
        k = -k;
        len = yd.length;
      } else {
        d = yd;
        e = xe;
        len = xd.length;
      }
      i = Math.max(Math.ceil(pr / LOG_BASE), len) + 2;
      if (k > i) {
        k = i;
        d.length = 1;
      }
      d.reverse();
      for (i = k; i--; ) d.push(0);
      d.reverse();
    } else {
      i = xd.length;
      len = yd.length;
      xLTy = i < len;
      if (xLTy) len = i;
      for (i = 0; i < len; i++) {
        if (xd[i] != yd[i]) {
          xLTy = xd[i] < yd[i];
          break;
        }
      }
      k = 0;
    }
    if (xLTy) {
      d = xd;
      xd = yd;
      yd = d;
      y.s = -y.s;
    }
    len = xd.length;
    for (i = yd.length - len; i > 0; --i) xd[len++] = 0;
    for (i = yd.length; i > k; ) {
      if (xd[--i] < yd[i]) {
        for (j = i; j && xd[--j] === 0; ) xd[j] = BASE - 1;
        --xd[j];
        xd[i] += BASE;
      }
      xd[i] -= yd[i];
    }
    for (; xd[--len] === 0; ) xd.pop();
    for (; xd[0] === 0; xd.shift()) --e;
    if (!xd[0]) return new Ctor(rm === 3 ? -0 : 0);
    y.d = xd;
    y.e = getBase10Exponent(xd, e);
    return external ? finalise(y, pr, rm) : y;
  };
  P.modulo = P.mod = function(y) {
    var q, x = this, Ctor = x.constructor;
    y = new Ctor(y);
    if (!x.d || !y.s || y.d && !y.d[0]) return new Ctor(NaN);
    if (!y.d || x.d && !x.d[0]) {
      return finalise(new Ctor(x), Ctor.precision, Ctor.rounding);
    }
    external = false;
    if (Ctor.modulo == 9) {
      q = divide(x, y.abs(), 0, 3, 1);
      q.s *= y.s;
    } else {
      q = divide(x, y, 0, Ctor.modulo, 1);
    }
    q = q.times(y);
    external = true;
    return x.minus(q);
  };
  P.naturalExponential = P.exp = function() {
    return naturalExponential(this);
  };
  P.naturalLogarithm = P.ln = function() {
    return naturalLogarithm(this);
  };
  P.negated = P.neg = function() {
    var x = new this.constructor(this);
    x.s = -x.s;
    return finalise(x);
  };
  P.plus = P.add = function(y) {
    var carry, d, e, i, k, len, pr, rm, xd, yd, x = this, Ctor = x.constructor;
    y = new Ctor(y);
    if (!x.d || !y.d) {
      if (!x.s || !y.s) y = new Ctor(NaN);
      else if (!x.d) y = new Ctor(y.d || x.s === y.s ? x : NaN);
      return y;
    }
    if (x.s != y.s) {
      y.s = -y.s;
      return x.minus(y);
    }
    xd = x.d;
    yd = y.d;
    pr = Ctor.precision;
    rm = Ctor.rounding;
    if (!xd[0] || !yd[0]) {
      if (!yd[0]) y = new Ctor(x);
      return external ? finalise(y, pr, rm) : y;
    }
    k = mathfloor(x.e / LOG_BASE);
    e = mathfloor(y.e / LOG_BASE);
    xd = xd.slice();
    i = k - e;
    if (i) {
      if (i < 0) {
        d = xd;
        i = -i;
        len = yd.length;
      } else {
        d = yd;
        e = k;
        len = xd.length;
      }
      k = Math.ceil(pr / LOG_BASE);
      len = k > len ? k + 1 : len + 1;
      if (i > len) {
        i = len;
        d.length = 1;
      }
      d.reverse();
      for (; i--; ) d.push(0);
      d.reverse();
    }
    len = xd.length;
    i = yd.length;
    if (len - i < 0) {
      i = len;
      d = yd;
      yd = xd;
      xd = d;
    }
    for (carry = 0; i; ) {
      carry = (xd[--i] = xd[i] + yd[i] + carry) / BASE | 0;
      xd[i] %= BASE;
    }
    if (carry) {
      xd.unshift(carry);
      ++e;
    }
    for (len = xd.length; xd[--len] == 0; ) xd.pop();
    y.d = xd;
    y.e = getBase10Exponent(xd, e);
    return external ? finalise(y, pr, rm) : y;
  };
  P.precision = P.sd = function(z) {
    var k, x = this;
    if (z !== void 0 && z !== !!z && z !== 1 && z !== 0) throw Error(invalidArgument + z);
    if (x.d) {
      k = getPrecision(x.d);
      if (z && x.e + 1 > k) k = x.e + 1;
    } else {
      k = NaN;
    }
    return k;
  };
  P.round = function() {
    var x = this, Ctor = x.constructor;
    return finalise(new Ctor(x), x.e + 1, Ctor.rounding);
  };
  P.sine = P.sin = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (!x.isFinite()) return new Ctor(NaN);
    if (x.isZero()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + Math.max(x.e, x.sd()) + LOG_BASE;
    Ctor.rounding = 1;
    x = sine(Ctor, toLessThanHalfPi(Ctor, x));
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return finalise(quadrant > 2 ? x.neg() : x, pr, rm, true);
  };
  P.squareRoot = P.sqrt = function() {
    var m, n, sd, r, rep, t, x = this, d = x.d, e = x.e, s = x.s, Ctor = x.constructor;
    if (s !== 1 || !d || !d[0]) {
      return new Ctor(!s || s < 0 && (!d || d[0]) ? NaN : d ? x : 1 / 0);
    }
    external = false;
    s = Math.sqrt(+x);
    if (s == 0 || s == 1 / 0) {
      n = digitsToString(d);
      if ((n.length + e) % 2 == 0) n += "0";
      s = Math.sqrt(n);
      e = mathfloor((e + 1) / 2) - (e < 0 || e % 2);
      if (s == 1 / 0) {
        n = "5e" + e;
      } else {
        n = s.toExponential();
        n = n.slice(0, n.indexOf("e") + 1) + e;
      }
      r = new Ctor(n);
    } else {
      r = new Ctor(s.toString());
    }
    sd = (e = Ctor.precision) + 3;
    for (; ; ) {
      t = r;
      r = t.plus(divide(x, t, sd + 2, 1)).times(0.5);
      if (digitsToString(t.d).slice(0, sd) === (n = digitsToString(r.d)).slice(0, sd)) {
        n = n.slice(sd - 3, sd + 1);
        if (n == "9999" || !rep && n == "4999") {
          if (!rep) {
            finalise(t, e + 1, 0);
            if (t.times(t).eq(x)) {
              r = t;
              break;
            }
          }
          sd += 4;
          rep = 1;
        } else {
          if (!+n || !+n.slice(1) && n.charAt(0) == "5") {
            finalise(r, e + 1, 1);
            m = !r.times(r).eq(x);
          }
          break;
        }
      }
    }
    external = true;
    return finalise(r, e, Ctor.rounding, m);
  };
  P.tangent = P.tan = function() {
    var pr, rm, x = this, Ctor = x.constructor;
    if (!x.isFinite()) return new Ctor(NaN);
    if (x.isZero()) return new Ctor(x);
    pr = Ctor.precision;
    rm = Ctor.rounding;
    Ctor.precision = pr + 10;
    Ctor.rounding = 1;
    x = x.sin();
    x.s = 1;
    x = divide(x, new Ctor(1).minus(x.times(x)).sqrt(), pr + 10, 0);
    Ctor.precision = pr;
    Ctor.rounding = rm;
    return finalise(quadrant == 2 || quadrant == 4 ? x.neg() : x, pr, rm, true);
  };
  P.times = P.mul = function(y) {
    var carry, e, i, k, r, rL, t, xdL, ydL, x = this, Ctor = x.constructor, xd = x.d, yd = (y = new Ctor(y)).d;
    y.s *= x.s;
    if (!xd || !xd[0] || !yd || !yd[0]) {
      return new Ctor(!y.s || xd && !xd[0] && !yd || yd && !yd[0] && !xd ? NaN : !xd || !yd ? y.s / 0 : y.s * 0);
    }
    e = mathfloor(x.e / LOG_BASE) + mathfloor(y.e / LOG_BASE);
    xdL = xd.length;
    ydL = yd.length;
    if (xdL < ydL) {
      r = xd;
      xd = yd;
      yd = r;
      rL = xdL;
      xdL = ydL;
      ydL = rL;
    }
    r = [];
    rL = xdL + ydL;
    for (i = rL; i--; ) r.push(0);
    for (i = ydL; --i >= 0; ) {
      carry = 0;
      for (k = xdL + i; k > i; ) {
        t = r[k] + yd[i] * xd[k - i - 1] + carry;
        r[k--] = t % BASE | 0;
        carry = t / BASE | 0;
      }
      r[k] = (r[k] + carry) % BASE | 0;
    }
    for (; !r[--rL]; ) r.pop();
    if (carry) ++e;
    else r.shift();
    y.d = r;
    y.e = getBase10Exponent(r, e);
    return external ? finalise(y, Ctor.precision, Ctor.rounding) : y;
  };
  P.toBinary = function(sd, rm) {
    return toStringBinary(this, 2, sd, rm);
  };
  P.toDecimalPlaces = P.toDP = function(dp, rm) {
    var x = this, Ctor = x.constructor;
    x = new Ctor(x);
    if (dp === void 0) return x;
    checkInt32(dp, 0, MAX_DIGITS);
    if (rm === void 0) rm = Ctor.rounding;
    else checkInt32(rm, 0, 8);
    return finalise(x, dp + x.e + 1, rm);
  };
  P.toExponential = function(dp, rm) {
    var str, x = this, Ctor = x.constructor;
    if (dp === void 0) {
      str = finiteToString(x, true);
    } else {
      checkInt32(dp, 0, MAX_DIGITS);
      if (rm === void 0) rm = Ctor.rounding;
      else checkInt32(rm, 0, 8);
      x = finalise(new Ctor(x), dp + 1, rm);
      str = finiteToString(x, true, dp + 1);
    }
    return x.isNeg() && !x.isZero() ? "-" + str : str;
  };
  P.toFixed = function(dp, rm) {
    var str, y, x = this, Ctor = x.constructor;
    if (dp === void 0) {
      str = finiteToString(x);
    } else {
      checkInt32(dp, 0, MAX_DIGITS);
      if (rm === void 0) rm = Ctor.rounding;
      else checkInt32(rm, 0, 8);
      y = finalise(new Ctor(x), dp + x.e + 1, rm);
      str = finiteToString(y, false, dp + y.e + 1);
    }
    return x.isNeg() && !x.isZero() ? "-" + str : str;
  };
  P.toFraction = function(maxD) {
    var d, d0, d1, d2, e, k, n, n0, n13, pr, q, r, x = this, xd = x.d, Ctor = x.constructor;
    if (!xd) return new Ctor(x);
    n13 = d0 = new Ctor(1);
    d1 = n0 = new Ctor(0);
    d = new Ctor(d1);
    e = d.e = getPrecision(xd) - x.e - 1;
    k = e % LOG_BASE;
    d.d[0] = mathpow(10, k < 0 ? LOG_BASE + k : k);
    if (maxD == null) {
      maxD = e > 0 ? d : n13;
    } else {
      n = new Ctor(maxD);
      if (!n.isInt() || n.lt(n13)) throw Error(invalidArgument + n);
      maxD = n.gt(d) ? e > 0 ? d : n13 : n;
    }
    external = false;
    n = new Ctor(digitsToString(xd));
    pr = Ctor.precision;
    Ctor.precision = e = xd.length * LOG_BASE * 2;
    for (; ; ) {
      q = divide(n, d, 0, 1, 1);
      d2 = d0.plus(q.times(d1));
      if (d2.cmp(maxD) == 1) break;
      d0 = d1;
      d1 = d2;
      d2 = n13;
      n13 = n0.plus(q.times(d2));
      n0 = d2;
      d2 = d;
      d = n.minus(q.times(d2));
      n = d2;
    }
    d2 = divide(maxD.minus(d0), d1, 0, 1, 1);
    n0 = n0.plus(d2.times(n13));
    d0 = d0.plus(d2.times(d1));
    n0.s = n13.s = x.s;
    r = divide(n13, d1, e, 1).minus(x).abs().cmp(divide(n0, d0, e, 1).minus(x).abs()) < 1 ? [n13, d1] : [n0, d0];
    Ctor.precision = pr;
    external = true;
    return r;
  };
  P.toHexadecimal = P.toHex = function(sd, rm) {
    return toStringBinary(this, 16, sd, rm);
  };
  P.toNearest = function(y, rm) {
    var x = this, Ctor = x.constructor;
    x = new Ctor(x);
    if (y == null) {
      if (!x.d) return x;
      y = new Ctor(1);
      rm = Ctor.rounding;
    } else {
      y = new Ctor(y);
      if (rm === void 0) {
        rm = Ctor.rounding;
      } else {
        checkInt32(rm, 0, 8);
      }
      if (!x.d) return y.s ? x : y;
      if (!y.d) {
        if (y.s) y.s = x.s;
        return y;
      }
    }
    if (y.d[0]) {
      external = false;
      x = divide(x, y, 0, rm, 1).times(y);
      external = true;
      finalise(x);
    } else {
      y.s = x.s;
      x = y;
    }
    return x;
  };
  P.toNumber = function() {
    return +this;
  };
  P.toOctal = function(sd, rm) {
    return toStringBinary(this, 8, sd, rm);
  };
  P.toPower = P.pow = function(y) {
    var e, k, pr, r, rm, s, x = this, Ctor = x.constructor, yn = +(y = new Ctor(y));
    if (!x.d || !y.d || !x.d[0] || !y.d[0]) return new Ctor(mathpow(+x, yn));
    x = new Ctor(x);
    if (x.eq(1)) return x;
    pr = Ctor.precision;
    rm = Ctor.rounding;
    if (y.eq(1)) return finalise(x, pr, rm);
    e = mathfloor(y.e / LOG_BASE);
    if (e >= y.d.length - 1 && (k = yn < 0 ? -yn : yn) <= MAX_SAFE_INTEGER) {
      r = intPow(Ctor, x, k, pr);
      return y.s < 0 ? new Ctor(1).div(r) : finalise(r, pr, rm);
    }
    s = x.s;
    if (s < 0) {
      if (e < y.d.length - 1) return new Ctor(NaN);
      if ((y.d[e] & 1) == 0) s = 1;
      if (x.e == 0 && x.d[0] == 1 && x.d.length == 1) {
        x.s = s;
        return x;
      }
    }
    k = mathpow(+x, yn);
    e = k == 0 || !isFinite(k) ? mathfloor(yn * (Math.log("0." + digitsToString(x.d)) / Math.LN10 + x.e + 1)) : new Ctor(k + "").e;
    if (e > Ctor.maxE + 1 || e < Ctor.minE - 1) return new Ctor(e > 0 ? s / 0 : 0);
    external = false;
    Ctor.rounding = x.s = 1;
    k = Math.min(12, (e + "").length);
    r = naturalExponential(y.times(naturalLogarithm(x, pr + k)), pr);
    if (r.d) {
      r = finalise(r, pr + 5, 1);
      if (checkRoundingDigits(r.d, pr, rm)) {
        e = pr + 10;
        r = finalise(naturalExponential(y.times(naturalLogarithm(x, e + k)), e), e + 5, 1);
        if (+digitsToString(r.d).slice(pr + 1, pr + 15) + 1 == 1e14) {
          r = finalise(r, pr + 1, 0);
        }
      }
    }
    r.s = s;
    external = true;
    Ctor.rounding = rm;
    return finalise(r, pr, rm);
  };
  P.toPrecision = function(sd, rm) {
    var str, x = this, Ctor = x.constructor;
    if (sd === void 0) {
      str = finiteToString(x, x.e <= Ctor.toExpNeg || x.e >= Ctor.toExpPos);
    } else {
      checkInt32(sd, 1, MAX_DIGITS);
      if (rm === void 0) rm = Ctor.rounding;
      else checkInt32(rm, 0, 8);
      x = finalise(new Ctor(x), sd, rm);
      str = finiteToString(x, sd <= x.e || x.e <= Ctor.toExpNeg, sd);
    }
    return x.isNeg() && !x.isZero() ? "-" + str : str;
  };
  P.toSignificantDigits = P.toSD = function(sd, rm) {
    var x = this, Ctor = x.constructor;
    if (sd === void 0) {
      sd = Ctor.precision;
      rm = Ctor.rounding;
    } else {
      checkInt32(sd, 1, MAX_DIGITS);
      if (rm === void 0) rm = Ctor.rounding;
      else checkInt32(rm, 0, 8);
    }
    return finalise(new Ctor(x), sd, rm);
  };
  P.toString = function() {
    var x = this, Ctor = x.constructor, str = finiteToString(x, x.e <= Ctor.toExpNeg || x.e >= Ctor.toExpPos);
    return x.isNeg() && !x.isZero() ? "-" + str : str;
  };
  P.truncated = P.trunc = function() {
    return finalise(new this.constructor(this), this.e + 1, 1);
  };
  P.valueOf = P.toJSON = function() {
    var x = this, Ctor = x.constructor, str = finiteToString(x, x.e <= Ctor.toExpNeg || x.e >= Ctor.toExpPos);
    return x.isNeg() ? "-" + str : str;
  };
  function digitsToString(d) {
    var i, k, ws, indexOfLastWord = d.length - 1, str = "", w = d[0];
    if (indexOfLastWord > 0) {
      str += w;
      for (i = 1; i < indexOfLastWord; i++) {
        ws = d[i] + "";
        k = LOG_BASE - ws.length;
        if (k) str += getZeroString(k);
        str += ws;
      }
      w = d[i];
      ws = w + "";
      k = LOG_BASE - ws.length;
      if (k) str += getZeroString(k);
    } else if (w === 0) {
      return "0";
    }
    for (; w % 10 === 0; ) w /= 10;
    return str + w;
  }
  function checkInt32(i, min2, max2) {
    if (i !== ~~i || i < min2 || i > max2) {
      throw Error(invalidArgument + i);
    }
  }
  function checkRoundingDigits(d, i, rm, repeating) {
    var di, k, r, rd;
    for (k = d[0]; k >= 10; k /= 10) --i;
    if (--i < 0) {
      i += LOG_BASE;
      di = 0;
    } else {
      di = Math.ceil((i + 1) / LOG_BASE);
      i %= LOG_BASE;
    }
    k = mathpow(10, LOG_BASE - i);
    rd = d[di] % k | 0;
    if (repeating == null) {
      if (i < 3) {
        if (i == 0) rd = rd / 100 | 0;
        else if (i == 1) rd = rd / 10 | 0;
        r = rm < 4 && rd == 99999 || rm > 3 && rd == 49999 || rd == 5e4 || rd == 0;
      } else {
        r = (rm < 4 && rd + 1 == k || rm > 3 && rd + 1 == k / 2) && (d[di + 1] / k / 100 | 0) == mathpow(10, i - 2) - 1 || (rd == k / 2 || rd == 0) && (d[di + 1] / k / 100 | 0) == 0;
      }
    } else {
      if (i < 4) {
        if (i == 0) rd = rd / 1e3 | 0;
        else if (i == 1) rd = rd / 100 | 0;
        else if (i == 2) rd = rd / 10 | 0;
        r = (repeating || rm < 4) && rd == 9999 || !repeating && rm > 3 && rd == 4999;
      } else {
        r = ((repeating || rm < 4) && rd + 1 == k || !repeating && rm > 3 && rd + 1 == k / 2) && (d[di + 1] / k / 1e3 | 0) == mathpow(10, i - 3) - 1;
      }
    }
    return r;
  }
  function convertBase(str, baseIn, baseOut) {
    var j, arr = [0], arrL, i = 0, strL = str.length;
    for (; i < strL; ) {
      for (arrL = arr.length; arrL--; ) arr[arrL] *= baseIn;
      arr[0] += NUMERALS.indexOf(str.charAt(i++));
      for (j = 0; j < arr.length; j++) {
        if (arr[j] > baseOut - 1) {
          if (arr[j + 1] === void 0) arr[j + 1] = 0;
          arr[j + 1] += arr[j] / baseOut | 0;
          arr[j] %= baseOut;
        }
      }
    }
    return arr.reverse();
  }
  function cosine(Ctor, x) {
    var k, len, y;
    if (x.isZero()) return x;
    len = x.d.length;
    if (len < 32) {
      k = Math.ceil(len / 3);
      y = (1 / tinyPow(4, k)).toString();
    } else {
      k = 16;
      y = "2.3283064365386962890625e-10";
    }
    Ctor.precision += k;
    x = taylorSeries(Ctor, 1, x.times(y), new Ctor(1));
    for (var i = k; i--; ) {
      var cos2x = x.times(x);
      x = cos2x.times(cos2x).minus(cos2x).times(8).plus(1);
    }
    Ctor.precision -= k;
    return x;
  }
  var divide = /* @__PURE__ */ (function() {
    function multiplyInteger(x, k, base) {
      var temp, carry = 0, i = x.length;
      for (x = x.slice(); i--; ) {
        temp = x[i] * k + carry;
        x[i] = temp % base | 0;
        carry = temp / base | 0;
      }
      if (carry) x.unshift(carry);
      return x;
    }
    function compare(a, b, aL, bL) {
      var i, r;
      if (aL != bL) {
        r = aL > bL ? 1 : -1;
      } else {
        for (i = r = 0; i < aL; i++) {
          if (a[i] != b[i]) {
            r = a[i] > b[i] ? 1 : -1;
            break;
          }
        }
      }
      return r;
    }
    function subtract2(a, b, aL, base) {
      var i = 0;
      for (; aL--; ) {
        a[aL] -= i;
        i = a[aL] < b[aL] ? 1 : 0;
        a[aL] = i * base + a[aL] - b[aL];
      }
      for (; !a[0] && a.length > 1; ) a.shift();
    }
    return function(x, y, pr, rm, dp, base) {
      var cmp, e, i, k, logBase, more, prod, prodL, q, qd, rem, remL, rem0, sd, t, xi, xL, yd0, yL, yz, Ctor = x.constructor, sign4 = x.s == y.s ? 1 : -1, xd = x.d, yd = y.d;
      if (!xd || !xd[0] || !yd || !yd[0]) {
        return new Ctor(
          // Return NaN if either NaN, or both Infinity or 0.
          !x.s || !y.s || (xd ? yd && xd[0] == yd[0] : !yd) ? NaN : (
            // Return ±0 if x is 0 or y is ±Infinity, or return ±Infinity as y is 0.
            xd && xd[0] == 0 || !yd ? sign4 * 0 : sign4 / 0
          )
        );
      }
      if (base) {
        logBase = 1;
        e = x.e - y.e;
      } else {
        base = BASE;
        logBase = LOG_BASE;
        e = mathfloor(x.e / logBase) - mathfloor(y.e / logBase);
      }
      yL = yd.length;
      xL = xd.length;
      q = new Ctor(sign4);
      qd = q.d = [];
      for (i = 0; yd[i] == (xd[i] || 0); i++) ;
      if (yd[i] > (xd[i] || 0)) e--;
      if (pr == null) {
        sd = pr = Ctor.precision;
        rm = Ctor.rounding;
      } else if (dp) {
        sd = pr + (x.e - y.e) + 1;
      } else {
        sd = pr;
      }
      if (sd < 0) {
        qd.push(1);
        more = true;
      } else {
        sd = sd / logBase + 2 | 0;
        i = 0;
        if (yL == 1) {
          k = 0;
          yd = yd[0];
          sd++;
          for (; (i < xL || k) && sd--; i++) {
            t = k * base + (xd[i] || 0);
            qd[i] = t / yd | 0;
            k = t % yd | 0;
          }
          more = k || i < xL;
        } else {
          k = base / (yd[0] + 1) | 0;
          if (k > 1) {
            yd = multiplyInteger(yd, k, base);
            xd = multiplyInteger(xd, k, base);
            yL = yd.length;
            xL = xd.length;
          }
          xi = yL;
          rem = xd.slice(0, yL);
          remL = rem.length;
          for (; remL < yL; ) rem[remL++] = 0;
          yz = yd.slice();
          yz.unshift(0);
          yd0 = yd[0];
          if (yd[1] >= base / 2) ++yd0;
          do {
            k = 0;
            cmp = compare(yd, rem, yL, remL);
            if (cmp < 0) {
              rem0 = rem[0];
              if (yL != remL) rem0 = rem0 * base + (rem[1] || 0);
              k = rem0 / yd0 | 0;
              if (k > 1) {
                if (k >= base) k = base - 1;
                prod = multiplyInteger(yd, k, base);
                prodL = prod.length;
                remL = rem.length;
                cmp = compare(prod, rem, prodL, remL);
                if (cmp == 1) {
                  k--;
                  subtract2(prod, yL < prodL ? yz : yd, prodL, base);
                }
              } else {
                if (k == 0) cmp = k = 1;
                prod = yd.slice();
              }
              prodL = prod.length;
              if (prodL < remL) prod.unshift(0);
              subtract2(rem, prod, remL, base);
              if (cmp == -1) {
                remL = rem.length;
                cmp = compare(yd, rem, yL, remL);
                if (cmp < 1) {
                  k++;
                  subtract2(rem, yL < remL ? yz : yd, remL, base);
                }
              }
              remL = rem.length;
            } else if (cmp === 0) {
              k++;
              rem = [0];
            }
            qd[i++] = k;
            if (cmp && rem[0]) {
              rem[remL++] = xd[xi] || 0;
            } else {
              rem = [xd[xi]];
              remL = 1;
            }
          } while ((xi++ < xL || rem[0] !== void 0) && sd--);
          more = rem[0] !== void 0;
        }
        if (!qd[0]) qd.shift();
      }
      if (logBase == 1) {
        q.e = e;
        inexact = more;
      } else {
        for (i = 1, k = qd[0]; k >= 10; k /= 10) i++;
        q.e = i + e * logBase - 1;
        finalise(q, dp ? pr + q.e + 1 : pr, rm, more);
      }
      return q;
    };
  })();
  function finalise(x, sd, rm, isTruncated) {
    var digits2, i, j, k, rd, roundUp, w, xd, xdi, Ctor = x.constructor;
    out: if (sd != null) {
      xd = x.d;
      if (!xd) return x;
      for (digits2 = 1, k = xd[0]; k >= 10; k /= 10) digits2++;
      i = sd - digits2;
      if (i < 0) {
        i += LOG_BASE;
        j = sd;
        w = xd[xdi = 0];
        rd = w / mathpow(10, digits2 - j - 1) % 10 | 0;
      } else {
        xdi = Math.ceil((i + 1) / LOG_BASE);
        k = xd.length;
        if (xdi >= k) {
          if (isTruncated) {
            for (; k++ <= xdi; ) xd.push(0);
            w = rd = 0;
            digits2 = 1;
            i %= LOG_BASE;
            j = i - LOG_BASE + 1;
          } else {
            break out;
          }
        } else {
          w = k = xd[xdi];
          for (digits2 = 1; k >= 10; k /= 10) digits2++;
          i %= LOG_BASE;
          j = i - LOG_BASE + digits2;
          rd = j < 0 ? 0 : w / mathpow(10, digits2 - j - 1) % 10 | 0;
        }
      }
      isTruncated = isTruncated || sd < 0 || xd[xdi + 1] !== void 0 || (j < 0 ? w : w % mathpow(10, digits2 - j - 1));
      roundUp = rm < 4 ? (rd || isTruncated) && (rm == 0 || rm == (x.s < 0 ? 3 : 2)) : rd > 5 || rd == 5 && (rm == 4 || isTruncated || rm == 6 && // Check whether the digit to the left of the rounding digit is odd.
      (i > 0 ? j > 0 ? w / mathpow(10, digits2 - j) : 0 : xd[xdi - 1]) % 10 & 1 || rm == (x.s < 0 ? 8 : 7));
      if (sd < 1 || !xd[0]) {
        xd.length = 0;
        if (roundUp) {
          sd -= x.e + 1;
          xd[0] = mathpow(10, (LOG_BASE - sd % LOG_BASE) % LOG_BASE);
          x.e = -sd || 0;
        } else {
          xd[0] = x.e = 0;
        }
        return x;
      }
      if (i == 0) {
        xd.length = xdi;
        k = 1;
        xdi--;
      } else {
        xd.length = xdi + 1;
        k = mathpow(10, LOG_BASE - i);
        xd[xdi] = j > 0 ? (w / mathpow(10, digits2 - j) % mathpow(10, j) | 0) * k : 0;
      }
      if (roundUp) {
        for (; ; ) {
          if (xdi == 0) {
            for (i = 1, j = xd[0]; j >= 10; j /= 10) i++;
            j = xd[0] += k;
            for (k = 1; j >= 10; j /= 10) k++;
            if (i != k) {
              x.e++;
              if (xd[0] == BASE) xd[0] = 1;
            }
            break;
          } else {
            xd[xdi] += k;
            if (xd[xdi] != BASE) break;
            xd[xdi--] = 0;
            k = 1;
          }
        }
      }
      for (i = xd.length; xd[--i] === 0; ) xd.pop();
    }
    if (external) {
      if (x.e > Ctor.maxE) {
        x.d = null;
        x.e = NaN;
      } else if (x.e < Ctor.minE) {
        x.e = 0;
        x.d = [0];
      }
    }
    return x;
  }
  function finiteToString(x, isExp, sd) {
    if (!x.isFinite()) return nonFiniteToString(x);
    var k, e = x.e, str = digitsToString(x.d), len = str.length;
    if (isExp) {
      if (sd && (k = sd - len) > 0) {
        str = str.charAt(0) + "." + str.slice(1) + getZeroString(k);
      } else if (len > 1) {
        str = str.charAt(0) + "." + str.slice(1);
      }
      str = str + (x.e < 0 ? "e" : "e+") + x.e;
    } else if (e < 0) {
      str = "0." + getZeroString(-e - 1) + str;
      if (sd && (k = sd - len) > 0) str += getZeroString(k);
    } else if (e >= len) {
      str += getZeroString(e + 1 - len);
      if (sd && (k = sd - e - 1) > 0) str = str + "." + getZeroString(k);
    } else {
      if ((k = e + 1) < len) str = str.slice(0, k) + "." + str.slice(k);
      if (sd && (k = sd - len) > 0) {
        if (e + 1 === len) str += ".";
        str += getZeroString(k);
      }
    }
    return str;
  }
  function getBase10Exponent(digits2, e) {
    var w = digits2[0];
    for (e *= LOG_BASE; w >= 10; w /= 10) e++;
    return e;
  }
  function getLn10(Ctor, sd, pr) {
    if (sd > LN10_PRECISION) {
      external = true;
      if (pr) Ctor.precision = pr;
      throw Error(precisionLimitExceeded);
    }
    return finalise(new Ctor(LN10), sd, 1, true);
  }
  function getPi(Ctor, sd, rm) {
    if (sd > PI_PRECISION) throw Error(precisionLimitExceeded);
    return finalise(new Ctor(PI), sd, rm, true);
  }
  function getPrecision(digits2) {
    var w = digits2.length - 1, len = w * LOG_BASE + 1;
    w = digits2[w];
    if (w) {
      for (; w % 10 == 0; w /= 10) len--;
      for (w = digits2[0]; w >= 10; w /= 10) len++;
    }
    return len;
  }
  function getZeroString(k) {
    var zs = "";
    for (; k--; ) zs += "0";
    return zs;
  }
  function intPow(Ctor, x, n, pr) {
    var isTruncated, r = new Ctor(1), k = Math.ceil(pr / LOG_BASE + 4);
    external = false;
    for (; ; ) {
      if (n % 2) {
        r = r.times(x);
        if (truncate(r.d, k)) isTruncated = true;
      }
      n = mathfloor(n / 2);
      if (n === 0) {
        n = r.d.length - 1;
        if (isTruncated && r.d[n] === 0) ++r.d[n];
        break;
      }
      x = x.times(x);
      truncate(x.d, k);
    }
    external = true;
    return r;
  }
  function isOdd(n) {
    return n.d[n.d.length - 1] & 1;
  }
  function maxOrMin(Ctor, args, n) {
    var k, y, x = new Ctor(args[0]), i = 0;
    for (; ++i < args.length; ) {
      y = new Ctor(args[i]);
      if (!y.s) {
        x = y;
        break;
      }
      k = x.cmp(y);
      if (k === n || k === 0 && x.s === n) {
        x = y;
      }
    }
    return x;
  }
  function naturalExponential(x, sd) {
    var denominator, guard, j, pow3, sum3, t, wpr, rep = 0, i = 0, k = 0, Ctor = x.constructor, rm = Ctor.rounding, pr = Ctor.precision;
    if (!x.d || !x.d[0] || x.e > 17) {
      return new Ctor(x.d ? !x.d[0] ? 1 : x.s < 0 ? 0 : 1 / 0 : x.s ? x.s < 0 ? 0 : x : 0 / 0);
    }
    if (sd == null) {
      external = false;
      wpr = pr;
    } else {
      wpr = sd;
    }
    t = new Ctor(0.03125);
    while (x.e > -2) {
      x = x.times(t);
      k += 5;
    }
    guard = Math.log(mathpow(2, k)) / Math.LN10 * 2 + 5 | 0;
    wpr += guard;
    denominator = pow3 = sum3 = new Ctor(1);
    Ctor.precision = wpr;
    for (; ; ) {
      pow3 = finalise(pow3.times(x), wpr, 1);
      denominator = denominator.times(++i);
      t = sum3.plus(divide(pow3, denominator, wpr, 1));
      if (digitsToString(t.d).slice(0, wpr) === digitsToString(sum3.d).slice(0, wpr)) {
        j = k;
        while (j--) sum3 = finalise(sum3.times(sum3), wpr, 1);
        if (sd == null) {
          if (rep < 3 && checkRoundingDigits(sum3.d, wpr - guard, rm, rep)) {
            Ctor.precision = wpr += 10;
            denominator = pow3 = t = new Ctor(1);
            i = 0;
            rep++;
          } else {
            return finalise(sum3, Ctor.precision = pr, rm, external = true);
          }
        } else {
          Ctor.precision = pr;
          return sum3;
        }
      }
      sum3 = t;
    }
  }
  function naturalLogarithm(y, sd) {
    var c, c0, denominator, e, numerator, rep, sum3, t, wpr, x1, x2, n = 1, guard = 10, x = y, xd = x.d, Ctor = x.constructor, rm = Ctor.rounding, pr = Ctor.precision;
    if (x.s < 0 || !xd || !xd[0] || !x.e && xd[0] == 1 && xd.length == 1) {
      return new Ctor(xd && !xd[0] ? -1 / 0 : x.s != 1 ? NaN : xd ? 0 : x);
    }
    if (sd == null) {
      external = false;
      wpr = pr;
    } else {
      wpr = sd;
    }
    Ctor.precision = wpr += guard;
    c = digitsToString(xd);
    c0 = c.charAt(0);
    if (Math.abs(e = x.e) < 15e14) {
      while (c0 < 7 && c0 != 1 || c0 == 1 && c.charAt(1) > 3) {
        x = x.times(y);
        c = digitsToString(x.d);
        c0 = c.charAt(0);
        n++;
      }
      e = x.e;
      if (c0 > 1) {
        x = new Ctor("0." + c);
        e++;
      } else {
        x = new Ctor(c0 + "." + c.slice(1));
      }
    } else {
      t = getLn10(Ctor, wpr + 2, pr).times(e + "");
      x = naturalLogarithm(new Ctor(c0 + "." + c.slice(1)), wpr - guard).plus(t);
      Ctor.precision = pr;
      return sd == null ? finalise(x, pr, rm, external = true) : x;
    }
    x1 = x;
    sum3 = numerator = x = divide(x.minus(1), x.plus(1), wpr, 1);
    x2 = finalise(x.times(x), wpr, 1);
    denominator = 3;
    for (; ; ) {
      numerator = finalise(numerator.times(x2), wpr, 1);
      t = sum3.plus(divide(numerator, new Ctor(denominator), wpr, 1));
      if (digitsToString(t.d).slice(0, wpr) === digitsToString(sum3.d).slice(0, wpr)) {
        sum3 = sum3.times(2);
        if (e !== 0) sum3 = sum3.plus(getLn10(Ctor, wpr + 2, pr).times(e + ""));
        sum3 = divide(sum3, new Ctor(n), wpr, 1);
        if (sd == null) {
          if (checkRoundingDigits(sum3.d, wpr - guard, rm, rep)) {
            Ctor.precision = wpr += guard;
            t = numerator = x = divide(x1.minus(1), x1.plus(1), wpr, 1);
            x2 = finalise(x.times(x), wpr, 1);
            denominator = rep = 1;
          } else {
            return finalise(sum3, Ctor.precision = pr, rm, external = true);
          }
        } else {
          Ctor.precision = pr;
          return sum3;
        }
      }
      sum3 = t;
      denominator += 2;
    }
  }
  function nonFiniteToString(x) {
    return String(x.s * x.s / 0);
  }
  function parseDecimal(x, str) {
    var e, i, len;
    if ((e = str.indexOf(".")) > -1) str = str.replace(".", "");
    if ((i = str.search(/e/i)) > 0) {
      if (e < 0) e = i;
      e += +str.slice(i + 1);
      str = str.substring(0, i);
    } else if (e < 0) {
      e = str.length;
    }
    for (i = 0; str.charCodeAt(i) === 48; i++) ;
    for (len = str.length; str.charCodeAt(len - 1) === 48; --len) ;
    str = str.slice(i, len);
    if (str) {
      len -= i;
      x.e = e = e - i - 1;
      x.d = [];
      i = (e + 1) % LOG_BASE;
      if (e < 0) i += LOG_BASE;
      if (i < len) {
        if (i) x.d.push(+str.slice(0, i));
        for (len -= LOG_BASE; i < len; ) x.d.push(+str.slice(i, i += LOG_BASE));
        str = str.slice(i);
        i = LOG_BASE - str.length;
      } else {
        i -= len;
      }
      for (; i--; ) str += "0";
      x.d.push(+str);
      if (external) {
        if (x.e > x.constructor.maxE) {
          x.d = null;
          x.e = NaN;
        } else if (x.e < x.constructor.minE) {
          x.e = 0;
          x.d = [0];
        }
      }
    } else {
      x.e = 0;
      x.d = [0];
    }
    return x;
  }
  function parseOther(x, str) {
    var base, Ctor, divisor, i, isFloat, len, p, xd, xe;
    if (str.indexOf("_") > -1) {
      str = str.replace(/(\d)_(?=\d)/g, "$1");
      if (isDecimal.test(str)) return parseDecimal(x, str);
    } else if (str === "Infinity" || str === "NaN") {
      if (!+str) x.s = NaN;
      x.e = NaN;
      x.d = null;
      return x;
    }
    if (isHex.test(str)) {
      base = 16;
      str = str.toLowerCase();
    } else if (isBinary.test(str)) {
      base = 2;
    } else if (isOctal.test(str)) {
      base = 8;
    } else {
      throw Error(invalidArgument + str);
    }
    i = str.search(/p/i);
    if (i > 0) {
      p = +str.slice(i + 1);
      str = str.substring(2, i);
    } else {
      str = str.slice(2);
    }
    i = str.indexOf(".");
    isFloat = i >= 0;
    Ctor = x.constructor;
    if (isFloat) {
      str = str.replace(".", "");
      len = str.length;
      i = len - i;
      divisor = intPow(Ctor, new Ctor(base), i, i * 2);
    }
    xd = convertBase(str, base, BASE);
    xe = xd.length - 1;
    for (i = xe; xd[i] === 0; --i) xd.pop();
    if (i < 0) return new Ctor(x.s * 0);
    x.e = getBase10Exponent(xd, xe);
    x.d = xd;
    external = false;
    if (isFloat) x = divide(x, divisor, len * 4);
    if (p) x = x.times(Math.abs(p) < 54 ? mathpow(2, p) : Decimal.pow(2, p));
    external = true;
    return x;
  }
  function sine(Ctor, x) {
    var k, len = x.d.length;
    if (len < 3) {
      return x.isZero() ? x : taylorSeries(Ctor, 2, x, x);
    }
    k = 1.4 * Math.sqrt(len);
    k = k > 16 ? 16 : k | 0;
    x = x.times(1 / tinyPow(5, k));
    x = taylorSeries(Ctor, 2, x, x);
    var sin2_x, d5 = new Ctor(5), d16 = new Ctor(16), d20 = new Ctor(20);
    for (; k--; ) {
      sin2_x = x.times(x);
      x = x.times(d5.plus(sin2_x.times(d16.times(sin2_x).minus(d20))));
    }
    return x;
  }
  function taylorSeries(Ctor, n, x, y, isHyperbolic) {
    var j, t, u, x2, i = 1, pr = Ctor.precision, k = Math.ceil(pr / LOG_BASE);
    external = false;
    x2 = x.times(x);
    u = new Ctor(y);
    for (; ; ) {
      t = divide(u.times(x2), new Ctor(n++ * n++), pr, 1);
      u = isHyperbolic ? y.plus(t) : y.minus(t);
      y = divide(t.times(x2), new Ctor(n++ * n++), pr, 1);
      t = u.plus(y);
      if (t.d[k] !== void 0) {
        for (j = k; t.d[j] === u.d[j] && j--; ) ;
        if (j == -1) break;
      }
      j = u;
      u = y;
      y = t;
      t = j;
      i++;
    }
    external = true;
    t.d.length = k + 1;
    return t;
  }
  function tinyPow(b, e) {
    var n = b;
    while (--e) n *= b;
    return n;
  }
  function toLessThanHalfPi(Ctor, x) {
    var t, isNeg = x.s < 0, pi = getPi(Ctor, Ctor.precision, 1), halfPi = pi.times(0.5);
    x = x.abs();
    if (x.lte(halfPi)) {
      quadrant = isNeg ? 4 : 1;
      return x;
    }
    t = x.divToInt(pi);
    if (t.isZero()) {
      quadrant = isNeg ? 3 : 2;
    } else {
      x = x.minus(t.times(pi));
      if (x.lte(halfPi)) {
        quadrant = isOdd(t) ? isNeg ? 2 : 3 : isNeg ? 4 : 1;
        return x;
      }
      quadrant = isOdd(t) ? isNeg ? 1 : 4 : isNeg ? 3 : 2;
    }
    return x.minus(pi).abs();
  }
  function toStringBinary(x, baseOut, sd, rm) {
    var base, e, i, k, len, roundUp, str, xd, y, Ctor = x.constructor, isExp = sd !== void 0;
    if (isExp) {
      checkInt32(sd, 1, MAX_DIGITS);
      if (rm === void 0) rm = Ctor.rounding;
      else checkInt32(rm, 0, 8);
    } else {
      sd = Ctor.precision;
      rm = Ctor.rounding;
    }
    if (!x.isFinite()) {
      str = nonFiniteToString(x);
    } else {
      str = finiteToString(x);
      i = str.indexOf(".");
      if (isExp) {
        base = 2;
        if (baseOut == 16) {
          sd = sd * 4 - 3;
        } else if (baseOut == 8) {
          sd = sd * 3 - 2;
        }
      } else {
        base = baseOut;
      }
      if (i >= 0) {
        str = str.replace(".", "");
        y = new Ctor(1);
        y.e = str.length - i;
        y.d = convertBase(finiteToString(y), 10, base);
        y.e = y.d.length;
      }
      xd = convertBase(str, 10, base);
      e = len = xd.length;
      for (; xd[--len] == 0; ) xd.pop();
      if (!xd[0]) {
        str = isExp ? "0p+0" : "0";
      } else {
        if (i < 0) {
          e--;
        } else {
          x = new Ctor(x);
          x.d = xd;
          x.e = e;
          x = divide(x, y, sd, rm, 0, base);
          xd = x.d;
          e = x.e;
          roundUp = inexact;
        }
        i = xd[sd];
        k = base / 2;
        roundUp = roundUp || xd[sd + 1] !== void 0;
        roundUp = rm < 4 ? (i !== void 0 || roundUp) && (rm === 0 || rm === (x.s < 0 ? 3 : 2)) : i > k || i === k && (rm === 4 || roundUp || rm === 6 && xd[sd - 1] & 1 || rm === (x.s < 0 ? 8 : 7));
        xd.length = sd;
        if (roundUp) {
          for (; ++xd[--sd] > base - 1; ) {
            xd[sd] = 0;
            if (!sd) {
              ++e;
              xd.unshift(1);
            }
          }
        }
        for (len = xd.length; !xd[len - 1]; --len) ;
        for (i = 0, str = ""; i < len; i++) str += NUMERALS.charAt(xd[i]);
        if (isExp) {
          if (len > 1) {
            if (baseOut == 16 || baseOut == 8) {
              i = baseOut == 16 ? 4 : 3;
              for (--len; len % i; len++) str += "0";
              xd = convertBase(str, base, baseOut);
              for (len = xd.length; !xd[len - 1]; --len) ;
              for (i = 1, str = "1."; i < len; i++) str += NUMERALS.charAt(xd[i]);
            } else {
              str = str.charAt(0) + "." + str.slice(1);
            }
          }
          str = str + (e < 0 ? "p" : "p+") + e;
        } else if (e < 0) {
          for (; ++e; ) str = "0" + str;
          str = "0." + str;
        } else {
          if (++e > len) for (e -= len; e--; ) str += "0";
          else if (e < len) str = str.slice(0, e) + "." + str.slice(e);
        }
      }
      str = (baseOut == 16 ? "0x" : baseOut == 2 ? "0b" : baseOut == 8 ? "0o" : "") + str;
    }
    return x.s < 0 ? "-" + str : str;
  }
  function truncate(arr, len) {
    if (arr.length > len) {
      arr.length = len;
      return true;
    }
  }
  function abs(x) {
    return new this(x).abs();
  }
  function acos(x) {
    return new this(x).acos();
  }
  function acosh(x) {
    return new this(x).acosh();
  }
  function add(x, y) {
    return new this(x).plus(y);
  }
  function asin(x) {
    return new this(x).asin();
  }
  function asinh(x) {
    return new this(x).asinh();
  }
  function atan(x) {
    return new this(x).atan();
  }
  function atanh(x) {
    return new this(x).atanh();
  }
  function atan2(y, x) {
    y = new this(y);
    x = new this(x);
    var r, pr = this.precision, rm = this.rounding, wpr = pr + 4;
    if (!y.s || !x.s) {
      r = new this(NaN);
    } else if (!y.d && !x.d) {
      r = getPi(this, wpr, 1).times(x.s > 0 ? 0.25 : 0.75);
      r.s = y.s;
    } else if (!x.d || y.isZero()) {
      r = x.s < 0 ? getPi(this, pr, rm) : new this(0);
      r.s = y.s;
    } else if (!y.d || x.isZero()) {
      r = getPi(this, wpr, 1).times(0.5);
      r.s = y.s;
    } else if (x.s < 0) {
      this.precision = wpr;
      this.rounding = 1;
      r = this.atan(divide(y, x, wpr, 1));
      x = getPi(this, wpr, 1);
      this.precision = pr;
      this.rounding = rm;
      r = y.s < 0 ? r.minus(x) : r.plus(x);
    } else {
      r = this.atan(divide(y, x, wpr, 1));
    }
    return r;
  }
  function cbrt3(x) {
    return new this(x).cbrt();
  }
  function ceil(x) {
    return finalise(x = new this(x), x.e + 1, 2);
  }
  function clamp(x, min2, max2) {
    return new this(x).clamp(min2, max2);
  }
  function config3(obj) {
    if (!obj || typeof obj !== "object") throw Error(decimalError + "Object expected");
    var i, p, v, useDefaults = obj.defaults === true, ps = [
      "precision",
      1,
      MAX_DIGITS,
      "rounding",
      0,
      8,
      "toExpNeg",
      -EXP_LIMIT,
      0,
      "toExpPos",
      0,
      EXP_LIMIT,
      "maxE",
      0,
      EXP_LIMIT,
      "minE",
      -EXP_LIMIT,
      0,
      "modulo",
      0,
      9
    ];
    for (i = 0; i < ps.length; i += 3) {
      if (p = ps[i], useDefaults) this[p] = DEFAULTS[p];
      if ((v = obj[p]) !== void 0) {
        if (mathfloor(v) === v && v >= ps[i + 1] && v <= ps[i + 2]) this[p] = v;
        else throw Error(invalidArgument + p + ": " + v);
      }
    }
    if (p = "crypto", useDefaults) this[p] = DEFAULTS[p];
    if ((v = obj[p]) !== void 0) {
      if (v === true || v === false || v === 0 || v === 1) {
        if (v) {
          if (typeof crypto != "undefined" && crypto && (crypto.getRandomValues || crypto.randomBytes)) {
            this[p] = true;
          } else {
            throw Error(cryptoUnavailable);
          }
        } else {
          this[p] = false;
        }
      } else {
        throw Error(invalidArgument + p + ": " + v);
      }
    }
    return this;
  }
  function cos(x) {
    return new this(x).cos();
  }
  function cosh(x) {
    return new this(x).cosh();
  }
  function clone2(obj) {
    var i, p, ps;
    function Decimal2(v) {
      var e, i2, t, x = this;
      if (!(x instanceof Decimal2)) return new Decimal2(v);
      x.constructor = Decimal2;
      if (isDecimalInstance(v)) {
        x.s = v.s;
        if (external) {
          if (!v.d || v.e > Decimal2.maxE) {
            x.e = NaN;
            x.d = null;
          } else if (v.e < Decimal2.minE) {
            x.e = 0;
            x.d = [0];
          } else {
            x.e = v.e;
            x.d = v.d.slice();
          }
        } else {
          x.e = v.e;
          x.d = v.d ? v.d.slice() : v.d;
        }
        return;
      }
      t = typeof v;
      if (t === "number") {
        if (v === 0) {
          x.s = 1 / v < 0 ? -1 : 1;
          x.e = 0;
          x.d = [0];
          return;
        }
        if (v < 0) {
          v = -v;
          x.s = -1;
        } else {
          x.s = 1;
        }
        if (v === ~~v && v < 1e7) {
          for (e = 0, i2 = v; i2 >= 10; i2 /= 10) e++;
          if (external) {
            if (e > Decimal2.maxE) {
              x.e = NaN;
              x.d = null;
            } else if (e < Decimal2.minE) {
              x.e = 0;
              x.d = [0];
            } else {
              x.e = e;
              x.d = [v];
            }
          } else {
            x.e = e;
            x.d = [v];
          }
          return;
        }
        if (v * 0 !== 0) {
          if (!v) x.s = NaN;
          x.e = NaN;
          x.d = null;
          return;
        }
        return parseDecimal(x, v.toString());
      }
      if (t === "string") {
        if ((i2 = v.charCodeAt(0)) === 45) {
          v = v.slice(1);
          x.s = -1;
        } else {
          if (i2 === 43) v = v.slice(1);
          x.s = 1;
        }
        return isDecimal.test(v) ? parseDecimal(x, v) : parseOther(x, v);
      }
      if (t === "bigint") {
        if (v < 0) {
          v = -v;
          x.s = -1;
        } else {
          x.s = 1;
        }
        return parseDecimal(x, v.toString());
      }
      throw Error(invalidArgument + v);
    }
    Decimal2.prototype = P;
    Decimal2.ROUND_UP = 0;
    Decimal2.ROUND_DOWN = 1;
    Decimal2.ROUND_CEIL = 2;
    Decimal2.ROUND_FLOOR = 3;
    Decimal2.ROUND_HALF_UP = 4;
    Decimal2.ROUND_HALF_DOWN = 5;
    Decimal2.ROUND_HALF_EVEN = 6;
    Decimal2.ROUND_HALF_CEIL = 7;
    Decimal2.ROUND_HALF_FLOOR = 8;
    Decimal2.EUCLID = 9;
    Decimal2.config = Decimal2.set = config3;
    Decimal2.clone = clone2;
    Decimal2.isDecimal = isDecimalInstance;
    Decimal2.abs = abs;
    Decimal2.acos = acos;
    Decimal2.acosh = acosh;
    Decimal2.add = add;
    Decimal2.asin = asin;
    Decimal2.asinh = asinh;
    Decimal2.atan = atan;
    Decimal2.atanh = atanh;
    Decimal2.atan2 = atan2;
    Decimal2.cbrt = cbrt3;
    Decimal2.ceil = ceil;
    Decimal2.clamp = clamp;
    Decimal2.cos = cos;
    Decimal2.cosh = cosh;
    Decimal2.div = div;
    Decimal2.exp = exp;
    Decimal2.floor = floor;
    Decimal2.hypot = hypot;
    Decimal2.ln = ln;
    Decimal2.log = log;
    Decimal2.log10 = log103;
    Decimal2.log2 = log23;
    Decimal2.max = max;
    Decimal2.min = min;
    Decimal2.mod = mod;
    Decimal2.mul = mul;
    Decimal2.pow = pow;
    Decimal2.random = random;
    Decimal2.round = round;
    Decimal2.sign = sign2;
    Decimal2.sin = sin;
    Decimal2.sinh = sinh;
    Decimal2.sqrt = sqrt;
    Decimal2.sub = sub;
    Decimal2.sum = sum;
    Decimal2.tan = tan;
    Decimal2.tanh = tanh;
    Decimal2.trunc = trunc;
    if (obj === void 0) obj = {};
    if (obj) {
      if (obj.defaults !== true) {
        ps = ["precision", "rounding", "toExpNeg", "toExpPos", "maxE", "minE", "modulo", "crypto"];
        for (i = 0; i < ps.length; ) if (!obj.hasOwnProperty(p = ps[i++])) obj[p] = this[p];
      }
    }
    Decimal2.config(obj);
    return Decimal2;
  }
  function div(x, y) {
    return new this(x).div(y);
  }
  function exp(x) {
    return new this(x).exp();
  }
  function floor(x) {
    return finalise(x = new this(x), x.e + 1, 3);
  }
  function hypot() {
    var i, n, t = new this(0);
    external = false;
    for (i = 0; i < arguments.length; ) {
      n = new this(arguments[i++]);
      if (!n.d) {
        if (n.s) {
          external = true;
          return new this(1 / 0);
        }
        t = n;
      } else if (t.d) {
        t = t.plus(n.times(n));
      }
    }
    external = true;
    return t.sqrt();
  }
  function isDecimalInstance(obj) {
    return obj instanceof Decimal || obj && obj.toStringTag === tag || false;
  }
  function ln(x) {
    return new this(x).ln();
  }
  function log(x, y) {
    return new this(x).log(y);
  }
  function log23(x) {
    return new this(x).log(2);
  }
  function log103(x) {
    return new this(x).log(10);
  }
  function max() {
    return maxOrMin(this, arguments, -1);
  }
  function min() {
    return maxOrMin(this, arguments, 1);
  }
  function mod(x, y) {
    return new this(x).mod(y);
  }
  function mul(x, y) {
    return new this(x).mul(y);
  }
  function pow(x, y) {
    return new this(x).pow(y);
  }
  function random(sd) {
    var d, e, k, n, i = 0, r = new this(1), rd = [];
    if (sd === void 0) sd = this.precision;
    else checkInt32(sd, 1, MAX_DIGITS);
    k = Math.ceil(sd / LOG_BASE);
    if (!this.crypto) {
      for (; i < k; ) rd[i++] = Math.random() * 1e7 | 0;
    } else if (crypto.getRandomValues) {
      d = crypto.getRandomValues(new Uint32Array(k));
      for (; i < k; ) {
        n = d[i];
        if (n >= 429e7) {
          d[i] = crypto.getRandomValues(new Uint32Array(1))[0];
        } else {
          rd[i++] = n % 1e7;
        }
      }
    } else if (crypto.randomBytes) {
      d = crypto.randomBytes(k *= 4);
      for (; i < k; ) {
        n = d[i] + (d[i + 1] << 8) + (d[i + 2] << 16) + ((d[i + 3] & 127) << 24);
        if (n >= 214e7) {
          crypto.randomBytes(4).copy(d, i);
        } else {
          rd.push(n % 1e7);
          i += 4;
        }
      }
      i = k / 4;
    } else {
      throw Error(cryptoUnavailable);
    }
    k = rd[--i];
    sd %= LOG_BASE;
    if (k && sd) {
      n = mathpow(10, LOG_BASE - sd);
      rd[i] = (k / n | 0) * n;
    }
    for (; rd[i] === 0; i--) rd.pop();
    if (i < 0) {
      e = 0;
      rd = [0];
    } else {
      e = -1;
      for (; rd[0] === 0; e -= LOG_BASE) rd.shift();
      for (k = 1, n = rd[0]; n >= 10; n /= 10) k++;
      if (k < LOG_BASE) e -= LOG_BASE - k;
    }
    r.e = e;
    r.d = rd;
    return r;
  }
  function round(x) {
    return finalise(x = new this(x), x.e + 1, this.rounding);
  }
  function sign2(x) {
    x = new this(x);
    return x.d ? x.d[0] ? x.s : 0 * x.s : x.s || NaN;
  }
  function sin(x) {
    return new this(x).sin();
  }
  function sinh(x) {
    return new this(x).sinh();
  }
  function sqrt(x) {
    return new this(x).sqrt();
  }
  function sub(x, y) {
    return new this(x).sub(y);
  }
  function sum() {
    var i = 0, args = arguments, x = new this(args[i]);
    external = false;
    for (; x.s && ++i < args.length; ) x = x.plus(args[i]);
    external = true;
    return finalise(x, this.precision, this.rounding);
  }
  function tan(x) {
    return new this(x).tan();
  }
  function tanh(x) {
    return new this(x).tanh();
  }
  function trunc(x) {
    return finalise(x = new this(x), x.e + 1, 1);
  }
  P[/* @__PURE__ */ Symbol.for("nodejs.util.inspect.custom")] = P.toString;
  P[Symbol.toStringTag] = "Decimal";
  var Decimal = P.constructor = clone2(DEFAULTS);
  LN10 = new Decimal(LN10);
  PI = new Decimal(PI);
  var decimal_default = Decimal;

  // node_modules/mathjs/lib/esm/type/bignumber/BigNumber.js
  var name = "BigNumber";
  var dependencies2 = ["?on", "config"];
  var createBigNumberClass = /* @__PURE__ */ factory(name, dependencies2, (_ref) => {
    var {
      on,
      config: config4
    } = _ref;
    var BigNumber2 = decimal_default.clone({
      precision: config4.precision,
      modulo: decimal_default.EUCLID
    });
    BigNumber2.prototype = Object.create(BigNumber2.prototype);
    BigNumber2.prototype.type = "BigNumber";
    BigNumber2.prototype.isBigNumber = true;
    BigNumber2.prototype.toJSON = function() {
      return {
        mathjs: "BigNumber",
        value: this.toString()
      };
    };
    BigNumber2.fromJSON = function(json) {
      return new BigNumber2(json.value);
    };
    if (on) {
      on("config", function(curr, prev) {
        if (curr.precision !== prev.precision) {
          BigNumber2.config({
            precision: curr.precision
          });
        }
      });
    }
    return BigNumber2;
  }, {
    isClass: true
  });

  // node_modules/complex.js/dist/complex.mjs
  var cosh2 = Math.cosh || function(x) {
    return Math.abs(x) < 1e-9 ? 1 - x : (Math.exp(x) + Math.exp(-x)) * 0.5;
  };
  var sinh2 = Math.sinh || function(x) {
    return Math.abs(x) < 1e-9 ? x : (Math.exp(x) - Math.exp(-x)) * 0.5;
  };
  var cosm1 = (x) => {
    const s = Math.sin(0.5 * x);
    return -2 * s * s;
  };
  var hypot2 = function(x, y) {
    x = Math.abs(x);
    y = Math.abs(y);
    if (x < y) [x, y] = [y, x];
    if (x < 1e8) return Math.sqrt(x * x + y * y);
    y /= x;
    return x * Math.sqrt(1 + y * y);
  };
  var parser_exit = function() {
    throw SyntaxError("Invalid Param");
  };
  function logHypot(a, b) {
    const _a = Math.abs(a);
    const _b = Math.abs(b);
    if (a === 0) {
      return Math.log(_b);
    }
    if (b === 0) {
      return Math.log(_a);
    }
    if (_a < 3e3 && _b < 3e3) {
      return Math.log(a * a + b * b) * 0.5;
    }
    a = a * 0.5;
    b = b * 0.5;
    return 0.5 * Math.log(a * a + b * b) + Math.LN2;
  }
  var P2 = { "re": 0, "im": 0 };
  var parse = function(a, b) {
    const z = P2;
    if (a === void 0 || a === null) {
      z["re"] = z["im"] = 0;
    } else if (b !== void 0) {
      z["re"] = a;
      z["im"] = b;
    } else
      switch (typeof a) {
        case "object":
          if ("im" in a && "re" in a) {
            z["re"] = a["re"];
            z["im"] = a["im"];
          } else if ("abs" in a && "arg" in a) {
            if (!isFinite(a["abs"]) && isFinite(a["arg"])) {
              return Complex["INFINITY"];
            }
            z["re"] = a["abs"] * Math.cos(a["arg"]);
            z["im"] = a["abs"] * Math.sin(a["arg"]);
          } else if ("r" in a && "phi" in a) {
            if (!isFinite(a["r"]) && isFinite(a["phi"])) {
              return Complex["INFINITY"];
            }
            z["re"] = a["r"] * Math.cos(a["phi"]);
            z["im"] = a["r"] * Math.sin(a["phi"]);
          } else if (a.length === 2) {
            z["re"] = a[0];
            z["im"] = a[1];
          } else {
            parser_exit();
          }
          break;
        case "string":
          z["im"] = /* void */
          z["re"] = 0;
          const tokens = a.replace(/_/g, "").match(/\d+\.?\d*e[+-]?\d+|\d+\.?\d*|\.\d+|./g);
          let plus = 1;
          let minus = 0;
          if (tokens === null) {
            parser_exit();
          }
          for (let i = 0; i < tokens.length; i++) {
            const c = tokens[i];
            if (c === " " || c === "	" || c === "\n") {
            } else if (c === "+") {
              plus++;
            } else if (c === "-") {
              minus++;
            } else if (c === "i" || c === "I") {
              if (plus + minus === 0) {
                parser_exit();
              }
              if (tokens[i + 1] !== " " && !isNaN(tokens[i + 1])) {
                z["im"] += parseFloat((minus % 2 ? "-" : "") + tokens[i + 1]);
                i++;
              } else {
                z["im"] += parseFloat((minus % 2 ? "-" : "") + "1");
              }
              plus = minus = 0;
            } else {
              if (plus + minus === 0 || isNaN(c)) {
                parser_exit();
              }
              if (tokens[i + 1] === "i" || tokens[i + 1] === "I") {
                z["im"] += parseFloat((minus % 2 ? "-" : "") + c);
                i++;
              } else {
                z["re"] += parseFloat((minus % 2 ? "-" : "") + c);
              }
              plus = minus = 0;
            }
          }
          if (plus + minus > 0) {
            parser_exit();
          }
          break;
        case "number":
          z["im"] = 0;
          z["re"] = a;
          break;
        default:
          parser_exit();
      }
    if (isNaN(z["re"]) || isNaN(z["im"])) {
    }
    return z;
  };
  function Complex(a, b) {
    if (!(this instanceof Complex)) {
      return new Complex(a, b);
    }
    const z = parse(a, b);
    this["re"] = z["re"];
    this["im"] = z["im"];
  }
  Complex.prototype = {
    "re": 0,
    "im": 0,
    /**
     * Calculates the sign of a complex number, which is a normalized complex
     *
     * @returns {Complex}
     */
    "sign": function() {
      const abs3 = hypot2(this["re"], this["im"]);
      return new Complex(
        this["re"] / abs3,
        this["im"] / abs3
      );
    },
    /**
     * Adds two complex numbers
     *
     * @returns {Complex}
     */
    "add": function(a, b) {
      const z = parse(a, b);
      const tInfin = this["isInfinite"]();
      const zInfin = !(isFinite(z["re"]) && isFinite(z["im"]));
      if (tInfin || zInfin) {
        if (tInfin && zInfin) {
          return Complex["NAN"];
        }
        return Complex["INFINITY"];
      }
      return new Complex(
        this["re"] + z["re"],
        this["im"] + z["im"]
      );
    },
    /**
     * Subtracts two complex numbers
     *
     * @returns {Complex}
     */
    "sub": function(a, b) {
      const z = parse(a, b);
      const tInfin = this["isInfinite"]();
      const zInfin = !(isFinite(z["re"]) && isFinite(z["im"]));
      if (tInfin || zInfin) {
        if (tInfin && zInfin) {
          return Complex["NAN"];
        }
        return Complex["INFINITY"];
      }
      return new Complex(
        this["re"] - z["re"],
        this["im"] - z["im"]
      );
    },
    /**
     * Multiplies two complex numbers
     *
     * @returns {Complex}
     */
    "mul": function(a, b) {
      const z = parse(a, b);
      const tInfin = this["isInfinite"]();
      const zInfin = !(isFinite(z["re"]) && isFinite(z["im"]));
      const tIsZero = this["re"] === 0 && this["im"] === 0;
      const zIsZero = z["re"] === 0 && z["im"] === 0;
      if (tInfin && zIsZero || zInfin && tIsZero) {
        return Complex["NAN"];
      }
      if (tInfin || zInfin) {
        return Complex["INFINITY"];
      }
      if (z["im"] === 0 && this["im"] === 0) {
        return new Complex(this["re"] * z["re"], 0);
      }
      return new Complex(
        this["re"] * z["re"] - this["im"] * z["im"],
        this["re"] * z["im"] + this["im"] * z["re"]
      );
    },
    /**
     * Divides two complex numbers
     *
     * @returns {Complex}
     */
    "div": function(a, b) {
      const z = parse(a, b);
      const tInfin = this["isInfinite"]();
      const zInfin = !(isFinite(z["re"]) && isFinite(z["im"]));
      const tIsZero = this["re"] === 0 && this["im"] === 0;
      const zIsZero = z["re"] === 0 && z["im"] === 0;
      if (tIsZero && zIsZero || tInfin && zInfin) {
        return Complex["NAN"];
      }
      if (zIsZero || tInfin) {
        return Complex["INFINITY"];
      }
      if (tIsZero || zInfin) {
        return Complex["ZERO"];
      }
      if (0 === z["im"]) {
        return new Complex(this["re"] / z["re"], this["im"] / z["re"]);
      }
      if (Math.abs(z["re"]) < Math.abs(z["im"])) {
        const x = z["re"] / z["im"];
        const t = z["re"] * x + z["im"];
        return new Complex(
          (this["re"] * x + this["im"]) / t,
          (this["im"] * x - this["re"]) / t
        );
      } else {
        const x = z["im"] / z["re"];
        const t = z["im"] * x + z["re"];
        return new Complex(
          (this["re"] + this["im"] * x) / t,
          (this["im"] - this["re"] * x) / t
        );
      }
    },
    /**
     * Calculate the power of two complex numbers
     *
     * @returns {Complex}
     */
    "pow": function(a, b) {
      const z = parse(a, b);
      const tIsZero = this["re"] === 0 && this["im"] === 0;
      const zIsZero = z["re"] === 0 && z["im"] === 0;
      if (zIsZero) {
        return Complex["ONE"];
      }
      if (z["im"] === 0) {
        if (this["im"] === 0 && this["re"] > 0) {
          return new Complex(Math.pow(this["re"], z["re"]), 0);
        } else if (this["re"] === 0) {
          switch ((z["re"] % 4 + 4) % 4) {
            case 0:
              return new Complex(Math.pow(this["im"], z["re"]), 0);
            case 1:
              return new Complex(0, Math.pow(this["im"], z["re"]));
            case 2:
              return new Complex(-Math.pow(this["im"], z["re"]), 0);
            case 3:
              return new Complex(0, -Math.pow(this["im"], z["re"]));
          }
        }
      }
      if (tIsZero && z["re"] > 0) {
        return Complex["ZERO"];
      }
      const arg = Math.atan2(this["im"], this["re"]);
      const loh = logHypot(this["re"], this["im"]);
      let re2 = Math.exp(z["re"] * loh - z["im"] * arg);
      let im2 = z["im"] * loh + z["re"] * arg;
      return new Complex(
        re2 * Math.cos(im2),
        re2 * Math.sin(im2)
      );
    },
    /**
     * Calculate the complex square root
     *
     * @returns {Complex}
     */
    "sqrt": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        if (a >= 0) {
          return new Complex(Math.sqrt(a), 0);
        } else {
          return new Complex(0, Math.sqrt(-a));
        }
      }
      const r = hypot2(a, b);
      let re2 = Math.sqrt(0.5 * (r + Math.abs(a)));
      let im2 = Math.abs(b) / (2 * re2);
      if (a >= 0) {
        return new Complex(re2, b < 0 ? -im2 : im2);
      } else {
        return new Complex(im2, b < 0 ? -re2 : re2);
      }
    },
    /**
     * Calculate the complex exponent
     *
     * @returns {Complex}
     */
    "exp": function() {
      const er = Math.exp(this["re"]);
      if (this["im"] === 0) {
        return new Complex(er, 0);
      }
      return new Complex(
        er * Math.cos(this["im"]),
        er * Math.sin(this["im"])
      );
    },
    /**
     * Calculate the complex exponent and subtracts one.
     *
     * This may be more accurate than `Complex(x).exp().sub(1)` if
     * `x` is small.
     *
     * @returns {Complex}
     */
    "expm1": function() {
      const a = this["re"];
      const b = this["im"];
      return new Complex(
        Math.expm1(a) * Math.cos(b) + cosm1(b),
        Math.exp(a) * Math.sin(b)
      );
    },
    /**
     * Calculate the natural log
     *
     * @returns {Complex}
     */
    "log": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0 && a > 0) {
        return new Complex(Math.log(a), 0);
      }
      return new Complex(
        logHypot(a, b),
        Math.atan2(b, a)
      );
    },
    /**
     * Calculate the magnitude of the complex number
     *
     * @returns {number}
     */
    "abs": function() {
      return hypot2(this["re"], this["im"]);
    },
    /**
     * Calculate the angle of the complex number
     *
     * @returns {number}
     */
    "arg": function() {
      return Math.atan2(this["im"], this["re"]);
    },
    /**
     * Calculate the sine of the complex number
     *
     * @returns {Complex}
     */
    "sin": function() {
      const a = this["re"];
      const b = this["im"];
      return new Complex(
        Math.sin(a) * cosh2(b),
        Math.cos(a) * sinh2(b)
      );
    },
    /**
     * Calculate the cosine
     *
     * @returns {Complex}
     */
    "cos": function() {
      const a = this["re"];
      const b = this["im"];
      return new Complex(
        Math.cos(a) * cosh2(b),
        -Math.sin(a) * sinh2(b)
      );
    },
    /**
     * Calculate the tangent
     *
     * @returns {Complex}
     */
    "tan": function() {
      const a = 2 * this["re"];
      const b = 2 * this["im"];
      const d = Math.cos(a) + cosh2(b);
      return new Complex(
        Math.sin(a) / d,
        sinh2(b) / d
      );
    },
    /**
     * Calculate the cotangent
     *
     * @returns {Complex}
     */
    "cot": function() {
      const a = 2 * this["re"];
      const b = 2 * this["im"];
      const d = Math.cos(a) - cosh2(b);
      return new Complex(
        -Math.sin(a) / d,
        sinh2(b) / d
      );
    },
    /**
     * Calculate the secant
     *
     * @returns {Complex}
     */
    "sec": function() {
      const a = this["re"];
      const b = this["im"];
      const d = 0.5 * cosh2(2 * b) + 0.5 * Math.cos(2 * a);
      return new Complex(
        Math.cos(a) * cosh2(b) / d,
        Math.sin(a) * sinh2(b) / d
      );
    },
    /**
     * Calculate the cosecans
     *
     * @returns {Complex}
     */
    "csc": function() {
      const a = this["re"];
      const b = this["im"];
      const d = 0.5 * cosh2(2 * b) - 0.5 * Math.cos(2 * a);
      return new Complex(
        Math.sin(a) * cosh2(b) / d,
        -Math.cos(a) * sinh2(b) / d
      );
    },
    /**
     * Calculate the complex arcus sinus
     *
     * @returns {Complex}
     */
    "asin": function() {
      const a = this["re"];
      const b = this["im"];
      const t1 = new Complex(
        b * b - a * a + 1,
        -2 * a * b
      )["sqrt"]();
      const t2 = new Complex(
        t1["re"] - b,
        t1["im"] + a
      )["log"]();
      return new Complex(t2["im"], -t2["re"]);
    },
    /**
     * Calculate the complex arcus cosinus
     *
     * @returns {Complex}
     */
    "acos": function() {
      const a = this["re"];
      const b = this["im"];
      const t1 = new Complex(
        b * b - a * a + 1,
        -2 * a * b
      )["sqrt"]();
      const t2 = new Complex(
        t1["re"] - b,
        t1["im"] + a
      )["log"]();
      return new Complex(Math.PI / 2 - t2["im"], t2["re"]);
    },
    /**
     * Calculate the complex arcus tangent
     *
     * @returns {Complex}
     */
    "atan": function() {
      const a = this["re"];
      const b = this["im"];
      if (a === 0) {
        if (b === 1) {
          return new Complex(0, Infinity);
        }
        if (b === -1) {
          return new Complex(0, -Infinity);
        }
      }
      const d = a * a + (1 - b) * (1 - b);
      const t1 = new Complex(
        (1 - b * b - a * a) / d,
        -2 * a / d
      ).log();
      return new Complex(-0.5 * t1["im"], 0.5 * t1["re"]);
    },
    /**
     * Calculate the complex arcus cotangent
     *
     * @returns {Complex}
     */
    "acot": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        return new Complex(Math.atan2(1, a), 0);
      }
      const d = a * a + b * b;
      return d !== 0 ? new Complex(
        a / d,
        -b / d
      ).atan() : new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      ).atan();
    },
    /**
     * Calculate the complex arcus secant
     *
     * @returns {Complex}
     */
    "asec": function() {
      const a = this["re"];
      const b = this["im"];
      if (a === 0 && b === 0) {
        return new Complex(0, Infinity);
      }
      const d = a * a + b * b;
      return d !== 0 ? new Complex(
        a / d,
        -b / d
      ).acos() : new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      ).acos();
    },
    /**
     * Calculate the complex arcus cosecans
     *
     * @returns {Complex}
     */
    "acsc": function() {
      const a = this["re"];
      const b = this["im"];
      if (a === 0 && b === 0) {
        return new Complex(Math.PI / 2, Infinity);
      }
      const d = a * a + b * b;
      return d !== 0 ? new Complex(
        a / d,
        -b / d
      ).asin() : new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      ).asin();
    },
    /**
     * Calculate the complex sinh
     *
     * @returns {Complex}
     */
    "sinh": function() {
      const a = this["re"];
      const b = this["im"];
      return new Complex(
        sinh2(a) * Math.cos(b),
        cosh2(a) * Math.sin(b)
      );
    },
    /**
     * Calculate the complex cosh
     *
     * @returns {Complex}
     */
    "cosh": function() {
      const a = this["re"];
      const b = this["im"];
      return new Complex(
        cosh2(a) * Math.cos(b),
        sinh2(a) * Math.sin(b)
      );
    },
    /**
     * Calculate the complex tanh
     *
     * @returns {Complex}
     */
    "tanh": function() {
      const a = 2 * this["re"];
      const b = 2 * this["im"];
      const d = cosh2(a) + Math.cos(b);
      return new Complex(
        sinh2(a) / d,
        Math.sin(b) / d
      );
    },
    /**
     * Calculate the complex coth
     *
     * @returns {Complex}
     */
    "coth": function() {
      const a = 2 * this["re"];
      const b = 2 * this["im"];
      const d = cosh2(a) - Math.cos(b);
      return new Complex(
        sinh2(a) / d,
        -Math.sin(b) / d
      );
    },
    /**
     * Calculate the complex csch
     *
     * @returns {Complex}
     */
    "csch": function() {
      const a = this["re"];
      const b = this["im"];
      const d = Math.cos(2 * b) - cosh2(2 * a);
      return new Complex(
        -2 * sinh2(a) * Math.cos(b) / d,
        2 * cosh2(a) * Math.sin(b) / d
      );
    },
    /**
     * Calculate the complex sech
     *
     * @returns {Complex}
     */
    "sech": function() {
      const a = this["re"];
      const b = this["im"];
      const d = Math.cos(2 * b) + cosh2(2 * a);
      return new Complex(
        2 * cosh2(a) * Math.cos(b) / d,
        -2 * sinh2(a) * Math.sin(b) / d
      );
    },
    /**
     * Calculate the complex asinh
     *
     * @returns {Complex}
     */
    "asinh": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        if (a === 0) {
          return new Complex(0, 0);
        }
        const x = Math.abs(a);
        const r = Math.log(x + Math.sqrt(x * x + 1));
        return new Complex(a < 0 ? -r : r, 0);
      }
      const re2 = a * a - b * b + 1;
      const im2 = 2 * a * b;
      const t = new Complex(re2, im2)["sqrt"]();
      return new Complex(a + t["re"], b + t["im"])["log"]();
    },
    /**
     * Calculate the complex acosh
     *
     * @returns {Complex}
     */
    "acosh": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        if (a > 1) {
          return new Complex(
            Math.log(a + Math.sqrt(a - 1) * Math.sqrt(a + 1)),
            0
          );
        }
        if (a < -1) {
          const t = Math.sqrt(a * a - 1);
          return new Complex(Math.log(-a + t), Math.PI);
        }
        return new Complex(0, Math.acos(a));
      }
      const t1 = new Complex(a - 1, b)["sqrt"]();
      const t2 = new Complex(a + 1, b)["sqrt"]();
      return new Complex(
        a + t1["re"] * t2["re"] - t1["im"] * t2["im"],
        b + t1["re"] * t2["im"] + t1["im"] * t2["re"]
      )["log"]();
    },
    /**
     * Calculate the complex atanh
     *
     * @returns {Complex}
     */
    "atanh": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        if (a === 0) {
          return new Complex(0, 0);
        }
        if (a === 1) {
          return new Complex(Infinity, 0);
        }
        if (a === -1) {
          return new Complex(-Infinity, 0);
        }
        if (-1 < a && a < 1) {
          return new Complex(
            0.5 * Math.log((1 + a) / (1 - a)),
            0
          );
        }
        if (a > 1) {
          const t2 = (a + 1) / (a - 1);
          return new Complex(
            0.5 * Math.log(t2),
            -Math.PI / 2
          );
        }
        const t = (1 + a) / (1 - a);
        return new Complex(
          0.5 * Math.log(-t),
          // log((1 - a)/(1 + a))
          Math.PI / 2
        );
      }
      const oneMinus = 1 - a;
      const onePlus = 1 + a;
      const d = oneMinus * oneMinus + b * b;
      if (d === 0) {
        return new Complex(
          a !== -1 ? a / 0 : 0,
          b !== 0 ? b / 0 : 0
        );
      }
      const xr = (onePlus * oneMinus - b * b) / d;
      const xi = (b * oneMinus + onePlus * b) / d;
      return new Complex(
        logHypot(xr, xi) / 2,
        Math.atan2(xi, xr) / 2
      );
    },
    /**
     * Calculate the complex acoth
     *
     * @returns {Complex}
     */
    "acoth": function() {
      const a = this["re"];
      const b = this["im"];
      if (a === 0 && b === 0) {
        return new Complex(0, Math.PI / 2);
      }
      const d = a * a + b * b;
      if (d !== 0) {
        return new Complex(a / d, -b / d)["atanh"]();
      }
      return new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      )["atanh"]();
    },
    /**
     * Calculate the complex acsch
     *
     * @returns {Complex}
     */
    "acsch": function() {
      const a = this["re"];
      const b = this["im"];
      if (b === 0) {
        if (a === 0) {
          return new Complex(Infinity, 0);
        }
        const inv2 = 1 / a;
        return new Complex(
          Math.log(inv2 + Math.sqrt(inv2 * inv2 + 1)),
          0
        );
      }
      const d = a * a + b * b;
      if (d !== 0) {
        return new Complex(a / d, -b / d)["asinh"]();
      }
      return new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      )["asinh"]();
    },
    /**
     * Calculate the complex asech
     *
     * @returns {Complex}
     */
    "asech": function() {
      const a = this["re"];
      const b = this["im"];
      if (this["isZero"]()) {
        return Complex["INFINITY"];
      }
      const d = a * a + b * b;
      if (d !== 0) {
        return new Complex(a / d, -b / d)["acosh"]();
      }
      return new Complex(
        a !== 0 ? a / 0 : 0,
        b !== 0 ? -b / 0 : 0
      )["acosh"]();
    },
    /**
     * Calculate the complex inverse 1/z
     *
     * @returns {Complex}
     */
    "inverse": function() {
      if (this["isZero"]()) {
        return Complex["INFINITY"];
      }
      if (this["isInfinite"]()) {
        return Complex["ZERO"];
      }
      const a = this["re"];
      const b = this["im"];
      const d = a * a + b * b;
      return new Complex(a / d, -b / d);
    },
    /**
     * Returns the complex conjugate
     *
     * @returns {Complex}
     */
    "conjugate": function() {
      return new Complex(this["re"], -this["im"]);
    },
    /**
     * Gets the negated complex number
     *
     * @returns {Complex}
     */
    "neg": function() {
      return new Complex(-this["re"], -this["im"]);
    },
    /**
     * Ceils the actual complex number
     *
     * @returns {Complex}
     */
    "ceil": function(places) {
      places = Math.pow(10, places || 0);
      return new Complex(
        Math.ceil(this["re"] * places) / places,
        Math.ceil(this["im"] * places) / places
      );
    },
    /**
     * Floors the actual complex number
     *
     * @returns {Complex}
     */
    "floor": function(places) {
      places = Math.pow(10, places || 0);
      return new Complex(
        Math.floor(this["re"] * places) / places,
        Math.floor(this["im"] * places) / places
      );
    },
    /**
     * Ceils the actual complex number
     *
     * @returns {Complex}
     */
    "round": function(places) {
      places = Math.pow(10, places || 0);
      return new Complex(
        Math.round(this["re"] * places) / places,
        Math.round(this["im"] * places) / places
      );
    },
    /**
     * Compares two complex numbers
     *
     * **Note:** new Complex(Infinity).equals(Infinity) === false
     *
     * @returns {boolean}
     */
    "equals": function(a, b) {
      const z = parse(a, b);
      return Math.abs(z["re"] - this["re"]) <= Complex["EPSILON"] && Math.abs(z["im"] - this["im"]) <= Complex["EPSILON"];
    },
    /**
     * Clones the actual object
     *
     * @returns {Complex}
     */
    "clone": function() {
      return new Complex(this["re"], this["im"]);
    },
    /**
     * Gets a string of the actual complex number
     *
     * @returns {string}
     */
    "toString": function() {
      let a = this["re"];
      let b = this["im"];
      let ret = "";
      if (this["isNaN"]()) {
        return "NaN";
      }
      if (this["isInfinite"]()) {
        return "Infinity";
      }
      if (Math.abs(a) < Complex["EPSILON"]) {
        a = 0;
      }
      if (Math.abs(b) < Complex["EPSILON"]) {
        b = 0;
      }
      if (b === 0) {
        return ret + a;
      }
      if (a !== 0) {
        ret += a;
        ret += " ";
        if (b < 0) {
          b = -b;
          ret += "-";
        } else {
          ret += "+";
        }
        ret += " ";
      } else if (b < 0) {
        b = -b;
        ret += "-";
      }
      if (1 !== b) {
        ret += b;
      }
      return ret + "i";
    },
    /**
     * Returns the actual number as a vector
     *
     * @returns {Array}
     */
    "toVector": function() {
      return [this["re"], this["im"]];
    },
    /**
     * Returns the actual real value of the current object
     *
     * @returns {number|null}
     */
    "valueOf": function() {
      if (this["im"] === 0) {
        return this["re"];
      }
      return null;
    },
    /**
     * Determines whether a complex number is not on the Riemann sphere.
     *
     * @returns {boolean}
     */
    "isNaN": function() {
      return isNaN(this["re"]) || isNaN(this["im"]);
    },
    /**
     * Determines whether or not a complex number is at the zero pole of the
     * Riemann sphere.
     *
     * @returns {boolean}
     */
    "isZero": function() {
      return this["im"] === 0 && this["re"] === 0;
    },
    /**
     * Determines whether a complex number is not at the infinity pole of the
     * Riemann sphere.
     *
     * @returns {boolean}
     */
    "isFinite": function() {
      return isFinite(this["re"]) && isFinite(this["im"]);
    },
    /**
     * Determines whether or not a complex number is at the infinity pole of the
     * Riemann sphere.
     *
     * @returns {boolean}
     */
    "isInfinite": function() {
      return !this["isFinite"]();
    }
  };
  Complex["ZERO"] = new Complex(0, 0);
  Complex["ONE"] = new Complex(1, 0);
  Complex["I"] = new Complex(0, 1);
  Complex["PI"] = new Complex(Math.PI, 0);
  Complex["E"] = new Complex(Math.E, 0);
  Complex["INFINITY"] = new Complex(Infinity, Infinity);
  Complex["NAN"] = new Complex(NaN, NaN);
  Complex["EPSILON"] = 1e-15;

  // node_modules/mathjs/lib/esm/type/complex/Complex.js
  var name2 = "Complex";
  var dependencies3 = [];
  var createComplexClass = /* @__PURE__ */ factory(name2, dependencies3, () => {
    Complex.prototype.type = "Complex";
    Complex.prototype.isComplex = true;
    Complex.prototype.toJSON = function() {
      return {
        mathjs: "Complex",
        re: this.re,
        im: this.im
      };
    };
    Complex.prototype.toPolar = function() {
      return {
        r: this.abs(),
        phi: this.arg()
      };
    };
    Complex.prototype.format = function(options) {
      var str = "";
      var im2 = this.im;
      var re2 = this.re;
      var strRe = format(this.re, options);
      var strIm = format(this.im, options);
      var precision = isNumber(options) ? options : options ? options.precision : null;
      if (precision !== null) {
        var epsilon = Math.pow(10, -precision);
        if (Math.abs(re2 / im2) < epsilon) {
          re2 = 0;
        }
        if (Math.abs(im2 / re2) < epsilon) {
          im2 = 0;
        }
      }
      if (im2 === 0) {
        str = strRe;
      } else if (re2 === 0) {
        if (im2 === 1) {
          str = "i";
        } else if (im2 === -1) {
          str = "-i";
        } else {
          str = strIm + "i";
        }
      } else {
        if (im2 < 0) {
          if (im2 === -1) {
            str = strRe + " - i";
          } else {
            str = strRe + " - " + strIm.substring(1) + "i";
          }
        } else {
          if (im2 === 1) {
            str = strRe + " + i";
          } else {
            str = strRe + " + " + strIm + "i";
          }
        }
      }
      return str;
    };
    Complex.fromPolar = function(args) {
      switch (arguments.length) {
        case 1: {
          var arg = arguments[0];
          if (typeof arg === "object") {
            return Complex(arg);
          } else {
            throw new TypeError("Input has to be an object with r and phi keys.");
          }
        }
        case 2: {
          var r = arguments[0];
          var phi = arguments[1];
          if (isNumber(r)) {
            if (isUnit(phi) && phi.hasBase("ANGLE")) {
              phi = phi.toNumber("rad");
            }
            if (isNumber(phi)) {
              return new Complex({
                r,
                phi
              });
            }
            throw new TypeError("Phi is not a number nor an angle unit.");
          } else {
            throw new TypeError("Radius r is not a number.");
          }
        }
        default:
          throw new SyntaxError("Wrong number of arguments in function fromPolar");
      }
    };
    Complex.prototype.valueOf = Complex.prototype.toString;
    Complex.fromJSON = function(json) {
      return new Complex(json);
    };
    Complex.compare = function(a, b) {
      if (a.re > b.re) {
        return 1;
      }
      if (a.re < b.re) {
        return -1;
      }
      if (a.im > b.im) {
        return 1;
      }
      if (a.im < b.im) {
        return -1;
      }
      return 0;
    };
    return Complex;
  }, {
    isClass: true
  });

  // node_modules/fraction.js/fraction.js
  var MAX_CYCLE_LEN = 2e3;
  var P3 = {
    "s": 1,
    "n": 0,
    "d": 1
  };
  function assign(n, s) {
    if (isNaN(n = parseInt(n, 10))) {
      throw InvalidParameter();
    }
    return n * s;
  }
  function newFraction(n, d) {
    if (d === 0) {
      throw DivisionByZero();
    }
    var f = Object.create(Fraction.prototype);
    f["s"] = n < 0 ? -1 : 1;
    n = n < 0 ? -n : n;
    var a = gcd(n, d);
    f["n"] = n / a;
    f["d"] = d / a;
    return f;
  }
  function factorize(num) {
    var factors = {};
    var n = num;
    var i = 2;
    var s = 4;
    while (s <= n) {
      while (n % i === 0) {
        n /= i;
        factors[i] = (factors[i] || 0) + 1;
      }
      s += 1 + 2 * i++;
    }
    if (n !== num) {
      if (n > 1)
        factors[n] = (factors[n] || 0) + 1;
    } else {
      factors[num] = (factors[num] || 0) + 1;
    }
    return factors;
  }
  var parse2 = function(p1, p2) {
    var n = 0, d = 1, s = 1;
    var v = 0, w = 0, x = 0, y = 1, z = 1;
    var A = 0, B = 1;
    var C = 1, D = 1;
    var N = 1e7;
    var M;
    if (p1 === void 0 || p1 === null) {
    } else if (p2 !== void 0) {
      n = p1;
      d = p2;
      s = n * d;
      if (n % 1 !== 0 || d % 1 !== 0) {
        throw NonIntegerParameter();
      }
    } else
      switch (typeof p1) {
        case "object": {
          if ("d" in p1 && "n" in p1) {
            n = p1["n"];
            d = p1["d"];
            if ("s" in p1)
              n *= p1["s"];
          } else if (0 in p1) {
            n = p1[0];
            if (1 in p1)
              d = p1[1];
          } else {
            throw InvalidParameter();
          }
          s = n * d;
          break;
        }
        case "number": {
          if (p1 < 0) {
            s = p1;
            p1 = -p1;
          }
          if (p1 % 1 === 0) {
            n = p1;
          } else if (p1 > 0) {
            if (p1 >= 1) {
              z = Math.pow(10, Math.floor(1 + Math.log(p1) / Math.LN10));
              p1 /= z;
            }
            while (B <= N && D <= N) {
              M = (A + C) / (B + D);
              if (p1 === M) {
                if (B + D <= N) {
                  n = A + C;
                  d = B + D;
                } else if (D > B) {
                  n = C;
                  d = D;
                } else {
                  n = A;
                  d = B;
                }
                break;
              } else {
                if (p1 > M) {
                  A += C;
                  B += D;
                } else {
                  C += A;
                  D += B;
                }
                if (B > N) {
                  n = C;
                  d = D;
                } else {
                  n = A;
                  d = B;
                }
              }
            }
            n *= z;
          } else if (isNaN(p1) || isNaN(p2)) {
            d = n = NaN;
          }
          break;
        }
        case "string": {
          B = p1.match(/\d+|./g);
          if (B === null)
            throw InvalidParameter();
          if (B[A] === "-") {
            s = -1;
            A++;
          } else if (B[A] === "+") {
            A++;
          }
          if (B.length === A + 1) {
            w = assign(B[A++], s);
          } else if (B[A + 1] === "." || B[A] === ".") {
            if (B[A] !== ".") {
              v = assign(B[A++], s);
            }
            A++;
            if (A + 1 === B.length || B[A + 1] === "(" && B[A + 3] === ")" || B[A + 1] === "'" && B[A + 3] === "'") {
              w = assign(B[A], s);
              y = Math.pow(10, B[A].length);
              A++;
            }
            if (B[A] === "(" && B[A + 2] === ")" || B[A] === "'" && B[A + 2] === "'") {
              x = assign(B[A + 1], s);
              z = Math.pow(10, B[A + 1].length) - 1;
              A += 3;
            }
          } else if (B[A + 1] === "/" || B[A + 1] === ":") {
            w = assign(B[A], s);
            y = assign(B[A + 2], 1);
            A += 3;
          } else if (B[A + 3] === "/" && B[A + 1] === " ") {
            v = assign(B[A], s);
            w = assign(B[A + 2], s);
            y = assign(B[A + 4], 1);
            A += 5;
          }
          if (B.length <= A) {
            d = y * z;
            s = /* void */
            n = x + d * v + z * w;
            break;
          }
        }
        default:
          throw InvalidParameter();
      }
    if (d === 0) {
      throw DivisionByZero();
    }
    P3["s"] = s < 0 ? -1 : 1;
    P3["n"] = Math.abs(n);
    P3["d"] = Math.abs(d);
  };
  function modpow(b, e, m) {
    var r = 1;
    for (; e > 0; b = b * b % m, e >>= 1) {
      if (e & 1) {
        r = r * b % m;
      }
    }
    return r;
  }
  function cycleLen(n, d) {
    for (; d % 2 === 0; d /= 2) {
    }
    for (; d % 5 === 0; d /= 5) {
    }
    if (d === 1)
      return 0;
    var rem = 10 % d;
    var t = 1;
    for (; rem !== 1; t++) {
      rem = rem * 10 % d;
      if (t > MAX_CYCLE_LEN)
        return 0;
    }
    return t;
  }
  function cycleStart(n, d, len) {
    var rem1 = 1;
    var rem2 = modpow(10, len, d);
    for (var t = 0; t < 300; t++) {
      if (rem1 === rem2)
        return t;
      rem1 = rem1 * 10 % d;
      rem2 = rem2 * 10 % d;
    }
    return 0;
  }
  function gcd(a, b) {
    if (!a)
      return b;
    if (!b)
      return a;
    while (1) {
      a %= b;
      if (!a)
        return b;
      b %= a;
      if (!b)
        return a;
    }
  }
  function Fraction(a, b) {
    parse2(a, b);
    if (this instanceof Fraction) {
      a = gcd(P3["d"], P3["n"]);
      this["s"] = P3["s"];
      this["n"] = P3["n"] / a;
      this["d"] = P3["d"] / a;
    } else {
      return newFraction(P3["s"] * P3["n"], P3["d"]);
    }
  }
  var DivisionByZero = function() {
    return new Error("Division by Zero");
  };
  var InvalidParameter = function() {
    return new Error("Invalid argument");
  };
  var NonIntegerParameter = function() {
    return new Error("Parameters must be integer");
  };
  Fraction.prototype = {
    "s": 1,
    "n": 0,
    "d": 1,
    /**
     * Calculates the absolute value
     *
     * Ex: new Fraction(-4).abs() => 4
     **/
    "abs": function() {
      return newFraction(this["n"], this["d"]);
    },
    /**
     * Inverts the sign of the current fraction
     *
     * Ex: new Fraction(-4).neg() => 4
     **/
    "neg": function() {
      return newFraction(-this["s"] * this["n"], this["d"]);
    },
    /**
     * Adds two rational numbers
     *
     * Ex: new Fraction({n: 2, d: 3}).add("14.9") => 467 / 30
     **/
    "add": function(a, b) {
      parse2(a, b);
      return newFraction(
        this["s"] * this["n"] * P3["d"] + P3["s"] * this["d"] * P3["n"],
        this["d"] * P3["d"]
      );
    },
    /**
     * Subtracts two rational numbers
     *
     * Ex: new Fraction({n: 2, d: 3}).add("14.9") => -427 / 30
     **/
    "sub": function(a, b) {
      parse2(a, b);
      return newFraction(
        this["s"] * this["n"] * P3["d"] - P3["s"] * this["d"] * P3["n"],
        this["d"] * P3["d"]
      );
    },
    /**
     * Multiplies two rational numbers
     *
     * Ex: new Fraction("-17.(345)").mul(3) => 5776 / 111
     **/
    "mul": function(a, b) {
      parse2(a, b);
      return newFraction(
        this["s"] * P3["s"] * this["n"] * P3["n"],
        this["d"] * P3["d"]
      );
    },
    /**
     * Divides two rational numbers
     *
     * Ex: new Fraction("-17.(345)").inverse().div(3)
     **/
    "div": function(a, b) {
      parse2(a, b);
      return newFraction(
        this["s"] * P3["s"] * this["n"] * P3["d"],
        this["d"] * P3["n"]
      );
    },
    /**
     * Clones the actual object
     *
     * Ex: new Fraction("-17.(345)").clone()
     **/
    "clone": function() {
      return newFraction(this["s"] * this["n"], this["d"]);
    },
    /**
     * Calculates the modulo of two rational numbers - a more precise fmod
     *
     * Ex: new Fraction('4.(3)').mod([7, 8]) => (13/3) % (7/8) = (5/6)
     **/
    "mod": function(a, b) {
      if (isNaN(this["n"]) || isNaN(this["d"])) {
        return new Fraction(NaN);
      }
      if (a === void 0) {
        return newFraction(this["s"] * this["n"] % this["d"], 1);
      }
      parse2(a, b);
      if (0 === P3["n"] && 0 === this["d"]) {
        throw DivisionByZero();
      }
      return newFraction(
        this["s"] * (P3["d"] * this["n"]) % (P3["n"] * this["d"]),
        P3["d"] * this["d"]
      );
    },
    /**
     * Calculates the fractional gcd of two rational numbers
     *
     * Ex: new Fraction(5,8).gcd(3,7) => 1/56
     */
    "gcd": function(a, b) {
      parse2(a, b);
      return newFraction(gcd(P3["n"], this["n"]) * gcd(P3["d"], this["d"]), P3["d"] * this["d"]);
    },
    /**
     * Calculates the fractional lcm of two rational numbers
     *
     * Ex: new Fraction(5,8).lcm(3,7) => 15
     */
    "lcm": function(a, b) {
      parse2(a, b);
      if (P3["n"] === 0 && this["n"] === 0) {
        return newFraction(0, 1);
      }
      return newFraction(P3["n"] * this["n"], gcd(P3["n"], this["n"]) * gcd(P3["d"], this["d"]));
    },
    /**
     * Calculates the ceil of a rational number
     *
     * Ex: new Fraction('4.(3)').ceil() => (5 / 1)
     **/
    "ceil": function(places) {
      places = Math.pow(10, places || 0);
      if (isNaN(this["n"]) || isNaN(this["d"])) {
        return new Fraction(NaN);
      }
      return newFraction(Math.ceil(places * this["s"] * this["n"] / this["d"]), places);
    },
    /**
     * Calculates the floor of a rational number
     *
     * Ex: new Fraction('4.(3)').floor() => (4 / 1)
     **/
    "floor": function(places) {
      places = Math.pow(10, places || 0);
      if (isNaN(this["n"]) || isNaN(this["d"])) {
        return new Fraction(NaN);
      }
      return newFraction(Math.floor(places * this["s"] * this["n"] / this["d"]), places);
    },
    /**
     * Rounds a rational number
     *
     * Ex: new Fraction('4.(3)').round() => (4 / 1)
     **/
    "round": function(places) {
      places = Math.pow(10, places || 0);
      if (isNaN(this["n"]) || isNaN(this["d"])) {
        return new Fraction(NaN);
      }
      return newFraction(Math.round(places * this["s"] * this["n"] / this["d"]), places);
    },
    /**
     * Rounds a rational number to a multiple of another rational number
     *
     * Ex: new Fraction('0.9').roundTo("1/8") => 7 / 8
     **/
    "roundTo": function(a, b) {
      parse2(a, b);
      return newFraction(this["s"] * Math.round(this["n"] * P3["d"] / (this["d"] * P3["n"])) * P3["n"], P3["d"]);
    },
    /**
     * Gets the inverse of the fraction, means numerator and denominator are exchanged
     *
     * Ex: new Fraction([-3, 4]).inverse() => -4 / 3
     **/
    "inverse": function() {
      return newFraction(this["s"] * this["d"], this["n"]);
    },
    /**
     * Calculates the fraction to some rational exponent, if possible
     *
     * Ex: new Fraction(-1,2).pow(-3) => -8
     */
    "pow": function(a, b) {
      parse2(a, b);
      if (P3["d"] === 1) {
        if (P3["s"] < 0) {
          return newFraction(Math.pow(this["s"] * this["d"], P3["n"]), Math.pow(this["n"], P3["n"]));
        } else {
          return newFraction(Math.pow(this["s"] * this["n"], P3["n"]), Math.pow(this["d"], P3["n"]));
        }
      }
      if (this["s"] < 0) return null;
      var N = factorize(this["n"]);
      var D = factorize(this["d"]);
      var n = 1;
      var d = 1;
      for (var k in N) {
        if (k === "1") continue;
        if (k === "0") {
          n = 0;
          break;
        }
        N[k] *= P3["n"];
        if (N[k] % P3["d"] === 0) {
          N[k] /= P3["d"];
        } else return null;
        n *= Math.pow(k, N[k]);
      }
      for (var k in D) {
        if (k === "1") continue;
        D[k] *= P3["n"];
        if (D[k] % P3["d"] === 0) {
          D[k] /= P3["d"];
        } else return null;
        d *= Math.pow(k, D[k]);
      }
      if (P3["s"] < 0) {
        return newFraction(d, n);
      }
      return newFraction(n, d);
    },
    /**
     * Check if two rational numbers are the same
     *
     * Ex: new Fraction(19.6).equals([98, 5]);
     **/
    "equals": function(a, b) {
      parse2(a, b);
      return this["s"] * this["n"] * P3["d"] === P3["s"] * P3["n"] * this["d"];
    },
    /**
     * Check if two rational numbers are the same
     *
     * Ex: new Fraction(19.6).equals([98, 5]);
     **/
    "compare": function(a, b) {
      parse2(a, b);
      var t = this["s"] * this["n"] * P3["d"] - P3["s"] * P3["n"] * this["d"];
      return (0 < t) - (t < 0);
    },
    "simplify": function(eps) {
      if (isNaN(this["n"]) || isNaN(this["d"])) {
        return this;
      }
      eps = eps || 1e-3;
      var thisABS = this["abs"]();
      var cont = thisABS["toContinued"]();
      for (var i = 1; i < cont.length; i++) {
        var s = newFraction(cont[i - 1], 1);
        for (var k = i - 2; k >= 0; k--) {
          s = s["inverse"]()["add"](cont[k]);
        }
        if (Math.abs(s["sub"](thisABS).valueOf()) < eps) {
          return s["mul"](this["s"]);
        }
      }
      return this;
    },
    /**
     * Check if two rational numbers are divisible
     *
     * Ex: new Fraction(19.6).divisible(1.5);
     */
    "divisible": function(a, b) {
      parse2(a, b);
      return !(!(P3["n"] * this["d"]) || this["n"] * P3["d"] % (P3["n"] * this["d"]));
    },
    /**
     * Returns a decimal representation of the fraction
     *
     * Ex: new Fraction("100.'91823'").valueOf() => 100.91823918239183
     **/
    "valueOf": function() {
      return this["s"] * this["n"] / this["d"];
    },
    /**
     * Returns a string-fraction representation of a Fraction object
     *
     * Ex: new Fraction("1.'3'").toFraction(true) => "4 1/3"
     **/
    "toFraction": function(excludeWhole) {
      var whole, str = "";
      var n = this["n"];
      var d = this["d"];
      if (this["s"] < 0) {
        str += "-";
      }
      if (d === 1) {
        str += n;
      } else {
        if (excludeWhole && (whole = Math.floor(n / d)) > 0) {
          str += whole;
          str += " ";
          n %= d;
        }
        str += n;
        str += "/";
        str += d;
      }
      return str;
    },
    /**
     * Returns a latex representation of a Fraction object
     *
     * Ex: new Fraction("1.'3'").toLatex() => "\frac{4}{3}"
     **/
    "toLatex": function(excludeWhole) {
      var whole, str = "";
      var n = this["n"];
      var d = this["d"];
      if (this["s"] < 0) {
        str += "-";
      }
      if (d === 1) {
        str += n;
      } else {
        if (excludeWhole && (whole = Math.floor(n / d)) > 0) {
          str += whole;
          n %= d;
        }
        str += "\\frac{";
        str += n;
        str += "}{";
        str += d;
        str += "}";
      }
      return str;
    },
    /**
     * Returns an array of continued fraction elements
     *
     * Ex: new Fraction("7/8").toContinued() => [0,1,7]
     */
    "toContinued": function() {
      var t;
      var a = this["n"];
      var b = this["d"];
      var res = [];
      if (isNaN(a) || isNaN(b)) {
        return res;
      }
      do {
        res.push(Math.floor(a / b));
        t = a % b;
        a = b;
        b = t;
      } while (a !== 1);
      return res;
    },
    /**
     * Creates a string representation of a fraction with all digits
     *
     * Ex: new Fraction("100.'91823'").toString() => "100.(91823)"
     **/
    "toString": function(dec) {
      var N = this["n"];
      var D = this["d"];
      if (isNaN(N) || isNaN(D)) {
        return "NaN";
      }
      dec = dec || 15;
      var cycLen = cycleLen(N, D);
      var cycOff = cycleStart(N, D, cycLen);
      var str = this["s"] < 0 ? "-" : "";
      str += N / D | 0;
      N %= D;
      N *= 10;
      if (N)
        str += ".";
      if (cycLen) {
        for (var i = cycOff; i--; ) {
          str += N / D | 0;
          N %= D;
          N *= 10;
        }
        str += "(";
        for (var i = cycLen; i--; ) {
          str += N / D | 0;
          N %= D;
          N *= 10;
        }
        str += ")";
      } else {
        for (var i = dec; N && i--; ) {
          str += N / D | 0;
          N %= D;
          N *= 10;
        }
      }
      return str;
    }
  };

  // node_modules/mathjs/lib/esm/type/fraction/Fraction.js
  var name3 = "Fraction";
  var dependencies4 = [];
  var createFractionClass = /* @__PURE__ */ factory(name3, dependencies4, () => {
    Fraction.prototype.type = "Fraction";
    Fraction.prototype.isFraction = true;
    Fraction.prototype.toJSON = function() {
      return {
        mathjs: "Fraction",
        n: this.s * this.n,
        d: this.d
      };
    };
    Fraction.fromJSON = function(json) {
      return new Fraction(json);
    };
    return Fraction;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/matrix/Matrix.js
  var name4 = "Matrix";
  var dependencies5 = [];
  var createMatrixClass = /* @__PURE__ */ factory(name4, dependencies5, () => {
    function Matrix2() {
      if (!(this instanceof Matrix2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
    }
    Matrix2.prototype.type = "Matrix";
    Matrix2.prototype.isMatrix = true;
    Matrix2.prototype.storage = function() {
      throw new Error("Cannot invoke storage on a Matrix interface");
    };
    Matrix2.prototype.datatype = function() {
      throw new Error("Cannot invoke datatype on a Matrix interface");
    };
    Matrix2.prototype.create = function(data, datatype) {
      throw new Error("Cannot invoke create on a Matrix interface");
    };
    Matrix2.prototype.subset = function(index2, replacement, defaultValue) {
      throw new Error("Cannot invoke subset on a Matrix interface");
    };
    Matrix2.prototype.get = function(index2) {
      throw new Error("Cannot invoke get on a Matrix interface");
    };
    Matrix2.prototype.set = function(index2, value, defaultValue) {
      throw new Error("Cannot invoke set on a Matrix interface");
    };
    Matrix2.prototype.resize = function(size2, defaultValue) {
      throw new Error("Cannot invoke resize on a Matrix interface");
    };
    Matrix2.prototype.reshape = function(size2, defaultValue) {
      throw new Error("Cannot invoke reshape on a Matrix interface");
    };
    Matrix2.prototype.clone = function() {
      throw new Error("Cannot invoke clone on a Matrix interface");
    };
    Matrix2.prototype.size = function() {
      throw new Error("Cannot invoke size on a Matrix interface");
    };
    Matrix2.prototype.map = function(callback, skipZeros) {
      throw new Error("Cannot invoke map on a Matrix interface");
    };
    Matrix2.prototype.forEach = function(callback) {
      throw new Error("Cannot invoke forEach on a Matrix interface");
    };
    Matrix2.prototype[Symbol.iterator] = function() {
      throw new Error("Cannot iterate a Matrix interface");
    };
    Matrix2.prototype.toArray = function() {
      throw new Error("Cannot invoke toArray on a Matrix interface");
    };
    Matrix2.prototype.valueOf = function() {
      throw new Error("Cannot invoke valueOf on a Matrix interface");
    };
    Matrix2.prototype.format = function(options) {
      throw new Error("Cannot invoke format on a Matrix interface");
    };
    Matrix2.prototype.toString = function() {
      throw new Error("Cannot invoke toString on a Matrix interface");
    };
    return Matrix2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/matrix/DenseMatrix.js
  var name5 = "DenseMatrix";
  var dependencies6 = ["Matrix"];
  var createDenseMatrixClass = /* @__PURE__ */ factory(name5, dependencies6, (_ref) => {
    var {
      Matrix: Matrix2
    } = _ref;
    function DenseMatrix2(data, datatype) {
      if (!(this instanceof DenseMatrix2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      if (datatype && !isString(datatype)) {
        throw new Error("Invalid datatype: " + datatype);
      }
      if (isMatrix(data)) {
        if (data.type === "DenseMatrix") {
          this._data = clone(data._data);
          this._size = clone(data._size);
          this._datatype = datatype || data._datatype;
        } else {
          this._data = data.toArray();
          this._size = data.size();
          this._datatype = datatype || data._datatype;
        }
      } else if (data && isArray(data.data) && isArray(data.size)) {
        this._data = data.data;
        this._size = data.size;
        validate(this._data, this._size);
        this._datatype = datatype || data.datatype;
      } else if (isArray(data)) {
        this._data = preprocess(data);
        this._size = arraySize(this._data);
        validate(this._data, this._size);
        this._datatype = datatype;
      } else if (data) {
        throw new TypeError("Unsupported type of data (" + typeOf(data) + ")");
      } else {
        this._data = [];
        this._size = [0];
        this._datatype = datatype;
      }
    }
    DenseMatrix2.prototype = new Matrix2();
    DenseMatrix2.prototype.createDenseMatrix = function(data, datatype) {
      return new DenseMatrix2(data, datatype);
    };
    DenseMatrix2.prototype.type = "DenseMatrix";
    DenseMatrix2.prototype.isDenseMatrix = true;
    DenseMatrix2.prototype.getDataType = function() {
      return getArrayDataType(this._data, typeOf);
    };
    DenseMatrix2.prototype.storage = function() {
      return "dense";
    };
    DenseMatrix2.prototype.datatype = function() {
      return this._datatype;
    };
    DenseMatrix2.prototype.create = function(data, datatype) {
      return new DenseMatrix2(data, datatype);
    };
    DenseMatrix2.prototype.subset = function(index2, replacement, defaultValue) {
      switch (arguments.length) {
        case 1:
          return _get(this, index2);
        // intentional fall through
        case 2:
        case 3:
          return _set(this, index2, replacement, defaultValue);
        default:
          throw new SyntaxError("Wrong number of arguments");
      }
    };
    DenseMatrix2.prototype.get = function(index2) {
      if (!isArray(index2)) {
        throw new TypeError("Array expected");
      }
      if (index2.length !== this._size.length) {
        throw new DimensionError(index2.length, this._size.length);
      }
      for (var x = 0; x < index2.length; x++) {
        validateIndex(index2[x], this._size[x]);
      }
      var data = this._data;
      for (var i = 0, ii = index2.length; i < ii; i++) {
        var indexI = index2[i];
        validateIndex(indexI, data.length);
        data = data[indexI];
      }
      return data;
    };
    DenseMatrix2.prototype.set = function(index2, value, defaultValue) {
      if (!isArray(index2)) {
        throw new TypeError("Array expected");
      }
      if (index2.length < this._size.length) {
        throw new DimensionError(index2.length, this._size.length, "<");
      }
      var i, ii, indexI;
      var size2 = index2.map(function(i2) {
        return i2 + 1;
      });
      _fit(this, size2, defaultValue);
      var data = this._data;
      for (i = 0, ii = index2.length - 1; i < ii; i++) {
        indexI = index2[i];
        validateIndex(indexI, data.length);
        data = data[indexI];
      }
      indexI = index2[index2.length - 1];
      validateIndex(indexI, data.length);
      data[indexI] = value;
      return this;
    };
    function _get(matrix2, index2) {
      if (!isIndex(index2)) {
        throw new TypeError("Invalid index");
      }
      var isScalar = index2.isScalar();
      if (isScalar) {
        return matrix2.get(index2.min());
      } else {
        var size2 = index2.size();
        if (size2.length !== matrix2._size.length) {
          throw new DimensionError(size2.length, matrix2._size.length);
        }
        var min2 = index2.min();
        var max2 = index2.max();
        for (var i = 0, ii = matrix2._size.length; i < ii; i++) {
          validateIndex(min2[i], matrix2._size[i]);
          validateIndex(max2[i], matrix2._size[i]);
        }
        return new DenseMatrix2(_getSubmatrix(matrix2._data, index2, size2.length, 0), matrix2._datatype);
      }
    }
    function _getSubmatrix(data, index2, dims, dim) {
      var last = dim === dims - 1;
      var range2 = index2.dimension(dim);
      if (last) {
        return range2.map(function(i) {
          validateIndex(i, data.length);
          return data[i];
        }).valueOf();
      } else {
        return range2.map(function(i) {
          validateIndex(i, data.length);
          var child = data[i];
          return _getSubmatrix(child, index2, dims, dim + 1);
        }).valueOf();
      }
    }
    function _set(matrix2, index2, submatrix, defaultValue) {
      if (!index2 || index2.isIndex !== true) {
        throw new TypeError("Invalid index");
      }
      var iSize = index2.size();
      var isScalar = index2.isScalar();
      var sSize;
      if (isMatrix(submatrix)) {
        sSize = submatrix.size();
        submatrix = submatrix.valueOf();
      } else {
        sSize = arraySize(submatrix);
      }
      if (isScalar) {
        if (sSize.length !== 0) {
          throw new TypeError("Scalar expected");
        }
        matrix2.set(index2.min(), submatrix, defaultValue);
      } else {
        if (iSize.length < matrix2._size.length) {
          throw new DimensionError(iSize.length, matrix2._size.length, "<");
        }
        if (sSize.length < iSize.length) {
          var i = 0;
          var outer = 0;
          while (iSize[i] === 1 && sSize[i] === 1) {
            i++;
          }
          while (iSize[i] === 1) {
            outer++;
            i++;
          }
          submatrix = unsqueeze(submatrix, iSize.length, outer, sSize);
        }
        if (!deepStrictEqual(iSize, sSize)) {
          throw new DimensionError(iSize, sSize, ">");
        }
        var size2 = index2.max().map(function(i2) {
          return i2 + 1;
        });
        _fit(matrix2, size2, defaultValue);
        var dims = iSize.length;
        var dim = 0;
        _setSubmatrix(matrix2._data, index2, submatrix, dims, dim);
      }
      return matrix2;
    }
    function _setSubmatrix(data, index2, submatrix, dims, dim) {
      var last = dim === dims - 1;
      var range2 = index2.dimension(dim);
      if (last) {
        range2.forEach(function(dataIndex, subIndex) {
          validateIndex(dataIndex);
          data[dataIndex] = submatrix[subIndex[0]];
        });
      } else {
        range2.forEach(function(dataIndex, subIndex) {
          validateIndex(dataIndex);
          _setSubmatrix(data[dataIndex], index2, submatrix[subIndex[0]], dims, dim + 1);
        });
      }
    }
    DenseMatrix2.prototype.resize = function(size2, defaultValue, copy) {
      if (!isCollection(size2)) {
        throw new TypeError("Array or Matrix expected");
      }
      var sizeArray = size2.valueOf().map((value) => {
        return Array.isArray(value) && value.length === 1 ? value[0] : value;
      });
      var m = copy ? this.clone() : this;
      return _resize2(m, sizeArray, defaultValue);
    };
    function _resize2(matrix2, size2, defaultValue) {
      if (size2.length === 0) {
        var v = matrix2._data;
        while (isArray(v)) {
          v = v[0];
        }
        return v;
      }
      matrix2._size = size2.slice(0);
      matrix2._data = resize(matrix2._data, matrix2._size, defaultValue);
      return matrix2;
    }
    DenseMatrix2.prototype.reshape = function(size2, copy) {
      var m = copy ? this.clone() : this;
      m._data = reshape(m._data, size2);
      var currentLength = m._size.reduce((length, size3) => length * size3);
      m._size = processSizesWildcard(size2, currentLength);
      return m;
    };
    function _fit(matrix2, size2, defaultValue) {
      var newSize = matrix2._size.slice(0);
      var changed = false;
      while (newSize.length < size2.length) {
        newSize.push(0);
        changed = true;
      }
      for (var i = 0, ii = size2.length; i < ii; i++) {
        if (size2[i] > newSize[i]) {
          newSize[i] = size2[i];
          changed = true;
        }
      }
      if (changed) {
        _resize2(matrix2, newSize, defaultValue);
      }
    }
    DenseMatrix2.prototype.clone = function() {
      var m = new DenseMatrix2({
        data: clone(this._data),
        size: clone(this._size),
        datatype: this._datatype
      });
      return m;
    };
    DenseMatrix2.prototype.size = function() {
      return this._size.slice(0);
    };
    DenseMatrix2.prototype.map = function(callback) {
      var me = this;
      var recurse = function recurse2(value, index2) {
        if (isArray(value)) {
          return value.map(function(child, i) {
            return recurse2(child, index2.concat(i));
          });
        } else {
          return callback(value, index2, me);
        }
      };
      var data = recurse(this._data, []);
      var datatype = this._datatype !== void 0 ? getArrayDataType(data, typeOf) : void 0;
      return new DenseMatrix2(data, datatype);
    };
    DenseMatrix2.prototype.forEach = function(callback) {
      var me = this;
      var recurse = function recurse2(value, index2) {
        if (isArray(value)) {
          value.forEach(function(child, i) {
            recurse2(child, index2.concat(i));
          });
        } else {
          callback(value, index2, me);
        }
      };
      recurse(this._data, []);
    };
    DenseMatrix2.prototype[Symbol.iterator] = function* () {
      var recurse = function* recurse2(value, index2) {
        if (isArray(value)) {
          for (var i = 0; i < value.length; i++) {
            yield* recurse2(value[i], index2.concat(i));
          }
        } else {
          yield {
            value,
            index: index2
          };
        }
      };
      yield* recurse(this._data, []);
    };
    DenseMatrix2.prototype.rows = function() {
      var result = [];
      var s = this.size();
      if (s.length !== 2) {
        throw new TypeError("Rows can only be returned for a 2D matrix.");
      }
      var data = this._data;
      for (var row of data) {
        result.push(new DenseMatrix2([row], this._datatype));
      }
      return result;
    };
    DenseMatrix2.prototype.columns = function() {
      var _this = this;
      var result = [];
      var s = this.size();
      if (s.length !== 2) {
        throw new TypeError("Rows can only be returned for a 2D matrix.");
      }
      var data = this._data;
      var _loop = function _loop2(i2) {
        var col = data.map((row) => [row[i2]]);
        result.push(new DenseMatrix2(col, _this._datatype));
      };
      for (var i = 0; i < s[1]; i++) {
        _loop(i);
      }
      return result;
    };
    DenseMatrix2.prototype.toArray = function() {
      return clone(this._data);
    };
    DenseMatrix2.prototype.valueOf = function() {
      return this._data;
    };
    DenseMatrix2.prototype.format = function(options) {
      return format3(this._data, options);
    };
    DenseMatrix2.prototype.toString = function() {
      return format3(this._data);
    };
    DenseMatrix2.prototype.toJSON = function() {
      return {
        mathjs: "DenseMatrix",
        data: this._data,
        size: this._size,
        datatype: this._datatype
      };
    };
    DenseMatrix2.prototype.diagonal = function(k) {
      if (k) {
        if (isBigNumber(k)) {
          k = k.toNumber();
        }
        if (!isNumber(k) || !isInteger(k)) {
          throw new TypeError("The parameter k must be an integer number");
        }
      } else {
        k = 0;
      }
      var kSuper = k > 0 ? k : 0;
      var kSub = k < 0 ? -k : 0;
      var rows = this._size[0];
      var columns = this._size[1];
      var n = Math.min(rows - kSub, columns - kSuper);
      var data = [];
      for (var i = 0; i < n; i++) {
        data[i] = this._data[i + kSub][i + kSuper];
      }
      return new DenseMatrix2({
        data,
        size: [n],
        datatype: this._datatype
      });
    };
    DenseMatrix2.diagonal = function(size2, value, k, defaultValue) {
      if (!isArray(size2)) {
        throw new TypeError("Array expected, size parameter");
      }
      if (size2.length !== 2) {
        throw new Error("Only two dimensions matrix are supported");
      }
      size2 = size2.map(function(s) {
        if (isBigNumber(s)) {
          s = s.toNumber();
        }
        if (!isNumber(s) || !isInteger(s) || s < 1) {
          throw new Error("Size values must be positive integers");
        }
        return s;
      });
      if (k) {
        if (isBigNumber(k)) {
          k = k.toNumber();
        }
        if (!isNumber(k) || !isInteger(k)) {
          throw new TypeError("The parameter k must be an integer number");
        }
      } else {
        k = 0;
      }
      var kSuper = k > 0 ? k : 0;
      var kSub = k < 0 ? -k : 0;
      var rows = size2[0];
      var columns = size2[1];
      var n = Math.min(rows - kSub, columns - kSuper);
      var _value;
      if (isArray(value)) {
        if (value.length !== n) {
          throw new Error("Invalid value array length");
        }
        _value = function _value2(i) {
          return value[i];
        };
      } else if (isMatrix(value)) {
        var ms = value.size();
        if (ms.length !== 1 || ms[0] !== n) {
          throw new Error("Invalid matrix length");
        }
        _value = function _value2(i) {
          return value.get([i]);
        };
      } else {
        _value = function _value2() {
          return value;
        };
      }
      if (!defaultValue) {
        defaultValue = isBigNumber(_value(0)) ? _value(0).mul(0) : 0;
      }
      var data = [];
      if (size2.length > 0) {
        data = resize(data, size2, defaultValue);
        for (var d = 0; d < n; d++) {
          data[d + kSub][d + kSuper] = _value(d);
        }
      }
      return new DenseMatrix2({
        data,
        size: [rows, columns]
      });
    };
    DenseMatrix2.fromJSON = function(json) {
      return new DenseMatrix2(json);
    };
    DenseMatrix2.prototype.swapRows = function(i, j) {
      if (!isNumber(i) || !isInteger(i) || !isNumber(j) || !isInteger(j)) {
        throw new Error("Row index must be positive integers");
      }
      if (this._size.length !== 2) {
        throw new Error("Only two dimensional matrix is supported");
      }
      validateIndex(i, this._size[0]);
      validateIndex(j, this._size[0]);
      DenseMatrix2._swapRows(i, j, this._data);
      return this;
    };
    DenseMatrix2._swapRows = function(i, j, data) {
      var vi = data[i];
      data[i] = data[j];
      data[j] = vi;
    };
    function preprocess(data) {
      for (var i = 0, ii = data.length; i < ii; i++) {
        var elem = data[i];
        if (isArray(elem)) {
          data[i] = preprocess(elem);
        } else if (elem && elem.isMatrix === true) {
          data[i] = preprocess(elem.valueOf());
        }
      }
      return data;
    }
    return DenseMatrix2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/utils/collection.js
  function containsCollections(array) {
    for (var i = 0; i < array.length; i++) {
      if (isCollection(array[i])) {
        return true;
      }
    }
    return false;
  }
  function deepForEach(array, callback) {
    if (isMatrix(array)) {
      array = array.valueOf();
    }
    for (var i = 0, ii = array.length; i < ii; i++) {
      var value = array[i];
      if (Array.isArray(value)) {
        deepForEach(value, callback);
      } else {
        callback(value);
      }
    }
  }
  function deepMap(array, callback, skipZeros) {
    if (array && typeof array.map === "function") {
      return array.map(function(x) {
        return deepMap(x, callback, skipZeros);
      });
    } else {
      return callback(array);
    }
  }
  function reduce(mat, dim, callback) {
    var size2 = Array.isArray(mat) ? arraySize(mat) : mat.size();
    if (dim < 0 || dim >= size2.length) {
      throw new IndexError(dim, size2.length);
    }
    if (isMatrix(mat)) {
      return mat.create(_reduce(mat.valueOf(), dim, callback));
    } else {
      return _reduce(mat, dim, callback);
    }
  }
  function _reduce(mat, dim, callback) {
    var i, ret, val, tran;
    if (dim <= 0) {
      if (!Array.isArray(mat[0])) {
        val = mat[0];
        for (i = 1; i < mat.length; i++) {
          val = callback(val, mat[i]);
        }
        return val;
      } else {
        tran = _switch(mat);
        ret = [];
        for (i = 0; i < tran.length; i++) {
          ret[i] = _reduce(tran[i], dim - 1, callback);
        }
        return ret;
      }
    } else {
      ret = [];
      for (i = 0; i < mat.length; i++) {
        ret[i] = _reduce(mat[i], dim - 1, callback);
      }
      return ret;
    }
  }
  function _switch(mat) {
    var I = mat.length;
    var J = mat[0].length;
    var i, j;
    var ret = [];
    for (j = 0; j < J; j++) {
      var tmp = [];
      for (i = 0; i < I; i++) {
        tmp.push(mat[i][j]);
      }
      ret.push(tmp);
    }
    return ret;
  }

  // node_modules/mathjs/lib/esm/function/utils/isInteger.js
  var name6 = "isInteger";
  var dependencies7 = ["typed"];
  var createIsInteger = /* @__PURE__ */ factory(name6, dependencies7, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name6, {
      number: isInteger,
      // TODO: what to do with isInteger(add(0.1, 0.2))  ?
      BigNumber: function BigNumber2(x) {
        return x.isInt();
      },
      Fraction: function Fraction3(x) {
        return x.d === 1 && isFinite(x.n);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/plain/number/arithmetic.js
  var n1 = "number";
  var n2 = "number, number";
  function absNumber(a) {
    return Math.abs(a);
  }
  absNumber.signature = n1;
  function addNumber(a, b) {
    return a + b;
  }
  addNumber.signature = n2;
  function subtractNumber(a, b) {
    return a - b;
  }
  subtractNumber.signature = n2;
  function multiplyNumber(a, b) {
    return a * b;
  }
  multiplyNumber.signature = n2;
  function divideNumber(a, b) {
    return a / b;
  }
  divideNumber.signature = n2;
  function unaryMinusNumber(x) {
    return -x;
  }
  unaryMinusNumber.signature = n1;
  function unaryPlusNumber(x) {
    return x;
  }
  unaryPlusNumber.signature = n1;
  function cbrtNumber(x) {
    return cbrt(x);
  }
  cbrtNumber.signature = n1;
  function ceilNumber(x) {
    return Math.ceil(x);
  }
  ceilNumber.signature = n1;
  function cubeNumber(x) {
    return x * x * x;
  }
  cubeNumber.signature = n1;
  function expNumber(x) {
    return Math.exp(x);
  }
  expNumber.signature = n1;
  function expm1Number(x) {
    return expm1(x);
  }
  expm1Number.signature = n1;
  function fixNumber(x) {
    return x > 0 ? Math.floor(x) : Math.ceil(x);
  }
  fixNumber.signature = n1;
  function floorNumber(x) {
    return Math.floor(x);
  }
  floorNumber.signature = n1;
  function gcdNumber(a, b) {
    if (!isInteger(a) || !isInteger(b)) {
      throw new Error("Parameters in function gcd must be integer numbers");
    }
    var r;
    while (b !== 0) {
      r = a % b;
      a = b;
      b = r;
    }
    return a < 0 ? -a : a;
  }
  gcdNumber.signature = n2;
  function lcmNumber(a, b) {
    if (!isInteger(a) || !isInteger(b)) {
      throw new Error("Parameters in function lcm must be integer numbers");
    }
    if (a === 0 || b === 0) {
      return 0;
    }
    var t;
    var prod = a * b;
    while (b !== 0) {
      t = b;
      b = a % t;
      a = t;
    }
    return Math.abs(prod / a);
  }
  lcmNumber.signature = n2;
  function logNumber(x) {
    return Math.log(x);
  }
  logNumber.signature = n1;
  function log10Number(x) {
    return log10(x);
  }
  log10Number.signature = n1;
  function log2Number(x) {
    return log2(x);
  }
  log2Number.signature = n1;
  function log1pNumber(x) {
    return log1p(x);
  }
  log1pNumber.signature = n1;
  function modNumber(x, y) {
    if (y > 0) {
      return x - y * Math.floor(x / y);
    } else if (y === 0) {
      return x;
    } else {
      throw new Error("Cannot calculate mod for a negative divisor");
    }
  }
  modNumber.signature = n2;
  function nthRootNumber(a, root) {
    var inv2 = root < 0;
    if (inv2) {
      root = -root;
    }
    if (root === 0) {
      throw new Error("Root must be non-zero");
    }
    if (a < 0 && Math.abs(root) % 2 !== 1) {
      throw new Error("Root must be odd when a is negative.");
    }
    if (a === 0) {
      return inv2 ? Infinity : 0;
    }
    if (!isFinite(a)) {
      return inv2 ? 0 : a;
    }
    var x = Math.pow(Math.abs(a), 1 / root);
    x = a < 0 ? -x : x;
    return inv2 ? 1 / x : x;
  }
  nthRootNumber.signature = n2;
  function signNumber(x) {
    return sign(x);
  }
  signNumber.signature = n1;
  function sqrtNumber(x) {
    return Math.sqrt(x);
  }
  sqrtNumber.signature = n1;
  function squareNumber(x) {
    return x * x;
  }
  squareNumber.signature = n1;
  function xgcdNumber(a, b) {
    var t;
    var q;
    var r;
    var x = 0;
    var lastx = 1;
    var y = 1;
    var lasty = 0;
    if (!isInteger(a) || !isInteger(b)) {
      throw new Error("Parameters in function xgcd must be integer numbers");
    }
    while (b) {
      q = Math.floor(a / b);
      r = a - q * b;
      t = x;
      x = lastx - q * x;
      lastx = t;
      t = y;
      y = lasty - q * y;
      lasty = t;
      a = b;
      b = r;
    }
    var res;
    if (a < 0) {
      res = [-a, -lastx, -lasty];
    } else {
      res = [a, a ? lastx : 0, lasty];
    }
    return res;
  }
  xgcdNumber.signature = n2;
  function powNumber(x, y) {
    if (x * x < 1 && y === Infinity || x * x > 1 && y === -Infinity) {
      return 0;
    }
    return Math.pow(x, y);
  }
  powNumber.signature = n2;
  function roundNumber(value) {
    var decimals = arguments.length > 1 && arguments[1] !== void 0 ? arguments[1] : 0;
    return parseFloat(toFixed(value, decimals));
  }
  roundNumber.signature = n2;
  function normNumber(x) {
    return Math.abs(x);
  }
  normNumber.signature = n1;

  // node_modules/mathjs/lib/esm/plain/number/utils.js
  var n12 = "number";
  function isIntegerNumber(x) {
    return isInteger(x);
  }
  isIntegerNumber.signature = n12;
  function isNegativeNumber(x) {
    return x < 0;
  }
  isNegativeNumber.signature = n12;
  function isPositiveNumber(x) {
    return x > 0;
  }
  isPositiveNumber.signature = n12;
  function isZeroNumber(x) {
    return x === 0;
  }
  isZeroNumber.signature = n12;
  function isNaNNumber(x) {
    return Number.isNaN(x);
  }
  isNaNNumber.signature = n12;

  // node_modules/mathjs/lib/esm/function/utils/isZero.js
  var name7 = "isZero";
  var dependencies8 = ["typed"];
  var createIsZero = /* @__PURE__ */ factory(name7, dependencies8, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name7, {
      number: isZeroNumber,
      BigNumber: function BigNumber2(x) {
        return x.isZero();
      },
      Complex: function Complex3(x) {
        return x.re === 0 && x.im === 0;
      },
      Fraction: function Fraction3(x) {
        return x.d === 1 && x.n === 0;
      },
      Unit: function Unit(x) {
        return this(x.value);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/utils/bignumber/nearlyEqual.js
  function nearlyEqual2(x, y, epsilon) {
    if (epsilon === null || epsilon === void 0) {
      return x.eq(y);
    }
    if (x.eq(y)) {
      return true;
    }
    if (x.isNaN() || y.isNaN()) {
      return false;
    }
    if (x.isFinite() && y.isFinite()) {
      var diff = x.minus(y).abs();
      if (diff.isZero()) {
        return true;
      } else {
        var max2 = x.constructor.max(x.abs(), y.abs());
        return diff.lte(max2.times(epsilon));
      }
    }
    return false;
  }

  // node_modules/mathjs/lib/esm/utils/complex.js
  function complexEquals(x, y, epsilon) {
    return nearlyEqual(x.re, y.re, epsilon) && nearlyEqual(x.im, y.im, epsilon);
  }

  // node_modules/mathjs/lib/esm/function/relational/equalScalar.js
  var name8 = "equalScalar";
  var dependencies9 = ["typed", "config"];
  var createEqualScalar = /* @__PURE__ */ factory(name8, dependencies9, (_ref) => {
    var {
      typed: typed2,
      config: config4
    } = _ref;
    return typed2(name8, {
      "boolean, boolean": function booleanBoolean(x, y) {
        return x === y;
      },
      "number, number": function numberNumber(x, y) {
        return nearlyEqual(x, y, config4.epsilon);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.eq(y) || nearlyEqual2(x, y, config4.epsilon);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.equals(y);
      },
      "Complex, Complex": function ComplexComplex(x, y) {
        return complexEquals(x, y, config4.epsilon);
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (!x.equalBase(y)) {
          throw new Error("Cannot compare units with different base");
        }
        return this(x.value, y.value);
      }
    });
  });
  var createEqualScalarNumber = factory(name8, ["typed", "config"], (_ref2) => {
    var {
      typed: typed2,
      config: config4
    } = _ref2;
    return typed2(name8, {
      "number, number": function numberNumber(x, y) {
        return nearlyEqual(x, y, config4.epsilon);
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/matrix/SparseMatrix.js
  var name9 = "SparseMatrix";
  var dependencies10 = ["typed", "equalScalar", "Matrix"];
  var createSparseMatrixClass = /* @__PURE__ */ factory(name9, dependencies10, (_ref) => {
    var {
      typed: typed2,
      equalScalar: equalScalar2,
      Matrix: Matrix2
    } = _ref;
    function SparseMatrix2(data, datatype) {
      if (!(this instanceof SparseMatrix2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      if (datatype && !isString(datatype)) {
        throw new Error("Invalid datatype: " + datatype);
      }
      if (isMatrix(data)) {
        _createFromMatrix(this, data, datatype);
      } else if (data && isArray(data.index) && isArray(data.ptr) && isArray(data.size)) {
        this._values = data.values;
        this._index = data.index;
        this._ptr = data.ptr;
        this._size = data.size;
        this._datatype = datatype || data.datatype;
      } else if (isArray(data)) {
        _createFromArray(this, data, datatype);
      } else if (data) {
        throw new TypeError("Unsupported type of data (" + typeOf(data) + ")");
      } else {
        this._values = [];
        this._index = [];
        this._ptr = [0];
        this._size = [0, 0];
        this._datatype = datatype;
      }
    }
    function _createFromMatrix(matrix2, source, datatype) {
      if (source.type === "SparseMatrix") {
        matrix2._values = source._values ? clone(source._values) : void 0;
        matrix2._index = clone(source._index);
        matrix2._ptr = clone(source._ptr);
        matrix2._size = clone(source._size);
        matrix2._datatype = datatype || source._datatype;
      } else {
        _createFromArray(matrix2, source.valueOf(), datatype || source._datatype);
      }
    }
    function _createFromArray(matrix2, data, datatype) {
      matrix2._values = [];
      matrix2._index = [];
      matrix2._ptr = [];
      matrix2._datatype = datatype;
      var rows = data.length;
      var columns = 0;
      var eq = equalScalar2;
      var zero = 0;
      if (isString(datatype)) {
        eq = typed2.find(equalScalar2, [datatype, datatype]) || equalScalar2;
        zero = typed2.convert(0, datatype);
      }
      if (rows > 0) {
        var j = 0;
        do {
          matrix2._ptr.push(matrix2._index.length);
          for (var i = 0; i < rows; i++) {
            var row = data[i];
            if (isArray(row)) {
              if (j === 0 && columns < row.length) {
                columns = row.length;
              }
              if (j < row.length) {
                var v = row[j];
                if (!eq(v, zero)) {
                  matrix2._values.push(v);
                  matrix2._index.push(i);
                }
              }
            } else {
              if (j === 0 && columns < 1) {
                columns = 1;
              }
              if (!eq(row, zero)) {
                matrix2._values.push(row);
                matrix2._index.push(i);
              }
            }
          }
          j++;
        } while (j < columns);
      }
      matrix2._ptr.push(matrix2._index.length);
      matrix2._size = [rows, columns];
    }
    SparseMatrix2.prototype = new Matrix2();
    SparseMatrix2.prototype.createSparseMatrix = function(data, datatype) {
      return new SparseMatrix2(data, datatype);
    };
    SparseMatrix2.prototype.type = "SparseMatrix";
    SparseMatrix2.prototype.isSparseMatrix = true;
    SparseMatrix2.prototype.getDataType = function() {
      return getArrayDataType(this._values, typeOf);
    };
    SparseMatrix2.prototype.storage = function() {
      return "sparse";
    };
    SparseMatrix2.prototype.datatype = function() {
      return this._datatype;
    };
    SparseMatrix2.prototype.create = function(data, datatype) {
      return new SparseMatrix2(data, datatype);
    };
    SparseMatrix2.prototype.density = function() {
      var rows = this._size[0];
      var columns = this._size[1];
      return rows !== 0 && columns !== 0 ? this._index.length / (rows * columns) : 0;
    };
    SparseMatrix2.prototype.subset = function(index2, replacement, defaultValue) {
      if (!this._values) {
        throw new Error("Cannot invoke subset on a Pattern only matrix");
      }
      switch (arguments.length) {
        case 1:
          return _getsubset(this, index2);
        // intentional fall through
        case 2:
        case 3:
          return _setsubset(this, index2, replacement, defaultValue);
        default:
          throw new SyntaxError("Wrong number of arguments");
      }
    };
    function _getsubset(matrix2, idx) {
      if (!isIndex(idx)) {
        throw new TypeError("Invalid index");
      }
      var isScalar = idx.isScalar();
      if (isScalar) {
        return matrix2.get(idx.min());
      }
      var size2 = idx.size();
      if (size2.length !== matrix2._size.length) {
        throw new DimensionError(size2.length, matrix2._size.length);
      }
      var i, ii, k, kk;
      var min2 = idx.min();
      var max2 = idx.max();
      for (i = 0, ii = matrix2._size.length; i < ii; i++) {
        validateIndex(min2[i], matrix2._size[i]);
        validateIndex(max2[i], matrix2._size[i]);
      }
      var mvalues = matrix2._values;
      var mindex = matrix2._index;
      var mptr = matrix2._ptr;
      var rows = idx.dimension(0);
      var columns = idx.dimension(1);
      var w = [];
      var pv = [];
      rows.forEach(function(i2, r) {
        pv[i2] = r[0];
        w[i2] = true;
      });
      var values = mvalues ? [] : void 0;
      var index2 = [];
      var ptr = [];
      columns.forEach(function(j) {
        ptr.push(index2.length);
        for (k = mptr[j], kk = mptr[j + 1]; k < kk; k++) {
          i = mindex[k];
          if (w[i] === true) {
            index2.push(pv[i]);
            if (values) {
              values.push(mvalues[k]);
            }
          }
        }
      });
      ptr.push(index2.length);
      return new SparseMatrix2({
        values,
        index: index2,
        ptr,
        size: size2,
        datatype: matrix2._datatype
      });
    }
    function _setsubset(matrix2, index2, submatrix, defaultValue) {
      if (!index2 || index2.isIndex !== true) {
        throw new TypeError("Invalid index");
      }
      var iSize = index2.size();
      var isScalar = index2.isScalar();
      var sSize;
      if (isMatrix(submatrix)) {
        sSize = submatrix.size();
        submatrix = submatrix.toArray();
      } else {
        sSize = arraySize(submatrix);
      }
      if (isScalar) {
        if (sSize.length !== 0) {
          throw new TypeError("Scalar expected");
        }
        matrix2.set(index2.min(), submatrix, defaultValue);
      } else {
        if (iSize.length !== 1 && iSize.length !== 2) {
          throw new DimensionError(iSize.length, matrix2._size.length, "<");
        }
        if (sSize.length < iSize.length) {
          var i = 0;
          var outer = 0;
          while (iSize[i] === 1 && sSize[i] === 1) {
            i++;
          }
          while (iSize[i] === 1) {
            outer++;
            i++;
          }
          submatrix = unsqueeze(submatrix, iSize.length, outer, sSize);
        }
        if (!deepStrictEqual(iSize, sSize)) {
          throw new DimensionError(iSize, sSize, ">");
        }
        var x0 = index2.min()[0];
        var y0 = index2.min()[1];
        var m = sSize[0];
        var n = sSize[1];
        for (var x = 0; x < m; x++) {
          for (var y = 0; y < n; y++) {
            var v = submatrix[x][y];
            matrix2.set([x + x0, y + y0], v, defaultValue);
          }
        }
      }
      return matrix2;
    }
    SparseMatrix2.prototype.get = function(index2) {
      if (!isArray(index2)) {
        throw new TypeError("Array expected");
      }
      if (index2.length !== this._size.length) {
        throw new DimensionError(index2.length, this._size.length);
      }
      if (!this._values) {
        throw new Error("Cannot invoke get on a Pattern only matrix");
      }
      var i = index2[0];
      var j = index2[1];
      validateIndex(i, this._size[0]);
      validateIndex(j, this._size[1]);
      var k = _getValueIndex(i, this._ptr[j], this._ptr[j + 1], this._index);
      if (k < this._ptr[j + 1] && this._index[k] === i) {
        return this._values[k];
      }
      return 0;
    };
    SparseMatrix2.prototype.set = function(index2, v, defaultValue) {
      if (!isArray(index2)) {
        throw new TypeError("Array expected");
      }
      if (index2.length !== this._size.length) {
        throw new DimensionError(index2.length, this._size.length);
      }
      if (!this._values) {
        throw new Error("Cannot invoke set on a Pattern only matrix");
      }
      var i = index2[0];
      var j = index2[1];
      var rows = this._size[0];
      var columns = this._size[1];
      var eq = equalScalar2;
      var zero = 0;
      if (isString(this._datatype)) {
        eq = typed2.find(equalScalar2, [this._datatype, this._datatype]) || equalScalar2;
        zero = typed2.convert(0, this._datatype);
      }
      if (i > rows - 1 || j > columns - 1) {
        _resize2(this, Math.max(i + 1, rows), Math.max(j + 1, columns), defaultValue);
        rows = this._size[0];
        columns = this._size[1];
      }
      validateIndex(i, rows);
      validateIndex(j, columns);
      var k = _getValueIndex(i, this._ptr[j], this._ptr[j + 1], this._index);
      if (k < this._ptr[j + 1] && this._index[k] === i) {
        if (!eq(v, zero)) {
          this._values[k] = v;
        } else {
          _remove(k, j, this._values, this._index, this._ptr);
        }
      } else {
        _insert(k, i, j, v, this._values, this._index, this._ptr);
      }
      return this;
    };
    function _getValueIndex(i, top, bottom, index2) {
      if (bottom - top === 0) {
        return bottom;
      }
      for (var r = top; r < bottom; r++) {
        if (index2[r] === i) {
          return r;
        }
      }
      return top;
    }
    function _remove(k, j, values, index2, ptr) {
      values.splice(k, 1);
      index2.splice(k, 1);
      for (var x = j + 1; x < ptr.length; x++) {
        ptr[x]--;
      }
    }
    function _insert(k, i, j, v, values, index2, ptr) {
      values.splice(k, 0, v);
      index2.splice(k, 0, i);
      for (var x = j + 1; x < ptr.length; x++) {
        ptr[x]++;
      }
    }
    SparseMatrix2.prototype.resize = function(size2, defaultValue, copy) {
      if (!isCollection(size2)) {
        throw new TypeError("Array or Matrix expected");
      }
      var sizeArray = size2.valueOf().map((value) => {
        return Array.isArray(value) && value.length === 1 ? value[0] : value;
      });
      if (sizeArray.length !== 2) {
        throw new Error("Only two dimensions matrix are supported");
      }
      sizeArray.forEach(function(value) {
        if (!isNumber(value) || !isInteger(value) || value < 0) {
          throw new TypeError("Invalid size, must contain positive integers (size: " + format3(sizeArray) + ")");
        }
      });
      var m = copy ? this.clone() : this;
      return _resize2(m, sizeArray[0], sizeArray[1], defaultValue);
    };
    function _resize2(matrix2, rows, columns, defaultValue) {
      var value = defaultValue || 0;
      var eq = equalScalar2;
      var zero = 0;
      if (isString(matrix2._datatype)) {
        eq = typed2.find(equalScalar2, [matrix2._datatype, matrix2._datatype]) || equalScalar2;
        zero = typed2.convert(0, matrix2._datatype);
        value = typed2.convert(value, matrix2._datatype);
      }
      var ins = !eq(value, zero);
      var r = matrix2._size[0];
      var c = matrix2._size[1];
      var i, j, k;
      if (columns > c) {
        for (j = c; j < columns; j++) {
          matrix2._ptr[j] = matrix2._values.length;
          if (ins) {
            for (i = 0; i < r; i++) {
              matrix2._values.push(value);
              matrix2._index.push(i);
            }
          }
        }
        matrix2._ptr[columns] = matrix2._values.length;
      } else if (columns < c) {
        matrix2._ptr.splice(columns + 1, c - columns);
        matrix2._values.splice(matrix2._ptr[columns], matrix2._values.length);
        matrix2._index.splice(matrix2._ptr[columns], matrix2._index.length);
      }
      c = columns;
      if (rows > r) {
        if (ins) {
          var n = 0;
          for (j = 0; j < c; j++) {
            matrix2._ptr[j] = matrix2._ptr[j] + n;
            k = matrix2._ptr[j + 1] + n;
            var p = 0;
            for (i = r; i < rows; i++, p++) {
              matrix2._values.splice(k + p, 0, value);
              matrix2._index.splice(k + p, 0, i);
              n++;
            }
          }
          matrix2._ptr[c] = matrix2._values.length;
        }
      } else if (rows < r) {
        var d = 0;
        for (j = 0; j < c; j++) {
          matrix2._ptr[j] = matrix2._ptr[j] - d;
          var k0 = matrix2._ptr[j];
          var k1 = matrix2._ptr[j + 1] - d;
          for (k = k0; k < k1; k++) {
            i = matrix2._index[k];
            if (i > rows - 1) {
              matrix2._values.splice(k, 1);
              matrix2._index.splice(k, 1);
              d++;
            }
          }
        }
        matrix2._ptr[j] = matrix2._values.length;
      }
      matrix2._size[0] = rows;
      matrix2._size[1] = columns;
      return matrix2;
    }
    SparseMatrix2.prototype.reshape = function(sizes, copy) {
      if (!isArray(sizes)) {
        throw new TypeError("Array expected");
      }
      if (sizes.length !== 2) {
        throw new Error("Sparse matrices can only be reshaped in two dimensions");
      }
      sizes.forEach(function(value) {
        if (!isNumber(value) || !isInteger(value) || value <= -2 || value === 0) {
          throw new TypeError("Invalid size, must contain positive integers or -1 (size: " + format3(sizes) + ")");
        }
      });
      var currentLength = this._size[0] * this._size[1];
      sizes = processSizesWildcard(sizes, currentLength);
      var newLength = sizes[0] * sizes[1];
      if (currentLength !== newLength) {
        throw new Error("Reshaping sparse matrix will result in the wrong number of elements");
      }
      var m = copy ? this.clone() : this;
      if (this._size[0] === sizes[0] && this._size[1] === sizes[1]) {
        return m;
      }
      var colIndex = [];
      for (var i = 0; i < m._ptr.length; i++) {
        for (var j = 0; j < m._ptr[i + 1] - m._ptr[i]; j++) {
          colIndex.push(i);
        }
      }
      var values = m._values.slice();
      var rowIndex = m._index.slice();
      for (var _i = 0; _i < m._index.length; _i++) {
        var r1 = rowIndex[_i];
        var c1 = colIndex[_i];
        var flat = r1 * m._size[1] + c1;
        colIndex[_i] = flat % sizes[1];
        rowIndex[_i] = Math.floor(flat / sizes[1]);
      }
      m._values.length = 0;
      m._index.length = 0;
      m._ptr.length = sizes[1] + 1;
      m._size = sizes.slice();
      for (var _i2 = 0; _i2 < m._ptr.length; _i2++) {
        m._ptr[_i2] = 0;
      }
      for (var h = 0; h < values.length; h++) {
        var _i3 = rowIndex[h];
        var _j = colIndex[h];
        var v = values[h];
        var k = _getValueIndex(_i3, m._ptr[_j], m._ptr[_j + 1], m._index);
        _insert(k, _i3, _j, v, m._values, m._index, m._ptr);
      }
      return m;
    };
    SparseMatrix2.prototype.clone = function() {
      var m = new SparseMatrix2({
        values: this._values ? clone(this._values) : void 0,
        index: clone(this._index),
        ptr: clone(this._ptr),
        size: clone(this._size),
        datatype: this._datatype
      });
      return m;
    };
    SparseMatrix2.prototype.size = function() {
      return this._size.slice(0);
    };
    SparseMatrix2.prototype.map = function(callback, skipZeros) {
      if (!this._values) {
        throw new Error("Cannot invoke map on a Pattern only matrix");
      }
      var me = this;
      var rows = this._size[0];
      var columns = this._size[1];
      var invoke = function invoke2(v, i, j) {
        return callback(v, [i, j], me);
      };
      return _map(this, 0, rows - 1, 0, columns - 1, invoke, skipZeros);
    };
    function _map(matrix2, minRow, maxRow, minColumn, maxColumn, callback, skipZeros) {
      var values = [];
      var index2 = [];
      var ptr = [];
      var eq = equalScalar2;
      var zero = 0;
      if (isString(matrix2._datatype)) {
        eq = typed2.find(equalScalar2, [matrix2._datatype, matrix2._datatype]) || equalScalar2;
        zero = typed2.convert(0, matrix2._datatype);
      }
      var invoke = function invoke2(v, x, y) {
        v = callback(v, x, y);
        if (!eq(v, zero)) {
          values.push(v);
          index2.push(x);
        }
      };
      for (var j = minColumn; j <= maxColumn; j++) {
        ptr.push(values.length);
        var k0 = matrix2._ptr[j];
        var k1 = matrix2._ptr[j + 1];
        if (skipZeros) {
          for (var k = k0; k < k1; k++) {
            var i = matrix2._index[k];
            if (i >= minRow && i <= maxRow) {
              invoke(matrix2._values[k], i - minRow, j - minColumn);
            }
          }
        } else {
          var _values = {};
          for (var _k = k0; _k < k1; _k++) {
            var _i4 = matrix2._index[_k];
            _values[_i4] = matrix2._values[_k];
          }
          for (var _i5 = minRow; _i5 <= maxRow; _i5++) {
            var value = _i5 in _values ? _values[_i5] : 0;
            invoke(value, _i5 - minRow, j - minColumn);
          }
        }
      }
      ptr.push(values.length);
      return new SparseMatrix2({
        values,
        index: index2,
        ptr,
        size: [maxRow - minRow + 1, maxColumn - minColumn + 1]
      });
    }
    SparseMatrix2.prototype.forEach = function(callback, skipZeros) {
      if (!this._values) {
        throw new Error("Cannot invoke forEach on a Pattern only matrix");
      }
      var me = this;
      var rows = this._size[0];
      var columns = this._size[1];
      for (var j = 0; j < columns; j++) {
        var k0 = this._ptr[j];
        var k1 = this._ptr[j + 1];
        if (skipZeros) {
          for (var k = k0; k < k1; k++) {
            var i = this._index[k];
            callback(this._values[k], [i, j], me);
          }
        } else {
          var values = {};
          for (var _k2 = k0; _k2 < k1; _k2++) {
            var _i6 = this._index[_k2];
            values[_i6] = this._values[_k2];
          }
          for (var _i7 = 0; _i7 < rows; _i7++) {
            var value = _i7 in values ? values[_i7] : 0;
            callback(value, [_i7, j], me);
          }
        }
      }
    };
    SparseMatrix2.prototype[Symbol.iterator] = function* () {
      if (!this._values) {
        throw new Error("Cannot iterate a Pattern only matrix");
      }
      var columns = this._size[1];
      for (var j = 0; j < columns; j++) {
        var k0 = this._ptr[j];
        var k1 = this._ptr[j + 1];
        for (var k = k0; k < k1; k++) {
          var i = this._index[k];
          yield {
            value: this._values[k],
            index: [i, j]
          };
        }
      }
    };
    SparseMatrix2.prototype.toArray = function() {
      return _toArray(this._values, this._index, this._ptr, this._size, true);
    };
    SparseMatrix2.prototype.valueOf = function() {
      return _toArray(this._values, this._index, this._ptr, this._size, false);
    };
    function _toArray(values, index2, ptr, size2, copy) {
      var rows = size2[0];
      var columns = size2[1];
      var a = [];
      var i, j;
      for (i = 0; i < rows; i++) {
        a[i] = [];
        for (j = 0; j < columns; j++) {
          a[i][j] = 0;
        }
      }
      for (j = 0; j < columns; j++) {
        var k0 = ptr[j];
        var k1 = ptr[j + 1];
        for (var k = k0; k < k1; k++) {
          i = index2[k];
          a[i][j] = values ? copy ? clone(values[k]) : values[k] : 1;
        }
      }
      return a;
    }
    SparseMatrix2.prototype.format = function(options) {
      var rows = this._size[0];
      var columns = this._size[1];
      var density = this.density();
      var str = "Sparse Matrix [" + format3(rows, options) + " x " + format3(columns, options) + "] density: " + format3(density, options) + "\n";
      for (var j = 0; j < columns; j++) {
        var k0 = this._ptr[j];
        var k1 = this._ptr[j + 1];
        for (var k = k0; k < k1; k++) {
          var i = this._index[k];
          str += "\n    (" + format3(i, options) + ", " + format3(j, options) + ") ==> " + (this._values ? format3(this._values[k], options) : "X");
        }
      }
      return str;
    };
    SparseMatrix2.prototype.toString = function() {
      return format3(this.toArray());
    };
    SparseMatrix2.prototype.toJSON = function() {
      return {
        mathjs: "SparseMatrix",
        values: this._values,
        index: this._index,
        ptr: this._ptr,
        size: this._size,
        datatype: this._datatype
      };
    };
    SparseMatrix2.prototype.diagonal = function(k) {
      if (k) {
        if (isBigNumber(k)) {
          k = k.toNumber();
        }
        if (!isNumber(k) || !isInteger(k)) {
          throw new TypeError("The parameter k must be an integer number");
        }
      } else {
        k = 0;
      }
      var kSuper = k > 0 ? k : 0;
      var kSub = k < 0 ? -k : 0;
      var rows = this._size[0];
      var columns = this._size[1];
      var n = Math.min(rows - kSub, columns - kSuper);
      var values = [];
      var index2 = [];
      var ptr = [];
      ptr[0] = 0;
      for (var j = kSuper; j < columns && values.length < n; j++) {
        var k0 = this._ptr[j];
        var k1 = this._ptr[j + 1];
        for (var x = k0; x < k1; x++) {
          var i = this._index[x];
          if (i === j - kSuper + kSub) {
            values.push(this._values[x]);
            index2[values.length - 1] = i - kSub;
            break;
          }
        }
      }
      ptr.push(values.length);
      return new SparseMatrix2({
        values,
        index: index2,
        ptr,
        size: [n, 1]
      });
    };
    SparseMatrix2.fromJSON = function(json) {
      return new SparseMatrix2(json);
    };
    SparseMatrix2.diagonal = function(size2, value, k, defaultValue, datatype) {
      if (!isArray(size2)) {
        throw new TypeError("Array expected, size parameter");
      }
      if (size2.length !== 2) {
        throw new Error("Only two dimensions matrix are supported");
      }
      size2 = size2.map(function(s) {
        if (isBigNumber(s)) {
          s = s.toNumber();
        }
        if (!isNumber(s) || !isInteger(s) || s < 1) {
          throw new Error("Size values must be positive integers");
        }
        return s;
      });
      if (k) {
        if (isBigNumber(k)) {
          k = k.toNumber();
        }
        if (!isNumber(k) || !isInteger(k)) {
          throw new TypeError("The parameter k must be an integer number");
        }
      } else {
        k = 0;
      }
      var eq = equalScalar2;
      var zero = 0;
      if (isString(datatype)) {
        eq = typed2.find(equalScalar2, [datatype, datatype]) || equalScalar2;
        zero = typed2.convert(0, datatype);
      }
      var kSuper = k > 0 ? k : 0;
      var kSub = k < 0 ? -k : 0;
      var rows = size2[0];
      var columns = size2[1];
      var n = Math.min(rows - kSub, columns - kSuper);
      var _value;
      if (isArray(value)) {
        if (value.length !== n) {
          throw new Error("Invalid value array length");
        }
        _value = function _value2(i2) {
          return value[i2];
        };
      } else if (isMatrix(value)) {
        var ms = value.size();
        if (ms.length !== 1 || ms[0] !== n) {
          throw new Error("Invalid matrix length");
        }
        _value = function _value2(i2) {
          return value.get([i2]);
        };
      } else {
        _value = function _value2() {
          return value;
        };
      }
      var values = [];
      var index2 = [];
      var ptr = [];
      for (var j = 0; j < columns; j++) {
        ptr.push(values.length);
        var i = j - kSuper;
        if (i >= 0 && i < n) {
          var v = _value(i);
          if (!eq(v, zero)) {
            index2.push(i + kSub);
            values.push(v);
          }
        }
      }
      ptr.push(values.length);
      return new SparseMatrix2({
        values,
        index: index2,
        ptr,
        size: [rows, columns]
      });
    };
    SparseMatrix2.prototype.swapRows = function(i, j) {
      if (!isNumber(i) || !isInteger(i) || !isNumber(j) || !isInteger(j)) {
        throw new Error("Row index must be positive integers");
      }
      if (this._size.length !== 2) {
        throw new Error("Only two dimensional matrix is supported");
      }
      validateIndex(i, this._size[0]);
      validateIndex(j, this._size[0]);
      SparseMatrix2._swapRows(i, j, this._size[1], this._values, this._index, this._ptr);
      return this;
    };
    SparseMatrix2._forEachRow = function(j, values, index2, ptr, callback) {
      var k0 = ptr[j];
      var k1 = ptr[j + 1];
      for (var k = k0; k < k1; k++) {
        callback(index2[k], values[k]);
      }
    };
    SparseMatrix2._swapRows = function(x, y, columns, values, index2, ptr) {
      for (var j = 0; j < columns; j++) {
        var k0 = ptr[j];
        var k1 = ptr[j + 1];
        var kx = _getValueIndex(x, k0, k1, index2);
        var ky = _getValueIndex(y, k0, k1, index2);
        if (kx < k1 && ky < k1 && index2[kx] === x && index2[ky] === y) {
          if (values) {
            var v = values[kx];
            values[kx] = values[ky];
            values[ky] = v;
          }
          continue;
        }
        if (kx < k1 && index2[kx] === x && (ky >= k1 || index2[ky] !== y)) {
          var vx = values ? values[kx] : void 0;
          index2.splice(ky, 0, y);
          if (values) {
            values.splice(ky, 0, vx);
          }
          index2.splice(ky <= kx ? kx + 1 : kx, 1);
          if (values) {
            values.splice(ky <= kx ? kx + 1 : kx, 1);
          }
          continue;
        }
        if (ky < k1 && index2[ky] === y && (kx >= k1 || index2[kx] !== x)) {
          var vy = values ? values[ky] : void 0;
          index2.splice(kx, 0, x);
          if (values) {
            values.splice(kx, 0, vy);
          }
          index2.splice(kx <= ky ? ky + 1 : ky, 1);
          if (values) {
            values.splice(kx <= ky ? ky + 1 : ky, 1);
          }
        }
      }
    };
    return SparseMatrix2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/number.js
  var name10 = "number";
  var dependencies11 = ["typed"];
  function getNonDecimalNumberParts(input) {
    var nonDecimalWithRadixMatch = input.match(/(0[box])([0-9a-fA-F]*)\.([0-9a-fA-F]*)/);
    if (nonDecimalWithRadixMatch) {
      var radix = {
        "0b": 2,
        "0o": 8,
        "0x": 16
      }[nonDecimalWithRadixMatch[1]];
      var integerPart = nonDecimalWithRadixMatch[2];
      var fractionalPart = nonDecimalWithRadixMatch[3];
      return {
        input,
        radix,
        integerPart,
        fractionalPart
      };
    } else {
      return null;
    }
  }
  function makeNumberFromNonDecimalParts(parts) {
    var n = parseInt(parts.integerPart, parts.radix);
    var f = 0;
    for (var i = 0; i < parts.fractionalPart.length; i++) {
      var digitValue = parseInt(parts.fractionalPart[i], parts.radix);
      f += digitValue / Math.pow(parts.radix, i + 1);
    }
    var result = n + f;
    if (isNaN(result)) {
      throw new SyntaxError('String "' + parts.input + '" is no valid number');
    }
    return result;
  }
  var createNumber = /* @__PURE__ */ factory(name10, dependencies11, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    var number2 = typed2("number", {
      "": function _() {
        return 0;
      },
      number: function number3(x) {
        return x;
      },
      string: function string(x) {
        if (x === "NaN") return NaN;
        var nonDecimalNumberParts = getNonDecimalNumberParts(x);
        if (nonDecimalNumberParts) {
          return makeNumberFromNonDecimalParts(nonDecimalNumberParts);
        }
        var size2 = 0;
        var wordSizeSuffixMatch = x.match(/(0[box][0-9a-fA-F]*)i([0-9]*)/);
        if (wordSizeSuffixMatch) {
          size2 = Number(wordSizeSuffixMatch[2]);
          x = wordSizeSuffixMatch[1];
        }
        var num = Number(x);
        if (isNaN(num)) {
          throw new SyntaxError('String "' + x + '" is no valid number');
        }
        if (wordSizeSuffixMatch) {
          if (num > 2 ** size2 - 1) {
            throw new SyntaxError('String "'.concat(x, '" is out of range'));
          }
          if (num >= 2 ** (size2 - 1)) {
            num = num - 2 ** size2;
          }
        }
        return num;
      },
      BigNumber: function BigNumber2(x) {
        return x.toNumber();
      },
      Fraction: function Fraction3(x) {
        return x.valueOf();
      },
      Unit: function Unit(x) {
        throw new Error("Second argument with valueless unit expected");
      },
      null: function _null(x) {
        return 0;
      },
      "Unit, string | Unit": function UnitStringUnit(unit, valuelessUnit) {
        return unit.toNumber(valuelessUnit);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
    number2.fromJSON = function(json) {
      return parseFloat(json.value);
    };
    return number2;
  });

  // node_modules/mathjs/lib/esm/type/bignumber/function/bignumber.js
  var name11 = "bignumber";
  var dependencies12 = ["typed", "BigNumber"];
  var createBignumber = /* @__PURE__ */ factory(name11, dependencies12, (_ref) => {
    var {
      typed: typed2,
      BigNumber: BigNumber2
    } = _ref;
    return typed2("bignumber", {
      "": function _() {
        return new BigNumber2(0);
      },
      number: function number2(x) {
        return new BigNumber2(x + "");
      },
      string: function string(x) {
        var wordSizeSuffixMatch = x.match(/(0[box][0-9a-fA-F]*)i([0-9]*)/);
        if (wordSizeSuffixMatch) {
          var size2 = wordSizeSuffixMatch[2];
          var n = BigNumber2(wordSizeSuffixMatch[1]);
          var twoPowSize = new BigNumber2(2).pow(Number(size2));
          if (n.gt(twoPowSize.sub(1))) {
            throw new SyntaxError('String "'.concat(x, '" is out of range'));
          }
          var twoPowSizeSubOne = new BigNumber2(2).pow(Number(size2) - 1);
          if (n.gte(twoPowSizeSubOne)) {
            return n.sub(twoPowSize);
          } else {
            return n;
          }
        }
        return new BigNumber2(x);
      },
      BigNumber: function BigNumber3(x) {
        return x;
      },
      Fraction: function Fraction3(x) {
        return new BigNumber2(x.n).div(x.d).times(x.s);
      },
      null: function _null(x) {
        return new BigNumber2(0);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/complex/function/complex.js
  var name12 = "complex";
  var dependencies13 = ["typed", "Complex"];
  var createComplex = /* @__PURE__ */ factory(name12, dependencies13, (_ref) => {
    var {
      typed: typed2,
      Complex: Complex3
    } = _ref;
    return typed2("complex", {
      "": function _() {
        return Complex3.ZERO;
      },
      number: function number2(x) {
        return new Complex3(x, 0);
      },
      "number, number": function numberNumber(re2, im2) {
        return new Complex3(re2, im2);
      },
      // TODO: this signature should be redundant
      "BigNumber, BigNumber": function BigNumberBigNumber(re2, im2) {
        return new Complex3(re2.toNumber(), im2.toNumber());
      },
      Fraction: function Fraction3(x) {
        return new Complex3(x.valueOf(), 0);
      },
      Complex: function Complex4(x) {
        return x.clone();
      },
      string: function string(x) {
        return Complex3(x);
      },
      null: function _null(x) {
        return Complex3(0);
      },
      Object: function Object2(x) {
        if ("re" in x && "im" in x) {
          return new Complex3(x.re, x.im);
        }
        if ("r" in x && "phi" in x || "abs" in x && "arg" in x) {
          return new Complex3(x);
        }
        throw new Error("Expected object with properties (re and im) or (r and phi) or (abs and arg)");
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/fraction/function/fraction.js
  var name13 = "fraction";
  var dependencies14 = ["typed", "Fraction"];
  var createFraction = /* @__PURE__ */ factory(name13, dependencies14, (_ref) => {
    var {
      typed: typed2,
      Fraction: Fraction3
    } = _ref;
    return typed2("fraction", {
      number: function number2(x) {
        if (!isFinite(x) || isNaN(x)) {
          throw new Error(x + " cannot be represented as a fraction");
        }
        return new Fraction3(x);
      },
      string: function string(x) {
        return new Fraction3(x);
      },
      "number, number": function numberNumber(numerator, denominator) {
        return new Fraction3(numerator, denominator);
      },
      null: function _null(x) {
        return new Fraction3(0);
      },
      BigNumber: function BigNumber2(x) {
        return new Fraction3(x.toString());
      },
      Fraction: function Fraction4(x) {
        return x;
      },
      Object: function Object2(x) {
        return new Fraction3(x);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/matrix/function/matrix.js
  var name14 = "matrix";
  var dependencies15 = ["typed", "Matrix", "DenseMatrix", "SparseMatrix"];
  var createMatrix = /* @__PURE__ */ factory(name14, dependencies15, (_ref) => {
    var {
      typed: typed2,
      Matrix: Matrix2,
      DenseMatrix: DenseMatrix2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    return typed2(name14, {
      "": function _() {
        return _create([]);
      },
      string: function string(format4) {
        return _create([], format4);
      },
      "string, string": function stringString(format4, datatype) {
        return _create([], format4, datatype);
      },
      Array: function Array2(data) {
        return _create(data);
      },
      Matrix: function Matrix3(data) {
        return _create(data, data.storage());
      },
      "Array | Matrix, string": _create,
      "Array | Matrix, string, string": _create
    });
    function _create(data, format4, datatype) {
      if (format4 === "dense" || format4 === "default" || format4 === void 0) {
        return new DenseMatrix2(data, datatype);
      }
      if (format4 === "sparse") {
        return new SparseMatrix2(data, datatype);
      }
      throw new TypeError("Unknown matrix type " + JSON.stringify(format4) + ".");
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/matrixFromColumns.js
  var name15 = "matrixFromColumns";
  var dependencies16 = ["typed", "matrix", "flatten", "size"];
  var createMatrixFromColumns = /* @__PURE__ */ factory(name15, dependencies16, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      flatten: flatten3,
      size: size2
    } = _ref;
    return typed2(name15, {
      "...Array": function Array2(arr) {
        return _createArray(arr);
      },
      "...Matrix": function Matrix2(arr) {
        return matrix2(_createArray(arr.map((m) => m.toArray())));
      }
      // TODO implement this properly for SparseMatrix
    });
    function _createArray(arr) {
      if (arr.length === 0) throw new TypeError("At least one column is needed to construct a matrix.");
      var N = checkVectorTypeAndReturnLength(arr[0]);
      var result = [];
      for (var i = 0; i < N; i++) {
        result[i] = [];
      }
      for (var col of arr) {
        var colLength = checkVectorTypeAndReturnLength(col);
        if (colLength !== N) {
          throw new TypeError("The vectors had different length: " + (N | 0) + " \u2260 " + (colLength | 0));
        }
        var f = flatten3(col);
        for (var _i = 0; _i < N; _i++) {
          result[_i].push(f[_i]);
        }
      }
      return result;
    }
    function checkVectorTypeAndReturnLength(vec) {
      var s = size2(vec);
      if (s.length === 1) {
        return s[0];
      } else if (s.length === 2) {
        if (s[0] === 1) {
          return s[1];
        } else if (s[1] === 1) {
          return s[0];
        } else {
          throw new TypeError("At least one of the arguments is not a vector.");
        }
      } else {
        throw new TypeError("Only one- or two-dimensional vectors are supported.");
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/unaryMinus.js
  var name16 = "unaryMinus";
  var dependencies17 = ["typed"];
  var createUnaryMinus = /* @__PURE__ */ factory(name16, dependencies17, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name16, {
      number: unaryMinusNumber,
      Complex: function Complex3(x) {
        return x.neg();
      },
      BigNumber: function BigNumber2(x) {
        return x.neg();
      },
      Fraction: function Fraction3(x) {
        return x.neg();
      },
      Unit: function Unit(x) {
        var res = x.clone();
        res.value = this(x.value);
        return res;
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      }
      // TODO: add support for string
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/abs.js
  var name17 = "abs";
  var dependencies18 = ["typed"];
  var createAbs = /* @__PURE__ */ factory(name17, dependencies18, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name17, {
      number: absNumber,
      Complex: function Complex3(x) {
        return x.abs();
      },
      BigNumber: function BigNumber2(x) {
        return x.abs();
      },
      Fraction: function Fraction3(x) {
        return x.abs();
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      },
      Unit: function Unit(x) {
        return x.abs();
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/addScalar.js
  var name18 = "addScalar";
  var dependencies19 = ["typed"];
  var createAddScalar = /* @__PURE__ */ factory(name18, dependencies19, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name18, {
      "number, number": addNumber,
      "Complex, Complex": function ComplexComplex(x, y) {
        return x.add(y);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.plus(y);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.add(y);
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (x.value === null || x.value === void 0) throw new Error("Parameter x contains a unit with undefined value");
        if (y.value === null || y.value === void 0) throw new Error("Parameter y contains a unit with undefined value");
        if (!x.equalBase(y)) throw new Error("Units do not match");
        var res = x.clone();
        res.value = this(res.value, y.value);
        res.fixPrefix = false;
        return res;
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm11.js
  var name19 = "algorithm11";
  var dependencies20 = ["typed", "equalScalar"];
  var createAlgorithm11 = /* @__PURE__ */ factory(name19, dependencies20, (_ref) => {
    var {
      typed: typed2,
      equalScalar: equalScalar2
    } = _ref;
    return function algorithm11(s, b, callback, inverse) {
      var avalues = s._values;
      var aindex = s._index;
      var aptr = s._ptr;
      var asize = s._size;
      var adt = s._datatype;
      if (!avalues) {
        throw new Error("Cannot perform operation on Pattern Sparse Matrix and Scalar value");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var eq = equalScalar2;
      var zero = 0;
      var cf = callback;
      if (typeof adt === "string") {
        dt = adt;
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
        b = typed2.convert(b, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cvalues = [];
      var cindex = [];
      var cptr = [];
      for (var j = 0; j < columns; j++) {
        cptr[j] = cindex.length;
        for (var k0 = aptr[j], k1 = aptr[j + 1], k = k0; k < k1; k++) {
          var i = aindex[k];
          var v = inverse ? cf(b, avalues[k]) : cf(avalues[k], b);
          if (!eq(v, zero)) {
            cindex.push(i);
            cvalues.push(v);
          }
        }
      }
      cptr[columns] = cindex.length;
      return s.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm14.js
  var name20 = "algorithm14";
  var dependencies21 = ["typed"];
  var createAlgorithm14 = /* @__PURE__ */ factory(name20, dependencies21, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return function algorithm14(a, b, callback, inverse) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var dt;
      var cf = callback;
      if (typeof adt === "string") {
        dt = adt;
        b = typed2.convert(b, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cdata = asize.length > 0 ? _iterate(cf, 0, asize, asize[0], adata, b, inverse) : [];
      return a.createDenseMatrix({
        data: cdata,
        size: clone(asize),
        datatype: dt
      });
    };
    function _iterate(f, level, s, n, av, bv, inverse) {
      var cv = [];
      if (level === s.length - 1) {
        for (var i = 0; i < n; i++) {
          cv[i] = inverse ? f(bv, av[i]) : f(av[i], bv);
        }
      } else {
        for (var j = 0; j < n; j++) {
          cv[j] = _iterate(f, level + 1, s, s[level + 1], av[j], bv, inverse);
        }
      }
      return cv;
    }
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm01.js
  var name21 = "algorithm01";
  var dependencies22 = ["typed"];
  var createAlgorithm01 = /* @__PURE__ */ factory(name21, dependencies22, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return function algorithm1(denseMatrix, sparseMatrix, callback, inverse) {
      var adata = denseMatrix._data;
      var asize = denseMatrix._size;
      var adt = denseMatrix._datatype;
      var bvalues = sparseMatrix._values;
      var bindex = sparseMatrix._index;
      var bptr = sparseMatrix._ptr;
      var bsize = sparseMatrix._size;
      var bdt = sparseMatrix._datatype;
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      if (asize[0] !== bsize[0] || asize[1] !== bsize[1]) {
        throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
      }
      if (!bvalues) {
        throw new Error("Cannot perform operation on Dense Matrix and Pattern Sparse Matrix");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt = typeof adt === "string" && adt === bdt ? adt : void 0;
      var cf = dt ? typed2.find(callback, [dt, dt]) : callback;
      var i, j;
      var cdata = [];
      for (i = 0; i < rows; i++) {
        cdata[i] = [];
      }
      var x = [];
      var w = [];
      for (j = 0; j < columns; j++) {
        var mark = j + 1;
        for (var k0 = bptr[j], k1 = bptr[j + 1], k = k0; k < k1; k++) {
          i = bindex[k];
          x[i] = inverse ? cf(bvalues[k], adata[i][j]) : cf(adata[i][j], bvalues[k]);
          w[i] = mark;
        }
        for (i = 0; i < rows; i++) {
          if (w[i] === mark) {
            cdata[i][j] = x[i];
          } else {
            cdata[i][j] = adata[i][j];
          }
        }
      }
      return denseMatrix.createDenseMatrix({
        data: cdata,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm04.js
  var name22 = "algorithm04";
  var dependencies23 = ["typed", "equalScalar"];
  var createAlgorithm04 = /* @__PURE__ */ factory(name22, dependencies23, (_ref) => {
    var {
      typed: typed2,
      equalScalar: equalScalar2
    } = _ref;
    return function algorithm04(a, b, callback) {
      var avalues = a._values;
      var aindex = a._index;
      var aptr = a._ptr;
      var asize = a._size;
      var adt = a._datatype;
      var bvalues = b._values;
      var bindex = b._index;
      var bptr = b._ptr;
      var bsize = b._size;
      var bdt = b._datatype;
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      if (asize[0] !== bsize[0] || asize[1] !== bsize[1]) {
        throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var eq = equalScalar2;
      var zero = 0;
      var cf = callback;
      if (typeof adt === "string" && adt === bdt) {
        dt = adt;
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cvalues = avalues && bvalues ? [] : void 0;
      var cindex = [];
      var cptr = [];
      var xa = avalues && bvalues ? [] : void 0;
      var xb = avalues && bvalues ? [] : void 0;
      var wa = [];
      var wb = [];
      var i, j, k, k0, k1;
      for (j = 0; j < columns; j++) {
        cptr[j] = cindex.length;
        var mark = j + 1;
        for (k0 = aptr[j], k1 = aptr[j + 1], k = k0; k < k1; k++) {
          i = aindex[k];
          cindex.push(i);
          wa[i] = mark;
          if (xa) {
            xa[i] = avalues[k];
          }
        }
        for (k0 = bptr[j], k1 = bptr[j + 1], k = k0; k < k1; k++) {
          i = bindex[k];
          if (wa[i] === mark) {
            if (xa) {
              var v = cf(xa[i], bvalues[k]);
              if (!eq(v, zero)) {
                xa[i] = v;
              } else {
                wa[i] = null;
              }
            }
          } else {
            cindex.push(i);
            wb[i] = mark;
            if (xb) {
              xb[i] = bvalues[k];
            }
          }
        }
        if (xa && xb) {
          k = cptr[j];
          while (k < cindex.length) {
            i = cindex[k];
            if (wa[i] === mark) {
              cvalues[k] = xa[i];
              k++;
            } else if (wb[i] === mark) {
              cvalues[k] = xb[i];
              k++;
            } else {
              cindex.splice(k, 1);
            }
          }
        }
      }
      cptr[columns] = cindex.length;
      return a.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm10.js
  var name23 = "algorithm10";
  var dependencies24 = ["typed", "DenseMatrix"];
  var createAlgorithm10 = /* @__PURE__ */ factory(name23, dependencies24, (_ref) => {
    var {
      typed: typed2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    return function algorithm10(s, b, callback, inverse) {
      var avalues = s._values;
      var aindex = s._index;
      var aptr = s._ptr;
      var asize = s._size;
      var adt = s._datatype;
      if (!avalues) {
        throw new Error("Cannot perform operation on Pattern Sparse Matrix and Scalar value");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var cf = callback;
      if (typeof adt === "string") {
        dt = adt;
        b = typed2.convert(b, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cdata = [];
      var x = [];
      var w = [];
      for (var j = 0; j < columns; j++) {
        var mark = j + 1;
        for (var k0 = aptr[j], k1 = aptr[j + 1], k = k0; k < k1; k++) {
          var r = aindex[k];
          x[r] = avalues[k];
          w[r] = mark;
        }
        for (var i = 0; i < rows; i++) {
          if (j === 0) {
            cdata[i] = [];
          }
          if (w[i] === mark) {
            cdata[i][j] = inverse ? cf(b, x[i]) : cf(x[i], b);
          } else {
            cdata[i][j] = b;
          }
        }
      }
      return new DenseMatrix2({
        data: cdata,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm13.js
  var name24 = "algorithm13";
  var dependencies25 = ["typed"];
  var createAlgorithm13 = /* @__PURE__ */ factory(name24, dependencies25, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return function algorithm13(a, b, callback) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var bdata = b._data;
      var bsize = b._size;
      var bdt = b._datatype;
      var csize = [];
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      for (var s = 0; s < asize.length; s++) {
        if (asize[s] !== bsize[s]) {
          throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
        }
        csize[s] = asize[s];
      }
      var dt;
      var cf = callback;
      if (typeof adt === "string" && adt === bdt) {
        dt = adt;
        cf = typed2.find(callback, [dt, dt]);
      }
      var cdata = csize.length > 0 ? _iterate(cf, 0, csize, csize[0], adata, bdata) : [];
      return a.createDenseMatrix({
        data: cdata,
        size: csize,
        datatype: dt
      });
    };
    function _iterate(f, level, s, n, av, bv) {
      var cv = [];
      if (level === s.length - 1) {
        for (var i = 0; i < n; i++) {
          cv[i] = f(av[i], bv[i]);
        }
      } else {
        for (var j = 0; j < n; j++) {
          cv[j] = _iterate(f, level + 1, s, s[level + 1], av[j], bv[j]);
        }
      }
      return cv;
    }
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm03.js
  var name25 = "algorithm03";
  var dependencies26 = ["typed"];
  var createAlgorithm03 = /* @__PURE__ */ factory(name25, dependencies26, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return function algorithm03(denseMatrix, sparseMatrix, callback, inverse) {
      var adata = denseMatrix._data;
      var asize = denseMatrix._size;
      var adt = denseMatrix._datatype;
      var bvalues = sparseMatrix._values;
      var bindex = sparseMatrix._index;
      var bptr = sparseMatrix._ptr;
      var bsize = sparseMatrix._size;
      var bdt = sparseMatrix._datatype;
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      if (asize[0] !== bsize[0] || asize[1] !== bsize[1]) {
        throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
      }
      if (!bvalues) {
        throw new Error("Cannot perform operation on Dense Matrix and Pattern Sparse Matrix");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var zero = 0;
      var cf = callback;
      if (typeof adt === "string" && adt === bdt) {
        dt = adt;
        zero = typed2.convert(0, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cdata = [];
      for (var z = 0; z < rows; z++) {
        cdata[z] = [];
      }
      var x = [];
      var w = [];
      for (var j = 0; j < columns; j++) {
        var mark = j + 1;
        for (var k0 = bptr[j], k1 = bptr[j + 1], k = k0; k < k1; k++) {
          var i = bindex[k];
          x[i] = inverse ? cf(bvalues[k], adata[i][j]) : cf(adata[i][j], bvalues[k]);
          w[i] = mark;
        }
        for (var y = 0; y < rows; y++) {
          if (w[y] === mark) {
            cdata[y][j] = x[y];
          } else {
            cdata[y][j] = inverse ? cf(zero, adata[y][j]) : cf(adata[y][j], zero);
          }
        }
      }
      return denseMatrix.createDenseMatrix({
        data: cdata,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm05.js
  var name26 = "algorithm05";
  var dependencies27 = ["typed", "equalScalar"];
  var createAlgorithm05 = /* @__PURE__ */ factory(name26, dependencies27, (_ref) => {
    var {
      typed: typed2,
      equalScalar: equalScalar2
    } = _ref;
    return function algorithm05(a, b, callback) {
      var avalues = a._values;
      var aindex = a._index;
      var aptr = a._ptr;
      var asize = a._size;
      var adt = a._datatype;
      var bvalues = b._values;
      var bindex = b._index;
      var bptr = b._ptr;
      var bsize = b._size;
      var bdt = b._datatype;
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      if (asize[0] !== bsize[0] || asize[1] !== bsize[1]) {
        throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var eq = equalScalar2;
      var zero = 0;
      var cf = callback;
      if (typeof adt === "string" && adt === bdt) {
        dt = adt;
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cvalues = avalues && bvalues ? [] : void 0;
      var cindex = [];
      var cptr = [];
      var xa = cvalues ? [] : void 0;
      var xb = cvalues ? [] : void 0;
      var wa = [];
      var wb = [];
      var i, j, k, k1;
      for (j = 0; j < columns; j++) {
        cptr[j] = cindex.length;
        var mark = j + 1;
        for (k = aptr[j], k1 = aptr[j + 1]; k < k1; k++) {
          i = aindex[k];
          cindex.push(i);
          wa[i] = mark;
          if (xa) {
            xa[i] = avalues[k];
          }
        }
        for (k = bptr[j], k1 = bptr[j + 1]; k < k1; k++) {
          i = bindex[k];
          if (wa[i] !== mark) {
            cindex.push(i);
          }
          wb[i] = mark;
          if (xb) {
            xb[i] = bvalues[k];
          }
        }
        if (cvalues) {
          k = cptr[j];
          while (k < cindex.length) {
            i = cindex[k];
            var wai = wa[i];
            var wbi = wb[i];
            if (wai === mark || wbi === mark) {
              var va = wai === mark ? xa[i] : zero;
              var vb = wbi === mark ? xb[i] : zero;
              var vc = cf(va, vb);
              if (!eq(vc, zero)) {
                cvalues.push(vc);
                k++;
              } else {
                cindex.splice(k, 1);
              }
            }
          }
        }
      }
      cptr[columns] = cindex.length;
      return a.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm12.js
  var name27 = "algorithm12";
  var dependencies28 = ["typed", "DenseMatrix"];
  var createAlgorithm12 = /* @__PURE__ */ factory(name27, dependencies28, (_ref) => {
    var {
      typed: typed2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    return function algorithm12(s, b, callback, inverse) {
      var avalues = s._values;
      var aindex = s._index;
      var aptr = s._ptr;
      var asize = s._size;
      var adt = s._datatype;
      if (!avalues) {
        throw new Error("Cannot perform operation on Pattern Sparse Matrix and Scalar value");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var cf = callback;
      if (typeof adt === "string") {
        dt = adt;
        b = typed2.convert(b, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var cdata = [];
      var x = [];
      var w = [];
      for (var j = 0; j < columns; j++) {
        var mark = j + 1;
        for (var k0 = aptr[j], k1 = aptr[j + 1], k = k0; k < k1; k++) {
          var r = aindex[k];
          x[r] = avalues[k];
          w[r] = mark;
        }
        for (var i = 0; i < rows; i++) {
          if (j === 0) {
            cdata[i] = [];
          }
          if (w[i] === mark) {
            cdata[i][j] = inverse ? cf(b, x[i]) : cf(x[i], b);
          } else {
            cdata[i][j] = inverse ? cf(b, 0) : cf(0, b);
          }
        }
      }
      return new DenseMatrix2({
        data: cdata,
        size: [rows, columns],
        datatype: dt
      });
    };
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/multiplyScalar.js
  var name28 = "multiplyScalar";
  var dependencies29 = ["typed"];
  var createMultiplyScalar = /* @__PURE__ */ factory(name28, dependencies29, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2("multiplyScalar", {
      "number, number": multiplyNumber,
      "Complex, Complex": function ComplexComplex(x, y) {
        return x.mul(y);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.times(y);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.mul(y);
      },
      "number | Fraction | BigNumber | Complex, Unit": function numberFractionBigNumberComplexUnit(x, y) {
        var res = y.clone();
        res.value = res.value === null ? res._normalize(x) : this(res.value, x);
        return res;
      },
      "Unit, number | Fraction | BigNumber | Complex": function UnitNumberFractionBigNumberComplex(x, y) {
        var res = x.clone();
        res.value = res.value === null ? res._normalize(y) : this(res.value, y);
        return res;
      },
      "Unit, Unit": function UnitUnit(x, y) {
        return x.multiply(y);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/multiply.js
  var name29 = "multiply";
  var dependencies30 = ["typed", "matrix", "addScalar", "multiplyScalar", "equalScalar", "dot"];
  var createMultiply = /* @__PURE__ */ factory(name29, dependencies30, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      addScalar: addScalar2,
      multiplyScalar: multiplyScalar2,
      equalScalar: equalScalar2,
      dot: dot2
    } = _ref;
    var algorithm11 = createAlgorithm11({
      typed: typed2,
      equalScalar: equalScalar2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    function _validateMatrixDimensions(size1, size2) {
      switch (size1.length) {
        case 1:
          switch (size2.length) {
            case 1:
              if (size1[0] !== size2[0]) {
                throw new RangeError("Dimension mismatch in multiplication. Vectors must have the same length");
              }
              break;
            case 2:
              if (size1[0] !== size2[0]) {
                throw new RangeError("Dimension mismatch in multiplication. Vector length (" + size1[0] + ") must match Matrix rows (" + size2[0] + ")");
              }
              break;
            default:
              throw new Error("Can only multiply a 1 or 2 dimensional matrix (Matrix B has " + size2.length + " dimensions)");
          }
          break;
        case 2:
          switch (size2.length) {
            case 1:
              if (size1[1] !== size2[0]) {
                throw new RangeError("Dimension mismatch in multiplication. Matrix columns (" + size1[1] + ") must match Vector length (" + size2[0] + ")");
              }
              break;
            case 2:
              if (size1[1] !== size2[0]) {
                throw new RangeError("Dimension mismatch in multiplication. Matrix A columns (" + size1[1] + ") must match Matrix B rows (" + size2[0] + ")");
              }
              break;
            default:
              throw new Error("Can only multiply a 1 or 2 dimensional matrix (Matrix B has " + size2.length + " dimensions)");
          }
          break;
        default:
          throw new Error("Can only multiply a 1 or 2 dimensional matrix (Matrix A has " + size1.length + " dimensions)");
      }
    }
    function _multiplyVectorVector(a, b, n) {
      if (n === 0) {
        throw new Error("Cannot multiply two empty vectors");
      }
      return dot2(a, b);
    }
    function _multiplyVectorMatrix(a, b) {
      if (b.storage() !== "dense") {
        throw new Error("Support for SparseMatrix not implemented");
      }
      return _multiplyVectorDenseMatrix(a, b);
    }
    function _multiplyVectorDenseMatrix(a, b) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var bdata = b._data;
      var bsize = b._size;
      var bdt = b._datatype;
      var alength = asize[0];
      var bcolumns = bsize[1];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
      }
      var c = [];
      for (var j = 0; j < bcolumns; j++) {
        var sum3 = mf(adata[0], bdata[0][j]);
        for (var i = 1; i < alength; i++) {
          sum3 = af(sum3, mf(adata[i], bdata[i][j]));
        }
        c[j] = sum3;
      }
      return a.createDenseMatrix({
        data: c,
        size: [bcolumns],
        datatype: dt
      });
    }
    var _multiplyMatrixVector = typed2("_multiplyMatrixVector", {
      "DenseMatrix, any": _multiplyDenseMatrixVector,
      "SparseMatrix, any": _multiplySparseMatrixVector
    });
    var _multiplyMatrixMatrix = typed2("_multiplyMatrixMatrix", {
      "DenseMatrix, DenseMatrix": _multiplyDenseMatrixDenseMatrix,
      "DenseMatrix, SparseMatrix": _multiplyDenseMatrixSparseMatrix,
      "SparseMatrix, DenseMatrix": _multiplySparseMatrixDenseMatrix,
      "SparseMatrix, SparseMatrix": _multiplySparseMatrixSparseMatrix
    });
    function _multiplyDenseMatrixVector(a, b) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var bdata = b._data;
      var bdt = b._datatype;
      var arows = asize[0];
      var acolumns = asize[1];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
      }
      var c = [];
      for (var i = 0; i < arows; i++) {
        var row = adata[i];
        var sum3 = mf(row[0], bdata[0]);
        for (var j = 1; j < acolumns; j++) {
          sum3 = af(sum3, mf(row[j], bdata[j]));
        }
        c[i] = sum3;
      }
      return a.createDenseMatrix({
        data: c,
        size: [arows],
        datatype: dt
      });
    }
    function _multiplyDenseMatrixDenseMatrix(a, b) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var bdata = b._data;
      var bsize = b._size;
      var bdt = b._datatype;
      var arows = asize[0];
      var acolumns = asize[1];
      var bcolumns = bsize[1];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
      }
      var c = [];
      for (var i = 0; i < arows; i++) {
        var row = adata[i];
        c[i] = [];
        for (var j = 0; j < bcolumns; j++) {
          var sum3 = mf(row[0], bdata[0][j]);
          for (var x = 1; x < acolumns; x++) {
            sum3 = af(sum3, mf(row[x], bdata[x][j]));
          }
          c[i][j] = sum3;
        }
      }
      return a.createDenseMatrix({
        data: c,
        size: [arows, bcolumns],
        datatype: dt
      });
    }
    function _multiplyDenseMatrixSparseMatrix(a, b) {
      var adata = a._data;
      var asize = a._size;
      var adt = a._datatype;
      var bvalues = b._values;
      var bindex = b._index;
      var bptr = b._ptr;
      var bsize = b._size;
      var bdt = b._datatype;
      if (!bvalues) {
        throw new Error("Cannot multiply Dense Matrix times Pattern only Matrix");
      }
      var arows = asize[0];
      var bcolumns = bsize[1];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      var eq = equalScalar2;
      var zero = 0;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
      }
      var cvalues = [];
      var cindex = [];
      var cptr = [];
      var c = b.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [arows, bcolumns],
        datatype: dt
      });
      for (var jb = 0; jb < bcolumns; jb++) {
        cptr[jb] = cindex.length;
        var kb0 = bptr[jb];
        var kb1 = bptr[jb + 1];
        if (kb1 > kb0) {
          var last = 0;
          for (var i = 0; i < arows; i++) {
            var mark = i + 1;
            var cij = void 0;
            for (var kb = kb0; kb < kb1; kb++) {
              var ib = bindex[kb];
              if (last !== mark) {
                cij = mf(adata[i][ib], bvalues[kb]);
                last = mark;
              } else {
                cij = af(cij, mf(adata[i][ib], bvalues[kb]));
              }
            }
            if (last === mark && !eq(cij, zero)) {
              cindex.push(i);
              cvalues.push(cij);
            }
          }
        }
      }
      cptr[bcolumns] = cindex.length;
      return c;
    }
    function _multiplySparseMatrixVector(a, b) {
      var avalues = a._values;
      var aindex = a._index;
      var aptr = a._ptr;
      var adt = a._datatype;
      if (!avalues) {
        throw new Error("Cannot multiply Pattern only Matrix times Dense Matrix");
      }
      var bdata = b._data;
      var bdt = b._datatype;
      var arows = a._size[0];
      var brows = b._size[0];
      var cvalues = [];
      var cindex = [];
      var cptr = [];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      var eq = equalScalar2;
      var zero = 0;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
      }
      var x = [];
      var w = [];
      cptr[0] = 0;
      for (var ib = 0; ib < brows; ib++) {
        var vbi = bdata[ib];
        if (!eq(vbi, zero)) {
          for (var ka0 = aptr[ib], ka1 = aptr[ib + 1], ka = ka0; ka < ka1; ka++) {
            var ia = aindex[ka];
            if (!w[ia]) {
              w[ia] = true;
              cindex.push(ia);
              x[ia] = mf(vbi, avalues[ka]);
            } else {
              x[ia] = af(x[ia], mf(vbi, avalues[ka]));
            }
          }
        }
      }
      for (var p1 = cindex.length, p = 0; p < p1; p++) {
        var ic = cindex[p];
        cvalues[p] = x[ic];
      }
      cptr[1] = cindex.length;
      return a.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [arows, 1],
        datatype: dt
      });
    }
    function _multiplySparseMatrixDenseMatrix(a, b) {
      var avalues = a._values;
      var aindex = a._index;
      var aptr = a._ptr;
      var adt = a._datatype;
      if (!avalues) {
        throw new Error("Cannot multiply Pattern only Matrix times Dense Matrix");
      }
      var bdata = b._data;
      var bdt = b._datatype;
      var arows = a._size[0];
      var brows = b._size[0];
      var bcolumns = b._size[1];
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      var eq = equalScalar2;
      var zero = 0;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
        eq = typed2.find(equalScalar2, [dt, dt]);
        zero = typed2.convert(0, dt);
      }
      var cvalues = [];
      var cindex = [];
      var cptr = [];
      var c = a.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [arows, bcolumns],
        datatype: dt
      });
      var x = [];
      var w = [];
      for (var jb = 0; jb < bcolumns; jb++) {
        cptr[jb] = cindex.length;
        var mark = jb + 1;
        for (var ib = 0; ib < brows; ib++) {
          var vbij = bdata[ib][jb];
          if (!eq(vbij, zero)) {
            for (var ka0 = aptr[ib], ka1 = aptr[ib + 1], ka = ka0; ka < ka1; ka++) {
              var ia = aindex[ka];
              if (w[ia] !== mark) {
                w[ia] = mark;
                cindex.push(ia);
                x[ia] = mf(vbij, avalues[ka]);
              } else {
                x[ia] = af(x[ia], mf(vbij, avalues[ka]));
              }
            }
          }
        }
        for (var p0 = cptr[jb], p1 = cindex.length, p = p0; p < p1; p++) {
          var ic = cindex[p];
          cvalues[p] = x[ic];
        }
      }
      cptr[bcolumns] = cindex.length;
      return c;
    }
    function _multiplySparseMatrixSparseMatrix(a, b) {
      var avalues = a._values;
      var aindex = a._index;
      var aptr = a._ptr;
      var adt = a._datatype;
      var bvalues = b._values;
      var bindex = b._index;
      var bptr = b._ptr;
      var bdt = b._datatype;
      var arows = a._size[0];
      var bcolumns = b._size[1];
      var values = avalues && bvalues;
      var dt;
      var af = addScalar2;
      var mf = multiplyScalar2;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        dt = adt;
        af = typed2.find(addScalar2, [dt, dt]);
        mf = typed2.find(multiplyScalar2, [dt, dt]);
      }
      var cvalues = values ? [] : void 0;
      var cindex = [];
      var cptr = [];
      var c = a.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [arows, bcolumns],
        datatype: dt
      });
      var x = values ? [] : void 0;
      var w = [];
      var ka, ka0, ka1, kb, kb0, kb1, ia, ib;
      for (var jb = 0; jb < bcolumns; jb++) {
        cptr[jb] = cindex.length;
        var mark = jb + 1;
        for (kb0 = bptr[jb], kb1 = bptr[jb + 1], kb = kb0; kb < kb1; kb++) {
          ib = bindex[kb];
          if (values) {
            for (ka0 = aptr[ib], ka1 = aptr[ib + 1], ka = ka0; ka < ka1; ka++) {
              ia = aindex[ka];
              if (w[ia] !== mark) {
                w[ia] = mark;
                cindex.push(ia);
                x[ia] = mf(bvalues[kb], avalues[ka]);
              } else {
                x[ia] = af(x[ia], mf(bvalues[kb], avalues[ka]));
              }
            }
          } else {
            for (ka0 = aptr[ib], ka1 = aptr[ib + 1], ka = ka0; ka < ka1; ka++) {
              ia = aindex[ka];
              if (w[ia] !== mark) {
                w[ia] = mark;
                cindex.push(ia);
              }
            }
          }
        }
        if (values) {
          for (var p0 = cptr[jb], p1 = cindex.length, p = p0; p < p1; p++) {
            var ic = cindex[p];
            cvalues[p] = x[ic];
          }
        }
      }
      cptr[bcolumns] = cindex.length;
      return c;
    }
    return typed2(name29, extend({
      // we extend the signatures of multiplyScalar with signatures dealing with matrices
      "Array, Array": function ArrayArray(x, y) {
        _validateMatrixDimensions(arraySize(x), arraySize(y));
        var m = this(matrix2(x), matrix2(y));
        return isMatrix(m) ? m.valueOf() : m;
      },
      "Matrix, Matrix": function MatrixMatrix(x, y) {
        var xsize = x.size();
        var ysize = y.size();
        _validateMatrixDimensions(xsize, ysize);
        if (xsize.length === 1) {
          if (ysize.length === 1) {
            return _multiplyVectorVector(x, y, xsize[0]);
          }
          return _multiplyVectorMatrix(x, y);
        }
        if (ysize.length === 1) {
          return _multiplyMatrixVector(x, y);
        }
        return _multiplyMatrixMatrix(x, y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x, y.storage()), y);
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm11(x, y, multiplyScalar2, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, multiplyScalar2, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm11(y, x, multiplyScalar2, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, multiplyScalar2, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, multiplyScalar2, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, multiplyScalar2, true).valueOf();
      },
      "any, any": multiplyScalar2,
      "any, any, ...any": function anyAnyAny(x, y, rest) {
        var result = this(x, y);
        for (var i = 0; i < rest.length; i++) {
          result = this(result, rest[i]);
        }
        return result;
      }
    }, multiplyScalar2.signatures));
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/sign.js
  var name30 = "sign";
  var dependencies31 = ["typed", "BigNumber", "Fraction", "complex"];
  var createSign = /* @__PURE__ */ factory(name30, dependencies31, (_ref) => {
    var {
      typed: typed2,
      BigNumber: _BigNumber,
      complex: complex2,
      Fraction: _Fraction
    } = _ref;
    return typed2(name30, {
      number: signNumber,
      Complex: function Complex3(x) {
        return x.im === 0 ? complex2(signNumber(x.re)) : x.sign();
      },
      BigNumber: function BigNumber2(x) {
        return new _BigNumber(x.cmp(0));
      },
      Fraction: function Fraction3(x) {
        return new _Fraction(x.s, 1);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      },
      Unit: function Unit(x) {
        return this(x.value);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/sqrt.js
  var name31 = "sqrt";
  var dependencies32 = ["config", "typed", "Complex"];
  var createSqrt = /* @__PURE__ */ factory(name31, dependencies32, (_ref) => {
    var {
      config: config4,
      typed: typed2,
      Complex: Complex3
    } = _ref;
    return typed2("sqrt", {
      number: _sqrtNumber,
      Complex: function Complex4(x) {
        return x.sqrt();
      },
      BigNumber: function BigNumber2(x) {
        if (!x.isNegative() || config4.predictable) {
          return x.sqrt();
        } else {
          return _sqrtNumber(x.toNumber());
        }
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      },
      Unit: function Unit(x) {
        return x.pow(0.5);
      }
    });
    function _sqrtNumber(x) {
      if (isNaN(x)) {
        return NaN;
      } else if (x >= 0 || config4.predictable) {
        return Math.sqrt(x);
      } else {
        return new Complex3(x, 0).sqrt();
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/subtract.js
  var name32 = "subtract";
  var dependencies33 = ["typed", "matrix", "equalScalar", "addScalar", "unaryMinus", "DenseMatrix"];
  var createSubtract = /* @__PURE__ */ factory(name32, dependencies33, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      equalScalar: equalScalar2,
      addScalar: addScalar2,
      unaryMinus: unaryMinus2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm01 = createAlgorithm01({
      typed: typed2
    });
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm05 = createAlgorithm05({
      typed: typed2,
      equalScalar: equalScalar2
    });
    var algorithm10 = createAlgorithm10({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name32, {
      "number, number": function numberNumber(x, y) {
        return x - y;
      },
      "Complex, Complex": function ComplexComplex(x, y) {
        return x.sub(y);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.minus(y);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.sub(y);
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (x.value === null) {
          throw new Error("Parameter x contains a unit with undefined value");
        }
        if (y.value === null) {
          throw new Error("Parameter y contains a unit with undefined value");
        }
        if (!x.equalBase(y)) {
          throw new Error("Units do not match");
        }
        var res = x.clone();
        res.value = this(res.value, y.value);
        res.fixPrefix = false;
        return res;
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        checkEqualDimensions(x, y);
        return algorithm05(x, y, this);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        checkEqualDimensions(x, y);
        return algorithm03(y, x, this, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        checkEqualDimensions(x, y);
        return algorithm01(x, y, this, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        checkEqualDimensions(x, y);
        return algorithm13(x, y, this);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm10(x, unaryMinus2(y), addScalar2);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, this);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm10(y, x, this, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, this, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, this, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, this, true).valueOf();
      }
    });
  });
  function checkEqualDimensions(x, y) {
    var xsize = x.size();
    var ysize = y.size();
    if (xsize.length !== ysize.length) {
      throw new DimensionError(xsize.length, ysize.length);
    }
  }

  // node_modules/mathjs/lib/esm/type/matrix/utils/algorithm07.js
  var name33 = "algorithm07";
  var dependencies34 = ["typed", "DenseMatrix"];
  var createAlgorithm07 = /* @__PURE__ */ factory(name33, dependencies34, (_ref) => {
    var {
      typed: typed2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    return function algorithm07(a, b, callback) {
      var asize = a._size;
      var adt = a._datatype;
      var bsize = b._size;
      var bdt = b._datatype;
      if (asize.length !== bsize.length) {
        throw new DimensionError(asize.length, bsize.length);
      }
      if (asize[0] !== bsize[0] || asize[1] !== bsize[1]) {
        throw new RangeError("Dimension mismatch. Matrix A (" + asize + ") must match Matrix B (" + bsize + ")");
      }
      var rows = asize[0];
      var columns = asize[1];
      var dt;
      var zero = 0;
      var cf = callback;
      if (typeof adt === "string" && adt === bdt) {
        dt = adt;
        zero = typed2.convert(0, dt);
        cf = typed2.find(callback, [dt, dt]);
      }
      var i, j;
      var cdata = [];
      for (i = 0; i < rows; i++) {
        cdata[i] = [];
      }
      var xa = [];
      var xb = [];
      var wa = [];
      var wb = [];
      for (j = 0; j < columns; j++) {
        var mark = j + 1;
        _scatter(a, j, wa, xa, mark);
        _scatter(b, j, wb, xb, mark);
        for (i = 0; i < rows; i++) {
          var va = wa[i] === mark ? xa[i] : zero;
          var vb = wb[i] === mark ? xb[i] : zero;
          cdata[i][j] = cf(va, vb);
        }
      }
      return new DenseMatrix2({
        data: cdata,
        size: [rows, columns],
        datatype: dt
      });
    };
    function _scatter(m, j, w, x, mark) {
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      for (var k = ptr[j], k1 = ptr[j + 1]; k < k1; k++) {
        var i = index2[k];
        w[i] = mark;
        x[i] = values[k];
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/complex/conj.js
  var name34 = "conj";
  var dependencies35 = ["typed"];
  var createConj = /* @__PURE__ */ factory(name34, dependencies35, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name34, {
      number: function number2(x) {
        return x;
      },
      BigNumber: function BigNumber2(x) {
        return x;
      },
      Complex: function Complex3(x) {
        return x.conjugate();
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/complex/im.js
  var name35 = "im";
  var dependencies36 = ["typed"];
  var createIm = /* @__PURE__ */ factory(name35, dependencies36, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name35, {
      number: function number2(x) {
        return 0;
      },
      BigNumber: function BigNumber2(x) {
        return x.mul(0);
      },
      Fraction: function Fraction3(x) {
        return x.mul(0);
      },
      Complex: function Complex3(x) {
        return x.im;
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/complex/re.js
  var name36 = "re";
  var dependencies37 = ["typed"];
  var createRe = /* @__PURE__ */ factory(name36, dependencies37, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name36, {
      number: function number2(x) {
        return x;
      },
      BigNumber: function BigNumber2(x) {
        return x;
      },
      Fraction: function Fraction3(x) {
        return x;
      },
      Complex: function Complex3(x) {
        return x.re;
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/matrix/concat.js
  var name37 = "concat";
  var dependencies38 = ["typed", "matrix", "isInteger"];
  var createConcat = /* @__PURE__ */ factory(name37, dependencies38, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      isInteger: isInteger3
    } = _ref;
    return typed2(name37, {
      // TODO: change signature to '...Array | Matrix, dim?' when supported
      "...Array | Matrix | number | BigNumber": function ArrayMatrixNumberBigNumber(args) {
        var i;
        var len = args.length;
        var dim = -1;
        var prevDim;
        var asMatrix = false;
        var matrices = [];
        for (i = 0; i < len; i++) {
          var arg = args[i];
          if (isMatrix(arg)) {
            asMatrix = true;
          }
          if (isNumber(arg) || isBigNumber(arg)) {
            if (i !== len - 1) {
              throw new Error("Dimension must be specified as last argument");
            }
            prevDim = dim;
            dim = arg.valueOf();
            if (!isInteger3(dim)) {
              throw new TypeError("Integer number expected for dimension");
            }
            if (dim < 0 || i > 0 && dim > prevDim) {
              throw new IndexError(dim, prevDim + 1);
            }
          } else {
            var m = clone(arg).valueOf();
            var size2 = arraySize(m);
            matrices[i] = m;
            prevDim = dim;
            dim = size2.length - 1;
            if (i > 0 && dim !== prevDim) {
              throw new DimensionError(prevDim + 1, dim + 1);
            }
          }
        }
        if (matrices.length === 0) {
          throw new SyntaxError("At least one matrix expected");
        }
        var res = matrices.shift();
        while (matrices.length) {
          res = _concat(res, matrices.shift(), dim, 0);
        }
        return asMatrix ? matrix2(res) : res;
      },
      "...string": function string(args) {
        return args.join("");
      }
    });
  });
  function _concat(a, b, concatDim, dim) {
    if (dim < concatDim) {
      if (a.length !== b.length) {
        throw new DimensionError(a.length, b.length);
      }
      var c = [];
      for (var i = 0; i < a.length; i++) {
        c[i] = _concat(a[i], b[i], concatDim, dim + 1);
      }
      return c;
    } else {
      return a.concat(b);
    }
  }

  // node_modules/mathjs/lib/esm/function/matrix/column.js
  var name38 = "column";
  var dependencies39 = ["typed", "Index", "matrix", "range"];
  var createColumn = /* @__PURE__ */ factory(name38, dependencies39, (_ref) => {
    var {
      typed: typed2,
      Index: Index2,
      matrix: matrix2,
      range: range2
    } = _ref;
    return typed2(name38, {
      "Matrix, number": _column,
      "Array, number": function ArrayNumber(value, column2) {
        return _column(matrix2(clone(value)), column2).valueOf();
      }
    });
    function _column(value, column2) {
      if (value.size().length !== 2) {
        throw new Error("Only two dimensional matrix is supported");
      }
      validateIndex(column2, value.size()[1]);
      var rowRange = range2(0, value.size()[0]);
      var index2 = new Index2(rowRange, column2);
      return value.subset(index2);
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/diag.js
  var name39 = "diag";
  var dependencies40 = ["typed", "matrix", "DenseMatrix", "SparseMatrix"];
  var createDiag = /* @__PURE__ */ factory(name39, dependencies40, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      DenseMatrix: DenseMatrix2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    return typed2(name39, {
      // FIXME: simplify this huge amount of signatures as soon as typed-function supports optional arguments
      Array: function Array2(x) {
        return _diag(x, 0, arraySize(x), null);
      },
      "Array, number": function ArrayNumber(x, k) {
        return _diag(x, k, arraySize(x), null);
      },
      "Array, BigNumber": function ArrayBigNumber(x, k) {
        return _diag(x, k.toNumber(), arraySize(x), null);
      },
      "Array, string": function ArrayString(x, format4) {
        return _diag(x, 0, arraySize(x), format4);
      },
      "Array, number, string": function ArrayNumberString(x, k, format4) {
        return _diag(x, k, arraySize(x), format4);
      },
      "Array, BigNumber, string": function ArrayBigNumberString(x, k, format4) {
        return _diag(x, k.toNumber(), arraySize(x), format4);
      },
      Matrix: function Matrix2(x) {
        return _diag(x, 0, x.size(), x.storage());
      },
      "Matrix, number": function MatrixNumber(x, k) {
        return _diag(x, k, x.size(), x.storage());
      },
      "Matrix, BigNumber": function MatrixBigNumber(x, k) {
        return _diag(x, k.toNumber(), x.size(), x.storage());
      },
      "Matrix, string": function MatrixString(x, format4) {
        return _diag(x, 0, x.size(), format4);
      },
      "Matrix, number, string": function MatrixNumberString(x, k, format4) {
        return _diag(x, k, x.size(), format4);
      },
      "Matrix, BigNumber, string": function MatrixBigNumberString(x, k, format4) {
        return _diag(x, k.toNumber(), x.size(), format4);
      }
    });
    function _diag(x, k, size2, format4) {
      if (!isInteger(k)) {
        throw new TypeError("Second parameter in function diag must be an integer");
      }
      var kSuper = k > 0 ? k : 0;
      var kSub = k < 0 ? -k : 0;
      switch (size2.length) {
        case 1:
          return _createDiagonalMatrix(x, k, format4, size2[0], kSub, kSuper);
        case 2:
          return _getDiagonal(x, k, format4, size2, kSub, kSuper);
      }
      throw new RangeError("Matrix for function diag must be 2 dimensional");
    }
    function _createDiagonalMatrix(x, k, format4, l, kSub, kSuper) {
      var ms = [l + kSub, l + kSuper];
      if (format4 && format4 !== "sparse" && format4 !== "dense") {
        throw new TypeError("Unknown matrix type ".concat(format4, '"'));
      }
      var m = format4 === "sparse" ? SparseMatrix2.diagonal(ms, x, k) : DenseMatrix2.diagonal(ms, x, k);
      return format4 !== null ? m : m.valueOf();
    }
    function _getDiagonal(x, k, format4, s, kSub, kSuper) {
      if (isMatrix(x)) {
        var dm = x.diagonal(k);
        if (format4 !== null) {
          if (format4 !== dm.storage()) {
            return matrix2(dm, format4);
          }
          return dm;
        }
        return dm.valueOf();
      }
      var n = Math.min(s[0] - kSub, s[1] - kSuper);
      var vector = [];
      for (var i = 0; i < n; i++) {
        vector[i] = x[i + kSub][i + kSuper];
      }
      return format4 !== null ? matrix2(vector) : vector;
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/flatten.js
  var name40 = "flatten";
  var dependencies41 = ["typed", "matrix"];
  var createFlatten = /* @__PURE__ */ factory(name40, dependencies41, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2
    } = _ref;
    return typed2(name40, {
      Array: function Array2(x) {
        return flatten(clone(x));
      },
      Matrix: function Matrix2(x) {
        var flat = flatten(clone(x.toArray()));
        return matrix2(flat);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/matrix/identity.js
  var name41 = "identity";
  var dependencies42 = ["typed", "config", "matrix", "BigNumber", "DenseMatrix", "SparseMatrix"];
  var createIdentity = /* @__PURE__ */ factory(name41, dependencies42, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      BigNumber: BigNumber2,
      DenseMatrix: DenseMatrix2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    return typed2(name41, {
      "": function _() {
        return config4.matrix === "Matrix" ? matrix2([]) : [];
      },
      string: function string(format4) {
        return matrix2(format4);
      },
      "number | BigNumber": function numberBigNumber(rows) {
        return _identity(rows, rows, config4.matrix === "Matrix" ? "dense" : void 0);
      },
      "number | BigNumber, string": function numberBigNumberString(rows, format4) {
        return _identity(rows, rows, format4);
      },
      "number | BigNumber, number | BigNumber": function numberBigNumberNumberBigNumber(rows, cols) {
        return _identity(rows, cols, config4.matrix === "Matrix" ? "dense" : void 0);
      },
      "number | BigNumber, number | BigNumber, string": function numberBigNumberNumberBigNumberString(rows, cols, format4) {
        return _identity(rows, cols, format4);
      },
      Array: function Array2(size2) {
        return _identityVector(size2);
      },
      "Array, string": function ArrayString(size2, format4) {
        return _identityVector(size2, format4);
      },
      Matrix: function Matrix2(size2) {
        return _identityVector(size2.valueOf(), size2.storage());
      },
      "Matrix, string": function MatrixString(size2, format4) {
        return _identityVector(size2.valueOf(), format4);
      }
    });
    function _identityVector(size2, format4) {
      switch (size2.length) {
        case 0:
          return format4 ? matrix2(format4) : [];
        case 1:
          return _identity(size2[0], size2[0], format4);
        case 2:
          return _identity(size2[0], size2[1], format4);
        default:
          throw new Error("Vector containing two values expected");
      }
    }
    function _identity(rows, cols, format4) {
      var Big = isBigNumber(rows) || isBigNumber(cols) ? BigNumber2 : null;
      if (isBigNumber(rows)) rows = rows.toNumber();
      if (isBigNumber(cols)) cols = cols.toNumber();
      if (!isInteger(rows) || rows < 1) {
        throw new Error("Parameters in function identity must be positive integers");
      }
      if (!isInteger(cols) || cols < 1) {
        throw new Error("Parameters in function identity must be positive integers");
      }
      var one = Big ? new BigNumber2(1) : 1;
      var defaultValue = Big ? new Big(0) : 0;
      var size2 = [rows, cols];
      if (format4) {
        if (format4 === "sparse") {
          return SparseMatrix2.diagonal(size2, one, 0, defaultValue);
        }
        if (format4 === "dense") {
          return DenseMatrix2.diagonal(size2, one, 0, defaultValue);
        }
        throw new TypeError('Unknown matrix type "'.concat(format4, '"'));
      }
      var res = resize([], size2, defaultValue);
      var minimum = rows < cols ? rows : cols;
      for (var d = 0; d < minimum; d++) {
        res[d][d] = one;
      }
      return res;
    }
  });

  // node_modules/mathjs/lib/esm/utils/noop.js
  function noBignumber() {
    throw new Error('No "bignumber" implementation available');
  }
  function noFraction() {
    throw new Error('No "fraction" implementation available');
  }
  function noMatrix() {
    throw new Error('No "matrix" implementation available');
  }

  // node_modules/mathjs/lib/esm/function/matrix/range.js
  var name42 = "range";
  var dependencies43 = ["typed", "config", "?matrix", "?bignumber", "smaller", "smallerEq", "larger", "largerEq"];
  var createRange = /* @__PURE__ */ factory(name42, dependencies43, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      bignumber: bignumber2,
      smaller: smaller2,
      smallerEq: smallerEq2,
      larger: larger2,
      largerEq: largerEq2
    } = _ref;
    return typed2(name42, {
      // TODO: simplify signatures when typed-function supports default values and optional arguments
      // TODO: a number or boolean should not be converted to string here
      string: _strRange,
      "string, boolean": _strRange,
      "number, number": function numberNumber(start, end) {
        return _out(_rangeEx(start, end, 1));
      },
      "number, number, number": function numberNumberNumber(start, end, step) {
        return _out(_rangeEx(start, end, step));
      },
      "number, number, boolean": function numberNumberBoolean(start, end, includeEnd) {
        return includeEnd ? _out(_rangeInc(start, end, 1)) : _out(_rangeEx(start, end, 1));
      },
      "number, number, number, boolean": function numberNumberNumberBoolean(start, end, step, includeEnd) {
        return includeEnd ? _out(_rangeInc(start, end, step)) : _out(_rangeEx(start, end, step));
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(start, end) {
        var BigNumber2 = start.constructor;
        return _out(_bigRangeEx(start, end, new BigNumber2(1)));
      },
      "BigNumber, BigNumber, BigNumber": function BigNumberBigNumberBigNumber(start, end, step) {
        return _out(_bigRangeEx(start, end, step));
      },
      "BigNumber, BigNumber, boolean": function BigNumberBigNumberBoolean(start, end, includeEnd) {
        var BigNumber2 = start.constructor;
        return includeEnd ? _out(_bigRangeInc(start, end, new BigNumber2(1))) : _out(_bigRangeEx(start, end, new BigNumber2(1)));
      },
      "BigNumber, BigNumber, BigNumber, boolean": function BigNumberBigNumberBigNumberBoolean(start, end, step, includeEnd) {
        return includeEnd ? _out(_bigRangeInc(start, end, step)) : _out(_bigRangeEx(start, end, step));
      }
    });
    function _out(arr) {
      if (config4.matrix === "Matrix") {
        return matrix2 ? matrix2(arr) : noMatrix();
      }
      return arr;
    }
    function _strRange(str, includeEnd) {
      var r = _parse(str);
      if (!r) {
        throw new SyntaxError('String "' + str + '" is no valid range');
      }
      var fn;
      if (config4.number === "BigNumber") {
        if (bignumber2 === void 0) {
          noBignumber();
        }
        fn = includeEnd ? _bigRangeInc : _bigRangeEx;
        return _out(fn(bignumber2(r.start), bignumber2(r.end), bignumber2(r.step)));
      } else {
        fn = includeEnd ? _rangeInc : _rangeEx;
        return _out(fn(r.start, r.end, r.step));
      }
    }
    function _rangeEx(start, end, step) {
      var array = [];
      var x = start;
      if (step > 0) {
        while (smaller2(x, end)) {
          array.push(x);
          x += step;
        }
      } else if (step < 0) {
        while (larger2(x, end)) {
          array.push(x);
          x += step;
        }
      }
      return array;
    }
    function _rangeInc(start, end, step) {
      var array = [];
      var x = start;
      if (step > 0) {
        while (smallerEq2(x, end)) {
          array.push(x);
          x += step;
        }
      } else if (step < 0) {
        while (largerEq2(x, end)) {
          array.push(x);
          x += step;
        }
      }
      return array;
    }
    function _bigRangeEx(start, end, step) {
      var zero = bignumber2(0);
      var array = [];
      var x = start;
      if (step.gt(zero)) {
        while (smaller2(x, end)) {
          array.push(x);
          x = x.plus(step);
        }
      } else if (step.lt(zero)) {
        while (larger2(x, end)) {
          array.push(x);
          x = x.plus(step);
        }
      }
      return array;
    }
    function _bigRangeInc(start, end, step) {
      var zero = bignumber2(0);
      var array = [];
      var x = start;
      if (step.gt(zero)) {
        while (smallerEq2(x, end)) {
          array.push(x);
          x = x.plus(step);
        }
      } else if (step.lt(zero)) {
        while (largerEq2(x, end)) {
          array.push(x);
          x = x.plus(step);
        }
      }
      return array;
    }
    function _parse(str) {
      var args = str.split(":");
      var nums = args.map(function(arg) {
        return Number(arg);
      });
      var invalid = nums.some(function(num) {
        return isNaN(num);
      });
      if (invalid) {
        return null;
      }
      switch (nums.length) {
        case 2:
          return {
            start: nums[0],
            end: nums[1],
            step: 1
          };
        case 3:
          return {
            start: nums[0],
            end: nums[2],
            step: nums[1]
          };
        default:
          return null;
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/reshape.js
  var name43 = "reshape";
  var dependencies44 = ["typed", "isInteger", "matrix"];
  var createReshape = /* @__PURE__ */ factory(name43, dependencies44, (_ref) => {
    var {
      typed: typed2,
      isInteger: isInteger3
    } = _ref;
    return typed2(name43, {
      "Matrix, Array": function MatrixArray(x, sizes) {
        return x.reshape(sizes);
      },
      "Array, Array": function ArrayArray(x, sizes) {
        sizes.forEach(function(size2) {
          if (!isInteger3(size2)) {
            throw new TypeError("Invalid size for dimension: " + size2);
          }
        });
        return reshape(x, sizes);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/matrix/size.js
  var name44 = "size";
  var dependencies45 = ["typed", "config", "?matrix"];
  var createSize = /* @__PURE__ */ factory(name44, dependencies45, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2
    } = _ref;
    return typed2(name44, {
      Matrix: function Matrix2(x) {
        return x.create(x.size());
      },
      Array: arraySize,
      string: function string(x) {
        return config4.matrix === "Array" ? [x.length] : matrix2([x.length]);
      },
      "number | Complex | BigNumber | Unit | boolean | null": function numberComplexBigNumberUnitBooleanNull(x) {
        return config4.matrix === "Array" ? [] : matrix2 ? matrix2([]) : noMatrix();
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/matrix/subset.js
  var name45 = "subset";
  var dependencies46 = ["typed", "matrix"];
  var createSubset = /* @__PURE__ */ factory(name45, dependencies46, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2
    } = _ref;
    return typed2(name45, {
      // get subset
      "Array, Index": function ArrayIndex(value, index2) {
        var m = matrix2(value);
        var subset2 = m.subset(index2);
        return index2.isScalar() ? subset2 : subset2.valueOf();
      },
      "Matrix, Index": function MatrixIndex(value, index2) {
        return value.subset(index2);
      },
      "Object, Index": _getObjectProperty,
      "string, Index": _getSubstring,
      // set subset
      "Array, Index, any": function ArrayIndexAny(value, index2, replacement) {
        return matrix2(clone(value)).subset(index2, replacement, void 0).valueOf();
      },
      "Array, Index, any, any": function ArrayIndexAnyAny(value, index2, replacement, defaultValue) {
        return matrix2(clone(value)).subset(index2, replacement, defaultValue).valueOf();
      },
      "Matrix, Index, any": function MatrixIndexAny(value, index2, replacement) {
        return value.clone().subset(index2, replacement);
      },
      "Matrix, Index, any, any": function MatrixIndexAnyAny(value, index2, replacement, defaultValue) {
        return value.clone().subset(index2, replacement, defaultValue);
      },
      "string, Index, string": _setSubstring,
      "string, Index, string, string": _setSubstring,
      "Object, Index, any": _setObjectProperty
    });
  });
  function _getSubstring(str, index2) {
    if (!isIndex(index2)) {
      throw new TypeError("Index expected");
    }
    if (index2.size().length !== 1) {
      throw new DimensionError(index2.size().length, 1);
    }
    var strLen = str.length;
    validateIndex(index2.min()[0], strLen);
    validateIndex(index2.max()[0], strLen);
    var range2 = index2.dimension(0);
    var substr = "";
    range2.forEach(function(v) {
      substr += str.charAt(v);
    });
    return substr;
  }
  function _setSubstring(str, index2, replacement, defaultValue) {
    if (!index2 || index2.isIndex !== true) {
      throw new TypeError("Index expected");
    }
    if (index2.size().length !== 1) {
      throw new DimensionError(index2.size().length, 1);
    }
    if (defaultValue !== void 0) {
      if (typeof defaultValue !== "string" || defaultValue.length !== 1) {
        throw new TypeError("Single character expected as defaultValue");
      }
    } else {
      defaultValue = " ";
    }
    var range2 = index2.dimension(0);
    var len = range2.size()[0];
    if (len !== replacement.length) {
      throw new DimensionError(range2.size()[0], replacement.length);
    }
    var strLen = str.length;
    validateIndex(index2.min()[0]);
    validateIndex(index2.max()[0]);
    var chars = [];
    for (var i = 0; i < strLen; i++) {
      chars[i] = str.charAt(i);
    }
    range2.forEach(function(v, i2) {
      chars[v] = replacement.charAt(i2[0]);
    });
    if (chars.length > strLen) {
      for (var _i = strLen - 1, _len = chars.length; _i < _len; _i++) {
        if (!chars[_i]) {
          chars[_i] = defaultValue;
        }
      }
    }
    return chars.join("");
  }
  function _getObjectProperty(object, index2) {
    if (index2.size().length !== 1) {
      throw new DimensionError(index2.size(), 1);
    }
    var key = index2.dimension(0);
    if (typeof key !== "string") {
      throw new TypeError("String expected as index to retrieve an object property");
    }
    return getSafeProperty(object, key);
  }
  function _setObjectProperty(object, index2, replacement) {
    if (index2.size().length !== 1) {
      throw new DimensionError(index2.size(), 1);
    }
    var key = index2.dimension(0);
    if (typeof key !== "string") {
      throw new TypeError("String expected as index to retrieve an object property");
    }
    var updated = clone(object);
    setSafeProperty(updated, key, replacement);
    return updated;
  }

  // node_modules/mathjs/lib/esm/function/matrix/transpose.js
  var name46 = "transpose";
  var dependencies47 = ["typed", "matrix"];
  var createTranspose = /* @__PURE__ */ factory(name46, dependencies47, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2
    } = _ref;
    return typed2("transpose", {
      Array: function Array2(x) {
        return this(matrix2(x)).valueOf();
      },
      Matrix: function Matrix2(x) {
        var size2 = x.size();
        var c;
        switch (size2.length) {
          case 1:
            c = x.clone();
            break;
          case 2:
            {
              var rows = size2[0];
              var columns = size2[1];
              if (columns === 0) {
                throw new RangeError("Cannot transpose a 2D matrix with no columns (size: " + format3(size2) + ")");
              }
              switch (x.storage()) {
                case "dense":
                  c = _denseTranspose(x, rows, columns);
                  break;
                case "sparse":
                  c = _sparseTranspose(x, rows, columns);
                  break;
              }
            }
            break;
          default:
            throw new RangeError("Matrix must be a vector or two dimensional (size: " + format3(this._size) + ")");
        }
        return c;
      },
      // scalars
      any: function any(x) {
        return clone(x);
      }
    });
    function _denseTranspose(m, rows, columns) {
      var data = m._data;
      var transposed = [];
      var transposedRow;
      for (var j = 0; j < columns; j++) {
        transposedRow = transposed[j] = [];
        for (var i = 0; i < rows; i++) {
          transposedRow[i] = clone(data[i][j]);
        }
      }
      return m.createDenseMatrix({
        data: transposed,
        size: [columns, rows],
        datatype: m._datatype
      });
    }
    function _sparseTranspose(m, rows, columns) {
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      var cvalues = values ? [] : void 0;
      var cindex = [];
      var cptr = [];
      var w = [];
      for (var x = 0; x < rows; x++) {
        w[x] = 0;
      }
      var p, l, j;
      for (p = 0, l = index2.length; p < l; p++) {
        w[index2[p]]++;
      }
      var sum3 = 0;
      for (var i = 0; i < rows; i++) {
        cptr.push(sum3);
        sum3 += w[i];
        w[i] = cptr[i];
      }
      cptr.push(sum3);
      for (j = 0; j < columns; j++) {
        for (var k0 = ptr[j], k1 = ptr[j + 1], k = k0; k < k1; k++) {
          var q = w[index2[k]]++;
          cindex[q] = j;
          if (values) {
            cvalues[q] = clone(values[k]);
          }
        }
      }
      return m.createSparseMatrix({
        values: cvalues,
        index: cindex,
        ptr: cptr,
        size: [columns, rows],
        datatype: m._datatype
      });
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/ctranspose.js
  var name47 = "ctranspose";
  var dependencies48 = ["typed", "transpose", "conj"];
  var createCtranspose = /* @__PURE__ */ factory(name47, dependencies48, (_ref) => {
    var {
      typed: typed2,
      transpose: transpose2,
      conj: conj2
    } = _ref;
    return typed2(name47, {
      any: function any(x) {
        return conj2(transpose2(x));
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/matrix/zeros.js
  var name48 = "zeros";
  var dependencies49 = ["typed", "config", "matrix", "BigNumber"];
  var createZeros = /* @__PURE__ */ factory(name48, dependencies49, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      BigNumber: BigNumber2
    } = _ref;
    return typed2(name48, {
      "": function _() {
        return config4.matrix === "Array" ? _zeros([]) : _zeros([], "default");
      },
      // math.zeros(m, n, p, ..., format)
      // TODO: more accurate signature '...number | BigNumber, string' as soon as typed-function supports this
      "...number | BigNumber | string": function numberBigNumberString(size2) {
        var last = size2[size2.length - 1];
        if (typeof last === "string") {
          var format4 = size2.pop();
          return _zeros(size2, format4);
        } else if (config4.matrix === "Array") {
          return _zeros(size2);
        } else {
          return _zeros(size2, "default");
        }
      },
      Array: _zeros,
      Matrix: function Matrix2(size2) {
        var format4 = size2.storage();
        return _zeros(size2.valueOf(), format4);
      },
      "Array | Matrix, string": function ArrayMatrixString(size2, format4) {
        return _zeros(size2.valueOf(), format4);
      }
    });
    function _zeros(size2, format4) {
      var hasBigNumbers = _normalize(size2);
      var defaultValue = hasBigNumbers ? new BigNumber2(0) : 0;
      _validate2(size2);
      if (format4) {
        var m = matrix2(format4);
        if (size2.length > 0) {
          return m.resize(size2, defaultValue);
        }
        return m;
      } else {
        var arr = [];
        if (size2.length > 0) {
          return resize(arr, size2, defaultValue);
        }
        return arr;
      }
    }
    function _normalize(size2) {
      var hasBigNumbers = false;
      size2.forEach(function(value, index2, arr) {
        if (isBigNumber(value)) {
          hasBigNumbers = true;
          arr[index2] = value.toNumber();
        }
      });
      return hasBigNumbers;
    }
    function _validate2(size2) {
      size2.forEach(function(value) {
        if (typeof value !== "number" || !isInteger(value) || value < 0) {
          throw new Error("Parameters in function zeros must be positive integers");
        }
      });
    }
  });

  // node_modules/mathjs/lib/esm/function/statistics/utils/improveErrorMessage.js
  function improveErrorMessage(err, fnName, value) {
    var details;
    if (String(err).indexOf("Unexpected type") !== -1) {
      details = arguments.length > 2 ? " (type: " + typeOf(value) + ", value: " + JSON.stringify(value) + ")" : " (type: " + err.data.actual + ")";
      return new TypeError("Cannot calculate " + fnName + ", unexpected type of argument" + details);
    }
    if (String(err).indexOf("complex numbers") !== -1) {
      details = arguments.length > 2 ? " (type: " + typeOf(value) + ", value: " + JSON.stringify(value) + ")" : "";
      return new TypeError("Cannot calculate " + fnName + ", no ordering relation is defined for complex numbers" + details);
    }
    return err;
  }

  // node_modules/mathjs/lib/esm/function/utils/numeric.js
  var name49 = "numeric";
  var dependencies50 = ["number", "?bignumber", "?fraction"];
  var createNumeric = /* @__PURE__ */ factory(name49, dependencies50, (_ref) => {
    var {
      number: _number,
      bignumber: bignumber2,
      fraction: fraction2
    } = _ref;
    var validInputTypes = {
      string: true,
      number: true,
      BigNumber: true,
      Fraction: true
    };
    var validOutputTypes = {
      number: (x) => _number(x),
      BigNumber: bignumber2 ? (x) => bignumber2(x) : noBignumber,
      Fraction: fraction2 ? (x) => fraction2(x) : noFraction
    };
    return function numeric2(value, outputType) {
      var inputType = typeOf(value);
      if (!(inputType in validInputTypes)) {
        throw new TypeError("Cannot convert " + value + ' of type "' + inputType + '"; valid input types are ' + Object.keys(validInputTypes).join(", "));
      }
      if (!(outputType in validOutputTypes)) {
        throw new TypeError("Cannot convert " + value + ' to type "' + outputType + '"; valid output types are ' + Object.keys(validOutputTypes).join(", "));
      }
      if (outputType === inputType) {
        return value;
      } else {
        return validOutputTypes[outputType](value);
      }
    };
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/divideScalar.js
  var name50 = "divideScalar";
  var dependencies51 = ["typed", "numeric"];
  var createDivideScalar = /* @__PURE__ */ factory(name50, dependencies51, (_ref) => {
    var {
      typed: typed2,
      numeric: numeric2
    } = _ref;
    return typed2(name50, {
      "number, number": function numberNumber(x, y) {
        return x / y;
      },
      "Complex, Complex": function ComplexComplex(x, y) {
        return x.div(y);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.div(y);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.div(y);
      },
      "Unit, number | Fraction | BigNumber": function UnitNumberFractionBigNumber(x, y) {
        var res = x.clone();
        var one = numeric2(1, typeOf(y));
        res.value = this(res.value === null ? res._normalize(one) : res.value, y);
        return res;
      },
      "number | Fraction | BigNumber, Unit": function numberFractionBigNumberUnit(x, y) {
        var res = y.clone();
        res = res.pow(-1);
        var one = numeric2(1, typeOf(x));
        res.value = this(x, y.value === null ? y._normalize(one) : y.value);
        return res;
      },
      "Unit, Unit": function UnitUnit(x, y) {
        return x.divide(y);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/pow.js
  var name51 = "pow";
  var dependencies52 = ["typed", "config", "identity", "multiply", "matrix", "fraction", "number", "Complex"];
  var createPow = /* @__PURE__ */ factory(name51, dependencies52, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      identity: identity2,
      multiply: multiply2,
      matrix: matrix2,
      number: number2,
      fraction: fraction2,
      Complex: Complex3
    } = _ref;
    return typed2(name51, {
      "number, number": _pow,
      "Complex, Complex": function ComplexComplex(x, y) {
        return x.pow(y);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        if (y.isInteger() || x >= 0 || config4.predictable) {
          return x.pow(y);
        } else {
          return new Complex3(x.toNumber(), 0).pow(y.toNumber(), 0);
        }
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        var result = x.pow(y);
        if (result != null) {
          return result;
        }
        if (config4.predictable) {
          throw new Error("Result of pow is non-rational and cannot be expressed as a fraction");
        } else {
          return _pow(x.valueOf(), y.valueOf());
        }
      },
      "Array, number": _powArray,
      "Array, BigNumber": function ArrayBigNumber(x, y) {
        return _powArray(x, y.toNumber());
      },
      "Matrix, number": _powMatrix,
      "Matrix, BigNumber": function MatrixBigNumber(x, y) {
        return _powMatrix(x, y.toNumber());
      },
      "Unit, number | BigNumber": function UnitNumberBigNumber(x, y) {
        return x.pow(y);
      }
    });
    function _pow(x, y) {
      if (config4.predictable && !isInteger(y) && x < 0) {
        try {
          var yFrac = fraction2(y);
          var yNum = number2(yFrac);
          if (y === yNum || Math.abs((y - yNum) / y) < 1e-14) {
            if (yFrac.d % 2 === 1) {
              return (yFrac.n % 2 === 0 ? 1 : -1) * Math.pow(-x, y);
            }
          }
        } catch (ex) {
        }
      }
      if (config4.predictable && (x < -1 && y === Infinity || x > -1 && x < 0 && y === -Infinity)) {
        return NaN;
      }
      if (isInteger(y) || x >= 0 || config4.predictable) {
        return powNumber(x, y);
      } else {
        if (x * x < 1 && y === Infinity || x * x > 1 && y === -Infinity) {
          return 0;
        }
        return new Complex3(x, 0).pow(y, 0);
      }
    }
    function _powArray(x, y) {
      if (!isInteger(y) || y < 0) {
        throw new TypeError("For A^b, b must be a positive integer (value is " + y + ")");
      }
      var s = arraySize(x);
      if (s.length !== 2) {
        throw new Error("For A^b, A must be 2 dimensional (A has " + s.length + " dimensions)");
      }
      if (s[0] !== s[1]) {
        throw new Error("For A^b, A must be square (size is " + s[0] + "x" + s[1] + ")");
      }
      var res = identity2(s[0]).valueOf();
      var px = x;
      while (y >= 1) {
        if ((y & 1) === 1) {
          res = multiply2(px, res);
        }
        y >>= 1;
        px = multiply2(px, px);
      }
      return res;
    }
    function _powMatrix(x, y) {
      return matrix2(_powArray(x.valueOf(), y));
    }
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/log.js
  var name52 = "log";
  var dependencies53 = ["config", "typed", "divideScalar", "Complex"];
  var createLog = /* @__PURE__ */ factory(name52, dependencies53, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      divideScalar: divideScalar2,
      Complex: Complex3
    } = _ref;
    return typed2(name52, {
      number: function number2(x) {
        if (x >= 0 || config4.predictable) {
          return logNumber(x);
        } else {
          return new Complex3(x, 0).log();
        }
      },
      Complex: function Complex4(x) {
        return x.log();
      },
      BigNumber: function BigNumber2(x) {
        if (!x.isNegative() || config4.predictable) {
          return x.ln();
        } else {
          return new Complex3(x.toNumber(), 0).log();
        }
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      },
      "any, any": function anyAny(x, base) {
        return divideScalar2(this(x), this(base));
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/algebra/solver/utils/solveValidation.js
  function createSolveValidation(_ref) {
    var {
      DenseMatrix: DenseMatrix2
    } = _ref;
    return function solveValidation(m, b, copy) {
      var mSize = m.size();
      if (mSize.length !== 2) {
        throw new RangeError("Matrix must be two dimensional (size: " + format3(mSize) + ")");
      }
      var rows = mSize[0];
      var columns = mSize[1];
      if (rows !== columns) {
        throw new RangeError("Matrix must be square (size: " + format3(mSize) + ")");
      }
      var data = [];
      if (isMatrix(b)) {
        var bSize = b.size();
        var bdata = b._data;
        if (bSize.length === 1) {
          if (bSize[0] !== rows) {
            throw new RangeError("Dimension mismatch. Matrix columns must match vector length.");
          }
          for (var i = 0; i < rows; i++) {
            data[i] = [bdata[i]];
          }
          return new DenseMatrix2({
            data,
            size: [rows, 1],
            datatype: b._datatype
          });
        }
        if (bSize.length === 2) {
          if (bSize[0] !== rows || bSize[1] !== 1) {
            throw new RangeError("Dimension mismatch. Matrix columns must match vector length.");
          }
          if (isDenseMatrix(b)) {
            if (copy) {
              data = [];
              for (var _i = 0; _i < rows; _i++) {
                data[_i] = [bdata[_i][0]];
              }
              return new DenseMatrix2({
                data,
                size: [rows, 1],
                datatype: b._datatype
              });
            }
            return b;
          }
          if (isSparseMatrix(b)) {
            for (var _i2 = 0; _i2 < rows; _i2++) {
              data[_i2] = [0];
            }
            var values = b._values;
            var index2 = b._index;
            var ptr = b._ptr;
            for (var k1 = ptr[1], k = ptr[0]; k < k1; k++) {
              var _i3 = index2[k];
              data[_i3][0] = values[k];
            }
            return new DenseMatrix2({
              data,
              size: [rows, 1],
              datatype: b._datatype
            });
          }
        }
        throw new RangeError("Dimension mismatch. The right side has to be either 1- or 2-dimensional vector.");
      }
      if (isArray(b)) {
        var bsize = arraySize(b);
        if (bsize.length === 1) {
          if (bsize[0] !== rows) {
            throw new RangeError("Dimension mismatch. Matrix columns must match vector length.");
          }
          for (var _i4 = 0; _i4 < rows; _i4++) {
            data[_i4] = [b[_i4]];
          }
          return new DenseMatrix2({
            data,
            size: [rows, 1]
          });
        }
        if (bsize.length === 2) {
          if (bsize[0] !== rows || bsize[1] !== 1) {
            throw new RangeError("Dimension mismatch. Matrix columns must match vector length.");
          }
          for (var _i5 = 0; _i5 < rows; _i5++) {
            data[_i5] = [b[_i5][0]];
          }
          return new DenseMatrix2({
            data,
            size: [rows, 1]
          });
        }
        throw new RangeError("Dimension mismatch. The right side has to be either 1- or 2-dimensional vector.");
      }
    };
  }

  // node_modules/mathjs/lib/esm/function/algebra/solver/lsolve.js
  var name53 = "lsolve";
  var dependencies54 = ["typed", "matrix", "divideScalar", "multiplyScalar", "subtract", "equalScalar", "DenseMatrix"];
  var createLsolve = /* @__PURE__ */ factory(name53, dependencies54, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      divideScalar: divideScalar2,
      multiplyScalar: multiplyScalar2,
      subtract: subtract2,
      equalScalar: equalScalar2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var solveValidation = createSolveValidation({
      DenseMatrix: DenseMatrix2
    });
    return typed2(name53, {
      "SparseMatrix, Array | Matrix": function SparseMatrixArrayMatrix(m, b) {
        return _sparseForwardSubstitution(m, b);
      },
      "DenseMatrix, Array | Matrix": function DenseMatrixArrayMatrix(m, b) {
        return _denseForwardSubstitution(m, b);
      },
      "Array, Array | Matrix": function ArrayArrayMatrix(a, b) {
        var m = matrix2(a);
        var r = _denseForwardSubstitution(m, b);
        return r.valueOf();
      }
    });
    function _denseForwardSubstitution(m, b) {
      b = solveValidation(m, b, true);
      var bdata = b._data;
      var rows = m._size[0];
      var columns = m._size[1];
      var x = [];
      var mdata = m._data;
      for (var j = 0; j < columns; j++) {
        var bj = bdata[j][0] || 0;
        var xj = void 0;
        if (!equalScalar2(bj, 0)) {
          var vjj = mdata[j][j];
          if (equalScalar2(vjj, 0)) {
            throw new Error("Linear system cannot be solved since matrix is singular");
          }
          xj = divideScalar2(bj, vjj);
          for (var i = j + 1; i < rows; i++) {
            bdata[i] = [subtract2(bdata[i][0] || 0, multiplyScalar2(xj, mdata[i][j]))];
          }
        } else {
          xj = 0;
        }
        x[j] = [xj];
      }
      return new DenseMatrix2({
        data: x,
        size: [rows, 1]
      });
    }
    function _sparseForwardSubstitution(m, b) {
      b = solveValidation(m, b, true);
      var bdata = b._data;
      var rows = m._size[0];
      var columns = m._size[1];
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      var x = [];
      for (var j = 0; j < columns; j++) {
        var bj = bdata[j][0] || 0;
        if (!equalScalar2(bj, 0)) {
          var vjj = 0;
          var jValues = [];
          var jIndices = [];
          var firstIndex = ptr[j];
          var lastIndex = ptr[j + 1];
          for (var k = firstIndex; k < lastIndex; k++) {
            var i = index2[k];
            if (i === j) {
              vjj = values[k];
            } else if (i > j) {
              jValues.push(values[k]);
              jIndices.push(i);
            }
          }
          if (equalScalar2(vjj, 0)) {
            throw new Error("Linear system cannot be solved since matrix is singular");
          }
          var xj = divideScalar2(bj, vjj);
          for (var _k = 0, l = jIndices.length; _k < l; _k++) {
            var _i = jIndices[_k];
            bdata[_i] = [subtract2(bdata[_i][0] || 0, multiplyScalar2(xj, jValues[_k]))];
          }
          x[j] = [xj];
        } else {
          x[j] = [0];
        }
      }
      return new DenseMatrix2({
        data: x,
        size: [rows, 1]
      });
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/solver/usolve.js
  var name54 = "usolve";
  var dependencies55 = ["typed", "matrix", "divideScalar", "multiplyScalar", "subtract", "equalScalar", "DenseMatrix"];
  var createUsolve = /* @__PURE__ */ factory(name54, dependencies55, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      divideScalar: divideScalar2,
      multiplyScalar: multiplyScalar2,
      subtract: subtract2,
      equalScalar: equalScalar2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var solveValidation = createSolveValidation({
      DenseMatrix: DenseMatrix2
    });
    return typed2(name54, {
      "SparseMatrix, Array | Matrix": function SparseMatrixArrayMatrix(m, b) {
        return _sparseBackwardSubstitution(m, b);
      },
      "DenseMatrix, Array | Matrix": function DenseMatrixArrayMatrix(m, b) {
        return _denseBackwardSubstitution(m, b);
      },
      "Array, Array | Matrix": function ArrayArrayMatrix(a, b) {
        var m = matrix2(a);
        var r = _denseBackwardSubstitution(m, b);
        return r.valueOf();
      }
    });
    function _denseBackwardSubstitution(m, b) {
      b = solveValidation(m, b, true);
      var bdata = b._data;
      var rows = m._size[0];
      var columns = m._size[1];
      var x = [];
      var mdata = m._data;
      for (var j = columns - 1; j >= 0; j--) {
        var bj = bdata[j][0] || 0;
        var xj = void 0;
        if (!equalScalar2(bj, 0)) {
          var vjj = mdata[j][j];
          if (equalScalar2(vjj, 0)) {
            throw new Error("Linear system cannot be solved since matrix is singular");
          }
          xj = divideScalar2(bj, vjj);
          for (var i = j - 1; i >= 0; i--) {
            bdata[i] = [subtract2(bdata[i][0] || 0, multiplyScalar2(xj, mdata[i][j]))];
          }
        } else {
          xj = 0;
        }
        x[j] = [xj];
      }
      return new DenseMatrix2({
        data: x,
        size: [rows, 1]
      });
    }
    function _sparseBackwardSubstitution(m, b) {
      b = solveValidation(m, b, true);
      var bdata = b._data;
      var rows = m._size[0];
      var columns = m._size[1];
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      var x = [];
      for (var j = columns - 1; j >= 0; j--) {
        var bj = bdata[j][0] || 0;
        if (!equalScalar2(bj, 0)) {
          var vjj = 0;
          var jValues = [];
          var jIndices = [];
          var firstIndex = ptr[j];
          var lastIndex = ptr[j + 1];
          for (var k = lastIndex - 1; k >= firstIndex; k--) {
            var i = index2[k];
            if (i === j) {
              vjj = values[k];
            } else if (i < j) {
              jValues.push(values[k]);
              jIndices.push(i);
            }
          }
          if (equalScalar2(vjj, 0)) {
            throw new Error("Linear system cannot be solved since matrix is singular");
          }
          var xj = divideScalar2(bj, vjj);
          for (var _k = 0, _lastIndex = jIndices.length; _k < _lastIndex; _k++) {
            var _i = jIndices[_k];
            bdata[_i] = [subtract2(bdata[_i][0], multiplyScalar2(xj, jValues[_k]))];
          }
          x[j] = [xj];
        } else {
          x[j] = [0];
        }
      }
      return new DenseMatrix2({
        data: x,
        size: [rows, 1]
      });
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/solver/usolveAll.js
  var name55 = "usolveAll";
  var dependencies56 = ["typed", "matrix", "divideScalar", "multiplyScalar", "subtract", "equalScalar", "DenseMatrix"];
  var createUsolveAll = /* @__PURE__ */ factory(name55, dependencies56, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      divideScalar: divideScalar2,
      multiplyScalar: multiplyScalar2,
      subtract: subtract2,
      equalScalar: equalScalar2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var solveValidation = createSolveValidation({
      DenseMatrix: DenseMatrix2
    });
    return typed2(name55, {
      "SparseMatrix, Array | Matrix": function SparseMatrixArrayMatrix(m, b) {
        return _sparseBackwardSubstitution(m, b);
      },
      "DenseMatrix, Array | Matrix": function DenseMatrixArrayMatrix(m, b) {
        return _denseBackwardSubstitution(m, b);
      },
      "Array, Array | Matrix": function ArrayArrayMatrix(a, b) {
        var m = matrix2(a);
        var R = _denseBackwardSubstitution(m, b);
        return R.map((r) => r.valueOf());
      }
    });
    function _denseBackwardSubstitution(m, b_) {
      var B = [solveValidation(m, b_, true)._data.map((e) => e[0])];
      var M = m._data;
      var rows = m._size[0];
      var columns = m._size[1];
      for (var i = columns - 1; i >= 0; i--) {
        var L = B.length;
        for (var k = 0; k < L; k++) {
          var b = B[k];
          if (!equalScalar2(M[i][i], 0)) {
            b[i] = divideScalar2(b[i], M[i][i]);
            for (var j = i - 1; j >= 0; j--) {
              b[j] = subtract2(b[j], multiplyScalar2(b[i], M[j][i]));
            }
          } else if (!equalScalar2(b[i], 0)) {
            if (k === 0) {
              return [];
            } else {
              B.splice(k, 1);
              k -= 1;
              L -= 1;
            }
          } else if (k === 0) {
            var bNew = [...b];
            bNew[i] = 1;
            for (var _j = i - 1; _j >= 0; _j--) {
              bNew[_j] = subtract2(bNew[_j], M[_j][i]);
            }
            B.push(bNew);
          }
        }
      }
      return B.map((x) => new DenseMatrix2({
        data: x.map((e) => [e]),
        size: [rows, 1]
      }));
    }
    function _sparseBackwardSubstitution(m, b_) {
      var B = [solveValidation(m, b_, true)._data.map((e) => e[0])];
      var rows = m._size[0];
      var columns = m._size[1];
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      for (var i = columns - 1; i >= 0; i--) {
        var L = B.length;
        for (var k = 0; k < L; k++) {
          var b = B[k];
          var iValues = [];
          var iIndices = [];
          var firstIndex = ptr[i];
          var lastIndex = ptr[i + 1];
          var Mii = 0;
          for (var j = lastIndex - 1; j >= firstIndex; j--) {
            var J = index2[j];
            if (J === i) {
              Mii = values[j];
            } else if (J < i) {
              iValues.push(values[j]);
              iIndices.push(J);
            }
          }
          if (!equalScalar2(Mii, 0)) {
            b[i] = divideScalar2(b[i], Mii);
            for (var _j2 = 0, _lastIndex = iIndices.length; _j2 < _lastIndex; _j2++) {
              var _J = iIndices[_j2];
              b[_J] = subtract2(b[_J], multiplyScalar2(b[i], iValues[_j2]));
            }
          } else if (!equalScalar2(b[i], 0)) {
            if (k === 0) {
              return [];
            } else {
              B.splice(k, 1);
              k -= 1;
              L -= 1;
            }
          } else if (k === 0) {
            var bNew = [...b];
            bNew[i] = 1;
            for (var _j3 = 0, _lastIndex2 = iIndices.length; _j3 < _lastIndex2; _j3++) {
              var _J2 = iIndices[_j3];
              bNew[_J2] = subtract2(bNew[_J2], iValues[_j3]);
            }
            B.push(bNew);
          }
        }
      }
      return B.map((x) => new DenseMatrix2({
        data: x.map((e) => [e]),
        size: [rows, 1]
      }));
    }
  });

  // node_modules/mathjs/lib/esm/function/relational/equal.js
  var name56 = "equal";
  var dependencies57 = ["typed", "matrix", "equalScalar", "DenseMatrix"];
  var createEqual = /* @__PURE__ */ factory(name56, dependencies57, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      equalScalar: equalScalar2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm07 = createAlgorithm07({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm12 = createAlgorithm12({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name56, {
      "any, any": function anyAny(x, y) {
        if (x === null) {
          return y === null;
        }
        if (y === null) {
          return x === null;
        }
        if (x === void 0) {
          return y === void 0;
        }
        if (y === void 0) {
          return x === void 0;
        }
        return equalScalar2(x, y);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm07(x, y, equalScalar2);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm03(y, x, equalScalar2, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm03(x, y, equalScalar2, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, equalScalar2);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm12(x, y, equalScalar2, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, equalScalar2, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm12(y, x, equalScalar2, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, equalScalar2, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, equalScalar2, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, equalScalar2, true).valueOf();
      }
    });
  });
  var createEqualNumber = factory(name56, ["typed", "equalScalar"], (_ref2) => {
    var {
      typed: typed2,
      equalScalar: equalScalar2
    } = _ref2;
    return typed2(name56, {
      "any, any": function anyAny(x, y) {
        if (x === null) {
          return y === null;
        }
        if (y === null) {
          return x === null;
        }
        if (x === void 0) {
          return y === void 0;
        }
        if (y === void 0) {
          return x === void 0;
        }
        return equalScalar2(x, y);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/relational/smaller.js
  var name57 = "smaller";
  var dependencies58 = ["typed", "config", "matrix", "DenseMatrix"];
  var createSmaller = /* @__PURE__ */ factory(name57, dependencies58, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm07 = createAlgorithm07({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm12 = createAlgorithm12({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name57, {
      "boolean, boolean": function booleanBoolean(x, y) {
        return x < y;
      },
      "number, number": function numberNumber(x, y) {
        return x < y && !nearlyEqual(x, y, config4.epsilon);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.lt(y) && !nearlyEqual2(x, y, config4.epsilon);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.compare(y) === -1;
      },
      "Complex, Complex": function ComplexComplex(x, y) {
        throw new TypeError("No ordering relation is defined for complex numbers");
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (!x.equalBase(y)) {
          throw new Error("Cannot compare units with different base");
        }
        return this(x.value, y.value);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm07(x, y, this);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm03(y, x, this, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm03(x, y, this, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, this);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm12(x, y, this, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, this, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm12(y, x, this, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, this, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, this, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, this, true).valueOf();
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/relational/smallerEq.js
  var name58 = "smallerEq";
  var dependencies59 = ["typed", "config", "matrix", "DenseMatrix"];
  var createSmallerEq = /* @__PURE__ */ factory(name58, dependencies59, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm07 = createAlgorithm07({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm12 = createAlgorithm12({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name58, {
      "boolean, boolean": function booleanBoolean(x, y) {
        return x <= y;
      },
      "number, number": function numberNumber(x, y) {
        return x <= y || nearlyEqual(x, y, config4.epsilon);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.lte(y) || nearlyEqual2(x, y, config4.epsilon);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.compare(y) !== 1;
      },
      "Complex, Complex": function ComplexComplex() {
        throw new TypeError("No ordering relation is defined for complex numbers");
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (!x.equalBase(y)) {
          throw new Error("Cannot compare units with different base");
        }
        return this(x.value, y.value);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm07(x, y, this);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm03(y, x, this, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm03(x, y, this, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, this);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm12(x, y, this, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, this, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm12(y, x, this, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, this, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, this, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, this, true).valueOf();
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/relational/larger.js
  var name59 = "larger";
  var dependencies60 = ["typed", "config", "matrix", "DenseMatrix"];
  var createLarger = /* @__PURE__ */ factory(name59, dependencies60, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm07 = createAlgorithm07({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm12 = createAlgorithm12({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name59, {
      "boolean, boolean": function booleanBoolean(x, y) {
        return x > y;
      },
      "number, number": function numberNumber(x, y) {
        return x > y && !nearlyEqual(x, y, config4.epsilon);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.gt(y) && !nearlyEqual2(x, y, config4.epsilon);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.compare(y) === 1;
      },
      "Complex, Complex": function ComplexComplex() {
        throw new TypeError("No ordering relation is defined for complex numbers");
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (!x.equalBase(y)) {
          throw new Error("Cannot compare units with different base");
        }
        return this(x.value, y.value);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm07(x, y, this);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm03(y, x, this, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm03(x, y, this, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, this);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm12(x, y, this, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, this, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm12(y, x, this, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, this, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, this, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, this, true).valueOf();
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/relational/largerEq.js
  var name60 = "largerEq";
  var dependencies61 = ["typed", "config", "matrix", "DenseMatrix"];
  var createLargerEq = /* @__PURE__ */ factory(name60, dependencies61, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      matrix: matrix2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var algorithm03 = createAlgorithm03({
      typed: typed2
    });
    var algorithm07 = createAlgorithm07({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm12 = createAlgorithm12({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name60, {
      "boolean, boolean": function booleanBoolean(x, y) {
        return x >= y;
      },
      "number, number": function numberNumber(x, y) {
        return x >= y || nearlyEqual(x, y, config4.epsilon);
      },
      "BigNumber, BigNumber": function BigNumberBigNumber(x, y) {
        return x.gte(y) || nearlyEqual2(x, y, config4.epsilon);
      },
      "Fraction, Fraction": function FractionFraction(x, y) {
        return x.compare(y) !== -1;
      },
      "Complex, Complex": function ComplexComplex() {
        throw new TypeError("No ordering relation is defined for complex numbers");
      },
      "Unit, Unit": function UnitUnit(x, y) {
        if (!x.equalBase(y)) {
          throw new Error("Cannot compare units with different base");
        }
        return this(x.value, y.value);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm07(x, y, this);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm03(y, x, this, true);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm03(x, y, this, false);
      },
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, this);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm12(x, y, this, false);
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, this, false);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm12(y, x, this, true);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, this, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, this, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, this, true).valueOf();
      }
    });
  });

  // node_modules/mathjs/lib/esm/type/matrix/ImmutableDenseMatrix.js
  var name61 = "ImmutableDenseMatrix";
  var dependencies62 = ["smaller", "DenseMatrix"];
  var createImmutableDenseMatrixClass = /* @__PURE__ */ factory(name61, dependencies62, (_ref) => {
    var {
      smaller: smaller2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    function ImmutableDenseMatrix2(data, datatype) {
      if (!(this instanceof ImmutableDenseMatrix2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      if (datatype && !isString(datatype)) {
        throw new Error("Invalid datatype: " + datatype);
      }
      if (isMatrix(data) || isArray(data)) {
        var matrix2 = new DenseMatrix2(data, datatype);
        this._data = matrix2._data;
        this._size = matrix2._size;
        this._datatype = matrix2._datatype;
        this._min = null;
        this._max = null;
      } else if (data && isArray(data.data) && isArray(data.size)) {
        this._data = data.data;
        this._size = data.size;
        this._datatype = data.datatype;
        this._min = typeof data.min !== "undefined" ? data.min : null;
        this._max = typeof data.max !== "undefined" ? data.max : null;
      } else if (data) {
        throw new TypeError("Unsupported type of data (" + typeOf(data) + ")");
      } else {
        this._data = [];
        this._size = [0];
        this._datatype = datatype;
        this._min = null;
        this._max = null;
      }
    }
    ImmutableDenseMatrix2.prototype = new DenseMatrix2();
    ImmutableDenseMatrix2.prototype.type = "ImmutableDenseMatrix";
    ImmutableDenseMatrix2.prototype.isImmutableDenseMatrix = true;
    ImmutableDenseMatrix2.prototype.subset = function(index2) {
      switch (arguments.length) {
        case 1: {
          var m = DenseMatrix2.prototype.subset.call(this, index2);
          if (isMatrix(m)) {
            return new ImmutableDenseMatrix2({
              data: m._data,
              size: m._size,
              datatype: m._datatype
            });
          }
          return m;
        }
        // intentional fall through
        case 2:
        case 3:
          throw new Error("Cannot invoke set subset on an Immutable Matrix instance");
        default:
          throw new SyntaxError("Wrong number of arguments");
      }
    };
    ImmutableDenseMatrix2.prototype.set = function() {
      throw new Error("Cannot invoke set on an Immutable Matrix instance");
    };
    ImmutableDenseMatrix2.prototype.resize = function() {
      throw new Error("Cannot invoke resize on an Immutable Matrix instance");
    };
    ImmutableDenseMatrix2.prototype.reshape = function() {
      throw new Error("Cannot invoke reshape on an Immutable Matrix instance");
    };
    ImmutableDenseMatrix2.prototype.clone = function() {
      return new ImmutableDenseMatrix2({
        data: clone(this._data),
        size: clone(this._size),
        datatype: this._datatype
      });
    };
    ImmutableDenseMatrix2.prototype.toJSON = function() {
      return {
        mathjs: "ImmutableDenseMatrix",
        data: this._data,
        size: this._size,
        datatype: this._datatype
      };
    };
    ImmutableDenseMatrix2.fromJSON = function(json) {
      return new ImmutableDenseMatrix2(json);
    };
    ImmutableDenseMatrix2.prototype.swapRows = function() {
      throw new Error("Cannot invoke swapRows on an Immutable Matrix instance");
    };
    ImmutableDenseMatrix2.prototype.min = function() {
      if (this._min === null) {
        var m = null;
        this.forEach(function(v) {
          if (m === null || smaller2(v, m)) {
            m = v;
          }
        });
        this._min = m !== null ? m : void 0;
      }
      return this._min;
    };
    ImmutableDenseMatrix2.prototype.max = function() {
      if (this._max === null) {
        var m = null;
        this.forEach(function(v) {
          if (m === null || smaller2(m, v)) {
            m = v;
          }
        });
        this._max = m !== null ? m : void 0;
      }
      return this._max;
    };
    return ImmutableDenseMatrix2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/matrix/MatrixIndex.js
  var name62 = "Index";
  var dependencies63 = ["ImmutableDenseMatrix"];
  var createIndexClass = /* @__PURE__ */ factory(name62, dependencies63, (_ref) => {
    var {
      ImmutableDenseMatrix: ImmutableDenseMatrix2
    } = _ref;
    function Index2(ranges) {
      if (!(this instanceof Index2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      this._dimensions = [];
      this._isScalar = true;
      for (var i = 0, ii = arguments.length; i < ii; i++) {
        var arg = arguments[i];
        if (isRange(arg)) {
          this._dimensions.push(arg);
          this._isScalar = false;
        } else if (Array.isArray(arg) || isMatrix(arg)) {
          var m = _createImmutableMatrix(arg.valueOf());
          this._dimensions.push(m);
          var size2 = m.size();
          if (size2.length !== 1 || size2[0] !== 1) {
            this._isScalar = false;
          }
        } else if (typeof arg === "number") {
          this._dimensions.push(_createImmutableMatrix([arg]));
        } else if (typeof arg === "string") {
          this._dimensions.push(arg);
        } else {
          throw new TypeError("Dimension must be an Array, Matrix, number, string, or Range");
        }
      }
    }
    Index2.prototype.type = "Index";
    Index2.prototype.isIndex = true;
    function _createImmutableMatrix(arg) {
      for (var i = 0, l = arg.length; i < l; i++) {
        if (typeof arg[i] !== "number" || !isInteger(arg[i])) {
          throw new TypeError("Index parameters must be positive integer numbers");
        }
      }
      return new ImmutableDenseMatrix2(arg);
    }
    Index2.prototype.clone = function() {
      var index2 = new Index2();
      index2._dimensions = clone(this._dimensions);
      index2._isScalar = this._isScalar;
      return index2;
    };
    Index2.create = function(ranges) {
      var index2 = new Index2();
      Index2.apply(index2, ranges);
      return index2;
    };
    Index2.prototype.size = function() {
      var size2 = [];
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        var d = this._dimensions[i];
        size2[i] = typeof d === "string" ? 1 : d.size()[0];
      }
      return size2;
    };
    Index2.prototype.max = function() {
      var values = [];
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        var range2 = this._dimensions[i];
        values[i] = typeof range2 === "string" ? range2 : range2.max();
      }
      return values;
    };
    Index2.prototype.min = function() {
      var values = [];
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        var range2 = this._dimensions[i];
        values[i] = typeof range2 === "string" ? range2 : range2.min();
      }
      return values;
    };
    Index2.prototype.forEach = function(callback) {
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        callback(this._dimensions[i], i, this);
      }
    };
    Index2.prototype.dimension = function(dim) {
      return this._dimensions[dim] || null;
    };
    Index2.prototype.isObjectProperty = function() {
      return this._dimensions.length === 1 && typeof this._dimensions[0] === "string";
    };
    Index2.prototype.getObjectProperty = function() {
      return this.isObjectProperty() ? this._dimensions[0] : null;
    };
    Index2.prototype.isScalar = function() {
      return this._isScalar;
    };
    Index2.prototype.toArray = function() {
      var array = [];
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        var dimension = this._dimensions[i];
        array.push(typeof dimension === "string" ? dimension : dimension.toArray());
      }
      return array;
    };
    Index2.prototype.valueOf = Index2.prototype.toArray;
    Index2.prototype.toString = function() {
      var strings = [];
      for (var i = 0, ii = this._dimensions.length; i < ii; i++) {
        var dimension = this._dimensions[i];
        if (typeof dimension === "string") {
          strings.push(JSON.stringify(dimension));
        } else {
          strings.push(dimension.toString());
        }
      }
      return "[" + strings.join(", ") + "]";
    };
    Index2.prototype.toJSON = function() {
      return {
        mathjs: "Index",
        dimensions: this._dimensions
      };
    };
    Index2.fromJSON = function(json) {
      return Index2.create(json.dimensions);
    };
    return Index2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/matrix/FibonacciHeap.js
  var name63 = "FibonacciHeap";
  var dependencies64 = ["smaller", "larger"];
  var createFibonacciHeapClass = /* @__PURE__ */ factory(name63, dependencies64, (_ref) => {
    var {
      smaller: smaller2,
      larger: larger2
    } = _ref;
    var oneOverLogPhi = 1 / Math.log((1 + Math.sqrt(5)) / 2);
    function FibonacciHeap2() {
      if (!(this instanceof FibonacciHeap2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      this._minimum = null;
      this._size = 0;
    }
    FibonacciHeap2.prototype.type = "FibonacciHeap";
    FibonacciHeap2.prototype.isFibonacciHeap = true;
    FibonacciHeap2.prototype.insert = function(key, value) {
      var node = {
        key,
        value,
        degree: 0
      };
      if (this._minimum) {
        var minimum = this._minimum;
        node.left = minimum;
        node.right = minimum.right;
        minimum.right = node;
        node.right.left = node;
        if (smaller2(key, minimum.key)) {
          this._minimum = node;
        }
      } else {
        node.left = node;
        node.right = node;
        this._minimum = node;
      }
      this._size++;
      return node;
    };
    FibonacciHeap2.prototype.size = function() {
      return this._size;
    };
    FibonacciHeap2.prototype.clear = function() {
      this._minimum = null;
      this._size = 0;
    };
    FibonacciHeap2.prototype.isEmpty = function() {
      return this._size === 0;
    };
    FibonacciHeap2.prototype.extractMinimum = function() {
      var node = this._minimum;
      if (node === null) {
        return node;
      }
      var minimum = this._minimum;
      var numberOfChildren = node.degree;
      var x = node.child;
      while (numberOfChildren > 0) {
        var tempRight = x.right;
        x.left.right = x.right;
        x.right.left = x.left;
        x.left = minimum;
        x.right = minimum.right;
        minimum.right = x;
        x.right.left = x;
        x.parent = null;
        x = tempRight;
        numberOfChildren--;
      }
      node.left.right = node.right;
      node.right.left = node.left;
      if (node === node.right) {
        minimum = null;
      } else {
        minimum = node.right;
        minimum = _findMinimumNode(minimum, this._size);
      }
      this._size--;
      this._minimum = minimum;
      return node;
    };
    FibonacciHeap2.prototype.remove = function(node) {
      this._minimum = _decreaseKey(this._minimum, node, -1);
      this.extractMinimum();
    };
    function _decreaseKey(minimum, node, key) {
      node.key = key;
      var parent = node.parent;
      if (parent && smaller2(node.key, parent.key)) {
        _cut(minimum, node, parent);
        _cascadingCut(minimum, parent);
      }
      if (smaller2(node.key, minimum.key)) {
        minimum = node;
      }
      return minimum;
    }
    function _cut(minimum, node, parent) {
      node.left.right = node.right;
      node.right.left = node.left;
      parent.degree--;
      if (parent.child === node) {
        parent.child = node.right;
      }
      if (parent.degree === 0) {
        parent.child = null;
      }
      node.left = minimum;
      node.right = minimum.right;
      minimum.right = node;
      node.right.left = node;
      node.parent = null;
      node.mark = false;
    }
    function _cascadingCut(minimum, node) {
      var parent = node.parent;
      if (!parent) {
        return;
      }
      if (!node.mark) {
        node.mark = true;
      } else {
        _cut(minimum, node, parent);
        _cascadingCut(parent);
      }
    }
    var _linkNodes = function _linkNodes2(node, parent) {
      node.left.right = node.right;
      node.right.left = node.left;
      node.parent = parent;
      if (!parent.child) {
        parent.child = node;
        node.right = node;
        node.left = node;
      } else {
        node.left = parent.child;
        node.right = parent.child.right;
        parent.child.right = node;
        node.right.left = node;
      }
      parent.degree++;
      node.mark = false;
    };
    function _findMinimumNode(minimum, size2) {
      var arraySize2 = Math.floor(Math.log(size2) * oneOverLogPhi) + 1;
      var array = new Array(arraySize2);
      var numRoots = 0;
      var x = minimum;
      if (x) {
        numRoots++;
        x = x.right;
        while (x !== minimum) {
          numRoots++;
          x = x.right;
        }
      }
      var y;
      while (numRoots > 0) {
        var d = x.degree;
        var next = x.right;
        while (true) {
          y = array[d];
          if (!y) {
            break;
          }
          if (larger2(x.key, y.key)) {
            var temp = y;
            y = x;
            x = temp;
          }
          _linkNodes(y, x);
          array[d] = null;
          d++;
        }
        array[d] = x;
        x = next;
        numRoots--;
      }
      minimum = null;
      for (var i = 0; i < arraySize2; i++) {
        y = array[i];
        if (!y) {
          continue;
        }
        if (minimum) {
          y.left.right = y.right;
          y.right.left = y.left;
          y.left = minimum;
          y.right = minimum.right;
          minimum.right = y;
          y.right.left = y;
          if (smaller2(y.key, minimum.key)) {
            minimum = y;
          }
        } else {
          minimum = y;
        }
      }
      return minimum;
    }
    return FibonacciHeap2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/type/matrix/Spa.js
  var name64 = "Spa";
  var dependencies65 = ["addScalar", "equalScalar", "FibonacciHeap"];
  var createSpaClass = /* @__PURE__ */ factory(name64, dependencies65, (_ref) => {
    var {
      addScalar: addScalar2,
      equalScalar: equalScalar2,
      FibonacciHeap: FibonacciHeap2
    } = _ref;
    function Spa2() {
      if (!(this instanceof Spa2)) {
        throw new SyntaxError("Constructor must be called with the new operator");
      }
      this._values = [];
      this._heap = new FibonacciHeap2();
    }
    Spa2.prototype.type = "Spa";
    Spa2.prototype.isSpa = true;
    Spa2.prototype.set = function(i, v) {
      if (!this._values[i]) {
        var node = this._heap.insert(i, v);
        this._values[i] = node;
      } else {
        this._values[i].value = v;
      }
    };
    Spa2.prototype.get = function(i) {
      var node = this._values[i];
      if (node) {
        return node.value;
      }
      return 0;
    };
    Spa2.prototype.accumulate = function(i, v) {
      var node = this._values[i];
      if (!node) {
        node = this._heap.insert(i, v);
        this._values[i] = node;
      } else {
        node.value = addScalar2(node.value, v);
      }
    };
    Spa2.prototype.forEach = function(from, to, callback) {
      var heap = this._heap;
      var values = this._values;
      var nodes = [];
      var node = heap.extractMinimum();
      if (node) {
        nodes.push(node);
      }
      while (node && node.key <= to) {
        if (node.key >= from) {
          if (!equalScalar2(node.value, 0)) {
            callback(node.key, node.value, this);
          }
        }
        node = heap.extractMinimum();
        if (node) {
          nodes.push(node);
        }
      }
      for (var i = 0; i < nodes.length; i++) {
        var n = nodes[i];
        node = heap.insert(n.key, n.value);
        values[node.key] = node;
      }
    };
    Spa2.prototype.swap = function(i, j) {
      var nodei = this._values[i];
      var nodej = this._values[j];
      if (!nodei && nodej) {
        nodei = this._heap.insert(i, nodej.value);
        this._heap.remove(nodej);
        this._values[i] = nodei;
        this._values[j] = void 0;
      } else if (nodei && !nodej) {
        nodej = this._heap.insert(j, nodei.value);
        this._heap.remove(nodei);
        this._values[j] = nodej;
        this._values[i] = void 0;
      } else if (nodei && nodej) {
        var v = nodei.value;
        nodei.value = nodej.value;
        nodej.value = v;
      }
    };
    return Spa2;
  }, {
    isClass: true
  });

  // node_modules/mathjs/lib/esm/function/trigonometry/atan.js
  var name65 = "atan";
  var dependencies66 = ["typed"];
  var createAtan = /* @__PURE__ */ factory(name65, dependencies66, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2("atan", {
      number: function number2(x) {
        return Math.atan(x);
      },
      Complex: function Complex3(x) {
        return x.atan();
      },
      BigNumber: function BigNumber2(x) {
        return x.atan();
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/trigonometry/cos.js
  var name66 = "cos";
  var dependencies67 = ["typed"];
  var createCos = /* @__PURE__ */ factory(name66, dependencies67, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name66, {
      number: Math.cos,
      Complex: function Complex3(x) {
        return x.cos();
      },
      BigNumber: function BigNumber2(x) {
        return x.cos();
      },
      Unit: function Unit(x) {
        if (!x.hasBase(x.constructor.BASE_UNITS.ANGLE)) {
          throw new TypeError("Unit in function cos is no angle");
        }
        return this(x.value);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/trigonometry/sin.js
  var name67 = "sin";
  var dependencies68 = ["typed"];
  var createSin = /* @__PURE__ */ factory(name67, dependencies68, (_ref) => {
    var {
      typed: typed2
    } = _ref;
    return typed2(name67, {
      number: Math.sin,
      Complex: function Complex3(x) {
        return x.sin();
      },
      BigNumber: function BigNumber2(x) {
        return x.sin();
      },
      Unit: function Unit(x) {
        if (!x.hasBase(x.constructor.BASE_UNITS.ANGLE)) {
          throw new TypeError("Unit in function sin is no angle");
        }
        return this(x.value);
      },
      "Array | Matrix": function ArrayMatrix(x) {
        return deepMap(x, this, true);
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/add.js
  var name68 = "add";
  var dependencies69 = ["typed", "matrix", "addScalar", "equalScalar", "DenseMatrix", "SparseMatrix"];
  var createAdd = /* @__PURE__ */ factory(name68, dependencies69, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      addScalar: addScalar2,
      equalScalar: equalScalar2,
      DenseMatrix: DenseMatrix2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    var algorithm01 = createAlgorithm01({
      typed: typed2
    });
    var algorithm04 = createAlgorithm04({
      typed: typed2,
      equalScalar: equalScalar2
    });
    var algorithm10 = createAlgorithm10({
      typed: typed2,
      DenseMatrix: DenseMatrix2
    });
    var algorithm13 = createAlgorithm13({
      typed: typed2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2(name68, extend({
      // we extend the signatures of addScalar with signatures dealing with matrices
      "DenseMatrix, DenseMatrix": function DenseMatrixDenseMatrix(x, y) {
        return algorithm13(x, y, addScalar2);
      },
      "DenseMatrix, SparseMatrix": function DenseMatrixSparseMatrix(x, y) {
        return algorithm01(x, y, addScalar2, false);
      },
      "SparseMatrix, DenseMatrix": function SparseMatrixDenseMatrix(x, y) {
        return algorithm01(y, x, addScalar2, true);
      },
      "SparseMatrix, SparseMatrix": function SparseMatrixSparseMatrix(x, y) {
        return algorithm04(x, y, addScalar2);
      },
      "Array, Array": function ArrayArray(x, y) {
        return this(matrix2(x), matrix2(y)).valueOf();
      },
      "Array, Matrix": function ArrayMatrix(x, y) {
        return this(matrix2(x), y);
      },
      "Matrix, Array": function MatrixArray(x, y) {
        return this(x, matrix2(y));
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, addScalar2, false);
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm10(x, y, addScalar2, false);
      },
      "any, DenseMatrix": function anyDenseMatrix(x, y) {
        return algorithm14(y, x, addScalar2, true);
      },
      "any, SparseMatrix": function anySparseMatrix(x, y) {
        return algorithm10(y, x, addScalar2, true);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, addScalar2, false).valueOf();
      },
      "any, Array": function anyArray(x, y) {
        return algorithm14(matrix2(y), x, addScalar2, true).valueOf();
      },
      "any, any": addScalar2,
      "any, any, ...any": function anyAnyAny(x, y, rest) {
        var result = this(x, y);
        for (var i = 0; i < rest.length; i++) {
          result = this(result, rest[i]);
        }
        return result;
      }
    }, addScalar2.signatures));
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/norm.js
  var name69 = "norm";
  var dependencies70 = ["typed", "abs", "add", "pow", "conj", "sqrt", "multiply", "equalScalar", "larger", "smaller", "matrix", "ctranspose", "eigs"];
  var createNorm = /* @__PURE__ */ factory(name69, dependencies70, (_ref) => {
    var {
      typed: typed2,
      abs: abs3,
      add: add3,
      pow: pow3,
      conj: conj2,
      sqrt: sqrt3,
      multiply: multiply2,
      equalScalar: equalScalar2,
      larger: larger2,
      smaller: smaller2,
      matrix: matrix2,
      ctranspose: ctranspose2,
      eigs: eigs2
    } = _ref;
    return typed2(name69, {
      number: Math.abs,
      Complex: function Complex3(x) {
        return x.abs();
      },
      BigNumber: function BigNumber2(x) {
        return x.abs();
      },
      boolean: function boolean(x) {
        return Math.abs(x);
      },
      Array: function Array2(x) {
        return _norm(matrix2(x), 2);
      },
      Matrix: function Matrix2(x) {
        return _norm(x, 2);
      },
      "number | Complex | BigNumber | boolean, number | BigNumber | string": function numberComplexBigNumberBooleanNumberBigNumberString(x) {
        return this(x);
      },
      "Array, number | BigNumber | string": function ArrayNumberBigNumberString(x, p) {
        return _norm(matrix2(x), p);
      },
      "Matrix, number | BigNumber | string": function MatrixNumberBigNumberString(x, p) {
        return _norm(x, p);
      }
    });
    function _vectorNormPlusInfinity(x) {
      var pinf = 0;
      x.forEach(function(value) {
        var v = abs3(value);
        if (larger2(v, pinf)) {
          pinf = v;
        }
      }, true);
      return pinf;
    }
    function _vectorNormMinusInfinity(x) {
      var ninf;
      x.forEach(function(value) {
        var v = abs3(value);
        if (!ninf || smaller2(v, ninf)) {
          ninf = v;
        }
      }, true);
      return ninf || 0;
    }
    function _vectorNorm(x, p) {
      if (p === Number.POSITIVE_INFINITY || p === "inf") {
        return _vectorNormPlusInfinity(x);
      }
      if (p === Number.NEGATIVE_INFINITY || p === "-inf") {
        return _vectorNormMinusInfinity(x);
      }
      if (p === "fro") {
        return _norm(x, 2);
      }
      if (typeof p === "number" && !isNaN(p)) {
        if (!equalScalar2(p, 0)) {
          var n = 0;
          x.forEach(function(value) {
            n = add3(pow3(abs3(value), p), n);
          }, true);
          return pow3(n, 1 / p);
        }
        return Number.POSITIVE_INFINITY;
      }
      throw new Error("Unsupported parameter value");
    }
    function _matrixNormFrobenius(x) {
      var fro = 0;
      x.forEach(function(value, index2) {
        fro = add3(fro, multiply2(value, conj2(value)));
      });
      return abs3(sqrt3(fro));
    }
    function _matrixNormOne(x) {
      var c = [];
      var maxc = 0;
      x.forEach(function(value, index2) {
        var j = index2[1];
        var cj = add3(c[j] || 0, abs3(value));
        if (larger2(cj, maxc)) {
          maxc = cj;
        }
        c[j] = cj;
      }, true);
      return maxc;
    }
    function _matrixNormTwo(x) {
      var sizeX = x.size();
      if (sizeX[0] !== sizeX[1]) {
        throw new RangeError("Invalid matrix dimensions");
      }
      var tx = ctranspose2(x);
      var squaredX = multiply2(tx, x);
      var eigenVals = eigs2(squaredX).values.toArray();
      var rho = eigenVals[eigenVals.length - 1];
      return abs3(sqrt3(rho));
    }
    function _matrixNormInfinity(x) {
      var r = [];
      var maxr = 0;
      x.forEach(function(value, index2) {
        var i = index2[0];
        var ri = add3(r[i] || 0, abs3(value));
        if (larger2(ri, maxr)) {
          maxr = ri;
        }
        r[i] = ri;
      }, true);
      return maxr;
    }
    function _matrixNorm(x, p) {
      if (p === 1) {
        return _matrixNormOne(x);
      }
      if (p === Number.POSITIVE_INFINITY || p === "inf") {
        return _matrixNormInfinity(x);
      }
      if (p === "fro") {
        return _matrixNormFrobenius(x);
      }
      if (p === 2) {
        return _matrixNormTwo(x);
      }
      throw new Error("Unsupported parameter value " + p);
    }
    function _norm(x, p) {
      var sizeX = x.size();
      if (sizeX.length === 1) {
        return _vectorNorm(x, p);
      }
      if (sizeX.length === 2) {
        if (sizeX[0] && sizeX[1]) {
          return _matrixNorm(x, p);
        } else {
          throw new RangeError("Invalid matrix dimensions");
        }
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/dot.js
  var name70 = "dot";
  var dependencies71 = ["typed", "addScalar", "multiplyScalar", "conj", "size"];
  var createDot = /* @__PURE__ */ factory(name70, dependencies71, (_ref) => {
    var {
      typed: typed2,
      addScalar: addScalar2,
      multiplyScalar: multiplyScalar2,
      conj: conj2,
      size: size2
    } = _ref;
    return typed2(name70, {
      "Array | DenseMatrix, Array | DenseMatrix": _denseDot,
      "SparseMatrix, SparseMatrix": _sparseDot
    });
    function _validateDim(x, y) {
      var xSize = _size(x);
      var ySize = _size(y);
      var xLen, yLen;
      if (xSize.length === 1) {
        xLen = xSize[0];
      } else if (xSize.length === 2 && xSize[1] === 1) {
        xLen = xSize[0];
      } else {
        throw new RangeError("Expected a column vector, instead got a matrix of size (" + xSize.join(", ") + ")");
      }
      if (ySize.length === 1) {
        yLen = ySize[0];
      } else if (ySize.length === 2 && ySize[1] === 1) {
        yLen = ySize[0];
      } else {
        throw new RangeError("Expected a column vector, instead got a matrix of size (" + ySize.join(", ") + ")");
      }
      if (xLen !== yLen) throw new RangeError("Vectors must have equal length (" + xLen + " != " + yLen + ")");
      if (xLen === 0) throw new RangeError("Cannot calculate the dot product of empty vectors");
      return xLen;
    }
    function _denseDot(a, b) {
      var N = _validateDim(a, b);
      var adata = isMatrix(a) ? a._data : a;
      var adt = isMatrix(a) ? a._datatype : void 0;
      var bdata = isMatrix(b) ? b._data : b;
      var bdt = isMatrix(b) ? b._datatype : void 0;
      var aIsColumn = _size(a).length === 2;
      var bIsColumn = _size(b).length === 2;
      var add3 = addScalar2;
      var mul2 = multiplyScalar2;
      if (adt && bdt && adt === bdt && typeof adt === "string") {
        var dt = adt;
        add3 = typed2.find(addScalar2, [dt, dt]);
        mul2 = typed2.find(multiplyScalar2, [dt, dt]);
      }
      if (!aIsColumn && !bIsColumn) {
        var c = mul2(conj2(adata[0]), bdata[0]);
        for (var i = 1; i < N; i++) {
          c = add3(c, mul2(conj2(adata[i]), bdata[i]));
        }
        return c;
      }
      if (!aIsColumn && bIsColumn) {
        var _c = mul2(conj2(adata[0]), bdata[0][0]);
        for (var _i = 1; _i < N; _i++) {
          _c = add3(_c, mul2(conj2(adata[_i]), bdata[_i][0]));
        }
        return _c;
      }
      if (aIsColumn && !bIsColumn) {
        var _c2 = mul2(conj2(adata[0][0]), bdata[0]);
        for (var _i2 = 1; _i2 < N; _i2++) {
          _c2 = add3(_c2, mul2(conj2(adata[_i2][0]), bdata[_i2]));
        }
        return _c2;
      }
      if (aIsColumn && bIsColumn) {
        var _c3 = mul2(conj2(adata[0][0]), bdata[0][0]);
        for (var _i3 = 1; _i3 < N; _i3++) {
          _c3 = add3(_c3, mul2(conj2(adata[_i3][0]), bdata[_i3][0]));
        }
        return _c3;
      }
    }
    function _sparseDot(x, y) {
      _validateDim(x, y);
      var xindex = x._index;
      var xvalues = x._values;
      var yindex = y._index;
      var yvalues = y._values;
      var c = 0;
      var add3 = addScalar2;
      var mul2 = multiplyScalar2;
      var i = 0;
      var j = 0;
      while (i < xindex.length && j < yindex.length) {
        var I = xindex[i];
        var J = yindex[j];
        if (I < J) {
          i++;
          continue;
        }
        if (I > J) {
          j++;
          continue;
        }
        if (I === J) {
          c = add3(c, mul2(xvalues[i], yvalues[j]));
          i++;
          j++;
        }
      }
      return c;
    }
    function _size(x) {
      return isMatrix(x) ? x.size() : size2(x);
    }
  });

  // node_modules/mathjs/lib/esm/type/matrix/function/index.js
  var name71 = "index";
  var dependencies72 = ["typed", "Index"];
  var createIndex = /* @__PURE__ */ factory(name71, dependencies72, (_ref) => {
    var {
      typed: typed2,
      Index: Index2
    } = _ref;
    return typed2(name71, {
      "...number | string | BigNumber | Range | Array | Matrix": function numberStringBigNumberRangeArrayMatrix(args) {
        var ranges = args.map(function(arg) {
          if (isBigNumber(arg)) {
            return arg.toNumber();
          } else if (Array.isArray(arg) || isMatrix(arg)) {
            return arg.map(function(elem) {
              return isBigNumber(elem) ? elem.toNumber() : elem;
            });
          } else {
            return arg;
          }
        });
        var res = new Index2();
        Index2.apply(res, ranges);
        return res;
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/algebra/decomposition/lup.js
  var name72 = "lup";
  var dependencies73 = ["typed", "matrix", "abs", "addScalar", "divideScalar", "multiplyScalar", "subtract", "larger", "equalScalar", "unaryMinus", "DenseMatrix", "SparseMatrix", "Spa"];
  var createLup = /* @__PURE__ */ factory(name72, dependencies73, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      abs: abs3,
      addScalar: addScalar2,
      divideScalar: divideScalar2,
      multiplyScalar: multiplyScalar2,
      subtract: subtract2,
      larger: larger2,
      equalScalar: equalScalar2,
      unaryMinus: unaryMinus2,
      DenseMatrix: DenseMatrix2,
      SparseMatrix: SparseMatrix2,
      Spa: Spa2
    } = _ref;
    return typed2(name72, {
      DenseMatrix: function DenseMatrix3(m) {
        return _denseLUP(m);
      },
      SparseMatrix: function SparseMatrix3(m) {
        return _sparseLUP(m);
      },
      Array: function Array2(a) {
        var m = matrix2(a);
        var r = _denseLUP(m);
        return {
          L: r.L.valueOf(),
          U: r.U.valueOf(),
          p: r.p
        };
      }
    });
    function _denseLUP(m) {
      var rows = m._size[0];
      var columns = m._size[1];
      var n = Math.min(rows, columns);
      var data = clone(m._data);
      var ldata = [];
      var lsize = [rows, n];
      var udata = [];
      var usize = [n, columns];
      var i, j, k;
      var p = [];
      for (i = 0; i < rows; i++) {
        p[i] = i;
      }
      for (j = 0; j < columns; j++) {
        if (j > 0) {
          for (i = 0; i < rows; i++) {
            var min2 = Math.min(i, j);
            var s = 0;
            for (k = 0; k < min2; k++) {
              s = addScalar2(s, multiplyScalar2(data[i][k], data[k][j]));
            }
            data[i][j] = subtract2(data[i][j], s);
          }
        }
        var pi = j;
        var pabsv = 0;
        var vjj = 0;
        for (i = j; i < rows; i++) {
          var v = data[i][j];
          var absv = abs3(v);
          if (larger2(absv, pabsv)) {
            pi = i;
            pabsv = absv;
            vjj = v;
          }
        }
        if (j !== pi) {
          p[j] = [p[pi], p[pi] = p[j]][0];
          DenseMatrix2._swapRows(j, pi, data);
        }
        if (j < rows) {
          for (i = j + 1; i < rows; i++) {
            var vij = data[i][j];
            if (!equalScalar2(vij, 0)) {
              data[i][j] = divideScalar2(data[i][j], vjj);
            }
          }
        }
      }
      for (j = 0; j < columns; j++) {
        for (i = 0; i < rows; i++) {
          if (j === 0) {
            if (i < columns) {
              udata[i] = [];
            }
            ldata[i] = [];
          }
          if (i < j) {
            if (i < columns) {
              udata[i][j] = data[i][j];
            }
            if (j < rows) {
              ldata[i][j] = 0;
            }
            continue;
          }
          if (i === j) {
            if (i < columns) {
              udata[i][j] = data[i][j];
            }
            if (j < rows) {
              ldata[i][j] = 1;
            }
            continue;
          }
          if (i < columns) {
            udata[i][j] = 0;
          }
          if (j < rows) {
            ldata[i][j] = data[i][j];
          }
        }
      }
      var l = new DenseMatrix2({
        data: ldata,
        size: lsize
      });
      var u = new DenseMatrix2({
        data: udata,
        size: usize
      });
      var pv = [];
      for (i = 0, n = p.length; i < n; i++) {
        pv[p[i]] = i;
      }
      return {
        L: l,
        U: u,
        p: pv,
        toString: function toString() {
          return "L: " + this.L.toString() + "\nU: " + this.U.toString() + "\nP: " + this.p;
        }
      };
    }
    function _sparseLUP(m) {
      var rows = m._size[0];
      var columns = m._size[1];
      var n = Math.min(rows, columns);
      var values = m._values;
      var index2 = m._index;
      var ptr = m._ptr;
      var lvalues = [];
      var lindex = [];
      var lptr = [];
      var lsize = [rows, n];
      var uvalues = [];
      var uindex = [];
      var uptr = [];
      var usize = [n, columns];
      var i, j, k;
      var pvCo = [];
      var pvOc = [];
      for (i = 0; i < rows; i++) {
        pvCo[i] = i;
        pvOc[i] = i;
      }
      var swapIndeces = function swapIndeces2(x, y) {
        var kx = pvOc[x];
        var ky = pvOc[y];
        pvCo[kx] = y;
        pvCo[ky] = x;
        pvOc[x] = ky;
        pvOc[y] = kx;
      };
      var _loop = function _loop2() {
        var spa = new Spa2();
        if (j < rows) {
          lptr.push(lvalues.length);
          lvalues.push(1);
          lindex.push(j);
        }
        uptr.push(uvalues.length);
        var k0 = ptr[j];
        var k1 = ptr[j + 1];
        for (k = k0; k < k1; k++) {
          i = index2[k];
          spa.set(pvCo[i], values[k]);
        }
        if (j > 0) {
          spa.forEach(0, j - 1, function(k2, vkj) {
            SparseMatrix2._forEachRow(k2, lvalues, lindex, lptr, function(i2, vik) {
              if (i2 > k2) {
                spa.accumulate(i2, unaryMinus2(multiplyScalar2(vik, vkj)));
              }
            });
          });
        }
        var pi = j;
        var vjj = spa.get(j);
        var pabsv = abs3(vjj);
        spa.forEach(j + 1, rows - 1, function(x, v) {
          var absv = abs3(v);
          if (larger2(absv, pabsv)) {
            pi = x;
            pabsv = absv;
            vjj = v;
          }
        });
        if (j !== pi) {
          SparseMatrix2._swapRows(j, pi, lsize[1], lvalues, lindex, lptr);
          SparseMatrix2._swapRows(j, pi, usize[1], uvalues, uindex, uptr);
          spa.swap(j, pi);
          swapIndeces(j, pi);
        }
        spa.forEach(0, rows - 1, function(x, v) {
          if (x <= j) {
            uvalues.push(v);
            uindex.push(x);
          } else {
            v = divideScalar2(v, vjj);
            if (!equalScalar2(v, 0)) {
              lvalues.push(v);
              lindex.push(x);
            }
          }
        });
      };
      for (j = 0; j < columns; j++) {
        _loop();
      }
      uptr.push(uvalues.length);
      lptr.push(lvalues.length);
      return {
        L: new SparseMatrix2({
          values: lvalues,
          index: lindex,
          ptr: lptr,
          size: lsize
        }),
        U: new SparseMatrix2({
          values: uvalues,
          index: uindex,
          ptr: uptr,
          size: usize
        }),
        p: pvCo,
        toString: function toString() {
          return "L: " + this.L.toString() + "\nU: " + this.U.toString() + "\nP: " + this.p;
        }
      };
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/decomposition/qr.js
  var name73 = "qr";
  var dependencies74 = ["typed", "matrix", "zeros", "identity", "isZero", "equal", "sign", "sqrt", "conj", "unaryMinus", "addScalar", "divideScalar", "multiplyScalar", "subtract", "complex"];
  var createQr = /* @__PURE__ */ factory(name73, dependencies74, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      zeros: zeros3,
      identity: identity2,
      isZero: isZero2,
      equal: equal3,
      sign: sign4,
      sqrt: sqrt3,
      conj: conj2,
      unaryMinus: unaryMinus2,
      addScalar: addScalar2,
      divideScalar: divideScalar2,
      multiplyScalar: multiplyScalar2,
      subtract: subtract2,
      complex: complex2
    } = _ref;
    return _extends(typed2(name73, {
      DenseMatrix: function DenseMatrix2(m) {
        return _denseQR(m);
      },
      SparseMatrix: function SparseMatrix2(m) {
        return _sparseQR(m);
      },
      Array: function Array2(a) {
        var m = matrix2(a);
        var r = _denseQR(m);
        return {
          Q: r.Q.valueOf(),
          R: r.R.valueOf()
        };
      }
    }), {
      _denseQRimpl
    });
    function _denseQRimpl(m) {
      var rows = m._size[0];
      var cols = m._size[1];
      var Q = identity2([rows], "dense");
      var Qdata = Q._data;
      var R = m.clone();
      var Rdata = R._data;
      var i, j, k;
      var w = zeros3([rows], "");
      for (k = 0; k < Math.min(cols, rows); ++k) {
        var pivot = Rdata[k][k];
        var sgn = unaryMinus2(equal3(pivot, 0) ? 1 : sign4(pivot));
        var conjSgn = conj2(sgn);
        var alphaSquared = 0;
        for (i = k; i < rows; i++) {
          alphaSquared = addScalar2(alphaSquared, multiplyScalar2(Rdata[i][k], conj2(Rdata[i][k])));
        }
        var alpha = multiplyScalar2(sgn, sqrt3(alphaSquared));
        if (!isZero2(alpha)) {
          var u1 = subtract2(pivot, alpha);
          w[k] = 1;
          for (i = k + 1; i < rows; i++) {
            w[i] = divideScalar2(Rdata[i][k], u1);
          }
          var tau = unaryMinus2(conj2(divideScalar2(u1, alpha)));
          var s = void 0;
          for (j = k; j < cols; j++) {
            s = 0;
            for (i = k; i < rows; i++) {
              s = addScalar2(s, multiplyScalar2(conj2(w[i]), Rdata[i][j]));
            }
            s = multiplyScalar2(s, tau);
            for (i = k; i < rows; i++) {
              Rdata[i][j] = multiplyScalar2(subtract2(Rdata[i][j], multiplyScalar2(w[i], s)), conjSgn);
            }
          }
          for (i = 0; i < rows; i++) {
            s = 0;
            for (j = k; j < rows; j++) {
              s = addScalar2(s, multiplyScalar2(Qdata[i][j], w[j]));
            }
            s = multiplyScalar2(s, tau);
            for (j = k; j < rows; ++j) {
              Qdata[i][j] = divideScalar2(subtract2(Qdata[i][j], multiplyScalar2(s, conj2(w[j]))), conjSgn);
            }
          }
        }
      }
      return {
        Q,
        R,
        toString: function toString() {
          return "Q: " + this.Q.toString() + "\nR: " + this.R.toString();
        }
      };
    }
    function _denseQR(m) {
      var ret = _denseQRimpl(m);
      var Rdata = ret.R._data;
      if (m._data.length > 0) {
        var zero = Rdata[0][0].type === "Complex" ? complex2(0) : 0;
        for (var i = 0; i < Rdata.length; ++i) {
          for (var j = 0; j < i && j < (Rdata[0] || []).length; ++j) {
            Rdata[i][j] = zero;
          }
        }
      }
      return ret;
    }
    function _sparseQR(m) {
      throw new Error("qr not implemented for sparse matrices yet");
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csPermute.js
  function csPermute(a, pinv, q, values) {
    var avalues = a._values;
    var aindex = a._index;
    var aptr = a._ptr;
    var asize = a._size;
    var adt = a._datatype;
    var m = asize[0];
    var n = asize[1];
    var cvalues = values && a._values ? [] : null;
    var cindex = [];
    var cptr = [];
    var nz = 0;
    for (var k = 0; k < n; k++) {
      cptr[k] = nz;
      var j = q ? q[k] : k;
      for (var t0 = aptr[j], t1 = aptr[j + 1], t = t0; t < t1; t++) {
        var r = pinv ? pinv[aindex[t]] : aindex[t];
        cindex[nz] = r;
        if (cvalues) {
          cvalues[nz] = avalues[t];
        }
        nz++;
      }
    }
    cptr[n] = nz;
    return a.createSparseMatrix({
      values: cvalues,
      index: cindex,
      ptr: cptr,
      size: [m, n],
      datatype: adt
    });
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csTdfs.js
  function csTdfs(j, k, w, head, next, post, stack) {
    var top = 0;
    w[stack] = j;
    while (top >= 0) {
      var p = w[stack + top];
      var i = w[head + p];
      if (i === -1) {
        top--;
        post[k++] = p;
      } else {
        w[head + p] = w[next + i];
        ++top;
        w[stack + top] = i;
      }
    }
    return k;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csPost.js
  function csPost(parent, n) {
    if (!parent) {
      return null;
    }
    var k = 0;
    var j;
    var post = [];
    var w = [];
    var head = 0;
    var next = n;
    var stack = 2 * n;
    for (j = 0; j < n; j++) {
      w[head + j] = -1;
    }
    for (j = n - 1; j >= 0; j--) {
      if (parent[j] === -1) {
        continue;
      }
      w[next + j] = w[head + parent[j]];
      w[head + parent[j]] = j;
    }
    for (j = 0; j < n; j++) {
      if (parent[j] !== -1) {
        continue;
      }
      k = csTdfs(j, k, w, head, next, post, stack);
    }
    return post;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csEtree.js
  function csEtree(a, ata) {
    if (!a) {
      return null;
    }
    var aindex = a._index;
    var aptr = a._ptr;
    var asize = a._size;
    var m = asize[0];
    var n = asize[1];
    var parent = [];
    var w = [];
    var ancestor = 0;
    var prev = n;
    var i, inext;
    if (ata) {
      for (i = 0; i < m; i++) {
        w[prev + i] = -1;
      }
    }
    for (var k = 0; k < n; k++) {
      parent[k] = -1;
      w[ancestor + k] = -1;
      for (var p0 = aptr[k], p1 = aptr[k + 1], p = p0; p < p1; p++) {
        var r = aindex[p];
        i = ata ? w[prev + r] : r;
        for (; i !== -1 && i < k; i = inext) {
          inext = w[ancestor + i];
          w[ancestor + i] = k;
          if (inext === -1) {
            parent[i] = k;
          }
        }
        if (ata) {
          w[prev + r] = k;
        }
      }
    }
    return parent;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csFkeep.js
  function csFkeep(a, callback, other) {
    var avalues = a._values;
    var aindex = a._index;
    var aptr = a._ptr;
    var asize = a._size;
    var n = asize[1];
    var nz = 0;
    for (var j = 0; j < n; j++) {
      var p = aptr[j];
      aptr[j] = nz;
      for (; p < aptr[j + 1]; p++) {
        if (callback(aindex[p], j, avalues ? avalues[p] : 1, other)) {
          aindex[nz] = aindex[p];
          if (avalues) {
            avalues[nz] = avalues[p];
          }
          nz++;
        }
      }
    }
    aptr[n] = nz;
    aindex.splice(nz, aindex.length - nz);
    if (avalues) {
      avalues.splice(nz, avalues.length - nz);
    }
    return nz;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csFlip.js
  function csFlip(i) {
    return -i - 2;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csAmd.js
  var name74 = "csAmd";
  var dependencies75 = ["add", "multiply", "transpose"];
  var createCsAmd = /* @__PURE__ */ factory(name74, dependencies75, (_ref) => {
    var {
      add: add3,
      multiply: multiply2,
      transpose: transpose2
    } = _ref;
    return function csAmd(order, a) {
      if (!a || order <= 0 || order > 3) {
        return null;
      }
      var asize = a._size;
      var m = asize[0];
      var n = asize[1];
      var lemax = 0;
      var dense = Math.max(16, 10 * Math.sqrt(n));
      dense = Math.min(n - 2, dense);
      var cm = _createTargetMatrix(order, a, m, n, dense);
      csFkeep(cm, _diag, null);
      var cindex = cm._index;
      var cptr = cm._ptr;
      var cnz = cptr[n];
      var P4 = [];
      var W = [];
      var len = 0;
      var nv = n + 1;
      var next = 2 * (n + 1);
      var head = 3 * (n + 1);
      var elen = 4 * (n + 1);
      var degree = 5 * (n + 1);
      var w = 6 * (n + 1);
      var hhead = 7 * (n + 1);
      var last = P4;
      var mark = _initializeQuotientGraph(n, cptr, W, len, head, last, next, hhead, nv, w, elen, degree);
      var nel = _initializeDegreeLists(n, cptr, W, degree, elen, w, dense, nv, head, last, next);
      var mindeg = 0;
      var i, j, k, k1, k2, e, pj, ln2, nvi, pk, eln, p1, p2, pn, h, d;
      while (nel < n) {
        for (k = -1; mindeg < n && (k = W[head + mindeg]) === -1; mindeg++) {
          ;
        }
        if (W[next + k] !== -1) {
          last[W[next + k]] = -1;
        }
        W[head + mindeg] = W[next + k];
        var elenk = W[elen + k];
        var nvk = W[nv + k];
        nel += nvk;
        var dk = 0;
        W[nv + k] = -nvk;
        var p = cptr[k];
        var pk1 = elenk === 0 ? p : cnz;
        var pk2 = pk1;
        for (k1 = 1; k1 <= elenk + 1; k1++) {
          if (k1 > elenk) {
            e = k;
            pj = p;
            ln2 = W[len + k] - elenk;
          } else {
            e = cindex[p++];
            pj = cptr[e];
            ln2 = W[len + e];
          }
          for (k2 = 1; k2 <= ln2; k2++) {
            i = cindex[pj++];
            if ((nvi = W[nv + i]) <= 0) {
              continue;
            }
            dk += nvi;
            W[nv + i] = -nvi;
            cindex[pk2++] = i;
            if (W[next + i] !== -1) {
              last[W[next + i]] = last[i];
            }
            if (last[i] !== -1) {
              W[next + last[i]] = W[next + i];
            } else {
              W[head + W[degree + i]] = W[next + i];
            }
          }
          if (e !== k) {
            cptr[e] = csFlip(k);
            W[w + e] = 0;
          }
        }
        if (elenk !== 0) {
          cnz = pk2;
        }
        W[degree + k] = dk;
        cptr[k] = pk1;
        W[len + k] = pk2 - pk1;
        W[elen + k] = -2;
        mark = _wclear(mark, lemax, W, w, n);
        for (pk = pk1; pk < pk2; pk++) {
          i = cindex[pk];
          if ((eln = W[elen + i]) <= 0) {
            continue;
          }
          nvi = -W[nv + i];
          var wnvi = mark - nvi;
          for (p = cptr[i], p1 = cptr[i] + eln - 1; p <= p1; p++) {
            e = cindex[p];
            if (W[w + e] >= mark) {
              W[w + e] -= nvi;
            } else if (W[w + e] !== 0) {
              W[w + e] = W[degree + e] + wnvi;
            }
          }
        }
        for (pk = pk1; pk < pk2; pk++) {
          i = cindex[pk];
          p1 = cptr[i];
          p2 = p1 + W[elen + i] - 1;
          pn = p1;
          for (h = 0, d = 0, p = p1; p <= p2; p++) {
            e = cindex[p];
            if (W[w + e] !== 0) {
              var dext = W[w + e] - mark;
              if (dext > 0) {
                d += dext;
                cindex[pn++] = e;
                h += e;
              } else {
                cptr[e] = csFlip(k);
                W[w + e] = 0;
              }
            }
          }
          W[elen + i] = pn - p1 + 1;
          var p3 = pn;
          var p4 = p1 + W[len + i];
          for (p = p2 + 1; p < p4; p++) {
            j = cindex[p];
            var nvj = W[nv + j];
            if (nvj <= 0) {
              continue;
            }
            d += nvj;
            cindex[pn++] = j;
            h += j;
          }
          if (d === 0) {
            cptr[i] = csFlip(k);
            nvi = -W[nv + i];
            dk -= nvi;
            nvk += nvi;
            nel += nvi;
            W[nv + i] = 0;
            W[elen + i] = -1;
          } else {
            W[degree + i] = Math.min(W[degree + i], d);
            cindex[pn] = cindex[p3];
            cindex[p3] = cindex[p1];
            cindex[p1] = k;
            W[len + i] = pn - p1 + 1;
            h = (h < 0 ? -h : h) % n;
            W[next + i] = W[hhead + h];
            W[hhead + h] = i;
            last[i] = h;
          }
        }
        W[degree + k] = dk;
        lemax = Math.max(lemax, dk);
        mark = _wclear(mark + lemax, lemax, W, w, n);
        for (pk = pk1; pk < pk2; pk++) {
          i = cindex[pk];
          if (W[nv + i] >= 0) {
            continue;
          }
          h = last[i];
          i = W[hhead + h];
          W[hhead + h] = -1;
          for (; i !== -1 && W[next + i] !== -1; i = W[next + i], mark++) {
            ln2 = W[len + i];
            eln = W[elen + i];
            for (p = cptr[i] + 1; p <= cptr[i] + ln2 - 1; p++) {
              W[w + cindex[p]] = mark;
            }
            var jlast = i;
            for (j = W[next + i]; j !== -1; ) {
              var ok = W[len + j] === ln2 && W[elen + j] === eln;
              for (p = cptr[j] + 1; ok && p <= cptr[j] + ln2 - 1; p++) {
                if (W[w + cindex[p]] !== mark) {
                  ok = 0;
                }
              }
              if (ok) {
                cptr[j] = csFlip(i);
                W[nv + i] += W[nv + j];
                W[nv + j] = 0;
                W[elen + j] = -1;
                j = W[next + j];
                W[next + jlast] = j;
              } else {
                jlast = j;
                j = W[next + j];
              }
            }
          }
        }
        for (p = pk1, pk = pk1; pk < pk2; pk++) {
          i = cindex[pk];
          if ((nvi = -W[nv + i]) <= 0) {
            continue;
          }
          W[nv + i] = nvi;
          d = W[degree + i] + dk - nvi;
          d = Math.min(d, n - nel - nvi);
          if (W[head + d] !== -1) {
            last[W[head + d]] = i;
          }
          W[next + i] = W[head + d];
          last[i] = -1;
          W[head + d] = i;
          mindeg = Math.min(mindeg, d);
          W[degree + i] = d;
          cindex[p++] = i;
        }
        W[nv + k] = nvk;
        if ((W[len + k] = p - pk1) === 0) {
          cptr[k] = -1;
          W[w + k] = 0;
        }
        if (elenk !== 0) {
          cnz = p;
        }
      }
      for (i = 0; i < n; i++) {
        cptr[i] = csFlip(cptr[i]);
      }
      for (j = 0; j <= n; j++) {
        W[head + j] = -1;
      }
      for (j = n; j >= 0; j--) {
        if (W[nv + j] > 0) {
          continue;
        }
        W[next + j] = W[head + cptr[j]];
        W[head + cptr[j]] = j;
      }
      for (e = n; e >= 0; e--) {
        if (W[nv + e] <= 0) {
          continue;
        }
        if (cptr[e] !== -1) {
          W[next + e] = W[head + cptr[e]];
          W[head + cptr[e]] = e;
        }
      }
      for (k = 0, i = 0; i <= n; i++) {
        if (cptr[i] === -1) {
          k = csTdfs(i, k, W, head, next, P4, w);
        }
      }
      P4.splice(P4.length - 1, 1);
      return P4;
    };
    function _createTargetMatrix(order, a, m, n, dense) {
      var at = transpose2(a);
      if (order === 1 && n === m) {
        return add3(a, at);
      }
      if (order === 2) {
        var tindex = at._index;
        var tptr = at._ptr;
        var p2 = 0;
        for (var j = 0; j < m; j++) {
          var p = tptr[j];
          tptr[j] = p2;
          if (tptr[j + 1] - p > dense) {
            continue;
          }
          for (var p1 = tptr[j + 1]; p < p1; p++) {
            tindex[p2++] = tindex[p];
          }
        }
        tptr[m] = p2;
        a = transpose2(at);
        return multiply2(at, a);
      }
      return multiply2(at, a);
    }
    function _initializeQuotientGraph(n, cptr, W, len, head, last, next, hhead, nv, w, elen, degree) {
      for (var k = 0; k < n; k++) {
        W[len + k] = cptr[k + 1] - cptr[k];
      }
      W[len + n] = 0;
      for (var i = 0; i <= n; i++) {
        W[head + i] = -1;
        last[i] = -1;
        W[next + i] = -1;
        W[hhead + i] = -1;
        W[nv + i] = 1;
        W[w + i] = 1;
        W[elen + i] = 0;
        W[degree + i] = W[len + i];
      }
      var mark = _wclear(0, 0, W, w, n);
      W[elen + n] = -2;
      cptr[n] = -1;
      W[w + n] = 0;
      return mark;
    }
    function _initializeDegreeLists(n, cptr, W, degree, elen, w, dense, nv, head, last, next) {
      var nel = 0;
      for (var i = 0; i < n; i++) {
        var d = W[degree + i];
        if (d === 0) {
          W[elen + i] = -2;
          nel++;
          cptr[i] = -1;
          W[w + i] = 0;
        } else if (d > dense) {
          W[nv + i] = 0;
          W[elen + i] = -1;
          nel++;
          cptr[i] = csFlip(n);
          W[nv + n]++;
        } else {
          var h = W[head + d];
          if (h !== -1) {
            last[h] = i;
          }
          W[next + i] = W[head + d];
          W[head + d] = i;
        }
      }
      return nel;
    }
    function _wclear(mark, lemax, W, w, n) {
      if (mark < 2 || mark + lemax < 0) {
        for (var k = 0; k < n; k++) {
          if (W[w + k] !== 0) {
            W[w + k] = 1;
          }
        }
        mark = 2;
      }
      return mark;
    }
    function _diag(i, j) {
      return i !== j;
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csLeaf.js
  function csLeaf(i, j, w, first, maxfirst, prevleaf, ancestor) {
    var s, sparent;
    var jleaf = 0;
    var q;
    if (i <= j || w[first + j] <= w[maxfirst + i]) {
      return -1;
    }
    w[maxfirst + i] = w[first + j];
    var jprev = w[prevleaf + i];
    w[prevleaf + i] = j;
    if (jprev === -1) {
      jleaf = 1;
      q = i;
    } else {
      jleaf = 2;
      for (q = jprev; q !== w[ancestor + q]; q = w[ancestor + q]) {
        ;
      }
      for (s = jprev; s !== q; s = sparent) {
        sparent = w[ancestor + s];
        w[ancestor + s] = q;
      }
    }
    return {
      jleaf,
      q
    };
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csCounts.js
  var name75 = "csCounts";
  var dependencies76 = ["transpose"];
  var createCsCounts = /* @__PURE__ */ factory(name75, dependencies76, (_ref) => {
    var {
      transpose: transpose2
    } = _ref;
    return function(a, parent, post, ata) {
      if (!a || !parent || !post) {
        return null;
      }
      var asize = a._size;
      var m = asize[0];
      var n = asize[1];
      var i, j, k, J, p, p0, p1;
      var s = 4 * n + (ata ? n + m + 1 : 0);
      var w = [];
      var ancestor = 0;
      var maxfirst = n;
      var prevleaf = 2 * n;
      var first = 3 * n;
      var head = 4 * n;
      var next = 5 * n + 1;
      for (k = 0; k < s; k++) {
        w[k] = -1;
      }
      var colcount = [];
      var at = transpose2(a);
      var tindex = at._index;
      var tptr = at._ptr;
      for (k = 0; k < n; k++) {
        j = post[k];
        colcount[j] = w[first + j] === -1 ? 1 : 0;
        for (; j !== -1 && w[first + j] === -1; j = parent[j]) {
          w[first + j] = k;
        }
      }
      if (ata) {
        for (k = 0; k < n; k++) {
          w[post[k]] = k;
        }
        for (i = 0; i < m; i++) {
          for (k = n, p0 = tptr[i], p1 = tptr[i + 1], p = p0; p < p1; p++) {
            k = Math.min(k, w[tindex[p]]);
          }
          w[next + i] = w[head + k];
          w[head + k] = i;
        }
      }
      for (i = 0; i < n; i++) {
        w[ancestor + i] = i;
      }
      for (k = 0; k < n; k++) {
        j = post[k];
        if (parent[j] !== -1) {
          colcount[parent[j]]--;
        }
        for (J = ata ? w[head + k] : j; J !== -1; J = ata ? w[next + J] : -1) {
          for (p = tptr[J]; p < tptr[J + 1]; p++) {
            i = tindex[p];
            var r = csLeaf(i, j, w, first, maxfirst, prevleaf, ancestor);
            if (r.jleaf >= 1) {
              colcount[j]++;
            }
            if (r.jleaf === 2) {
              colcount[r.q]--;
            }
          }
        }
        if (parent[j] !== -1) {
          w[ancestor + j] = parent[j];
        }
      }
      for (j = 0; j < n; j++) {
        if (parent[j] !== -1) {
          colcount[parent[j]] += colcount[j];
        }
      }
      return colcount;
    };
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csSqr.js
  var name76 = "csSqr";
  var dependencies77 = ["add", "multiply", "transpose"];
  var createCsSqr = /* @__PURE__ */ factory(name76, dependencies77, (_ref) => {
    var {
      add: add3,
      multiply: multiply2,
      transpose: transpose2
    } = _ref;
    var csAmd = createCsAmd({
      add: add3,
      multiply: multiply2,
      transpose: transpose2
    });
    var csCounts = createCsCounts({
      transpose: transpose2
    });
    return function csSqr(order, a, qr2) {
      var aptr = a._ptr;
      var asize = a._size;
      var n = asize[1];
      var k;
      var s = {};
      s.q = csAmd(order, a);
      if (order && !s.q) {
        return null;
      }
      if (qr2) {
        var c = order ? csPermute(a, null, s.q, 0) : a;
        s.parent = csEtree(c, 1);
        var post = csPost(s.parent, n);
        s.cp = csCounts(c, s.parent, post, 1);
        if (c && s.parent && s.cp && _vcount(c, s)) {
          for (s.unz = 0, k = 0; k < n; k++) {
            s.unz += s.cp[k];
          }
        }
      } else {
        s.unz = 4 * aptr[n] + n;
        s.lnz = s.unz;
      }
      return s;
    };
    function _vcount(a, s) {
      var aptr = a._ptr;
      var aindex = a._index;
      var asize = a._size;
      var m = asize[0];
      var n = asize[1];
      s.pinv = [];
      s.leftmost = [];
      var parent = s.parent;
      var pinv = s.pinv;
      var leftmost = s.leftmost;
      var w = [];
      var next = 0;
      var head = m;
      var tail = m + n;
      var nque = m + 2 * n;
      var i, k, p, p0, p1;
      for (k = 0; k < n; k++) {
        w[head + k] = -1;
        w[tail + k] = -1;
        w[nque + k] = 0;
      }
      for (i = 0; i < m; i++) {
        leftmost[i] = -1;
      }
      for (k = n - 1; k >= 0; k--) {
        for (p0 = aptr[k], p1 = aptr[k + 1], p = p0; p < p1; p++) {
          leftmost[aindex[p]] = k;
        }
      }
      for (i = m - 1; i >= 0; i--) {
        pinv[i] = -1;
        k = leftmost[i];
        if (k === -1) {
          continue;
        }
        if (w[nque + k]++ === 0) {
          w[tail + k] = i;
        }
        w[next + i] = w[head + k];
        w[head + k] = i;
      }
      s.lnz = 0;
      s.m2 = m;
      for (k = 0; k < n; k++) {
        i = w[head + k];
        s.lnz++;
        if (i < 0) {
          i = s.m2++;
        }
        pinv[i] = k;
        if (--nque[k] <= 0) {
          continue;
        }
        s.lnz += w[nque + k];
        var pa = parent[k];
        if (pa !== -1) {
          if (w[nque + pa] === 0) {
            w[tail + pa] = w[tail + k];
          }
          w[next + w[tail + k]] = w[head + pa];
          w[head + pa] = w[next + i];
          w[nque + pa] += w[nque + k];
        }
      }
      for (i = 0; i < m; i++) {
        if (pinv[i] < 0) {
          pinv[i] = k++;
        }
      }
      return true;
    }
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csMarked.js
  function csMarked(w, j) {
    return w[j] < 0;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csMark.js
  function csMark(w, j) {
    w[j] = csFlip(w[j]);
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csUnflip.js
  function csUnflip(i) {
    return i < 0 ? csFlip(i) : i;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csDfs.js
  function csDfs(j, g, top, xi, pinv) {
    var index2 = g._index;
    var ptr = g._ptr;
    var size2 = g._size;
    var n = size2[1];
    var i, p, p2;
    var head = 0;
    xi[0] = j;
    while (head >= 0) {
      j = xi[head];
      var jnew = pinv ? pinv[j] : j;
      if (!csMarked(ptr, j)) {
        csMark(ptr, j);
        xi[n + head] = jnew < 0 ? 0 : csUnflip(ptr[jnew]);
      }
      var done = 1;
      for (p = xi[n + head], p2 = jnew < 0 ? 0 : csUnflip(ptr[jnew + 1]); p < p2; p++) {
        i = index2[p];
        if (csMarked(ptr, i)) {
          continue;
        }
        xi[n + head] = p;
        xi[++head] = i;
        done = 0;
        break;
      }
      if (done) {
        head--;
        xi[--top] = j;
      }
    }
    return top;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csReach.js
  function csReach(g, b, k, xi, pinv) {
    var gptr = g._ptr;
    var gsize = g._size;
    var bindex = b._index;
    var bptr = b._ptr;
    var n = gsize[1];
    var p, p0, p1;
    var top = n;
    for (p0 = bptr[k], p1 = bptr[k + 1], p = p0; p < p1; p++) {
      var i = bindex[p];
      if (!csMarked(gptr, i)) {
        top = csDfs(i, g, top, xi, pinv);
      }
    }
    for (p = top; p < n; p++) {
      csMark(gptr, xi[p]);
    }
    return top;
  }

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csSpsolve.js
  var name77 = "csSpsolve";
  var dependencies78 = ["divideScalar", "multiply", "subtract"];
  var createCsSpsolve = /* @__PURE__ */ factory(name77, dependencies78, (_ref) => {
    var {
      divideScalar: divideScalar2,
      multiply: multiply2,
      subtract: subtract2
    } = _ref;
    return function csSpsolve(g, b, k, xi, x, pinv, lo) {
      var gvalues = g._values;
      var gindex = g._index;
      var gptr = g._ptr;
      var gsize = g._size;
      var n = gsize[1];
      var bvalues = b._values;
      var bindex = b._index;
      var bptr = b._ptr;
      var p, p0, p1, q;
      var top = csReach(g, b, k, xi, pinv);
      for (p = top; p < n; p++) {
        x[xi[p]] = 0;
      }
      for (p0 = bptr[k], p1 = bptr[k + 1], p = p0; p < p1; p++) {
        x[bindex[p]] = bvalues[p];
      }
      for (var px = top; px < n; px++) {
        var j = xi[px];
        var J = pinv ? pinv[j] : j;
        if (J < 0) {
          continue;
        }
        p0 = gptr[J];
        p1 = gptr[J + 1];
        x[j] = divideScalar2(x[j], gvalues[lo ? p0 : p1 - 1]);
        p = lo ? p0 + 1 : p0;
        q = lo ? p1 : p1 - 1;
        for (; p < q; p++) {
          var i = gindex[p];
          x[i] = subtract2(x[i], multiply2(gvalues[p], x[j]));
        }
      }
      return top;
    };
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csLu.js
  var name78 = "csLu";
  var dependencies79 = ["abs", "divideScalar", "multiply", "subtract", "larger", "largerEq", "SparseMatrix"];
  var createCsLu = /* @__PURE__ */ factory(name78, dependencies79, (_ref) => {
    var {
      abs: abs3,
      divideScalar: divideScalar2,
      multiply: multiply2,
      subtract: subtract2,
      larger: larger2,
      largerEq: largerEq2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    var csSpsolve = createCsSpsolve({
      divideScalar: divideScalar2,
      multiply: multiply2,
      subtract: subtract2
    });
    return function csLu(m, s, tol) {
      if (!m) {
        return null;
      }
      var size2 = m._size;
      var n = size2[1];
      var q;
      var lnz = 100;
      var unz = 100;
      if (s) {
        q = s.q;
        lnz = s.lnz || lnz;
        unz = s.unz || unz;
      }
      var lvalues = [];
      var lindex = [];
      var lptr = [];
      var L = new SparseMatrix2({
        values: lvalues,
        index: lindex,
        ptr: lptr,
        size: [n, n]
      });
      var uvalues = [];
      var uindex = [];
      var uptr = [];
      var U = new SparseMatrix2({
        values: uvalues,
        index: uindex,
        ptr: uptr,
        size: [n, n]
      });
      var pinv = [];
      var i, p;
      var x = [];
      var xi = [];
      for (i = 0; i < n; i++) {
        x[i] = 0;
        pinv[i] = -1;
        lptr[i + 1] = 0;
      }
      lnz = 0;
      unz = 0;
      for (var k = 0; k < n; k++) {
        lptr[k] = lnz;
        uptr[k] = unz;
        var col = q ? q[k] : k;
        var top = csSpsolve(L, m, col, xi, x, pinv, 1);
        var ipiv = -1;
        var a = -1;
        for (p = top; p < n; p++) {
          i = xi[p];
          if (pinv[i] < 0) {
            var xabs = abs3(x[i]);
            if (larger2(xabs, a)) {
              a = xabs;
              ipiv = i;
            }
          } else {
            uindex[unz] = pinv[i];
            uvalues[unz++] = x[i];
          }
        }
        if (ipiv === -1 || a <= 0) {
          return null;
        }
        if (pinv[col] < 0 && largerEq2(abs3(x[col]), multiply2(a, tol))) {
          ipiv = col;
        }
        var pivot = x[ipiv];
        uindex[unz] = k;
        uvalues[unz++] = pivot;
        pinv[ipiv] = k;
        lindex[lnz] = ipiv;
        lvalues[lnz++] = 1;
        for (p = top; p < n; p++) {
          i = xi[p];
          if (pinv[i] < 0) {
            lindex[lnz] = i;
            lvalues[lnz++] = divideScalar2(x[i], pivot);
          }
          x[i] = 0;
        }
      }
      lptr[n] = lnz;
      uptr[n] = unz;
      for (p = 0; p < lnz; p++) {
        lindex[p] = pinv[lindex[p]];
      }
      lvalues.splice(lnz, lvalues.length - lnz);
      lindex.splice(lnz, lindex.length - lnz);
      uvalues.splice(unz, uvalues.length - unz);
      uindex.splice(unz, uindex.length - unz);
      return {
        L,
        U,
        pinv
      };
    };
  });

  // node_modules/mathjs/lib/esm/function/algebra/decomposition/slu.js
  var name79 = "slu";
  var dependencies80 = ["typed", "abs", "add", "multiply", "transpose", "divideScalar", "subtract", "larger", "largerEq", "SparseMatrix"];
  var createSlu = /* @__PURE__ */ factory(name79, dependencies80, (_ref) => {
    var {
      typed: typed2,
      abs: abs3,
      add: add3,
      multiply: multiply2,
      transpose: transpose2,
      divideScalar: divideScalar2,
      subtract: subtract2,
      larger: larger2,
      largerEq: largerEq2,
      SparseMatrix: SparseMatrix2
    } = _ref;
    var csSqr = createCsSqr({
      add: add3,
      multiply: multiply2,
      transpose: transpose2
    });
    var csLu = createCsLu({
      abs: abs3,
      divideScalar: divideScalar2,
      multiply: multiply2,
      subtract: subtract2,
      larger: larger2,
      largerEq: largerEq2,
      SparseMatrix: SparseMatrix2
    });
    return typed2(name79, {
      "SparseMatrix, number, number": function SparseMatrixNumberNumber(a, order, threshold) {
        if (!isInteger(order) || order < 0 || order > 3) {
          throw new Error("Symbolic Ordering and Analysis order must be an integer number in the interval [0, 3]");
        }
        if (threshold < 0 || threshold > 1) {
          throw new Error("Partial pivoting threshold must be a number from 0 to 1");
        }
        var s = csSqr(order, a, false);
        var f = csLu(a, s, threshold);
        return {
          L: f.L,
          U: f.U,
          p: f.pinv,
          q: s.q,
          toString: function toString() {
            return "L: " + this.L.toString() + "\nU: " + this.U.toString() + "\np: " + this.p.toString() + (this.q ? "\nq: " + this.q.toString() : "") + "\n";
          }
        };
      }
    });
  });

  // node_modules/mathjs/lib/esm/function/algebra/sparse/csIpvec.js
  function csIpvec(p, b) {
    var k;
    var n = b.length;
    var x = [];
    if (p) {
      for (k = 0; k < n; k++) {
        x[p[k]] = b[k];
      }
    } else {
      for (k = 0; k < n; k++) {
        x[k] = b[k];
      }
    }
    return x;
  }

  // node_modules/mathjs/lib/esm/function/algebra/solver/lusolve.js
  var name80 = "lusolve";
  var dependencies81 = ["typed", "matrix", "lup", "slu", "usolve", "lsolve", "DenseMatrix"];
  var createLusolve = /* @__PURE__ */ factory(name80, dependencies81, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      lup: lup2,
      slu: slu2,
      usolve: usolve2,
      lsolve: lsolve2,
      DenseMatrix: DenseMatrix2
    } = _ref;
    var solveValidation = createSolveValidation({
      DenseMatrix: DenseMatrix2
    });
    return typed2(name80, {
      "Array, Array | Matrix": function ArrayArrayMatrix(a, b) {
        a = matrix2(a);
        var d = lup2(a);
        var x = _lusolve(d.L, d.U, d.p, null, b);
        return x.valueOf();
      },
      "DenseMatrix, Array | Matrix": function DenseMatrixArrayMatrix(a, b) {
        var d = lup2(a);
        return _lusolve(d.L, d.U, d.p, null, b);
      },
      "SparseMatrix, Array | Matrix": function SparseMatrixArrayMatrix(a, b) {
        var d = lup2(a);
        return _lusolve(d.L, d.U, d.p, null, b);
      },
      "SparseMatrix, Array | Matrix, number, number": function SparseMatrixArrayMatrixNumberNumber(a, b, order, threshold) {
        var d = slu2(a, order, threshold);
        return _lusolve(d.L, d.U, d.p, d.q, b);
      },
      "Object, Array | Matrix": function ObjectArrayMatrix(d, b) {
        return _lusolve(d.L, d.U, d.p, d.q, b);
      }
    });
    function _toMatrix(a) {
      if (isMatrix(a)) {
        return a;
      }
      if (isArray(a)) {
        return matrix2(a);
      }
      throw new TypeError("Invalid Matrix LU decomposition");
    }
    function _lusolve(l, u, p, q, b) {
      l = _toMatrix(l);
      u = _toMatrix(u);
      if (p) {
        b = solveValidation(l, b, true);
        b._data = csIpvec(p, b._data);
      }
      var y = lsolve2(l, b);
      var x = usolve2(u, y);
      if (q) {
        x._data = csIpvec(q, x._data);
      }
      return x;
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/det.js
  var name81 = "det";
  var dependencies82 = ["typed", "matrix", "subtract", "multiply", "unaryMinus", "lup"];
  var createDet = /* @__PURE__ */ factory(name81, dependencies82, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      subtract: subtract2,
      multiply: multiply2,
      unaryMinus: unaryMinus2,
      lup: lup2
    } = _ref;
    return typed2(name81, {
      any: function any(x) {
        return clone(x);
      },
      "Array | Matrix": function det2(x) {
        var size2;
        if (isMatrix(x)) {
          size2 = x.size();
        } else if (Array.isArray(x)) {
          x = matrix2(x);
          size2 = x.size();
        } else {
          size2 = [];
        }
        switch (size2.length) {
          case 0:
            return clone(x);
          case 1:
            if (size2[0] === 1) {
              return clone(x.valueOf()[0]);
            } else {
              throw new RangeError("Matrix must be square (size: " + format3(size2) + ")");
            }
          case 2: {
            var rows = size2[0];
            var cols = size2[1];
            if (rows === cols) {
              return _det(x.clone().valueOf(), rows, cols);
            } else {
              throw new RangeError("Matrix must be square (size: " + format3(size2) + ")");
            }
          }
          default:
            throw new RangeError("Matrix must be two dimensional (size: " + format3(size2) + ")");
        }
      }
    });
    function _det(matrix3, rows, cols) {
      if (rows === 1) {
        return clone(matrix3[0][0]);
      } else if (rows === 2) {
        return subtract2(multiply2(matrix3[0][0], matrix3[1][1]), multiply2(matrix3[1][0], matrix3[0][1]));
      } else {
        var decomp = lup2(matrix3);
        var det2 = decomp.U[0][0];
        for (var _i = 1; _i < rows; _i++) {
          det2 = multiply2(det2, decomp.U[_i][_i]);
        }
        var evenCycles = 0;
        var i = 0;
        var visited = [];
        while (true) {
          while (visited[i]) {
            i++;
          }
          if (i >= rows) break;
          var j = i;
          var cycleLen2 = 0;
          while (!visited[decomp.p[j]]) {
            visited[decomp.p[j]] = true;
            j = decomp.p[j];
            cycleLen2++;
          }
          if (cycleLen2 % 2 === 0) {
            evenCycles++;
          }
        }
        return evenCycles % 2 === 0 ? det2 : unaryMinus2(det2);
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/inv.js
  var name82 = "inv";
  var dependencies83 = ["typed", "matrix", "divideScalar", "addScalar", "multiply", "unaryMinus", "det", "identity", "abs"];
  var createInv = /* @__PURE__ */ factory(name82, dependencies83, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      divideScalar: divideScalar2,
      addScalar: addScalar2,
      multiply: multiply2,
      unaryMinus: unaryMinus2,
      det: det2,
      identity: identity2,
      abs: abs3
    } = _ref;
    return typed2(name82, {
      "Array | Matrix": function ArrayMatrix(x) {
        var size2 = isMatrix(x) ? x.size() : arraySize(x);
        switch (size2.length) {
          case 1:
            if (size2[0] === 1) {
              if (isMatrix(x)) {
                return matrix2([divideScalar2(1, x.valueOf()[0])]);
              } else {
                return [divideScalar2(1, x[0])];
              }
            } else {
              throw new RangeError("Matrix must be square (size: " + format3(size2) + ")");
            }
          case 2: {
            var rows = size2[0];
            var cols = size2[1];
            if (rows === cols) {
              if (isMatrix(x)) {
                return matrix2(_inv(x.valueOf(), rows, cols), x.storage());
              } else {
                return _inv(x, rows, cols);
              }
            } else {
              throw new RangeError("Matrix must be square (size: " + format3(size2) + ")");
            }
          }
          default:
            throw new RangeError("Matrix must be two dimensional (size: " + format3(size2) + ")");
        }
      },
      any: function any(x) {
        return divideScalar2(1, x);
      }
    });
    function _inv(mat, rows, cols) {
      var r, s, f, value, temp;
      if (rows === 1) {
        value = mat[0][0];
        if (value === 0) {
          throw Error("Cannot calculate inverse, determinant is zero");
        }
        return [[divideScalar2(1, value)]];
      } else if (rows === 2) {
        var d = det2(mat);
        if (d === 0) {
          throw Error("Cannot calculate inverse, determinant is zero");
        }
        return [[divideScalar2(mat[1][1], d), divideScalar2(unaryMinus2(mat[0][1]), d)], [divideScalar2(unaryMinus2(mat[1][0]), d), divideScalar2(mat[0][0], d)]];
      } else {
        var A = mat.concat();
        for (r = 0; r < rows; r++) {
          A[r] = A[r].concat();
        }
        var B = identity2(rows).valueOf();
        for (var c = 0; c < cols; c++) {
          var ABig = abs3(A[c][c]);
          var rBig = c;
          r = c + 1;
          while (r < rows) {
            if (abs3(A[r][c]) > ABig) {
              ABig = abs3(A[r][c]);
              rBig = r;
            }
            r++;
          }
          if (ABig === 0) {
            throw Error("Cannot calculate inverse, determinant is zero");
          }
          r = rBig;
          if (r !== c) {
            temp = A[c];
            A[c] = A[r];
            A[r] = temp;
            temp = B[c];
            B[c] = B[r];
            B[r] = temp;
          }
          var Ac = A[c];
          var Bc = B[c];
          for (r = 0; r < rows; r++) {
            var Ar = A[r];
            var Br = B[r];
            if (r !== c) {
              if (Ar[c] !== 0) {
                f = divideScalar2(unaryMinus2(Ar[c]), Ac[c]);
                for (s = c; s < cols; s++) {
                  Ar[s] = addScalar2(Ar[s], multiply2(f, Ac[s]));
                }
                for (s = 0; s < cols; s++) {
                  Br[s] = addScalar2(Br[s], multiply2(f, Bc[s]));
                }
              }
            } else {
              f = Ac[c];
              for (s = c; s < cols; s++) {
                Ar[s] = divideScalar2(Ar[s], f);
              }
              for (s = 0; s < cols; s++) {
                Br[s] = divideScalar2(Br[s], f);
              }
            }
          }
        }
        return B;
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/matrix/eigs/complexEigs.js
  function createComplexEigs(_ref) {
    var {
      addScalar: addScalar2,
      subtract: subtract2,
      flatten: flatten3,
      multiply: multiply2,
      multiplyScalar: multiplyScalar2,
      divideScalar: divideScalar2,
      sqrt: sqrt3,
      abs: abs3,
      bignumber: bignumber2,
      diag: diag2,
      inv: inv2,
      qr: qr2,
      usolve: usolve2,
      usolveAll: usolveAll2,
      equal: equal3,
      complex: complex2,
      larger: larger2,
      smaller: smaller2,
      matrixFromColumns: matrixFromColumns2,
      dot: dot2
    } = _ref;
    function complexEigs(arr, N, prec, type, findVectors) {
      if (findVectors === void 0) {
        findVectors = true;
      }
      var R = balance(arr, N, prec, type, findVectors);
      reduceToHessenberg(arr, N, prec, type, findVectors, R);
      var {
        values,
        C
      } = iterateUntilTriangular(arr, N, prec, type, findVectors);
      C = multiply2(inv2(R), C);
      var vectors;
      if (findVectors) {
        vectors = findEigenvectors(arr, N, C, values, prec, type);
        vectors = matrixFromColumns2(...vectors);
      }
      return {
        values,
        vectors
      };
    }
    function balance(arr, N, prec, type, findVectors) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var zero = big ? bignumber2(0) : cplx ? complex2(0) : 0;
      var one = big ? bignumber2(1) : cplx ? complex2(1) : 1;
      var radix = big ? bignumber2(10) : 2;
      var radixSq = multiplyScalar2(radix, radix);
      var Rdiag;
      if (findVectors) {
        Rdiag = Array(N).fill(one);
      }
      var last = false;
      while (!last) {
        last = true;
        for (var i = 0; i < N; i++) {
          var colNorm = zero;
          var rowNorm = zero;
          for (var j = 0; j < N; j++) {
            if (i === j) continue;
            var c = abs3(arr[i][j]);
            colNorm = addScalar2(colNorm, c);
            rowNorm = addScalar2(rowNorm, c);
          }
          if (!equal3(colNorm, 0) && !equal3(rowNorm, 0)) {
            var f = one;
            var _c = colNorm;
            var rowDivRadix = divideScalar2(rowNorm, radix);
            var rowMulRadix = multiplyScalar2(rowNorm, radix);
            while (smaller2(_c, rowDivRadix)) {
              _c = multiplyScalar2(_c, radixSq);
              f = multiplyScalar2(f, radix);
            }
            while (larger2(_c, rowMulRadix)) {
              _c = divideScalar2(_c, radixSq);
              f = divideScalar2(f, radix);
            }
            var condition = smaller2(divideScalar2(addScalar2(_c, rowNorm), f), multiplyScalar2(addScalar2(colNorm, rowNorm), 0.95));
            if (condition) {
              last = false;
              var g = divideScalar2(1, f);
              for (var _j = 0; _j < N; _j++) {
                if (i === _j) {
                  continue;
                }
                arr[i][_j] = multiplyScalar2(arr[i][_j], f);
                arr[_j][i] = multiplyScalar2(arr[_j][i], g);
              }
              if (findVectors) {
                Rdiag[i] = multiplyScalar2(Rdiag[i], f);
              }
            }
          }
        }
      }
      return diag2(Rdiag);
    }
    function reduceToHessenberg(arr, N, prec, type, findVectors, R) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var zero = big ? bignumber2(0) : cplx ? complex2(0) : 0;
      if (big) {
        prec = bignumber2(prec);
      }
      for (var i = 0; i < N - 2; i++) {
        var maxIndex = 0;
        var max2 = zero;
        for (var j = i + 1; j < N; j++) {
          var el = arr[j][i];
          if (smaller2(abs3(max2), abs3(el))) {
            max2 = el;
            maxIndex = j;
          }
        }
        if (smaller2(abs3(max2), prec)) {
          continue;
        }
        if (maxIndex !== i + 1) {
          var tmp1 = arr[maxIndex];
          arr[maxIndex] = arr[i + 1];
          arr[i + 1] = tmp1;
          for (var _j2 = 0; _j2 < N; _j2++) {
            var tmp2 = arr[_j2][maxIndex];
            arr[_j2][maxIndex] = arr[_j2][i + 1];
            arr[_j2][i + 1] = tmp2;
          }
          if (findVectors) {
            var tmp3 = R[maxIndex];
            R[maxIndex] = R[i + 1];
            R[i + 1] = tmp3;
          }
        }
        for (var _j3 = i + 2; _j3 < N; _j3++) {
          var n = divideScalar2(arr[_j3][i], max2);
          if (n === 0) {
            continue;
          }
          for (var k = 0; k < N; k++) {
            arr[_j3][k] = subtract2(arr[_j3][k], multiplyScalar2(n, arr[i + 1][k]));
          }
          for (var _k = 0; _k < N; _k++) {
            arr[_k][i + 1] = addScalar2(arr[_k][i + 1], multiplyScalar2(n, arr[_k][_j3]));
          }
          if (findVectors) {
            for (var _k2 = 0; _k2 < N; _k2++) {
              R[_j3][_k2] = subtract2(R[_j3][_k2], multiplyScalar2(n, R[i + 1][_k2]));
            }
          }
        }
      }
      return R;
    }
    function iterateUntilTriangular(A, N, prec, type, findVectors) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var one = big ? bignumber2(1) : cplx ? complex2(1) : 1;
      if (big) {
        prec = bignumber2(prec);
      }
      var arr = clone(A);
      var lambdas = [];
      var n = N;
      var Sdiag = [];
      var Qtotal = findVectors ? diag2(Array(N).fill(one)) : void 0;
      var Qpartial = findVectors ? diag2(Array(n).fill(one)) : void 0;
      var lastConvergenceBefore = 0;
      while (lastConvergenceBefore <= 100) {
        lastConvergenceBefore += 1;
        var k = 0;
        for (var i = 0; i < n; i++) {
          arr[i][i] = subtract2(arr[i][i], k);
        }
        var {
          Q,
          R
        } = qr2(arr);
        arr = multiply2(R, Q);
        for (var _i = 0; _i < n; _i++) {
          arr[_i][_i] = addScalar2(arr[_i][_i], k);
        }
        if (findVectors) {
          Qpartial = multiply2(Qpartial, Q);
        }
        if (n === 1 || smaller2(abs3(arr[n - 1][n - 2]), prec)) {
          lastConvergenceBefore = 0;
          lambdas.push(arr[n - 1][n - 1]);
          if (findVectors) {
            Sdiag.unshift([[1]]);
            inflateMatrix(Qpartial, N);
            Qtotal = multiply2(Qtotal, Qpartial);
            if (n > 1) {
              Qpartial = diag2(Array(n - 1).fill(one));
            }
          }
          n -= 1;
          arr.pop();
          for (var _i2 = 0; _i2 < n; _i2++) {
            arr[_i2].pop();
          }
        } else if (n === 2 || smaller2(abs3(arr[n - 2][n - 3]), prec)) {
          lastConvergenceBefore = 0;
          var ll = eigenvalues2x2(arr[n - 2][n - 2], arr[n - 2][n - 1], arr[n - 1][n - 2], arr[n - 1][n - 1]);
          lambdas.push(...ll);
          if (findVectors) {
            Sdiag.unshift(jordanBase2x2(arr[n - 2][n - 2], arr[n - 2][n - 1], arr[n - 1][n - 2], arr[n - 1][n - 1], ll[0], ll[1], prec, type));
            inflateMatrix(Qpartial, N);
            Qtotal = multiply2(Qtotal, Qpartial);
            if (n > 2) {
              Qpartial = diag2(Array(n - 2).fill(one));
            }
          }
          n -= 2;
          arr.pop();
          arr.pop();
          for (var _i3 = 0; _i3 < n; _i3++) {
            arr[_i3].pop();
            arr[_i3].pop();
          }
        }
        if (n === 0) {
          break;
        }
      }
      lambdas.sort((a, b) => +subtract2(abs3(a), abs3(b)));
      if (lastConvergenceBefore > 100) {
        var err = Error("The eigenvalues failed to converge. Only found these eigenvalues: " + lambdas.join(", "));
        err.values = lambdas;
        err.vectors = [];
        throw err;
      }
      var C = findVectors ? multiply2(Qtotal, blockDiag(Sdiag, N)) : void 0;
      return {
        values: lambdas,
        C
      };
    }
    function findEigenvectors(A, N, C, values, prec, type) {
      var Cinv = inv2(C);
      var U = multiply2(Cinv, A, C);
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var zero = big ? bignumber2(0) : cplx ? complex2(0) : 0;
      var one = big ? bignumber2(1) : cplx ? complex2(1) : 1;
      var uniqueValues = [];
      var multiplicities = [];
      for (var \u03BB of values) {
        var i = indexOf(uniqueValues, \u03BB, equal3);
        if (i === -1) {
          uniqueValues.push(\u03BB);
          multiplicities.push(1);
        } else {
          multiplicities[i] += 1;
        }
      }
      var vectors = [];
      var len = uniqueValues.length;
      var b = Array(N).fill(zero);
      var E = diag2(Array(N).fill(one));
      var failedLambdas = [];
      for (var _i4 = 0; _i4 < len; _i4++) {
        var _\u03BB = uniqueValues[_i4];
        var _A = subtract2(U, multiply2(_\u03BB, E));
        var solutions = usolveAll2(_A, b);
        solutions = solutions.map((v) => multiply2(C, v));
        solutions.shift();
        while (solutions.length < multiplicities[_i4]) {
          var approxVec = inverseIterate(_A, N, solutions, prec, type);
          if (approxVec == null) {
            failedLambdas.push(_\u03BB);
            break;
          }
          solutions.push(approxVec);
        }
        vectors.push(...solutions.map((v) => flatten3(v)));
      }
      if (failedLambdas.length !== 0) {
        var err = new Error("Failed to find eigenvectors for the following eigenvalues: " + failedLambdas.join(", "));
        err.values = values;
        err.vectors = vectors;
        throw err;
      }
      return vectors;
    }
    function eigenvalues2x2(a, b, c, d) {
      var trA = addScalar2(a, d);
      var detA = subtract2(multiplyScalar2(a, d), multiplyScalar2(b, c));
      var x = multiplyScalar2(trA, 0.5);
      var y = multiplyScalar2(sqrt3(subtract2(multiplyScalar2(trA, trA), multiplyScalar2(4, detA))), 0.5);
      return [addScalar2(x, y), subtract2(x, y)];
    }
    function jordanBase2x2(a, b, c, d, l1, l2, prec, type) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var zero = big ? bignumber2(0) : cplx ? complex2(0) : 0;
      var one = big ? bignumber2(1) : cplx ? complex2(1) : 1;
      if (smaller2(abs3(c), prec)) {
        return [[one, zero], [zero, one]];
      }
      if (larger2(abs3(subtract2(l1, l2)), prec)) {
        return [[subtract2(l1, d), subtract2(l2, d)], [c, c]];
      }
      var na = subtract2(a, l1);
      var nb = subtract2(b, l1);
      var nc = subtract2(c, l1);
      var nd = subtract2(d, l1);
      if (smaller2(abs3(nb), prec)) {
        return [[na, one], [nc, zero]];
      } else {
        return [[nb, zero], [nd, one]];
      }
    }
    function inflateMatrix(arr, N) {
      for (var i = 0; i < arr.length; i++) {
        arr[i].push(...Array(N - arr[i].length).fill(0));
      }
      for (var _i5 = arr.length; _i5 < N; _i5++) {
        arr.push(Array(N).fill(0));
        arr[_i5][_i5] = 1;
      }
      return arr;
    }
    function blockDiag(arr, N) {
      var M = [];
      for (var i = 0; i < N; i++) {
        M[i] = Array(N).fill(0);
      }
      var I = 0;
      for (var sub2 of arr) {
        var n = sub2.length;
        for (var _i6 = 0; _i6 < n; _i6++) {
          for (var j = 0; j < n; j++) {
            M[I + _i6][I + j] = sub2[_i6][j];
          }
        }
        I += n;
      }
      return M;
    }
    function indexOf(arr, el, fn) {
      for (var i = 0; i < arr.length; i++) {
        if (fn(arr[i], el)) {
          return i;
        }
      }
      return -1;
    }
    function inverseIterate(A, N, orthog, prec, type) {
      var largeNum = type === "BigNumber" ? bignumber2(1e3) : 1e3;
      var b;
      var i = 0;
      while (true) {
        b = randomOrthogonalVector(N, orthog, type);
        b = usolve2(A, b);
        if (larger2(norm2(b), largeNum)) {
          break;
        }
        if (++i >= 5) {
          return null;
        }
      }
      i = 0;
      while (true) {
        var c = usolve2(A, b);
        if (smaller2(norm2(orthogonalComplement(b, [c])), prec)) {
          break;
        }
        if (++i >= 10) {
          return null;
        }
        b = normalize(c);
      }
      return b;
    }
    function randomOrthogonalVector(N, orthog, type) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var v = Array(N).fill(0).map((_) => 2 * Math.random() - 1);
      if (big) {
        v = v.map((n) => bignumber2(n));
      }
      if (cplx) {
        v = v.map((n) => complex2(n));
      }
      v = orthogonalComplement(v, orthog);
      return normalize(v, type);
    }
    function orthogonalComplement(v, orthog) {
      for (var w of orthog) {
        v = subtract2(v, multiply2(divideScalar2(dot2(w, v), dot2(w, w)), w));
      }
      return v;
    }
    function norm2(v) {
      return abs3(sqrt3(dot2(v, v)));
    }
    function normalize(v, type) {
      var big = type === "BigNumber";
      var cplx = type === "Complex";
      var one = big ? bignumber2(1) : cplx ? complex2(1) : 1;
      return multiply2(divideScalar2(one, norm2(v)), v);
    }
    return complexEigs;
  }

  // node_modules/mathjs/lib/esm/function/matrix/eigs/realSymetric.js
  function createRealSymmetric(_ref) {
    var {
      config: config4,
      addScalar: addScalar2,
      subtract: subtract2,
      abs: abs3,
      atan: atan4,
      cos: cos3,
      sin: sin3,
      multiplyScalar: multiplyScalar2,
      inv: inv2,
      bignumber: bignumber2,
      multiply: multiply2,
      add: add3
    } = _ref;
    function main(arr, N) {
      var prec = arguments.length > 2 && arguments[2] !== void 0 ? arguments[2] : config4.epsilon;
      var type = arguments.length > 3 ? arguments[3] : void 0;
      if (type === "number") {
        return diag2(arr, prec);
      }
      if (type === "BigNumber") {
        return diagBig(arr, prec);
      }
      throw TypeError("Unsupported data type: " + type);
    }
    function diag2(x, precision) {
      var N = x.length;
      var e0 = Math.abs(precision / N);
      var psi;
      var Sij = new Array(N);
      for (var i = 0; i < N; i++) {
        Sij[i] = createArray(N, 0);
        Sij[i][i] = 1;
      }
      var Vab = getAij(x);
      while (Math.abs(Vab[1]) >= Math.abs(e0)) {
        var _i = Vab[0][0];
        var j = Vab[0][1];
        psi = getTheta(x[_i][_i], x[j][j], x[_i][j]);
        x = x1(x, psi, _i, j);
        Sij = Sij1(Sij, psi, _i, j);
        Vab = getAij(x);
      }
      var Ei = createArray(N, 0);
      for (var _i2 = 0; _i2 < N; _i2++) {
        Ei[_i2] = x[_i2][_i2];
      }
      return sorting(clone(Ei), clone(Sij));
    }
    function diagBig(x, precision) {
      var N = x.length;
      var e0 = abs3(precision / N);
      var psi;
      var Sij = new Array(N);
      for (var i = 0; i < N; i++) {
        Sij[i] = createArray(N, 0);
        Sij[i][i] = 1;
      }
      var Vab = getAijBig(x);
      while (abs3(Vab[1]) >= abs3(e0)) {
        var _i3 = Vab[0][0];
        var j = Vab[0][1];
        psi = getThetaBig(x[_i3][_i3], x[j][j], x[_i3][j]);
        x = x1Big(x, psi, _i3, j);
        Sij = Sij1Big(Sij, psi, _i3, j);
        Vab = getAijBig(x);
      }
      var Ei = createArray(N, 0);
      for (var _i4 = 0; _i4 < N; _i4++) {
        Ei[_i4] = x[_i4][_i4];
      }
      return sorting(clone(Ei), clone(Sij));
    }
    function getTheta(aii, ajj, aij) {
      var denom = ajj - aii;
      if (Math.abs(denom) <= config4.epsilon) {
        return Math.PI / 4;
      } else {
        return 0.5 * Math.atan(2 * aij / (ajj - aii));
      }
    }
    function getThetaBig(aii, ajj, aij) {
      var denom = subtract2(ajj, aii);
      if (abs3(denom) <= config4.epsilon) {
        return bignumber2(-1).acos().div(4);
      } else {
        return multiplyScalar2(0.5, atan4(multiply2(2, aij, inv2(denom))));
      }
    }
    function Sij1(Sij, theta, i, j) {
      var N = Sij.length;
      var c = Math.cos(theta);
      var s = Math.sin(theta);
      var Ski = createArray(N, 0);
      var Skj = createArray(N, 0);
      for (var k = 0; k < N; k++) {
        Ski[k] = c * Sij[k][i] - s * Sij[k][j];
        Skj[k] = s * Sij[k][i] + c * Sij[k][j];
      }
      for (var _k = 0; _k < N; _k++) {
        Sij[_k][i] = Ski[_k];
        Sij[_k][j] = Skj[_k];
      }
      return Sij;
    }
    function Sij1Big(Sij, theta, i, j) {
      var N = Sij.length;
      var c = cos3(theta);
      var s = sin3(theta);
      var Ski = createArray(N, bignumber2(0));
      var Skj = createArray(N, bignumber2(0));
      for (var k = 0; k < N; k++) {
        Ski[k] = subtract2(multiplyScalar2(c, Sij[k][i]), multiplyScalar2(s, Sij[k][j]));
        Skj[k] = addScalar2(multiplyScalar2(s, Sij[k][i]), multiplyScalar2(c, Sij[k][j]));
      }
      for (var _k2 = 0; _k2 < N; _k2++) {
        Sij[_k2][i] = Ski[_k2];
        Sij[_k2][j] = Skj[_k2];
      }
      return Sij;
    }
    function x1Big(Hij, theta, i, j) {
      var N = Hij.length;
      var c = bignumber2(cos3(theta));
      var s = bignumber2(sin3(theta));
      var c2 = multiplyScalar2(c, c);
      var s2 = multiplyScalar2(s, s);
      var Aki = createArray(N, bignumber2(0));
      var Akj = createArray(N, bignumber2(0));
      var csHij = multiply2(bignumber2(2), c, s, Hij[i][j]);
      var Aii = addScalar2(subtract2(multiplyScalar2(c2, Hij[i][i]), csHij), multiplyScalar2(s2, Hij[j][j]));
      var Ajj = add3(multiplyScalar2(s2, Hij[i][i]), csHij, multiplyScalar2(c2, Hij[j][j]));
      for (var k = 0; k < N; k++) {
        Aki[k] = subtract2(multiplyScalar2(c, Hij[i][k]), multiplyScalar2(s, Hij[j][k]));
        Akj[k] = addScalar2(multiplyScalar2(s, Hij[i][k]), multiplyScalar2(c, Hij[j][k]));
      }
      Hij[i][i] = Aii;
      Hij[j][j] = Ajj;
      Hij[i][j] = bignumber2(0);
      Hij[j][i] = bignumber2(0);
      for (var _k3 = 0; _k3 < N; _k3++) {
        if (_k3 !== i && _k3 !== j) {
          Hij[i][_k3] = Aki[_k3];
          Hij[_k3][i] = Aki[_k3];
          Hij[j][_k3] = Akj[_k3];
          Hij[_k3][j] = Akj[_k3];
        }
      }
      return Hij;
    }
    function x1(Hij, theta, i, j) {
      var N = Hij.length;
      var c = Math.cos(theta);
      var s = Math.sin(theta);
      var c2 = c * c;
      var s2 = s * s;
      var Aki = createArray(N, 0);
      var Akj = createArray(N, 0);
      var Aii = c2 * Hij[i][i] - 2 * c * s * Hij[i][j] + s2 * Hij[j][j];
      var Ajj = s2 * Hij[i][i] + 2 * c * s * Hij[i][j] + c2 * Hij[j][j];
      for (var k = 0; k < N; k++) {
        Aki[k] = c * Hij[i][k] - s * Hij[j][k];
        Akj[k] = s * Hij[i][k] + c * Hij[j][k];
      }
      Hij[i][i] = Aii;
      Hij[j][j] = Ajj;
      Hij[i][j] = 0;
      Hij[j][i] = 0;
      for (var _k4 = 0; _k4 < N; _k4++) {
        if (_k4 !== i && _k4 !== j) {
          Hij[i][_k4] = Aki[_k4];
          Hij[_k4][i] = Aki[_k4];
          Hij[j][_k4] = Akj[_k4];
          Hij[_k4][j] = Akj[_k4];
        }
      }
      return Hij;
    }
    function getAij(Mij) {
      var N = Mij.length;
      var maxMij = 0;
      var maxIJ = [0, 1];
      for (var i = 0; i < N; i++) {
        for (var j = i + 1; j < N; j++) {
          if (Math.abs(maxMij) < Math.abs(Mij[i][j])) {
            maxMij = Math.abs(Mij[i][j]);
            maxIJ = [i, j];
          }
        }
      }
      return [maxIJ, maxMij];
    }
    function getAijBig(Mij) {
      var N = Mij.length;
      var maxMij = 0;
      var maxIJ = [0, 1];
      for (var i = 0; i < N; i++) {
        for (var j = i + 1; j < N; j++) {
          if (abs3(maxMij) < abs3(Mij[i][j])) {
            maxMij = abs3(Mij[i][j]);
            maxIJ = [i, j];
          }
        }
      }
      return [maxIJ, maxMij];
    }
    function sorting(E, S) {
      var N = E.length;
      var values = Array(N);
      var vectors = Array(N);
      for (var k = 0; k < N; k++) {
        vectors[k] = Array(N);
      }
      for (var i = 0; i < N; i++) {
        var minID = 0;
        var minE = E[0];
        for (var j = 0; j < E.length; j++) {
          if (abs3(E[j]) < abs3(minE)) {
            minID = j;
            minE = E[minID];
          }
        }
        values[i] = E.splice(minID, 1)[0];
        for (var _k5 = 0; _k5 < N; _k5++) {
          vectors[_k5][i] = S[_k5][minID];
          S[_k5].splice(minID, 1);
        }
      }
      return {
        values,
        vectors
      };
    }
    function createArray(size2, value) {
      var array = new Array(size2);
      for (var i = 0; i < size2; i++) {
        array[i] = value;
      }
      return array;
    }
    return main;
  }

  // node_modules/mathjs/lib/esm/function/matrix/eigs.js
  var name83 = "eigs";
  var dependencies84 = ["config", "typed", "matrix", "addScalar", "equal", "subtract", "abs", "atan", "cos", "sin", "multiplyScalar", "divideScalar", "inv", "bignumber", "multiply", "add", "larger", "column", "flatten", "number", "complex", "sqrt", "diag", "qr", "usolve", "usolveAll", "im", "re", "smaller", "matrixFromColumns", "dot"];
  var createEigs = /* @__PURE__ */ factory(name83, dependencies84, (_ref) => {
    var {
      config: config4,
      typed: typed2,
      matrix: matrix2,
      addScalar: addScalar2,
      subtract: subtract2,
      equal: equal3,
      abs: abs3,
      atan: atan4,
      cos: cos3,
      sin: sin3,
      multiplyScalar: multiplyScalar2,
      divideScalar: divideScalar2,
      inv: inv2,
      bignumber: bignumber2,
      multiply: multiply2,
      add: add3,
      larger: larger2,
      column: column2,
      flatten: flatten3,
      number: number2,
      complex: complex2,
      sqrt: sqrt3,
      diag: diag2,
      qr: qr2,
      usolve: usolve2,
      usolveAll: usolveAll2,
      im: im2,
      re: re2,
      smaller: smaller2,
      matrixFromColumns: matrixFromColumns2,
      dot: dot2
    } = _ref;
    var doRealSymetric = createRealSymmetric({
      config: config4,
      addScalar: addScalar2,
      subtract: subtract2,
      column: column2,
      flatten: flatten3,
      equal: equal3,
      abs: abs3,
      atan: atan4,
      cos: cos3,
      sin: sin3,
      multiplyScalar: multiplyScalar2,
      inv: inv2,
      bignumber: bignumber2,
      complex: complex2,
      multiply: multiply2,
      add: add3
    });
    var doComplexEigs = createComplexEigs({
      config: config4,
      addScalar: addScalar2,
      subtract: subtract2,
      multiply: multiply2,
      multiplyScalar: multiplyScalar2,
      flatten: flatten3,
      divideScalar: divideScalar2,
      sqrt: sqrt3,
      abs: abs3,
      bignumber: bignumber2,
      diag: diag2,
      qr: qr2,
      inv: inv2,
      usolve: usolve2,
      usolveAll: usolveAll2,
      equal: equal3,
      complex: complex2,
      larger: larger2,
      smaller: smaller2,
      matrixFromColumns: matrixFromColumns2,
      dot: dot2
    });
    return typed2("eigs", {
      Array: function Array2(x) {
        var mat = matrix2(x);
        return computeValuesAndVectors(mat);
      },
      "Array, number|BigNumber": function ArrayNumberBigNumber(x, prec) {
        var mat = matrix2(x);
        return computeValuesAndVectors(mat, prec);
      },
      Matrix: function Matrix2(mat) {
        var {
          values,
          vectors
        } = computeValuesAndVectors(mat);
        return {
          values: matrix2(values),
          vectors: matrix2(vectors)
        };
      },
      "Matrix, number|BigNumber": function MatrixNumberBigNumber(mat, prec) {
        var {
          values,
          vectors
        } = computeValuesAndVectors(mat, prec);
        return {
          values: matrix2(values),
          vectors: matrix2(vectors)
        };
      }
    });
    function computeValuesAndVectors(mat, prec) {
      if (prec === void 0) {
        prec = config4.epsilon;
      }
      var size2 = mat.size();
      if (size2.length !== 2 || size2[0] !== size2[1]) {
        throw new RangeError("Matrix must be square (size: " + format3(size2) + ")");
      }
      var arr = mat.toArray();
      var N = size2[0];
      if (isReal(arr, N, prec)) {
        coerceReal(arr, N);
        if (isSymmetric(arr, N, prec)) {
          var _type = coerceTypes(mat, arr, N);
          return doRealSymetric(arr, N, prec, _type);
        }
      }
      var type = coerceTypes(mat, arr, N);
      return doComplexEigs(arr, N, prec, type);
    }
    function isSymmetric(arr, N, prec) {
      for (var i = 0; i < N; i++) {
        for (var j = i; j < N; j++) {
          if (larger2(bignumber2(abs3(subtract2(arr[i][j], arr[j][i]))), prec)) {
            return false;
          }
        }
      }
      return true;
    }
    function isReal(arr, N, prec) {
      for (var i = 0; i < N; i++) {
        for (var j = 0; j < N; j++) {
          if (larger2(bignumber2(abs3(im2(arr[i][j]))), prec)) {
            return false;
          }
        }
      }
      return true;
    }
    function coerceReal(arr, N) {
      for (var i = 0; i < N; i++) {
        for (var j = 0; j < N; j++) {
          arr[i][j] = re2(arr[i][j]);
        }
      }
    }
    function coerceTypes(mat, arr, N) {
      var type = mat.datatype();
      if (type === "number" || type === "BigNumber" || type === "Complex") {
        return type;
      }
      var hasNumber = false;
      var hasBig = false;
      var hasComplex = false;
      for (var i = 0; i < N; i++) {
        for (var j = 0; j < N; j++) {
          var el = arr[i][j];
          if (isNumber(el) || isFraction(el)) {
            hasNumber = true;
          } else if (isBigNumber(el)) {
            hasBig = true;
          } else if (isComplex(el)) {
            hasComplex = true;
          } else {
            throw TypeError("Unsupported type in Matrix: " + typeOf(el));
          }
        }
      }
      if (hasBig && hasComplex) {
        console.warn("Complex BigNumbers not supported, this operation will lose precission.");
      }
      if (hasComplex) {
        for (var _i = 0; _i < N; _i++) {
          for (var _j = 0; _j < N; _j++) {
            arr[_i][_j] = complex2(arr[_i][_j]);
          }
        }
        return "Complex";
      }
      if (hasBig) {
        for (var _i2 = 0; _i2 < N; _i2++) {
          for (var _j2 = 0; _j2 < N; _j2++) {
            arr[_i2][_j2] = bignumber2(arr[_i2][_j2]);
          }
        }
        return "BigNumber";
      }
      if (hasNumber) {
        for (var _i3 = 0; _i3 < N; _i3++) {
          for (var _j3 = 0; _j3 < N; _j3++) {
            arr[_i3][_j3] = number2(arr[_i3][_j3]);
          }
        }
        return "number";
      } else {
        throw TypeError("Matrix contains unsupported types only.");
      }
    }
  });

  // node_modules/mathjs/lib/esm/function/arithmetic/divide.js
  var name84 = "divide";
  var dependencies85 = ["typed", "matrix", "multiply", "equalScalar", "divideScalar", "inv"];
  var createDivide = /* @__PURE__ */ factory(name84, dependencies85, (_ref) => {
    var {
      typed: typed2,
      matrix: matrix2,
      multiply: multiply2,
      equalScalar: equalScalar2,
      divideScalar: divideScalar2,
      inv: inv2
    } = _ref;
    var algorithm11 = createAlgorithm11({
      typed: typed2,
      equalScalar: equalScalar2
    });
    var algorithm14 = createAlgorithm14({
      typed: typed2
    });
    return typed2("divide", extend({
      // we extend the signatures of divideScalar with signatures dealing with matrices
      "Array | Matrix, Array | Matrix": function ArrayMatrixArrayMatrix(x, y) {
        return multiply2(x, inv2(y));
      },
      "DenseMatrix, any": function DenseMatrixAny(x, y) {
        return algorithm14(x, y, divideScalar2, false);
      },
      "SparseMatrix, any": function SparseMatrixAny(x, y) {
        return algorithm11(x, y, divideScalar2, false);
      },
      "Array, any": function ArrayAny(x, y) {
        return algorithm14(matrix2(x), y, divideScalar2, false).valueOf();
      },
      "any, Array | Matrix": function anyArrayMatrix(x, y) {
        return multiply2(x, inv2(y));
      }
    }, divideScalar2.signatures));
  });

  // node_modules/mathjs/lib/esm/function/statistics/sum.js
  var name85 = "sum";
  var dependencies86 = ["typed", "config", "add", "numeric"];
  var createSum = /* @__PURE__ */ factory(name85, dependencies86, (_ref) => {
    var {
      typed: typed2,
      config: config4,
      add: add3,
      numeric: numeric2
    } = _ref;
    return typed2(name85, {
      // sum([a, b, c, d, ...])
      "Array | Matrix": _sum,
      // sum([a, b, c, d, ...], dim)
      "Array | Matrix, number | BigNumber": _nsumDim,
      // sum(a, b, c, d, ...)
      "...": function _(args) {
        if (containsCollections(args)) {
          throw new TypeError("Scalar values expected in function sum");
        }
        return _sum(args);
      }
    });
    function _sum(array) {
      var sum3;
      deepForEach(array, function(value) {
        try {
          sum3 = sum3 === void 0 ? value : add3(sum3, value);
        } catch (err) {
          throw improveErrorMessage(err, "sum", value);
        }
      });
      if (sum3 === void 0) {
        sum3 = numeric2(0, config4.number);
      }
      if (typeof sum3 === "string") {
        sum3 = numeric2(sum3, config4.number);
      }
      return sum3;
    }
    function _nsumDim(array, dim) {
      try {
        var sum3 = reduce(array, dim, add3);
        return sum3;
      } catch (err) {
        throw improveErrorMessage(err, "sum");
      }
    }
  });

  // node_modules/mathjs/lib/esm/entry/pureFunctionsAny.generated.js
  var Complex2 = /* @__PURE__ */ createComplexClass({});
  var BigNumber = /* @__PURE__ */ createBigNumberClass({
    config
  });
  var Matrix = /* @__PURE__ */ createMatrixClass({});
  var Fraction2 = /* @__PURE__ */ createFractionClass({});
  var DenseMatrix = /* @__PURE__ */ createDenseMatrixClass({
    Matrix
  });
  var typed = /* @__PURE__ */ createTyped({
    BigNumber,
    Complex: Complex2,
    DenseMatrix,
    Fraction: Fraction2
  });
  var isInteger2 = /* @__PURE__ */ createIsInteger({
    typed
  });
  var equalScalar = /* @__PURE__ */ createEqualScalar({
    config,
    typed
  });
  var number = /* @__PURE__ */ createNumber({
    typed
  });
  var complex = /* @__PURE__ */ createComplex({
    Complex: Complex2,
    typed
  });
  var multiplyScalar = /* @__PURE__ */ createMultiplyScalar({
    typed
  });
  var sign3 = /* @__PURE__ */ createSign({
    BigNumber,
    Fraction: Fraction2,
    complex,
    typed
  });
  var im = /* @__PURE__ */ createIm({
    typed
  });
  var atan3 = /* @__PURE__ */ createAtan({
    typed
  });
  var fraction = /* @__PURE__ */ createFraction({
    Fraction: Fraction2,
    typed
  });
  var unaryMinus = /* @__PURE__ */ createUnaryMinus({
    typed
  });
  var addScalar = /* @__PURE__ */ createAddScalar({
    typed
  });
  var sqrt2 = /* @__PURE__ */ createSqrt({
    Complex: Complex2,
    config,
    typed
  });
  var conj = /* @__PURE__ */ createConj({
    typed
  });
  var cos2 = /* @__PURE__ */ createCos({
    typed
  });
  var sin2 = /* @__PURE__ */ createSin({
    typed
  });
  var SparseMatrix = /* @__PURE__ */ createSparseMatrixClass({
    Matrix,
    equalScalar,
    typed
  });
  var matrix = /* @__PURE__ */ createMatrix({
    DenseMatrix,
    Matrix,
    SparseMatrix,
    typed
  });
  var abs2 = /* @__PURE__ */ createAbs({
    typed
  });
  var concat = /* @__PURE__ */ createConcat({
    isInteger: isInteger2,
    matrix,
    typed
  });
  var diag = /* @__PURE__ */ createDiag({
    DenseMatrix,
    SparseMatrix,
    matrix,
    typed
  });
  var identity = /* @__PURE__ */ createIdentity({
    BigNumber,
    DenseMatrix,
    SparseMatrix,
    config,
    matrix,
    typed
  });
  var reshape2 = /* @__PURE__ */ createReshape({
    isInteger: isInteger2,
    matrix,
    typed
  });
  var size = /* @__PURE__ */ createSize({
    matrix,
    config,
    typed
  });
  var subset = /* @__PURE__ */ createSubset({
    matrix,
    typed
  });
  var zeros2 = /* @__PURE__ */ createZeros({
    BigNumber,
    config,
    matrix,
    typed
  });
  var smaller = /* @__PURE__ */ createSmaller({
    DenseMatrix,
    config,
    matrix,
    typed
  });
  var larger = /* @__PURE__ */ createLarger({
    DenseMatrix,
    config,
    matrix,
    typed
  });
  var ImmutableDenseMatrix = /* @__PURE__ */ createImmutableDenseMatrixClass({
    DenseMatrix,
    smaller
  });
  var FibonacciHeap = /* @__PURE__ */ createFibonacciHeapClass({
    larger,
    smaller
  });
  var add2 = /* @__PURE__ */ createAdd({
    DenseMatrix,
    SparseMatrix,
    addScalar,
    equalScalar,
    matrix,
    typed
  });
  var dot = /* @__PURE__ */ createDot({
    addScalar,
    conj,
    multiplyScalar,
    size,
    typed
  });
  var isZero = /* @__PURE__ */ createIsZero({
    typed
  });
  var multiply = /* @__PURE__ */ createMultiply({
    addScalar,
    dot,
    equalScalar,
    matrix,
    multiplyScalar,
    typed
  });
  var re = /* @__PURE__ */ createRe({
    typed
  });
  var flatten2 = /* @__PURE__ */ createFlatten({
    matrix,
    typed
  });
  var pow2 = /* @__PURE__ */ createPow({
    Complex: Complex2,
    config,
    fraction,
    identity,
    matrix,
    multiply,
    number,
    typed
  });
  var largerEq = /* @__PURE__ */ createLargerEq({
    DenseMatrix,
    config,
    matrix,
    typed
  });
  var Index = /* @__PURE__ */ createIndexClass({
    ImmutableDenseMatrix
  });
  var bignumber = /* @__PURE__ */ createBignumber({
    BigNumber,
    typed
  });
  var matrixFromColumns = /* @__PURE__ */ createMatrixFromColumns({
    flatten: flatten2,
    matrix,
    size,
    typed
  });
  var transpose = /* @__PURE__ */ createTranspose({
    matrix,
    typed
  });
  var numeric = /* @__PURE__ */ createNumeric({
    bignumber,
    fraction,
    number
  });
  var smallerEq = /* @__PURE__ */ createSmallerEq({
    DenseMatrix,
    config,
    matrix,
    typed
  });
  var index = /* @__PURE__ */ createIndex({
    Index,
    typed
  });
  var sum2 = /* @__PURE__ */ createSum({
    add: add2,
    config,
    numeric,
    typed
  });
  var subtract = /* @__PURE__ */ createSubtract({
    DenseMatrix,
    addScalar,
    equalScalar,
    matrix,
    typed,
    unaryMinus
  });
  var range = /* @__PURE__ */ createRange({
    bignumber,
    matrix,
    config,
    larger,
    largerEq,
    smaller,
    smallerEq,
    typed
  });
  var equal2 = /* @__PURE__ */ createEqual({
    DenseMatrix,
    equalScalar,
    matrix,
    typed
  });
  var ctranspose = /* @__PURE__ */ createCtranspose({
    conj,
    transpose,
    typed
  });
  var divideScalar = /* @__PURE__ */ createDivideScalar({
    numeric,
    typed
  });
  var lsolve = /* @__PURE__ */ createLsolve({
    DenseMatrix,
    divideScalar,
    equalScalar,
    matrix,
    multiplyScalar,
    subtract,
    typed
  });
  var Spa = /* @__PURE__ */ createSpaClass({
    FibonacciHeap,
    addScalar,
    equalScalar
  });
  var lup = /* @__PURE__ */ createLup({
    DenseMatrix,
    Spa,
    SparseMatrix,
    abs: abs2,
    addScalar,
    divideScalar,
    equalScalar,
    larger,
    matrix,
    multiplyScalar,
    subtract,
    typed,
    unaryMinus
  });
  var slu = /* @__PURE__ */ createSlu({
    SparseMatrix,
    abs: abs2,
    add: add2,
    divideScalar,
    larger,
    largerEq,
    multiply,
    subtract,
    transpose,
    typed
  });
  var det = /* @__PURE__ */ createDet({
    lup,
    matrix,
    multiply,
    subtract,
    typed,
    unaryMinus
  });
  var column = /* @__PURE__ */ createColumn({
    Index,
    matrix,
    range,
    typed
  });
  var log3 = /* @__PURE__ */ createLog({
    Complex: Complex2,
    config,
    divideScalar,
    typed
  });
  var usolveAll = /* @__PURE__ */ createUsolveAll({
    DenseMatrix,
    divideScalar,
    equalScalar,
    matrix,
    multiplyScalar,
    subtract,
    typed
  });
  var qr = /* @__PURE__ */ createQr({
    addScalar,
    complex,
    conj,
    divideScalar,
    equal: equal2,
    identity,
    isZero,
    matrix,
    multiplyScalar,
    sign: sign3,
    sqrt: sqrt2,
    subtract,
    typed,
    unaryMinus,
    zeros: zeros2
  });
  var inv = /* @__PURE__ */ createInv({
    abs: abs2,
    addScalar,
    det,
    divideScalar,
    identity,
    matrix,
    multiply,
    typed,
    unaryMinus
  });
  var divide2 = /* @__PURE__ */ createDivide({
    divideScalar,
    equalScalar,
    inv,
    matrix,
    multiply,
    typed
  });
  var usolve = /* @__PURE__ */ createUsolve({
    DenseMatrix,
    divideScalar,
    equalScalar,
    matrix,
    multiplyScalar,
    subtract,
    typed
  });
  var lusolve = /* @__PURE__ */ createLusolve({
    DenseMatrix,
    lsolve,
    lup,
    matrix,
    slu,
    typed,
    usolve
  });
  var eigs = /* @__PURE__ */ createEigs({
    abs: abs2,
    add: add2,
    addScalar,
    atan: atan3,
    bignumber,
    column,
    complex,
    config,
    cos: cos2,
    diag,
    divideScalar,
    dot,
    equal: equal2,
    flatten: flatten2,
    im,
    inv,
    larger,
    matrix,
    matrixFromColumns,
    multiply,
    multiplyScalar,
    number,
    qr,
    re,
    sin: sin2,
    smaller,
    sqrt: sqrt2,
    subtract,
    typed,
    usolve,
    usolveAll
  });
  var norm = /* @__PURE__ */ createNorm({
    abs: abs2,
    add: add2,
    conj,
    ctranspose,
    eigs,
    equalScalar,
    larger,
    matrix,
    multiply,
    pow: pow2,
    smaller,
    sqrt: sqrt2,
    typed
  });

  // src/molecule.js
  var import_elements = __toESM(require_chem_elements(), 1);
  var moleculesDict = {
    "AC3H4": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        3
      ],
      formula: "C3H4",
      name: "Allene"
    },
    "CH3COOH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        2,
        2
      ],
      formula: "C2H4O2",
      name: "Acetic acid"
    },
    "CH3COCH3": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        3,
        1
      ],
      formula: "C3H6O1",
      name: "Acetone"
    },
    "C2H3CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        3,
        1
      ],
      formula: "C3H4O1",
      name: "Acrolein"
    },
    "C2H5CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        3,
        1
      ],
      formula: "C3H6O1",
      name: "Propionaldehyde"
    },
    "C4H9CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        5,
        1
      ],
      formula: "C5H10O1",
      name: "3-Methylbutanal"
    },
    "AR": {
      elementsSymbol: [
        "Ar"
      ],
      numberOfAtoms: [
        1
      ],
      formula: "AR1",
      name: "Argon"
    },
    "C6H5CH2OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        7,
        1
      ],
      formula: "C7H8O1",
      name: "Benzyl alcohol"
    },
    "C6H4O2": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        6,
        2
      ],
      formula: "C6H4O2",
      name: "1,4-Benzoquinone"
    },
    "C6H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        6
      ],
      formula: "C6H6",
      name: "Benzene"
    },
    "C6H5CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        7,
        1
      ],
      formula: "C7H6O1",
      name: "Benzaldehyde"
    },
    "C6H5C2H4C6H5": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        14,
        14
      ],
      formula: "C14H14",
      name: "2-Methyldiphenylmethane"
    },
    "NC4H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        4
      ],
      formula: "C4H8",
      name: "Butene"
    },
    "C4H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        4
      ],
      formula: "C4H6",
      name: "Butyne"
    },
    "C12H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        12
      ],
      formula: "C12H8",
      name: "Acenaphthylene"
    },
    "C2H2": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        2,
        2
      ],
      formula: "C2H2",
      name: "Acetylene"
    },
    "C2H4": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        2
      ],
      formula: "C2H4",
      name: "Ethylene"
    },
    "C2H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        2
      ],
      formula: "C2H6",
      name: "Ethane"
    },
    "C3H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        3
      ],
      formula: "C3H6",
      name: "Propylene"
    },
    "C3H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        3
      ],
      formula: "C3H8",
      name: "Propane"
    },
    "C4H2": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        2,
        4
      ],
      formula: "C4H2",
      name: "Diacetylene"
    },
    "C4H4": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        4
      ],
      formula: "C4H4",
      name: "Vinylacetylene"
    },
    "CYC5H4O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        5,
        1
      ],
      formula: "C5H4O1",
      name: "Cyclopentadienone"
    },
    "C6H5O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        5,
        6,
        1
      ],
      formula: "C6H5O1",
      name: "Phenoxy"
    },
    "CYC6H10-ONE": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        6,
        1
      ],
      formula: "C6H10O1",
      name: "Cyclohexanone"
    },
    "CYC5H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        5
      ],
      formula: "C5H8",
      name: "Cyclopentene"
    },
    "CYC6H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        6
      ],
      formula: "C6H8",
      name: "Cyclohexadiene"
    },
    "CYC6H12": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        6
      ],
      formula: "C6H12",
      name: "Cyclohexane"
    },
    "CYC6H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        6
      ],
      formula: "C6H10",
      name: "Cyclohexene"
    },
    "CH2CO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        2,
        2,
        1
      ],
      formula: "C2H2O1",
      name: "Ketene"
    },
    "CH2O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        2,
        1,
        1
      ],
      formula: "C1H2O1",
      name: "Formaldehyde"
    },
    "CH3OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        1,
        1
      ],
      formula: "C1H4O1",
      name: "Methanol"
    },
    "CH4": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        1
      ],
      formula: "C1H4",
      name: "Methane"
    },
    "CO": {
      elementsSymbol: [
        "C",
        "O"
      ],
      numberOfAtoms: [
        1,
        1
      ],
      formula: "C1O1",
      name: "Carbon monoxide"
    },
    "CO2": {
      elementsSymbol: [
        "C",
        "O"
      ],
      numberOfAtoms: [
        1,
        2
      ],
      formula: "C1O2",
      name: "Carbon dioxide"
    },
    "CYC5H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        5
      ],
      formula: "C5H6",
      name: "Cyclopentadiene"
    },
    "MCPTD": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        6
      ],
      formula: "C6H8",
      name: "Methyl cyclopentadiene"
    },
    "CRESOL": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        7,
        1
      ],
      formula: "C7H8O1",
      name: "Cresol"
    },
    "NC10H20": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        20,
        10
      ],
      formula: "C10H20",
      name: "Normal decenes"
    },
    "C6H5CH2C6H5": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        13
      ],
      formula: "C13H12",
      name: "Diphenilmethane"
    },
    "DIPE": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        14,
        6,
        1
      ],
      formula: "C6H14O1",
      name: "Diisopropyl ether"
    },
    "CH3OCH3": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        2,
        1
      ],
      formula: "C2H6O1",
      name: "Dimethyl ether"
    },
    "CH3CH3-C5H6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        7
      ],
      formula: "C7H12",
      name: "Dimethyl pentadienes"
    },
    "C6H5C2H5": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        8
      ],
      formula: "C8H10",
      name: "Ethylbenzene"
    },
    "NC7H14": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        14,
        7
      ],
      formula: "C7H14",
      name: "Normal heptenes"
    },
    "NC6H12": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        6
      ],
      formula: "C6H12",
      name: "1-hexene"
    },
    "C5H9CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        6,
        1
      ],
      formula: "C6H10O1",
      name: "2-Hexenal"
    },
    "ETBE": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        14,
        6,
        1
      ],
      formula: "C6H14O1",
      name: "Ethyl tertiary butyl ether"
    },
    "C2H5OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        2,
        1
      ],
      formula: "C2H6O1",
      name: "Ethanol"
    },
    "C2H5OOH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        2,
        2
      ],
      formula: "C2H6O2",
      name: "Ethyl hydroperoxide"
    },
    "C2H4O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        2,
        1
      ],
      formula: "C2H4O1",
      name: "Ethylene oxide"
    },
    "C6H5C2H": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        6,
        8
      ],
      formula: "C8H6",
      name: "Phenylacetylene"
    },
    "BIPHENYL": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        12
      ],
      formula: "C12H10",
      name: "Biphenyl"
    },
    "C14H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        14
      ],
      formula: "C14H10",
      name: "Anthracene"
    },
    "C6H5OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        6,
        1
      ],
      formula: "C6H6O1",
      name: "Phenol"
    },
    "FLUORENE": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        13
      ],
      formula: "C13H10",
      name: "Fluorene"
    },
    "C10H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        10
      ],
      formula: "C10H8",
      name: "Naphthalene"
    },
    "H2": {
      elementsSymbol: [
        "H"
      ],
      numberOfAtoms: [
        2
      ],
      formula: "H2",
      name: "Hydrogen"
    },
    "H2O": {
      elementsSymbol: [
        "H",
        "O"
      ],
      numberOfAtoms: [
        2,
        1
      ],
      formula: "H2O1",
      name: "Water"
    },
    "H2O2": {
      elementsSymbol: [
        "H",
        "O"
      ],
      numberOfAtoms: [
        2,
        2
      ],
      formula: "H2O2",
      name: "Hydrogen peroxide"
    },
    "HE": {
      elementsSymbol: [
        "He"
      ],
      numberOfAtoms: [
        1
      ],
      formula: "HE1",
      name: "Helium"
    },
    "IC4H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        4
      ],
      formula: "C4H8",
      name: "Isobutene"
    },
    "IC3H7CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        4,
        1
      ],
      formula: "C4H8O1",
      name: "Isobutyrraldehyde"
    },
    "IC4H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        4
      ],
      formula: "C4H10",
      name: "Isobutane"
    },
    "IC8H18": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        18,
        8
      ],
      formula: "C8H18",
      name: "Isooctane"
    },
    "INDENE": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        9
      ],
      formula: "C9H8",
      name: "Indene"
    },
    "IC3H7OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        3,
        1
      ],
      formula: "C3H8O1",
      name: "2-propanol"
    },
    "IC5H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        5
      ],
      formula: "C5H10",
      name: "Isoamilene"
    },
    "IC3H5CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        4,
        1
      ],
      formula: "C4H6O1",
      name: "Methacrolein"
    },
    "MCYC6": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        14,
        7
      ],
      formula: "C7H14",
      name: "Methylcyclohexane"
    },
    "CH3CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        2,
        1
      ],
      formula: "C2H4O1",
      name: "Acetaldehyde"
    },
    "C10H7CH3": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        11
      ],
      formula: "C11H10",
      name: "Methylnaphthalene"
    },
    "CH3OOH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        1,
        2
      ],
      formula: "C1H4O2",
      name: "Methyl hydroperoxide"
    },
    "MTBE": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        12,
        5,
        1
      ],
      formula: "C5H12O1",
      name: "Methyl Tertiary Butyl Ether"
    },
    "N2": {
      elementsSymbol: [
        "N"
      ],
      numberOfAtoms: [
        2
      ],
      formula: "N2",
      name: "Nitrogen"
    },
    "C10H7OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        10,
        1
      ],
      formula: "C10H8O1",
      name: "Naphthol"
    },
    "C10H7CHO": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        11,
        1
      ],
      formula: "C11H8O1",
      name: "Naphthaldehyde"
    },
    "NC4H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        4
      ],
      formula: "C4H10",
      name: "Normal butane"
    },
    "NC10H22": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        22,
        10
      ],
      formula: "C10H22",
      name: "Normal decane"
    },
    "NC12H26": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        26,
        12
      ],
      formula: "C12H26",
      name: "Normal dodecane"
    },
    "NC5H12": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        5
      ],
      formula: "C5H12",
      name: "Normal pentane"
    },
    "NC7H16": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        16,
        7
      ],
      formula: "C7H16",
      name: "Normal heptane"
    },
    "NEOC5H12": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        5
      ],
      formula: "C5H12",
      name: "Neopentane"
    },
    "O2": {
      elementsSymbol: [
        "O"
      ],
      numberOfAtoms: [
        2
      ],
      formula: "O2",
      name: "Oxygen"
    },
    "IC8H16": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        16,
        8
      ],
      formula: "C8H16",
      name: "Isooctenes"
    },
    "NC5H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        5
      ],
      formula: "C5H10",
      name: "Pentenee"
    },
    "PC3H4": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        3
      ],
      formula: "C3H4",
      name: "Propyne"
    },
    "CH3CO3H": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        2,
        3
      ],
      formula: "C2H4O3",
      name: "Peracetic acid"
    },
    "HCO3H": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        2,
        1,
        3
      ],
      formula: "C1H2O3",
      name: "Performic acid"
    },
    "C3H6O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        3,
        1
      ],
      formula: "C3H6O1",
      name: "Propylene oxide"
    },
    "C5H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        5
      ],
      formula: "C5H8",
      name: "Isoprene"
    },
    "C16H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        16
      ],
      formula: "C16H10",
      name: "Pyrene"
    },
    "C6H5C2H3": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        8
      ],
      formula: "C8H8",
      name: "Styrene"
    },
    "TAME": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        14,
        6,
        1
      ],
      formula: "C6H14O1",
      name: "Tertiary Amyl Methyl Ether"
    },
    "TETRALIN": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        10
      ],
      formula: "C10H12",
      name: "Tetrahydronaphthalene"
    },
    "DECALIN": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        18,
        10
      ],
      formula: "C10H18",
      name: "Decahydronaphthalene"
    },
    "C7H8": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        8,
        7
      ],
      formula: "C7H8",
      name: "Toluene"
    },
    "XYLENE": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        8
      ],
      formula: "C8H10",
      name: "Xylenes"
    },
    "NC16H34": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        34,
        16
      ],
      formula: "C16H34",
      name: "Normal hexadecane"
    },
    "N2H4": {
      elementsSymbol: [
        "H",
        "N"
      ],
      numberOfAtoms: [
        4,
        2
      ],
      formula: "H4N2",
      name: "Hydrazine"
    },
    "N2O": {
      elementsSymbol: [
        "O",
        "N"
      ],
      numberOfAtoms: [
        1,
        2
      ],
      formula: "O1N2",
      name: "Dinitrogen monoxide"
    },
    "NH3": {
      elementsSymbol: [
        "H",
        "N"
      ],
      numberOfAtoms: [
        3,
        1
      ],
      formula: "H3N1",
      name: "Ammonia"
    },
    "NO": {
      elementsSymbol: [
        "O",
        "N"
      ],
      numberOfAtoms: [
        1,
        1
      ],
      formula: "O1N1",
      name: "Nitric oxide"
    },
    "NO2": {
      elementsSymbol: [
        "O",
        "N"
      ],
      numberOfAtoms: [
        2,
        1
      ],
      formula: "O2N1",
      name: "Nitric dioxide"
    },
    "C3H5OOH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        3,
        2
      ],
      formula: "C3H6O2",
      name: "Allyl hydroperoxide"
    },
    "NC3H7OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        3,
        1
      ],
      formula: "C3H8O1",
      name: "Propanol"
    },
    "N1C4H9OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        4,
        1
      ],
      formula: "C4H10O1",
      name: "1-Butanol"
    },
    "N2C4H9OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        4,
        1
      ],
      formula: "C4H10O1",
      name: "2-Butanol"
    },
    "MEK": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        4,
        1
      ],
      formula: "C4H8O1",
      name: "Methyl Ethyl Keton"
    },
    "TC4H9OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        4,
        1
      ],
      formula: "C4H10O1",
      name: "Tert Butanol"
    },
    "IC4H9OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        4,
        1
      ],
      formula: "C4H10O1",
      name: "Iso butanol"
    },
    "C4H7OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        4,
        1
      ],
      formula: "C4H8O1",
      name: "Butenol"
    },
    "C3H5OH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        3,
        1
      ],
      formula: "C3H6O1",
      name: "Allyl alcohol"
    },
    "C10H10": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        10,
        10
      ],
      formula: "C10H10",
      name: "Dialin"
    },
    "BZFUR": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        8,
        1
      ],
      formula: "C8H6O1",
      name: "Benzofuran"
    },
    "TMBENZ": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        9
      ],
      formula: "C9H12",
      name: "1,2,4 Tri methyl benzene"
    },
    "NPBENZ": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        12,
        9
      ],
      formula: "C9H12",
      name: "Normal propylbenzene"
    },
    "C6H5OCH3": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        7,
        1
      ],
      formula: "C7H8O1",
      name: "Anisole"
    },
    "MB": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        5,
        2
      ],
      formula: "C5H10O2",
      name: "Methyl butanoate"
    },
    "MCROT": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        5,
        2
      ],
      formula: "C5H8O2",
      name: "Methyl crotonate"
    },
    "MACRIL": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        4,
        2
      ],
      formula: "C4H6O2",
      name: "Methyl acrylate"
    },
    "DIBZFUR": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        12,
        1
      ],
      formula: "C12H8O1",
      name: "Dibenzofuran"
    },
    "DIFENET": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        12,
        1
      ],
      formula: "C12H10O1",
      name: "Diphenyl ether"
    },
    "C12H22": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        22,
        12
      ],
      formula: "C12H22",
      name: "Dodecadiene"
    },
    "BENZYNE": {
      elementsSymbol: [
        "H",
        "C"
      ],
      numberOfAtoms: [
        4,
        6
      ],
      formula: "C6H4",
      name: "Benzyne"
    },
    "C2H2O2": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        2,
        2,
        2
      ],
      formula: "C2H2O2",
      name: "Glyoxal"
    },
    "C4H6O2": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        6,
        4,
        2
      ],
      formula: "C4H6O2",
      name: "Butanedione"
    },
    "C5H4O2": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        5,
        2
      ],
      formula: "C5H4O2",
      name: "Furfural"
    },
    "C5H8O4": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        5,
        4
      ],
      formula: "C5H8O4",
      name: "Xylofuranose"
    },
    "C6H10O5": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        6,
        5
      ],
      formula: "C6H10O5",
      name: "Levoglucosan"
    },
    "C8H10O3": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        10,
        8,
        3
      ],
      formula: "C8H10O3",
      name: "2,6-Dimethoxyphenol"
    },
    "HCOOH": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        2,
        1,
        2
      ],
      formula: "C1H2O2",
      name: "Formic acid"
    },
    "GLYCEROL": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        8,
        3,
        3
      ],
      formula: "C3H8O3",
      name: "Glycerol"
    },
    "C4H4O": {
      elementsSymbol: [
        "H",
        "C",
        "O"
      ],
      numberOfAtoms: [
        4,
        4,
        1
      ],
      formula: "C4H4O1",
      name: "Furan"
    }
  };
  var chemicalNameToName = Object.fromEntries(Object.entries(moleculesDict).map(([k, v]) => [v.name, k]));
  function Molecule(gasSpecieName) {
    let _moleculeDict = void 0;
    let _numberOfElements = void 0;
    if (gasSpecieName != void 0) {
      _moleculeDict = _checkSpecieName(gasSpecieName);
      _numberOfElements = _moleculeDict.elementsSymbol.length;
    }
    function _checkSpecieName(gasSpecieName2) {
      try {
        return moleculesDict[gasSpecieName2];
      } catch (error) {
        console.log(error);
        AsaliError("Unknwon species name: " + gasSpecieName2);
      }
    }
    function getElementsList() {
      if (_moleculeDict == void 0) {
        return [];
      }
      return _moleculeDict.elementsSymbol.map((symbol) => import_elements.default.ChemElements.getBySymbol(symbol));
    }
    function getElementsSymbol() {
      if (_moleculeDict == void 0) {
        return "";
      }
      return _moleculeDict.elementsSymbol;
    }
    function getNumberOfAtoms() {
      if (_moleculeDict == void 0) {
        return 0;
      }
      return _moleculeDict.numberOfAtoms;
    }
    function getFormula() {
      if (_moleculeDict == void 0) {
        return "";
      }
      return _moleculeDict.formula;
    }
    function getChemicalName() {
      if (_moleculeDict == void 0) {
        return "";
      }
      return _moleculeDict.name;
    }
    function getElementCounterDict() {
      if (_moleculeDict == void 0) {
        return {};
      }
      let _elementCounter = {};
      for (let i = 0; i < _numberOfElements; i++) {
        _elementCounter[_moleculeDict.elementsSymbol[i]] = _moleculeDict.numberOfAtoms[i];
      }
      return _elementCounter;
    }
    function getNameFromChemicalName(chemicalName) {
      return chemicalNameToName[chemicalName];
    }
    function getAvailableSpecies() {
      return Object.keys(moleculesDict);
    }
    function getAvailableSpeciesFormula() {
      return Object.entries(moleculesDict).map(([k, v]) => v.formula);
    }
    function getAvailableSpeciesChemicalName() {
      return Object.entries(moleculesDict).map(([k, v]) => v.name);
    }
    return {
      getElementsList,
      getElementsSymbol,
      getNumberOfAtoms,
      getFormula,
      getChemicalName,
      getElementCounterDict,
      getNameFromChemicalName,
      getAvailableSpecies,
      getAvailableSpeciesFormula,
      getAvailableSpeciesChemicalName
    };
  }

  // src/jasali.js
  function GasState({
    temperature,
    pressure
  }) {
    let _temperature = temperature;
    let _pressure = pressure;
    function getTemperature() {
      return _temperature;
    }
    function getPressure() {
      return _pressure;
    }
    return {
      getTemperature,
      getPressure
    };
  }
  function GasSpecie({
    name: name86,
    gasState
  }) {
    let _thermo = ThermoParameter();
    let _transport = TransportParameters();
    let _name = name86;
    let _temperature = gasState.getTemperature();
    let _pressure = gasState.getPressure();
    let _highTemperatureCoefficients = _thermo.getHighTemperatureCoefficients(_name);
    let _lowTemperatureCoefficients = _thermo.getLowTemperatureCoefficients(_name);
    let _geometry = _transport.getGeometry(_name);
    let _LJpotential = _transport.getLJpotential(_name);
    let _LJdiameter = _transport.getLJdiameter(_name);
    let _dipole = _transport.getDipole(_name);
    let _polar = _transport.getPolar(_name);
    let _collision = _transport.getCollision(_name);
    let _molecularWeight = _transport.getMolecularWeight(_name);
    let _molefraction = 1;
    let _cp_update = true;
    let _h_update = true;
    let _s_update = true;
    let _mu_update = true;
    let _v_update = true;
    let _l_update = true;
    let _diff_update = true;
    let _cond_update = true;
    function _resetBools() {
      _cp_update = true;
      _h_update = true;
      _s_update = true;
      _mu_update = true;
      _v_update = true;
      _l_update = true;
      _diff_update = true;
      _cond_update = true;
    }
    function updateGasState(gasState2) {
      _temperature = gasState2.getTemperature();
      _pressure = gasState2.getPressure();
      _resetBools();
      return this;
    }
    function updateMoleFraction(moleFraction) {
      _molefraction = moleFraction;
      _resetBools();
      return this;
    }
    function getDensity() {
      return _molecularWeight * _pressure / (Parameters.R * _temperature);
    }
    function getMolecularWeight() {
      return _molecularWeight;
    }
    let _cpMole = 0;
    let _cpMass = 0;
    function _calculateSpecificHeat() {
      if (_cp_update) {
        let _coefficients = _highTemperatureCoefficients;
        if (_temperature < 1e3) {
          _coefficients = _lowTemperatureCoefficients;
        }
        _cpMole = _coefficients[0] + _coefficients[1] * _temperature + _coefficients[2] * Math.pow(_temperature, 2) + _coefficients[3] * Math.pow(_temperature, 3) + _coefficients[4] * Math.pow(_temperature, 4);
        _cpMole = _cpMole * Parameters.R;
        _cpMass = _cpMole / _molecularWeight;
        _cp_update = false;
      }
    }
    function getMolarSpecificHeat() {
      _calculateSpecificHeat();
      return _cpMole;
    }
    function getMassSpecificHeat() {
      _calculateSpecificHeat();
      return _cpMass;
    }
    let _hMole = 0;
    let _hMass = 0;
    function _calculateEnthalpy() {
      if (_h_update) {
        let _coefficients = _highTemperatureCoefficients;
        if (_temperature < 1e3) {
          _coefficients = _lowTemperatureCoefficients;
        }
        _hMole = _coefficients[0] + _coefficients[1] * _temperature / 2 + _coefficients[2] * Math.pow(_temperature, 2) / 3 + _coefficients[3] * Math.pow(_temperature, 3) / 4 + _coefficients[4] * Math.pow(_temperature, 4) / 5 + _coefficients[5] / _temperature;
        _hMole = _hMole * Parameters.R * _temperature;
        _hMass = _hMole / _molecularWeight;
        _h_update = false;
      }
    }
    function getMolarEnthalpy() {
      _calculateEnthalpy();
      return _hMole;
    }
    function getMassEnthalpy() {
      _calculateEnthalpy();
      return _hMass;
    }
    let _sMole = 0;
    let _sMass = 0;
    function _calculateEntropy() {
      if (_s_update) {
        let _coefficients = _highTemperatureCoefficients;
        if (_temperature < 1e3) {
          _coefficients = _lowTemperatureCoefficients;
        }
        _sMole = _coefficients[0] * Math.log(_temperature) + _coefficients[1] * _temperature + _coefficients[2] * Math.pow(_temperature, 2) / 2 + _coefficients[3] * Math.pow(_temperature, 3) / 3 + _coefficients[4] * Math.pow(_temperature, 4) / 4 + _coefficients[6];
        _sMole = Parameters.R * (_sMole - Math.log(_pressure / Parameters.referencePressure) - Math.log(_molefraction));
        _sMass = _sMole / _molecularWeight;
        _s_update = false;
      }
    }
    function getMolarEntropy() {
      _calculateEntropy();
      return _sMole;
    }
    function getMassEntropy() {
      _calculateEntropy();
      return _sMass;
    }
    function getMolarInternalEnergy() {
      _calculateEnthalpy();
      return _hMole - Parameters.R * _temperature;
    }
    function getMassInternalEnergy() {
      _calculateEnthalpy();
      return _hMass - Parameters.R * _temperature / _molecularWeight;
    }
    function getMolarGibbsFreeEnergy() {
      _calculateEntropy();
      _calculateEnthalpy();
      return _hMole - _sMole * _temperature;
    }
    function getMassGibbsFreeEnergy() {
      _calculateEntropy();
      _calculateEnthalpy();
      return _hMass - _sMass * _temperature;
    }
    let _mu = 0;
    function _calculateViscosity() {
      if (_mu_update) {
        let tr = _temperature / _LJpotential;
        let dr = 0.5 * Math.pow(_dipole, 2) / (_LJpotential * Parameters.k * Math.pow(_LJdiameter, 3));
        let sigma = CollisionIntegral22(tr, dr);
        _mu = 1e-5 * (5 / 16) * Math.sqrt(Parameters.pi * Parameters.k * _temperature * _molecularWeight * 1.66054) / (Parameters.pi * sigma * Math.pow(_LJdiameter, 2));
        _mu_update = false;
      }
    }
    function getViscosity() {
      _calculateViscosity();
      return _mu;
    }
    let _v = 0;
    function _calculateArithmeticMeanGasVelocity() {
      if (_v_update) {
        _v = Math.sqrt(8 * Parameters.R * _temperature / (Parameters.pi * _molecularWeight));
        _v_update = false;
      }
    }
    function getArithmeticMeanGasVelocity() {
      _calculateArithmeticMeanGasVelocity();
      return _v;
    }
    let _l = 0;
    function _calculateMeanFreePath() {
      if (_l_update) {
        _l = Parameters.k * 1e-3 * _temperature / (Math.sqrt(2) * _pressure * Math.pow(_LJdiameter, 2));
        _l_update = false;
      }
    }
    function getMeanFreePath() {
      _calculateMeanFreePath();
      return _l;
    }
    let _diff = 0;
    function _calculateDiffusion() {
      if (_diff_update) {
        let MWmix = _molecularWeight / 2;
        let tr = _temperature / _LJpotential;
        let dr = 0.5 * Math.pow(_dipole, 2) / (_LJpotential * Parameters.k * Math.pow(_LJdiameter, 3));
        let sigma = CollisionIntegral11(tr, dr);
        _diff = 3 / 16 * Math.sqrt(2 * Parameters.pi * Math.pow(Parameters.k * _temperature, 3) / (MWmix * 1.66054)) / (_pressure * Parameters.pi * Math.pow(_LJdiameter, 2) * sigma);
        _diff = _diff * 0.1;
        _diff_update = false;
      }
    }
    function getDiffusion() {
      _calculateDiffusion();
      return _diff;
    }
    let _cond = 0;
    function _calculateThermalConductivity() {
      if (_cond_update) {
        _calculateViscosity();
        _calculateDiffusion();
        _calculateSpecificHeat();
        let cvtrans = 0;
        let cvrot = 0;
        let cvvib = 0;
        if (_geometry == 0) {
          cvtrans = 3 * Parameters.R * 0.5;
          cvrot = 0;
          cvvib = 0;
        } else if (_geometry == 1) {
          cvtrans = 3 * Parameters.R * 0.5;
          cvrot = Parameters.R;
          cvvib = _cpMole - Parameters.R - 5 * Parameters.R * 0.5;
        } else {
          cvtrans = 3 * Parameters.R * 0.5;
          cvrot = 3 * Parameters.R * 0.5;
          cvvib = _cpMole - Parameters.R - 3 * Parameters.R;
        }
        let rho = getDensity();
        let A = 5 / 2 - rho * _diff / _mu;
        let F_T = 1 + 0.5 * Math.sqrt(Math.pow(Parameters.pi, 3) * _LJpotential / _temperature) + (0.25 * Math.pow(Parameters.pi, 2) + 2) * (_LJpotential / _temperature) + Math.sqrt(Math.pow(Parameters.pi * _LJpotential / _temperature, 3));
        let F_298 = 1 + 0.5 * Math.sqrt(Math.pow(Parameters.pi, 3) * _LJpotential / 298) + (0.25 * Math.pow(Parameters.pi, 2) + 2) * (_LJpotential / 298) + Math.sqrt(Math.pow(Parameters.pi * _LJpotential / 298, 3));
        let Zrot = _collision * F_298 / F_T;
        let B = Zrot + 2 / Parameters.pi * (5 / 3 * (cvrot / Parameters.R) + rho * _diff / _mu);
        let ftrans = 5 / 2 * (1 - 2 * cvrot * A / (Parameters.pi * cvtrans * B));
        let frot = rho * _diff / _mu * (1 + 2 * A / (Parameters.pi * B));
        let fvib = rho * _diff / _mu;
        _cond = _mu * (ftrans * cvtrans + frot * cvrot + fvib * cvvib) / _molecularWeight;
        _cond_update = false;
      }
    }
    function getThermalConductivity() {
      _calculateThermalConductivity();
      return _cond;
    }
    function getName() {
      return _name;
    }
    function getGeometry() {
      return _geometry;
    }
    function getLJpotential() {
      return _LJpotential;
    }
    function getLJdiameter() {
      return _LJdiameter;
    }
    function getDipole() {
      return _dipole;
    }
    function getPolar() {
      return _polar;
    }
    function getCollision() {
      return _collision;
    }
    return {
      updateGasState,
      updateMoleFraction,
      getName,
      getMolecularWeight,
      getDensity,
      getMolarSpecificHeat,
      getMassSpecificHeat,
      getMolarEnthalpy,
      getMassEnthalpy,
      getMolarEntropy,
      getMassEntropy,
      getMolarInternalEnergy,
      getMassInternalEnergy,
      getMolarGibbsFreeEnergy,
      getMassGibbsFreeEnergy,
      getViscosity,
      getArithmeticMeanGasVelocity,
      getMeanFreePath,
      getDiffusion,
      getThermalConductivity,
      getGeometry,
      getLJpotential,
      getLJdiameter,
      getDipole,
      getPolar,
      getCollision
    };
  }
  function GasMixture({
    mixtureComposition,
    gasState,
    compositionType
  }) {
    let _cp_update = true;
    let _h_update = true;
    let _s_update = true;
    let _mu_update = true;
    let _diff_update = true;
    let _diffMix_update = true;
    let _cond_update = true;
    function _resetBools() {
      _cp_update = true;
      _h_update = true;
      _s_update = true;
      _mu_update = true;
      _diff_update = true;
      _diffMix_update = true;
      _cond_update = true;
    }
    let _compositionType = compositionType;
    let _speciesName = Object.keys(mixtureComposition);
    let _numberOfSpecies = _speciesName.length;
    let _elementsCompositionDictionary = {};
    let _molecularWeight = 0;
    let _elementsSymbolList = new Array();
    let _speciesToelementsMatrix = new Array(_numberOfSpecies);
    let _species = new Array(_numberOfSpecies);
    let _moleFraction = new Array(_numberOfSpecies);
    let _massFraction = new Array(_numberOfSpecies);
    let _temperature = gasState.getTemperature();
    let _pressure = gasState.getPressure();
    if (_compositionType == Fractions.MOLE) {
      let compositionArray = new Array(_numberOfSpecies);
      for (let i = 0; i < _numberOfSpecies; i++) {
        _species[i] = GasSpecie({
          name: _speciesName[i],
          gasState
        });
        _moleFraction[i] = mixtureComposition[_speciesName[i]];
        compositionArray[i] = {
          "specie": _species[i],
          "value": _moleFraction[i]
        };
      }
      _molecularWeight = compositionArray.map((compositionDictionary) => compositionDictionary.value * compositionDictionary.specie.getMolecularWeight()).reduce((a, b) => a + b, 0);
      _massFraction = compositionArray.map((compositionDictionary) => compositionDictionary.value * compositionDictionary.specie.getMolecularWeight() / _molecularWeight);
    } else if (_compositionType == Fractions.MASS) {
      let compositionArray = new Array(_numberOfSpecies);
      for (let i = 0; i < _numberOfSpecies; i++) {
        _species[i] = GasSpecie({
          name: _speciesName[i],
          gasState
        });
        _massFraction[i] = mixtureComposition[_speciesName[i]];
        compositionArray[i] = {
          "specie": _species[i],
          "value": _massFraction[i]
        };
      }
      _molecularWeight = compositionArray.map((compositionDictionary) => compositionDictionary.value / compositionDictionary.specie.getMolecularWeight()).reduce((a, b) => a + b, 0);
      _moleFraction = compositionArray.map((compositionDictionary) => compositionDictionary.value / compositionDictionary.specie.getMolecularWeight() / _mixtureMolecularWeight);
    }
    if (Math.abs(_moleFraction.reduce((a, b) => a + b, 0) - 1) > 1e-8) {
      AsaliError("Composition sum != 1");
    } else {
      for (let i = 0; i < _numberOfSpecies; i++) {
        _species[i].updateMoleFraction(_moleFraction[i]);
      }
    }
    for (let i = 0; i < _numberOfSpecies; i++) {
      let molecule = Molecule(_speciesName[i]);
      _elementsCompositionDictionary[_speciesName[i]] = molecule.getElementCounterDict();
      _elementsSymbolList = _elementsSymbolList.concat(molecule.getElementsSymbol()).filter(UniqueArray);
    }
    let _numberOfElements = _elementsSymbolList.length;
    for (let i = 0; i < _numberOfSpecies; i++) {
      _speciesToelementsMatrix[i] = new Array(_numberOfElements).fill(0);
      for (let j = 0; j < _numberOfElements; j++) {
        if (_elementsSymbolList[j] in _elementsCompositionDictionary[_speciesName[i]]) {
          _speciesToelementsMatrix[i][j] = _elementsCompositionDictionary[_speciesName[i]][_elementsSymbolList[j]];
        }
      }
    }
    function updateGasState(gasState2) {
      _temperature = gasState2.getTemperature();
      _pressure = gasState2.getPressure();
      _resetBools();
      for (let i = 0; i < _numberOfSpecies; i++) {
        _species[i].updateGasState(gasState2);
      }
      return this;
    }
    function getTemperature() {
      return _temperature;
    }
    function getPressure() {
      return _pressure;
    }
    function getCompositionType() {
      return _compositionType;
    }
    function getMassFraction() {
      return _massFraction;
    }
    function getMoleFraction() {
      return _moleFraction;
    }
    function getSpecies() {
      for (let i = 0; i < _numberOfSpecies; i++) {
        _species[i].updateMoleFraction(1);
      }
      return _species;
    }
    function getSpeciesName() {
      return _speciesName;
    }
    function getNumberOfSpecies() {
      return _numberOfSpecies;
    }
    function getNumberOfElements() {
      return _numberOfElements;
    }
    function getElementsCompositionDictionary() {
      return _elementsCompositionDictionary;
    }
    function getElementsSymbolList() {
      return _elementsSymbolList;
    }
    function getSpeciesToElementsMatrix() {
      return _speciesToelementsMatrix;
    }
    let _speciesMolecularWeight = _species.map((specie) => specie.getMolecularWeight());
    function getMolecularWeight() {
      return _molecularWeight;
    }
    function getDensity() {
      return _molecularWeight * _pressure / (Parameters.R * _temperature);
    }
    function getSpeciesMolecularWeight() {
      return _speciesMolecularWeight;
    }
    let _cpMole = _species.map((specie) => specie.getMolarSpecificHeat());
    let _cpMass = _species.map((specie) => specie.getMassSpecificHeat());
    let _cpMixMole = 0;
    let _cpMixMass = 0;
    function _calculateSpecificHeat() {
      if (_cp_update) {
        _cpMixMole = 0;
        _cpMixMass = 0;
        for (let i = 0; i < _numberOfSpecies; i++) {
          _cpMixMole = _cpMixMole + _cpMole[i] * _moleFraction[i];
          _cpMixMass = _cpMixMass + _cpMass[i] * _massFraction[i];
        }
        _cp_update = false;
      }
    }
    function getMolarSpecificHeat() {
      _calculateSpecificHeat();
      return _cpMixMole;
    }
    function getMassSpecificHeat() {
      _calculateSpecificHeat();
      return _cpMixMass;
    }
    function getSpeciesMolarSpecificHeat() {
      return _species.map((specieDictionary) => specieDictionary.getsMolarSpecificHeat());
    }
    function getSpeciesMassSpecificHeat() {
      return _species.map((specieDictionary) => specieDictionary.getMassSpecificHeat());
    }
    let _hMole = _species.map((specie) => specie.getMolarEnthalpy());
    let _hMass = _species.map((specie) => specie.getMassEnthalpy());
    let _hMixMole = 0;
    let _hMixMass = 0;
    function _calculateEnthalpy() {
      if (_h_update) {
        _hMixMole = 0;
        _hMixMass = 0;
        for (let i = 0; i < _numberOfSpecies; i++) {
          _hMixMole = _hMixMole + _hMole[i] * _moleFraction[i];
          _hMixMass = _hMixMass + _hMass[i] * _massFraction[i];
        }
        _h_update = false;
      }
    }
    function getMolarEnthalpy() {
      _calculateEnthalpy();
      return _hMixMole;
    }
    function getMassEnthalpy() {
      _calculateEnthalpy();
      return _hMixMass;
    }
    function getSpeciesMolarEnthalpy() {
      return _species.map((specieDictionary) => specieDictionary.getMolarEnthalpy());
    }
    function getSpeciesMassEnthalpy() {
      return _species.map((specieDictionary) => specieDictionary.getMassEnthalpy());
    }
    let _sMole = _species.map((specie) => specie.getMolarEntropy());
    let _sMixMole = 0;
    let _sMixMass = 0;
    function _calculateEntropy() {
      if (_s_update) {
        _sMixMole = 0;
        _sMixMass = 0;
        for (let i = 0; i < _numberOfSpecies; i++) {
          _sMixMole = _sMixMole + _sMole[i] * _moleFraction[i];
        }
        _sMixMass = _sMixMole / _molecularWeight;
        _s_update = false;
      }
    }
    function getMolarEntropy() {
      _calculateEntropy();
      return _sMixMole;
    }
    function getMassEntropy() {
      _calculateEntropy();
      return _sMixMass;
    }
    function getSpeciesMolarEntropy() {
      return _species.map((specieDictionary) => specieDictionary.getMolarEntropy());
    }
    function getSpeciesMassEntropy() {
      return _species.map((specieDictionary) => specieDictionary.getMassEntropy());
    }
    function getMolarInternalEnergy() {
      _calculateEnthalpy();
      return _hMixMole - Parameters.R * _temperature;
    }
    function getMassInternalEnergy() {
      _calculateEnthalpy();
      return _hMixMass - Parameters.R * _temperature / _molecularWeight;
    }
    function getSpeciesMolarInternalEnergy() {
      return _species.map((specieDictionary) => specieDictionary.geMolarInternalEnergy());
    }
    function getSpeciesMassInternalEnergy() {
      return _species.map((specieDictionary) => specieDictionary.getMassInternalEnergy());
    }
    function getMolarGibbsFreeEnergy() {
      _calculateEnthalpy();
      _calculateEntropy();
      return _hMixMole - _sMixMole * _temperature;
    }
    function getMassGibbsFreeEnergy() {
      _calculateEnthalpy();
      _calculateEntropy();
      return _hMixMass - _sMixMass * _temperature;
    }
    function getSpeciesMolarGibbsFreeEnergy() {
      return _species.map((specieDictionary) => specieDictionary.getMolarGibbsFreeEnergy());
    }
    function getSpeciesMassGibbsFreeEnergy() {
      return _species.map((specieDictionary) => specieDictionary.getMassGibbsFreeEnergy());
    }
    let _mu = _species.map((specie) => specie.getViscosity());
    let _muMix = 0;
    function _calculateViscosity() {
      if (_mu_update) {
        _muMix = 0;
        let sum3 = 0;
        let phi = 0;
        for (let k = 0; k < _numberOfSpecies; k++) {
          sum3 = 0;
          for (let j = 0; j < _numberOfSpecies; j++) {
            phi = 1 / Math.sqrt(8) * (1 / Math.sqrt(1 + _speciesMolecularWeight[k] / _speciesMolecularWeight[j])) * Math.pow(1 + Math.sqrt(_mu[k] / _mu[j]) * Math.pow(_speciesMolecularWeight[j] / _speciesMolecularWeight[k], 1 / 4), 2);
            sum3 = sum3 + _moleFraction[j] * phi;
          }
          _muMix = _muMix + _moleFraction[k] * _mu[k] / sum3;
        }
        _mu_update = false;
      }
    }
    function getViscosity() {
      _calculateViscosity();
      return _muMix;
    }
    function getSpeciesViscosity() {
      return _species.map((specieDictionary) => specieDictionary.getViscosity());
    }
    let _diff = new Array(_numberOfSpecies);
    let _diffMix = new Array(_numberOfSpecies);
    let _polar = _species.map((specie) => specie.getPolar());
    let _LJpotential = _species.map((specie) => specie.getLJpotential());
    let _LJdiameter = _species.map((specie) => specie.getLJdiameter());
    let _dipole = _species.map((specie) => specie.getDipole());
    function _calculateBinaryDiffusion() {
      if (_diff_update) {
        for (let i = 0; i < _numberOfSpecies; i++) {
          _diff[i] = new Array(_numberOfSpecies);
        }
        for (let i = 0; i < _numberOfSpecies; i++) {
          for (let j = 0; j < i; j++) {
            _diff[i][j] = _diff[j][i];
          }
          for (let j = i; j < _numberOfSpecies; j++) {
            let MWmix = _speciesMolecularWeight[i] * _speciesMolecularWeight[j] / (_speciesMolecularWeight[i] + _speciesMolecularWeight[j]);
            let LJpotentialmix = 0;
            let LJdiametermix = 0;
            let dipolemix = 0;
            if (_polar[i] == 0 && _polar[j] == 0) {
              LJpotentialmix = Math.sqrt(_LJpotential[i] * _LJpotential[j]);
              LJdiametermix = 0.5 * (_LJdiameter[i] + _LJdiameter[j]);
              dipolemix = Math.sqrt(_dipole[i] * _dipole[j]);
            } else if (_polar[i] > 0 && _polar[j] > 0) {
              LJpotentialmix = Math.sqrt(_LJpotential[i] * _LJpotential[j]);
              LJdiametermix = 0.5 * (_LJdiameter[i] + _LJdiameter[j]);
              dipolemix = Math.sqrt(_dipole[i] * _dipole[j]);
            } else {
              let polarn = 0;
              let dipolep = 0;
              let chi = 0;
              if (_polar[i] == 0) {
                polarn = _polar[i] / Math.pow(_LJdiameter[i], 3);
                dipolep = 100 * _dipole[j] / Math.sqrt(_LJpotential[j] * 1.3806488 * Math.pow(_LJdiameter[j], 3));
                chi = 1 + 0.25 * polarn * dipolep * Math.sqrt(_LJpotential[j] / _LJpotential[i]);
              } else {
                polarn = _polar[j] / Math.pow(_LJdiameter[j], 3);
                dipolep = 100 * _dipole[i] / Math.sqrt(_LJpotential[i] * 1.3806488 * Math.pow(_LJdiameter[innerWidth], 3));
                chi = 1 + 0.25 * polarn * dipolep * Math.sqrt(_LJpotential[i] / _LJpotential[j]);
              }
              LJpotentialmix = Math.pow(chi, 2) * Math.sqrt(_LJpotential[i] * _LJpotential[j]);
              LJdiametermix = 0.5 * (_LJdiameter[i] + _LJdiameter[j]) * Math.pow(chi, -1 / 6);
              dipolemix = 0;
            }
            let tr = _temperature / LJpotentialmix;
            let dr = 0.5 * Math.pow(dipolemix, 2) / (LJpotentialmix * Parameters.k * Math.pow(LJdiametermix, 3));
            let sigma = CollisionIntegral11(tr, dr);
            _diff[i][j] = 3 / 16 * Math.sqrt(2 * Parameters.pi * Math.pow(Parameters.k * _temperature, 3) / (MWmix * 1.66054)) / (_pressure * Parameters.pi * Math.pow(LJdiametermix, 2) * sigma);
            _diff[i][j] = _diff[i][j] * 0.1;
          }
        }
        _diff_update = false;
      }
    }
    function _calculateMixtureDiffusion() {
      if (_diffMix_update) {
        _calculateBinaryDiffusion();
        for (let i = 0; i < _numberOfSpecies; i++) {
          let A = 0;
          let B = 0;
          for (let j = 0; j < _numberOfSpecies; j++) {
            if (j != i) {
              A = A + _moleFraction[j] * _speciesMolecularWeight[j];
              B = B + _moleFraction[j] / _diff[j][i];
            }
          }
          _diffMix[i] = A / (_molecularWeight * B);
        }
        _diffMix_update = false;
      }
    }
    function getBinaryDiffusion() {
      _calculateBinaryDiffusion();
      return _diff;
    }
    function getMixtureDiffusion() {
      _calculateMixtureDiffusion();
      return _diffMix;
    }
    function getSpeciesDiffusion() {
      return _species.map((specieDictionary) => specieDictionary.getDiffusion());
    }
    let _cond = _species.map((specie) => specie.getThermalConductivity());
    let _condMix = 0;
    function _calculateThermalConductivity() {
      if (_cond_update) {
        let A = 0;
        let B = 0;
        for (let i = 0; i < _numberOfSpecies; i++) {
          A = A + _moleFraction[i] * _cond[i];
          B = B + _moleFraction[i] / _cond[i];
        }
        _condMix = 0.5 * (A + 1 / B);
        _cond_update = false;
      }
    }
    function getThermalConductivity() {
      _calculateThermalConductivity();
      return _condMix;
    }
    function getSpeciesThermalConductivity() {
      return _species.map((specieDictionary) => specieDictionary.getThermalConductivity());
    }
    function getSpeciesArithmeticMeanGasVelocity() {
      return _species.map((specieDictionary) => specieDictionary.getArithmeticMeanGasVelocity());
    }
    function getSpeciesMeanFreePath() {
      return _species.map((specieDictionary) => specieDictionary.getMeanFreePath());
    }
    function calculateChemicalEquilibriumTP(iter = 10, tol = 1e-6) {
      let _g = new Array(_numberOfSpecies);
      for (let i = 0; i < _numberOfSpecies; i++) {
        let s = _species[i];
        s.updateMoleFraction(1);
        _g[i] = s.getMolarGibbsFreeEnergy() / Parameters.R / _temperature;
      }
      let _x0 = matrix(_moleFraction);
      let _ntot = _pressure / (Parameters.R * _temperature);
      let _n0 = multiply(_x0, _ntot);
      let _UL = matrix(_speciesToelementsMatrix);
      let _bL = multiply(transpose(_UL), _n0);
      let _LR = multiply(transpose(_UL), _ntot);
      for (let i = 0; i < iter; i++) {
        let _x = new Array(_numberOfSpecies);
        let _x_inv = new Array(_numberOfSpecies);
        for (let j = 0; j < _numberOfSpecies; j++) {
          let v = Math.max(subset(_x0, index(j)), 1e-16);
          _x_inv[j] = -1 / v;
          _x[j] = v;
        }
        let _UR = diag(_x_inv);
        let _bU = add2(add2(log3(_x), _g), -1);
        let _A = zeros2(_numberOfSpecies + _numberOfElements, _numberOfSpecies + _numberOfElements);
        _A = subset(_A, index(range(0, _numberOfSpecies), range(0, _numberOfElements)), _UL);
        _A = subset(_A, index(range(0, _numberOfSpecies), range(_numberOfElements, _numberOfElements + _numberOfSpecies)), _UR);
        _A = subset(_A, index(range(_numberOfSpecies, _numberOfSpecies + _numberOfElements), range(_numberOfElements, _numberOfElements + _numberOfSpecies)), _LR);
        let _b = concat(_bU, _bL);
        let _sol = lusolve(_A, _b);
        _x = subset(_sol, index(range(_numberOfElements, _numberOfSpecies + _numberOfElements), 0));
        _x = transpose(divide2(_x, sum2(_x)));
        _x = reshape2(_x, [-1]);
        if (norm(add2(_x, multiply(_x0, -1))) < tol) {
          _x0 = _x;
          break;
        } else {
          _x0 = _x;
        }
      }
      return _x0._data;
    }
    return {
      updateGasState,
      getTemperature,
      getPressure,
      getCompositionType,
      getSpecies,
      getSpeciesName,
      getNumberOfSpecies,
      getNumberOfElements,
      getElementsCompositionDictionary,
      getElementsSymbolList,
      getSpeciesToElementsMatrix,
      getMassFraction,
      getMoleFraction,
      getMolecularWeight,
      getSpeciesMolecularWeight,
      getDensity,
      getMolarSpecificHeat,
      getMassSpecificHeat,
      getSpeciesMolarSpecificHeat,
      getSpeciesMassSpecificHeat,
      getMolarEnthalpy,
      getMassEnthalpy,
      getSpeciesMolarEnthalpy,
      getSpeciesMassEnthalpy,
      getMolarEntropy,
      getMassEntropy,
      getSpeciesMolarEntropy,
      getSpeciesMassEntropy,
      getMolarInternalEnergy,
      getMassInternalEnergy,
      getSpeciesMolarInternalEnergy,
      getSpeciesMassInternalEnergy,
      getMolarGibbsFreeEnergy,
      getMassGibbsFreeEnergy,
      getSpeciesMolarGibbsFreeEnergy,
      getSpeciesMassGibbsFreeEnergy,
      getViscosity,
      getSpeciesViscosity,
      getBinaryDiffusion,
      getMixtureDiffusion,
      getSpeciesDiffusion,
      getThermalConductivity,
      getSpeciesThermalConductivity,
      getSpeciesArithmeticMeanGasVelocity,
      getSpeciesMeanFreePath,
      calculateChemicalEquilibriumTP
    };
  }
})();
/*! Bundled license information:

assert/assert.js:
  (*!
   * The buffer module from node.js, for the browser.
   *
   * @author   Feross Aboukhadijeh <feross@feross.org> <http://feross.org>
   * @license  MIT
   *)

decimal.js/decimal.mjs:
  (*!
   *  decimal.js v10.6.0
   *  An arbitrary-precision Decimal type for JavaScript.
   *  https://github.com/MikeMcl/decimal.js
   *  Copyright (c) 2025 Michael Mclaughlin <M8ch88l@gmail.com>
   *  MIT Licence
   *)

fraction.js/fraction.js:
  (**
   * @license Fraction.js v4.3.7 31/08/2023
   * https://www.xarg.org/2014/03/rational-numbers-in-javascript/
   *
   * Copyright (c) 2023, Robert Eisele (robert@raw.org)
   * Dual licensed under the MIT or GPL Version 2 licenses.
   **)
*/
