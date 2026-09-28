#!/usr/bin/env bash
# Run from any directory; compile only into a temporary directory.
set -euo pipefail
library_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
build_dir="$(mktemp -d)"
trap 'rm -rf -- "$build_dir"' EXIT
# --release is available in JDK 9+; this verifies Java 8 language/API compatibility.
find "$library_dir" -name '*.java' -print0 |
    xargs -0 javac --release 8 -Xlint:all,-options -Werror -d "$build_dir"
java -cp "$build_dir" LibraryTest
while IFS= read -r -d '' source; do
    class_name="$(basename -- "$source" .java)"
    if [[ "$class_name" == Main || "$class_name" == LibraryTest ]]; then continue; fi
    java -cp "$build_dir" "$class_name" > /dev/null
done < <(find "$library_dir" -name '*.java' -print0)
actual="$(printf '5\n1 2 3 4 5\n' | java -cp "$build_dir" Main)"
[[ "$actual" == 15 ]]
printf 'All standalone demos and the contest input/output example passed.\n'
