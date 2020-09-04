(this["webpackJsonpreason-game-of-life"]=this["webpackJsonpreason-game-of-life"]||[]).push([[0],{13:function(e,n,t){"use strict";n.boardSize=32,n.tileSize=".75rem"},16:function(e,n,t){"use strict";var r=t(2),a=t(32),i=t(36),o=t(37);t(66);var c=0|Date.now(),l=document.querySelector("#root");null!=l&&a.render(r.createElement(o.make,{}),l),i.register(),n.register_service_worker=function(e){i.register()},n.randomSeed=c},25:function(e,n,t){"use strict";var r=t(2),a=t(8),i=t(67),o=a.css(void 0,{hd:a.display("flex"),tl:{hd:a.color(a.Css.Color.white),tl:0}});var c={styles:o,make:function(e){var n={className:o},t=Object.assign(n,e),a=e.children;return r.createElement("div",t,[void 0!==a?a:null])}},l=a.css(void 0,{hd:a.display("flex"),tl:{hd:a.textAlign(a.center),tl:{hd:a.justifyContent(a.center),tl:{hd:a.alignItems(a.center),tl:{hd:a.paddingTop(a.rem(2)),tl:{hd:a.fontSize(a.rem(2)),tl:{hd:a.lineHeight(a.rem(1)),tl:0}}}}}}});var s={styles:l,make:function(e){var n={className:l},t=Object.assign(n,e),a=e.children;return r.createElement("div",t,[void 0!==a?a:null])}},u=a.css(void 0,{hd:a.width(a.pct(100)),tl:0});var d={styles:u,make:function(e){var n={className:u},t=Object.assign(n,e),a=e.children;return r.createElement("div",t,[void 0!==a?a:null])}};function m(e){var n=e.name;return r.createElement("i",{className:"fas fa-"+n})}var f={make:m};function h(e){var n=e.label,t=e.background,o=e.onClick,c=e.disabled,l=e.children,s=void 0!==c&&c,u="0 0 0 4px "+i.opacify(-.4,t),d=a.css(void 0,{hd:a.fontSize(a.rem(.9)),tl:{hd:a.padding2(a.rem(.5),a.rem(.8)),tl:{hd:a.p("background-color",t),tl:{hd:a.width(a.rem(3)),tl:{hd:a.height(a.rem(3)),tl:{hd:a.color(a.Css.Color.white),tl:{hd:a.borderRadius(a.pct(50)),tl:{hd:a.margin2("zero",a.rem(.5)),tl:{hd:a.borderWidth("zero"),tl:{hd:a.userSelect(a.none),tl:{hd:a.outline(a.rem(0),a.none,a.Css.Color.white),tl:{hd:a.fontWeight(700),tl:{hd:a.cursor("pointer"),tl:{hd:a.p("transition","all .15s ease-in"),tl:{hd:a.select(":focus",{hd:a.p("box-shadow",u),tl:{hd:a.opacity(.9),tl:0}}),tl:0}}}}}}}}}}}}}}});return r.createElement("button",{"aria-label":n,className:d,disabled:s,onClick:o},l)}var g={make:h};var v={make:function(e){var n=e.isToggled,t=e.onClick,a=e.label,i=e.disabled,o=void 0!==i&&i,c=n?"#666":"#7A8288",l=n?"pause":"play";return r.createElement(h,{label:a,background:c,onClick:t,disabled:o,children:r.createElement(m,{name:l})})}};n.Root=c,n.AppBar=s,n.Content=d,n.Icon=f,n.Button=g,n.ToggleButton=v},28:function(e,n,t){e.exports=t(29)},29:function(e,n,t){"use strict";t.r(n);t(30);var r=t(16);for(var a in r)"default"!==a&&function(e){t.d(n,e,(function(){return r[e]}))}(a)},36:function(e,n,t){"use strict";t.r(n),t.d(n,"register",(function(){return a})),t.d(n,"unregister",(function(){return o}));var r=Boolean("localhost"===window.location.hostname||"[::1]"===window.location.hostname||window.location.hostname.match(/^127(?:\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){3}$/));function a(e){if("serviceWorker"in navigator){if(new URL("/reason-game-of-life",window.location.href).origin!==window.location.origin)return;window.addEventListener("load",(function(){var n="".concat("/reason-game-of-life","/service-worker.js");r?(!function(e,n){fetch(e,{headers:{"Service-Worker":"script"}}).then((function(t){var r=t.headers.get("content-type");404===t.status||null!=r&&-1===r.indexOf("javascript")?navigator.serviceWorker.ready.then((function(e){e.unregister().then((function(){window.location.reload()}))})):i(e,n)})).catch((function(){console.log("No internet connection found. App is running in offline mode.")}))}(n,e),navigator.serviceWorker.ready.then((function(){console.log("This web app is being served cache-first by a service worker. To learn more, visit https://bit.ly/CRA-PWA")}))):i(n,e)}))}}function i(e,n){navigator.serviceWorker.register(e).then((function(e){e.onupdatefound=function(){var t=e.installing;null!=t&&(t.onstatechange=function(){"installed"===t.state&&(navigator.serviceWorker.controller?(console.log("New content is available and will be used when all tabs for this page are closed. See https://bit.ly/CRA-PWA."),n&&n.onUpdate&&n.onUpdate(e)):(console.log("Content is cached for offline use."),n&&n.onSuccess&&n.onSuccess(e)))})}})).catch((function(e){console.error("Error during service worker registration:",e)}))}function o(){"serviceWorker"in navigator&&navigator.serviceWorker.ready.then((function(e){e.unregister()})).catch((function(e){console.error(e.message)}))}},37:function(e,n,t){"use strict";var r=t(0),a=t(2),i=t(38),o=t(9),c=t(51),l=t(65),s=t(25);var u=function(e){var n=a.useReducer(c.Reducers.root,c.initialState),t=n[1],u=n[0],d=a.useCallback((function(e){return function(n){return r._1(t,{_0:[e,n]})}}),[t]),m=a.useCallback((function(e){return r._1(t,1)}),[t]),f=a.useCallback((function(e){return r._1(t,0)}),[t]),h=a.useCallback((function(e){return r._1(t,4)}),[t]),g=a.useCallback((function(e){return u.isPlaying?(cancelAnimationFrame(u.animationFrameId.contents),r._1(t,3)):(function e(n){return u.animationFrameId.contents=requestAnimationFrame(e),r._1(t,4)}(),r._1(t,2))}),[u.animationFrameId,u.isPlaying,t]);return a.createElement(s.Root.make,{children:a.createElement(s.Content.make,{children:null},a.createElement(s.AppBar.make,{children:o.str("Conway's Game of Life")}),a.createElement(l.make,{isPlaying:u.isPlaying,onReset:m,onRandom:f,onTick:h,onToggleAutoplay:g}),a.createElement(i.make,{data:u.grid,onToggle:d}),a.createElement("div",void 0,o.str(u.isPlaying?"avg update rate: "+String(u.frameRate)+" fps":"")))})};n.make=u},38:function(e,n,t){"use strict";var r=t(0),a=t(2),i=t(8),o=t(5),c=t(46),l=t(9),s=i.css(void 0,{hd:i.display("flex"),tl:{hd:i.border(i.rem(.25),i.solid,i.hex("222")),tl:{hd:i.borderRadius(i.rem(.75)),tl:{hd:i.padding(i.rem(.125)),tl:0}}}});function u(e){var n={className:s},t=Object.assign(n,e),r=e.children;return a.createElement("div",t,[void 0!==r?r:null])}var d={styles:s,make:u};var m=function(e){var n=e.data,t=e.onToggle,i=a.useCallback((function(e){return function(n,i){return a.createElement(c.make,{isAlive:1===i,onToggle:function(a){return r._2(t,e,n)},y:e,x:n,key:n+"-"+e})}}),[t]),s=a.useCallback((function(e){return function(n){return a.createElement("div",{key:String(e)},l.arr(o.mapWithIndex(n,r._1(i,e))))}}),[i]);return a.createElement(u,{children:l.arr(o.mapWithIndex(n,s))})};n.Wrapper=d,n.make=m},46:function(e,n,t){"use strict";var r=t(0),a=t(2),i=t(8),o=t(9),c=t(13);function l(e,n,t){return i.css(void 0,{hd:i.p("width",t),tl:{hd:i.p("height",t),tl:{hd:i.p("background",e),tl:{hd:i.borderRadius(i.pct(50)),tl:{hd:i.margin2(i.px(2),i.px(1)),tl:{hd:i.padding("zero"),tl:{hd:i.transitionProperty("all"),tl:{hd:i.transitionDuration(i.s(.1)),tl:{hd:i.transitionTimingFunction(i.easeInOut),tl:{hd:i.cursor("pointer"),tl:{hd:i.p("box-shadow",n),tl:0}}}}}}}}}}})}function s(e){var n={className:l(e.background,e.shadow,e.tileSize)},t=Object.assign(n,e),r=e.children;return a.createElement("div",t,[void 0!==r?r:null])}var u={styles:l,make:s};var d=function(e){var n=e.isAlive,t=e.onToggle,i=e.y,l=e.x,u=o.Colors.rainbowHSL(i,l),d=n?[u,"0 0 0 0 "+u]:["#272B30",""],m=a.useCallback((function(e){return function(n){if(1===n.nativeEvent.which)return r._1(e,void 0)}}),[]);return a.createElement(s,{onMouseDown:r._1(m,t),onMouseOver:r._1(m,t),tileSize:c.tileSize,shadow:d[1],background:d[0]})};n.Wrapper=u,n.make=d},51:function(e,n,t){"use strict";var r=t(52),a=t(9),i=t(13);var o={grid:r.makeRandomGrid(i.boardSize,0|Date.now()),isPlaying:!1,animationFrameId:{contents:0},startedAt:void 0,ticks:0,frameRate:0};function c(e,n,t){if("number"!==typeof n)return r.toggleTile(e,n._0);switch(n){case 0:return r.makeRandomGrid(i.boardSize,0|Date.now());case 1:return r.makeBlankGrid(i.boardSize);case 2:case 3:return e;case 4:return r.nextGeneration(e)}}function l(e,n,t){if("number"!==typeof n)return e;if(n<2)return e;switch(n-2|0){case 0:return!0;case 1:return!1;case 2:return e}}function s(e,n,t){if("number"!==typeof n)return e;if(n<2)return e;switch(n-2|0){case 0:return Date.now();case 1:return;case 2:return e}}function u(e,n,t){var r=t.isPlaying;if("number"!==typeof n)return e;switch(n){case 0:case 2:return e;case 1:case 3:return 0;case 4:return r?e+1|0:e}}function d(e,n,t){var r=t.startedAt;return"number"===typeof n?3!==n?n>=4&&void 0!==r?a.avgFrameRate(t.ticks,r):e:0:e}var m={grid:c,isPlaying:l,startedAt:s,ticks:u,frameRate:d,root:function(e,n){return{grid:c(e.grid,n),isPlaying:l(e.isPlaying,n),animationFrameId:e.animationFrameId,startedAt:s(e.startedAt,n),ticks:u(e.ticks,n,e),frameRate:d(e.frameRate,n,e)}}};n.makeSeed=function(e){return 0|Date.now()},n.initialState=o,n.Reducers=m},52:function(e,n,t){"use strict";var r=t(0),a=t(53),i=t(20),o=t(12),c=t(5),l=t(7);function s(e){var n=e[1],t=e[0];return n<0?t-1|0:n===t?0:n}function u(e,n){return[s([n,e[0]]),s([n,e[1]])]}function d(e,n){return c.mapWithIndex(n,(function(t,a){return c.mapWithIndex(a,(function(a,i){return r._3(e,[t,a],i,n)}))}))}function m(e){return c.make(e,c.make(e,0))}function f(e,n){var t=u(n,e.length);return l.caml_array_get(l.caml_array_get(e,t[0]),t[1])}var h={hd:-1,tl:{hd:0,tl:{hd:1,tl:0}}};function g(e,n){var t=n[1],r=n[0];return o.map(o.keep(o.flatten(o.map(h,(function(e){return o.map(h,(function(n){return[r+e|0,t+n|0]}))}))),(function(e){return i.caml_notequal(e,[r,t])})),(function(n){return f(e,n)}))}function v(e,n){return o.length(o.keep(g(e,n),(function(e){return 1===e})))}function k(e,n,t){var r=v(t,e);return n?3===r||2===r?1:0:3!==r?0:1}n.safeIndex=s,n.safePoint=u,n.mapGrid=d,n.makeBlankGrid=m,n.makeRandomGrid=function(e,n){return a.init(n),d((function(e,n,t){return a.$$int(10)>7?1:0}),m(e))},n.getTile=f,n.offset=h,n.getNeighbours=g,n.countLivingNeighbours=v,n.nextState=k,n.nextGeneration=function(e){return d(k,e)},n.toggleTile=function(e,n){var t=c.map(e,(function(e){return e.slice(0)})),r=u(n,e.length),a=r[1],i=r[0],o=l.caml_array_get(l.caml_array_get(t,i),a);return l.caml_array_set(l.caml_array_get(t,i),a,o?0:1),t}},65:function(e,n,t){"use strict";var r=t(2),a=t(8),i=t(25),o=a.css(void 0,{hd:a.display("flex"),tl:{hd:a.justifyContent(a.center),tl:{hd:a.alignItems(a.center),tl:{hd:a.padding2(a.rem(2),"zero"),tl:0}}}});function c(e){var n={className:o},t=Object.assign(n,e),a=e.children;return r.createElement("div",t,[void 0!==a?a:null])}var l={styles:o,make:c};var s=function(e){var n=e.isPlaying,t=e.onReset,a=e.onRandom,o=e.onTick,l=e.onToggleAutoplay;return r.createElement(c,{children:r.createElement("div",{role:"group"},r.createElement(i.Button.make,{label:"Reset grid",background:"#ee5f5b",onClick:t,children:r.createElement(i.Icon.make,{name:"undo"})}),r.createElement(i.Button.make,{label:"Random grid",background:"#62c462",onClick:a,children:r.createElement(i.Icon.make,{name:"random"})}),r.createElement(i.Button.make,{label:"Next state",background:"#7A8288",onClick:o,disabled:n,children:r.createElement(i.Icon.make,{name:"forward"})}),r.createElement(i.ToggleButton.make,{isToggled:n,onClick:l,label:"Toggle autpplay"}))})};n.Wrapper=l,n.make=s},66:function(e,n,t){},9:function(e,n,t){"use strict";var r=t(18),a=t(47),i=t(13);var o=Math.imul(i.boardSize,i.boardSize),c=o<<1,l=Math.sqrt(c),s=360/l,u=a.make(o);var d={sqrSize:o,sumOfSquares:c,diagonalLength:l,hueIncrement:s,colorCache:u,rainbowHSL:function(e,n){var t,i=e+"-"+n,o=a.get(u,i);if(void 0!==o)t=[o,!0];else{var c=Math.imul(e,e)+Math.imul(n,n)|0,l=Math.sqrt(c)*s;t=["hsl("+r.floor(l)+", 100%, 60%)",!1]}var d=t[0];return t[1]||a.set(u,i,d),d}};n.str=function(e){return e},n.arr=function(e){return e},n.avgFrameRate=function(e,n){return r.ceil(e/((Date.now()-n)/1e3))},n.Colors=d}},[[28,1,2]]]);
//# sourceMappingURL=main.1e816ae6.chunk.js.map