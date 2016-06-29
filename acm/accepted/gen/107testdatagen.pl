#!/usr/bin/perl

for ($t=2;$t<=10;$t++) {
	for ($n=1;$n<=100000;$n++) {
		if (pow($n+1,$t) > 1000000000) { last; };
		print pow($n+1,$t) . " " . pow($n,$t) . "\n";
	};
};

sub pow {
	my ($a,$n) = @_;
	local $i;
	local $t;
	$t = 1;
	for ($i=1;$i<=$n;$i++) {
		$t = $t * $a;
	};
	return $t;
};

