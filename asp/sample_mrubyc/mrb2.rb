puts("2 M 0")

p "creating bridge 2"
bridge = TECS::TsSample.new( "SimpleBridge2" )
times = 2
p "TEST sayHello #{times} times"
bridge.sayHello( times )
#len = 32
len = 8
buf = TECS::CharPointer.new( len )

# howAreYou ÇåƒÇ—èoÇ∑
p "TEST howAreYou"
bridge.howAreYou( buf, len )
print buf.to_s, "\n"

puts("2 M 1")

br = TECS::TsKernel.new( "BridgeKernel2" )
#br.delay(1000)
10.times{
	br.delay(100)
#	TECS::TsKernel.delay(100)
	puts("2 M x")
}

puts("2 M 2")
