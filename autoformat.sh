#!/bin/zsh
\cd "$(dirname "$0")">/dev/null
if which colout>/dev/null; then
  astyle -xc -A14 -s2 -j -xG -S -K -N -xn -xl -n **/*.{cpp,h}|\grep -P '^(?!Unchanged)'|colout '(Formatted)' green
else
  astyle -xc -A14 -s2 -j -xG -S -K -N -xn -xl -n **/*.{cpp,h}|\grep -P '^(?!Unchanged)'
fi
\cd ->/dev/null
