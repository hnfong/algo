all:
	set -e; for dd in *; do if [ -d "$$dd" ]; then ./checker.py ALL "$$dd"; fi; done

clean:
	find . -name '*.exe' -exec rm -vf '{}' ';'
