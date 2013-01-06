lxpx
====

PureData external for formatting MIDI SysEx messages to control Lexicon LXP-1 and LXP-5 audio effect units.

The Lexicon LXP-1 and LXP-5 are physical audio effect units that were produced in the mid 80s. The LXP-1 is mainly used for reverb effects, while its sister unit, the LXP-5, focuses on more specialized effects such as pitch shift. 

One unit takes half a rack unit in size. This makes for a limited UI. As a result, only a small portion of the many parameters available for the effect algorithms are reachable using physical knobs. Everything else must be controlled via MIDI. 

The LXP units have a rather unorthodox MIDI implementation. A unit called the Lexicon MRC was produced to gain full control. This was essentially a tailored MIDI controller. This project eliminates such a controller by:

1) Providing a PureData external, lxpx, that produces the correct SysEx messages given parameter number and value and input.

2) Providing PureData patches that functions as software MIDI controller interfaces for the LXP units effects.

This repo contains:

* C source code for the lxpx PD external as well as a selection of binaries
* Effect patches based on parameter definitions from owner's manuals
* A Python script for autogenerating effect patches based on a PD patch template