#!/usr/bin/env bash
# ─────────────────────────────────────────────────────────────
#  contest.sh  —  CP contest directory scaffolder
#  Author: @AdarshGaur
#
#  Usage:
#    ./contest.sh                          # interactive mode
#    ./contest.sh cf 925                   # Codeforces Round 925
#    ./contest.sh cf-edu 40                # Codeforces EDU Round 40
#    ./contest.sh cf-custom "hello-world"  # Codeforces custom name
#    ./contest.sh ac-abc 380               # AtCoder ABC 380
#    ./contest.sh ac-arc 180               # AtCoder ARC 180
#    ./contest.sh lc-weekly 423            # LeetCode Weekly 423
#    ./contest.sh lc-biweekly 120          # LeetCode Biweekly 120
#    ./contest.sh cses dp                  # CSES topic
#    ./contest.sh custom "codechef" "starters-120"   # any other site
#
#  Options:
#    -n <num>   override number of problems  (default: 6)
#    -d <dir>   override base directory      (default: ~/cp)
#
#  NOTE: use the shell function wrapper (see README at bottom)
#        instead of calling this script directly — the wrapper
#        is what makes `contest` cd into the new directory.
# ─────────────────────────────────────────────────────────────

set -euo pipefail

# ── Config ────────────────────────────────────────────────────
BASE_DIR="${CP_HOME:-$HOME/Dev/Competitive-Programming/live}"
DEFAULT_PROBLEMS=6
TEMPLATE_SRC="$(dirname "$0")/Template.java"

# ── Colors ────────────────────────────────────────────────────
RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'
CYAN='\033[0;36m'; BOLD='\033[1m'; RESET='\033[0m'

# ── Helpers ───────────────────────────────────────────────────
info()    { echo -e "${CYAN}${BOLD}→${RESET} $*"; }
success() { echo -e "${GREEN}${BOLD}✓${RESET} $*"; }
warn()    { echo -e "${YELLOW}${BOLD}!${RESET} $*"; }
err()     { echo -e "${RED}${BOLD}✗${RESET} $*" >&2; exit 1; }

# ── Platform registry ─────────────────────────────────────────
#
#  PLATFORM_DIR    subfolder under ~/cp/
#  PLATFORM_LABEL  human-readable label for summary output
#  PLATFORM_PREFIX prepended to contest id to form the dir name
#                  e.g. prefix "round-" + id "925"  →  round-925
#  PLATFORM_STYLE  "alpha" = A B C ...   "num" = P1 P2 P3 ...
#
declare -A PLATFORM_DIR=(
    [cf]="Codeforces"     [cf-edu]="Codeforces"    [cf-custom]="Codeforces"
    [ac-abc]="Atcoder"    [ac-arc]="Atcoder"
    [lc-weekly]="LeetCode" [lc-biweekly]="LeetCode"
    [cses]="CSES"
    [custom]="custom"
)
declare -A PLATFORM_LABEL=(
    [cf]="Codeforces Round"
    [cf-edu]="Codeforces EDU Round"
    [cf-custom]="Codeforces"
    [ac-abc]="AtCoder ABC"
    [ac-arc]="AtCoder ARC"
    [lc-weekly]="LeetCode Weekly"
    [lc-biweekly]="LeetCode Biweekly"
    [cses]="CSES"
    [custom]="Custom"
)
declare -A PLATFORM_PREFIX=(
    [cf]="round-"         [cf-edu]="edu-round-"   [cf-custom]=""
    [ac-abc]="abc-"       [ac-arc]="arc-"
    [lc-weekly]="weekly-" [lc-biweekly]="biweekly-"
    [cses]=""
    [custom]=""
)
declare -A PLATFORM_STYLE=(
    [cf]="alpha"          [cf-edu]="alpha"         [cf-custom]="alpha"
    [ac-abc]="alpha"      [ac-arc]="alpha"
    [lc-weekly]="num"     [lc-biweekly]="num"
    [cses]="alpha"
    [custom]="alpha"
)

is_valid_platform() { [[ -v PLATFORM_DIR["$1"] ]]; }

# ── Problem labels ────────────────────────────────────────────
problem_labels() {
    local style="$1" count="$2"
    local labels=()
    if [[ "$style" == "num" ]]; then
        for i in $(seq 1 "$count"); do labels+=("P$i"); done
    else
        for i in $(seq 0 $(( count - 1 ))); do
            labels+=("$(printf "\\$(printf '%03o' $(( 65 + i )))")")
        done
    fi
    echo "${labels[@]}"
}

