### Variables ------------------------------------------------------------------

TARGETS = terminal_test.native
PACKAGES = lambda-term,lwt
REBUILD = reasonbuild

### Tasks ----------------------------------------------------------------------

.PHONY: build
build: ${TARGETS}


.PHONY: run
run:
	./terminal_test.native


### Targets --------------------------------------------------------------------

%.native: %.re
	${REBUILD} -pkgs "${PACKAGES}" "$@"
