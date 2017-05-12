#define lines
#define wicker
#define vignette
//#define rotate
mat2 rot(float deg)
{
    return mat2(cos(deg),-sin(deg),
                sin(deg), cos(deg));

}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float t = iGlobalTime*.3;
	vec2 uv = fragCoord.xy / iResolution.xy;
    uv-=.5;
    vec2 bp = uv*2.;
    uv*=5.5-(sin(t)/2.);//;

    uv*=rot(iMouse.x/50.);
    #ifdef rotate
    uv*=rot(iMouse.x/50.-t);
    #endif

    uv=abs(uv)-1.5;
    uv*=rot(t*.2);
    uv=abs(uv);
    uv*=rot(t/2.);
    uv*=rot(t/1.1);
    uv=-abs(uv-.33);
    uv*=rot(t*.6);
    uv=mod(uv,.8)-.4;
    uv=abs(uv*1.4);

    float r = smoothstep(uv.x,.32,.31);
    r*=smoothstep(uv.x, .31,.32);
    r*=smoothstep(uv.y, .32,.31);
    r*=smoothstep(uv.y, .31,.32);
    vec4 tex = texture(iChannel0,vec2(.33*uv-(t+sin(t))*.15))*2.;//u  //v*c-t

    #ifdef wicker
    tex =texture(iChannel1,uv);
    #endif

    #ifdef vignette
    tex *= 1.-pow(length(bp*bp*bp*bp)*1.01,10.); //https://www.shadertoy.com/view/4sfXDs
	#endif
    fragColor = vec4(tex);

    #ifdef lines
    fragColor = vec4(r*tex);
    #endif
}
/* 2015 Passion */