# ── Java template ─────────────────────────────────────────────
generate_main_java() {
    cat <<'JAVA'
import java.util.*;
import java.io.*;

public class Main {

    // ── Debug flag (compile-time equivalent via JVM property) ──
    // Run locally  : java -Dcicada Main
    // Submit       : java Main          (DEBUG stays false, zero cost)
    static final boolean DEBUG = System.getProperty("cicada") != null;

    // ── Constants ──────────────────────────────────────────────
    static final long INF = (long) 2e18;
    static final long MOD = (long) 1e9 + 7;

    // ── Fast I/O ───────────────────────────────────────────────
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out   = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int    nextInt()    throws IOException { return Integer.parseInt(nextToken()); }
    static long   nextLong()   throws IOException { return Long.parseLong(nextToken()); }
    static double nextDouble() throws IOException { return Double.parseDouble(nextToken()); }
    static String nextLine()   throws IOException { return br.readLine(); }

    // ── Debug ──────────────────────────────────────────────────
    static void debug(Object... args) {
        if (DEBUG) System.err.println(Arrays.deepToString(args));
    }

    // ── Solve ──────────────────────────────────────────────────
    static void solve() throws IOException {

    }

    // ── Main ───────────────────────────────────────────────────
    public static void main(String[] args) throws IOException {
        int t = nextInt();
        while (t-- > 0) solve();
        out.flush();   // never forget — PrintWriter buffers silently
    }
}
JAVA
}

# ── Zed .zed/tasks.json ───────────────────────────────────────
generate_tasks_json() {
    cat <<'JSON'
[
    {
        "label": "CP: Run (debug)",
        "command": "dir=$(dirname \"$ZED_FILE\") && cd \"$dir\" && javac \"$ZED_FILE\" && java -Dcicada -cp \"$dir\" -Dcicada Main < \"$dir/input.txt\"",
        "cwd": "$ZED_FILE",
        "reveal": "always",
        "use_new_terminal": false,
        "allow_concurrent_runs": false,
    },
    {
        "label": "CP: Run (judge mode)",
        "command": "dir=$(dirname \"$ZED_FILE\") && cd \"$dir\" && javac \"$ZED_FILE\" && java -Dcicada -cp \"$dir\" Main < \"$dir/input.txt\"",
        "cwd": "$ZED_FILE",
        "reveal": "always",
        "use_new_terminal": false,
        "allow_concurrent_runs": false,
    },
]
JSON
}

# ── Interactive mode ──────────────────────────────────────────
interactive_mode() {
    echo -e "\n${BOLD}Contest scaffolder${RESET}"
    echo "────────────────────────────────────────"
    echo -e "Pick a platform:\n"
    echo -e "  ${CYAN}1${RESET}  cf           Codeforces Round"
    echo -e "  ${CYAN}2${RESET}  cf-edu       Codeforces EDU Round"
    echo -e "  ${CYAN}3${RESET}  cf-custom    Codeforces (custom name)"
    echo -e "  ${CYAN}4${RESET}  ac-abc       AtCoder ABC"
    echo -e "  ${CYAN}5${RESET}  ac-arc       AtCoder ARC"
    echo -e "  ${CYAN}6${RESET}  lc-weekly    LeetCode Weekly"
    echo -e "  ${CYAN}7${RESET}  lc-biweekly  LeetCode Biweekly"
    echo -e "  ${CYAN}8${RESET}  cses         CSES"
    echo -e "  ${CYAN}9${RESET}  custom       Other site\n"
    echo -n "Choice [1-9 or key]: "
    read -r choice

    case "$choice" in
        1|cf)           PLATFORM="cf"           ;;
        2|cf-edu)       PLATFORM="cf-edu"       ;;
        3|cf-custom)    PLATFORM="cf-custom"    ;;
        4|ac-abc)       PLATFORM="ac-abc"       ;;
        5|ac-arc)       PLATFORM="ac-arc"       ;;
        6|lc-weekly)    PLATFORM="lc-weekly"    ;;
        7|lc-biweekly)  PLATFORM="lc-biweekly"  ;;
        8|cses)         PLATFORM="cses"         ;;
        9|custom)       PLATFORM="custom"       ;;
        *) err "Invalid choice: $choice" ;;
    esac

    if [[ "$PLATFORM" == "custom" ]]; then
        echo -n "Site name (e.g. codechef, hackerrank): "
        read -r CUSTOM_SITE
        [[ -z "$CUSTOM_SITE" ]] && err "Site name cannot be empty."
        CUSTOM_SITE="${CUSTOM_SITE,,}"
    fi

    echo -n "Contest name/number: "
    read -r CONTEST_ID
    [[ -z "$CONTEST_ID" ]] && err "Contest name cannot be empty."

    if [[ -z "$NUM_PROBLEMS" ]]; then
        echo -n "Number of problems [default: $DEFAULT_PROBLEMS]: "
        read -r np
        NUM_PROBLEMS="${np:-$DEFAULT_PROBLEMS}"
    fi
}

# ── Argument parsing ──────────────────────────────────────────
NUM_PROBLEMS=""
CUSTOM_BASE=""
PLATFORM=""
CONTEST_ID=""
CUSTOM_SITE=""

POSITIONAL=()
while [[ $# -gt 0 ]]; do
    case "$1" in
        -n) NUM_PROBLEMS="$2"; shift 2 ;;
        -d) CUSTOM_BASE="$2";  shift 2 ;;
        -h|--help) sed -n '2,20p' "$0" | sed 's/^# \{0,1\}//'; exit 0 ;;
        *)  POSITIONAL+=("$1"); shift ;;
    esac
done
set -- "${POSITIONAL[@]+"${POSITIONAL[@]}"}"

