program pspn;
var
	i,j,k,n,z : longint;
	w : array[0..30,0..30] of longint;
begin
	n := 9;
	fillchar(w,sizeof(w),0);
	w[1,1] := 1;
	for i := 2 to n do begin
		{ do 1 and i first }
		z := 0;
		for j := 1 to i div 2 do begin
			if (i-j=j) then begin
				z := z + (w[j,j]*(w[j,j]-1))div 2+w[j,j];
			end else z := z + w[j,j]*w[i-j,j];
		end;
		w[i,1] := 2*z;
		w[i,i] := z;

		{ do i-1 downto 2 }

		for j := i-1 downto 2 do begin
			z := 0;
			for k := 1 to i div 2 do begin
			if (i-k=k) then begin
				z := z + (w[k,j]*(w[k,j]-1))div 2+w[k,j] ;
				writeln((w[k,j]*(w[k,j]-1))div 2+w[k,j], ' ', w[k,j]*w[k,j]);
			end else 
				z := z + w[k,j]*w[i-k,j];
			end;
			w[i,j] := w[i,i]+z;
		end;
		write('n = ', i:2,' ' );
		for j := 1 to n do begin
			write(w[i,j]:5);
		end;
		writeln;
	end
end.
