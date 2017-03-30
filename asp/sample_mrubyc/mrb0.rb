puts("0 M 0")

p "creating bridge 0"
bridge = TECS::TsSample.new( "SimpleBridge0" )
times = 5
p "TEST sayHello #{times} times"
bridge.sayHello( times )
#len = 32
len = 5
buf = TECS::CharPointer.new( len )

# howAreYou ÇåƒÇ—èoÇ∑
p "TEST howAreYou"
bridge.howAreYou( buf, len )
print buf.to_s, "\n"

puts("0 M 1")

br = TECS::TsKernel.new( "BridgeKernel0" )
#br.delay(1000)
10.times{
	br.delay(100)
#	TECS::TsKernel.delay(100)
	puts("0 M x")
}

puts("0 M 2")
