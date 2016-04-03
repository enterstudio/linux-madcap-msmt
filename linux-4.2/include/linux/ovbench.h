#ifndef _OVBENCH_H_
#define _OVBENCH_H_

/*
 * For inserting rdtsc in each points of packet TX data path.
 */

#define OVBENCH_TIMESTAMPNUM	18

static inline __u64
rdtsc(void)
{
	__u32 lo, hi;
	__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
	return (__u64)hi << 32 | lo;
}

#define SKB_OVBENCH(skb) (skb->ovbench_type > 0)
#define SKB_OVBENCH_ENCAPED(skb) (skb->ovbench_encaped)


#define OVTYPE_NOENCAP	1
#define OVTYPE_IPIP	2
#define OVTYPE_GRE	3
#define OVTYPE_GRETAP	4
#define OVTYPE_VXLAN	5
#define OVTYPE_NSH	6


#define first_xmit			ovbench_timestamp[0]
#define udp_tunnel_xmit_skb_in		ovbench_timestamp[1]
#define ip_tunnel_xmit_in		ovbench_timestamp[2]
#define iptunnel_xmit_in		ovbench_timestamp[3]
#define ip_local_out_sk_in		ovbench_timestamp[4]
#define dev_queue_xmit_in	       	ovbench_timestamp[5]

#define ip_local_out_sk_in_encaped	ovbench_timestamp[6]
#define dev_queue_xmit_in_encaped	ovbench_timestamp[7]

#define ip_routing_start		ovbench_timestamp[8]
#define ip_routing_end			ovbench_timestamp[9]


#define ipip_tunnel_xmit_in 		ovbench_timestamp[10]
// ip_tunnel_xmit_in
// ip_tunnel_xmit_end

#define ipgre_xmit_in 			ovbench_timestamp[10]
#define gre_xmit_in 			ovbench_timestamp[11]
#define	gre_encap_end			ovbench_timestamp[12]
// ip_tunnel_xmit_in
// ip_tunnel_xmit_end

#define gre_tap_xmit_in 		ovbench_timestamp[10]
#define gre_xmit_in 			ovbench_timestamp[11]
// ip_tunnel_xmit_in
// ip_tunnel_xmit_end

#define vxlan_xmit_in 			ovbench_timestamp[10]
#define vxlan_xmit_one_in 		ovbench_timestamp[11]
#define vxlan_xmit_skb_in 		ovbench_timestamp[12]
// udp_tunnel_xmit_skb_in
// udp_tunnel_xmit_skb_end


#define nsh_xmit_in			ovbench_timestamp[10]
#define nsh_xmit_lookup_end		ovbench_timestamp[11]
#define nsh_xmit_vxlan_in		ovbench_timestamp[12]
#define nsh_xmit_vxlan_skb_in		ovbench_timestamp[13]
// udp_tunnel_xmit_skb_in
// udp_tunnel_xmit_skb_end


/* used by raven only. not in sk_buff. */
#define raven_xmit_in			ovbench_timestamp[14]

/* software madcap */
#define sfmc_routing_in			ovbench_timestamp[14]
#define sfmc_udp_encap_in		ovbench_timestamp[15]
#define sfmc_ip_encap_in		ovbench_timestamp[16]
#define sfmc_encap_end			ovbench_timestamp[17]


#endif /* _OVBENCH_USER_H_ */