if [[ $# -eq 0 ]]; then
    interactive_mode
else
    PLATFORM="${1,,}"
    is_valid_platform "$PLATFORM" || err "Unknown platform key: '$PLATFORM'
Valid: cf  cf-edu  cf-custom  ac-abc  ac-arc  lc-weekly  lc-biweekly  cses  custom"

    if [[ "$PLATFORM" == "custom" ]]; then
        # contest custom <site> <contest-name>
        CUSTOM_SITE="${2:-}"
        CONTEST_ID="${3:-}"
        [[ -z "$CUSTOM_SITE" ]] && err "custom usage: contest custom <site> <contest-name>"
        [[ -z "$CONTEST_ID" ]] && err "custom usage: contest custom <site> <contest-name>"
        CUSTOM_SITE="${CUSTOM_SITE,,}"
    else
        CONTEST_ID="${2:-}"
        [[ -z "$CONTEST_ID" ]] && err "Provide a contest name/number.  e.g.: contest cf 925"
    fi
fi

NUM_PROBLEMS="${NUM_PROBLEMS:-$DEFAULT_PROBLEMS}"
BASE_DIR="${CUSTOM_BASE:-$BASE_DIR}"

# ── Build paths ───────────────────────────────────────────────
contest_slug="${CONTEST_ID,,}"
contest_slug="${contest_slug// /-}"          # spaces → hyphens
contest_slug="${PLATFORM_PREFIX[$PLATFORM]}${contest_slug}"

if [[ "$PLATFORM" == "custom" ]]; then
    platform_dir="$BASE_DIR/$CUSTOM_SITE"
    display_label="$CUSTOM_SITE — $contest_slug"
else
    platform_dir="$BASE_DIR/${PLATFORM_DIR[$PLATFORM]}"
    display_label="${PLATFORM_LABEL[$PLATFORM]} — $CONTEST_ID"
fi

contest_dir="$platform_dir/$contest_slug"

# ── Overwrite guard ───────────────────────────────────────────
if [[ -d "$contest_dir" ]]; then
    warn "Directory already exists: $contest_dir"
    echo -n "Overwrite problem folders inside? [y/N] "
    read -r confirm
    [[ "${confirm,,}" != "y" ]] && { info "Aborted."; exit 0; }
fi

# ── Scaffold ──────────────────────────────────────────────────
mkdir -p "$contest_dir"
mkdir -p "$contest_dir/.zed"
generate_tasks_json > "$contest_dir/.zed/tasks.json"

read -ra labels <<< "$(problem_labels "${PLATFORM_STYLE[$PLATFORM]}" "$NUM_PROBLEMS")"

for label in "${labels[@]}"; do
    prob_dir="$contest_dir/$label"
    mkdir -p "$prob_dir"
    if [[ -f "$TEMPLATE_SRC" ]]; then
        cp "$TEMPLATE_SRC" "$prob_dir/Main.java"
    else
        generate_main_java > "$prob_dir/Main.java"
    fi
    touch "$prob_dir/input.txt"
    touch "$prob_dir/output.txt"
done

# ── Summary ───────────────────────────────────────────────────
echo ""
echo -e "${BOLD}$display_label${RESET}"
echo -e "Location : ${CYAN}$contest_dir${RESET}"
echo ""
for label in "${labels[@]}"; do
    echo -e "  ${GREEN}${label}/${RESET}  Main.java  input.txt  output.txt"
done
echo -e "  ${CYAN}.zed/tasks.json${RESET}"
echo ""
success "Scaffolded. Moving you there now..."
echo ""

# ── Sentinel line read by the shell wrapper to cd ─────────────
# A script cannot cd its parent shell — the wrapper function below does it.
echo "CONTEST_DIR=$contest_dir"

# ═════════════════════════════════════════════════════════════════════════════
# SHELL WRAPPER  —  paste this into ~/.zshrc or ~/.bashrc
#
# Why a wrapper?  A child process (this script) cannot change the working
# directory of the parent shell. The wrapper runs the script, captures the
# last line (the CONTEST_DIR=... sentinel), and does the cd itself.
#
# contest() {
#     local output
#     output="$(~/Dev/Competitive-Programming/contest.sh "$@")"          # run script, capture output
#     echo "$output" | grep -v '^CONTEST_DIR='  # print everything except sentinel
#     local dir
#     dir="$(echo "$output" | grep '^CONTEST_DIR=' | cut -d= -f2-)"
#     [[ -n "$dir" && -d "$dir" ]] && cd "$dir" && echo "  $(pwd)"
# }
#
# ── Zed keybinding ────────────────────────────────────────────────────────────
# Add to ~/.config/zed/keymap.json to bind tasks to keys:
#
# [
#   {
#     "context": "Workspace",
#     "bindings": {
#       "ctrl-shift-r": ["task::Spawn", { "task_name": "CP: Run (debug)" }],
#       "ctrl-shift-j": ["task::Spawn", { "task_name": "CP: Run (judge mode)" }]
#     }
#   }
# ]
# ═════════════════════════════════════════════════════════════════════════════
