//
// Copyright (c) 2016 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include "benchmark.hpp"
#include "boost/msm-lite.hpp"

namespace msm = boost::msm::lite;

struct e1 {};
struct e2 {};
struct e3 {};
struct e4 {};
struct e5 {};
struct e6 {};
struct e7 {};
struct e8 {};
struct e9 {};
struct e10 {};
struct e11 {};
struct e12 {};
struct e13 {};
struct e14 {};
struct e15 {};
struct e16 {};
struct e17 {};
struct e18 {};
struct e19 {};
struct e20 {};
struct e21 {};
struct e22 {};
struct e23 {};
struct e24 {};
struct e25 {};
struct e26 {};
struct e27 {};
struct e28 {};
struct e29 {};
struct e30 {};
struct e31 {};
struct e32 {};
struct e33 {};
struct e34 {};
struct e35 {};
struct e36 {};
struct e37 {};
struct e38 {};
struct e39 {};
struct e40 {};
struct e41 {};
struct e42 {};
struct e43 {};
struct e44 {};
struct e45 {};
struct e46 {};
struct e47 {};
struct e48 {};
struct e49 {};
struct e50 {};

auto guard = [] { return true; };
auto action = [] {};

int main() {
  struct c {
    auto configure() const noexcept {
      using namespace msm;
      state<class idle> idle;
      state<class s1> s1;
      state<class s2> s2;
      state<class s3> s3;
      state<class s4> s4;
      state<class s5> s5;
      state<class s6> s6;
      state<class s7> s7;
      state<class s8> s8;
      state<class s9> s9;
      state<class s10> s10;
      state<class s11> s11;
      state<class s12> s12;
      state<class s13> s13;
      state<class s14> s14;
      state<class s15> s15;
      state<class s16> s16;
      state<class s17> s17;
      state<class s18> s18;
      state<class s19> s19;
      state<class s20> s20;
      state<class s21> s21;
      state<class s22> s22;
      state<class s23> s23;
      state<class s24> s24;
      state<class s25> s25;
      state<class s26> s26;
      state<class s27> s27;
      state<class s28> s28;
      state<class s29> s29;
      state<class s30> s30;
      state<class s31> s31;
      state<class s32> s32;
      state<class s33> s33;
      state<class s34> s34;
      state<class s35> s35;
      state<class s36> s36;
      state<class s37> s37;
      state<class s38> s38;
      state<class s39> s39;
      state<class s40> s40;
      state<class s41> s41;
      state<class s42> s42;
      state<class s43> s43;
      state<class s44> s44;
      state<class s45> s45;
      state<class s46> s46;
      state<class s47> s47;
      state<class s48> s48;
      state<class s49> s49;

      // clang-format off
      return make_transition_table(
	   idle(initial) == s1 + event<e1> [guard] / action
	 , s1 == s2 + event<e2> [guard] / action
	 , s2 == s3 + event<e3> [guard] / action
	 , s3 == s4 + event<e4> [guard] / action
	 , s4 == s5 + event<e5> [guard] / action
	 , s5 == s6 + event<e6> [guard] / action
	 , s6 == s7 + event<e7> [guard] / action
	 , s7 == s8 + event<e8> [guard] / action
	 , s8 == s9 + event<e9> [guard] / action
	 , s9 == s10 + event<e10> [guard] / action
	 , s10 == s11 + event<e11> [guard] / action
	 , s11 == s12 + event<e12> [guard] / action
	 , s12 == s13 + event<e13> [guard] / action
	 , s13 == s14 + event<e14> [guard] / action
	 , s14 == s15 + event<e15> [guard] / action
	 , s15 == s16 + event<e16> [guard] / action
	 , s16 == s17 + event<e17> [guard] / action
	 , s17 == s18 + event<e18> [guard] / action
	 , s18 == s19 + event<e19> [guard] / action
	 , s19 == s20 + event<e20> [guard] / action
	 , s20 == s21 + event<e21> [guard] / action
	 , s21 == s22 + event<e22> [guard] / action
	 , s22 == s23 + event<e23> [guard] / action
	 , s23 == s24 + event<e24> [guard] / action
	 , s24 == s25 + event<e25> [guard] / action
	 , s25 == s26 + event<e26> [guard] / action
	 , s26 == s27 + event<e27> [guard] / action
	 , s27 == s28 + event<e28> [guard] / action
	 , s28 == s29 + event<e29> [guard] / action
	 , s29 == s30 + event<e30> [guard] / action
	 , s30 == s31 + event<e31> [guard] / action
	 , s31 == s32 + event<e32> [guard] / action
	 , s32 == s33 + event<e33> [guard] / action
	 , s33 == s34 + event<e34> [guard] / action
	 , s34 == s35 + event<e35> [guard] / action
	 , s35 == s36 + event<e36> [guard] / action
	 , s36 == s37 + event<e37> [guard] / action
	 , s37 == s38 + event<e38> [guard] / action
	 , s38 == s39 + event<e39> [guard] / action
	 , s39 == s40 + event<e40> [guard] / action
	 , s40 == s41 + event<e41> [guard] / action
	 , s41 == s42 + event<e42> [guard] / action
	 , s42 == s43 + event<e43> [guard] / action
	 , s43 == s44 + event<e44> [guard] / action
	 , s44 == s45 + event<e45> [guard] / action
	 , s45 == s46 + event<e46> [guard] / action
	 , s46 == s47 + event<e47> [guard] / action
	 , s47 == s48 + event<e48> [guard] / action
	 , s48 == s49 + event<e49> [guard] / action
	 , s49 == idle + event<e50> [guard] / action
    );
      // clang-format on
    }
  };

  msm::sm<c> sm;

  benchmark_execution_speed([&] {
    for (auto i = 0; i < 1'000'000; ++i) {
      sm.process_event(e1());
      sm.process_event(e2());
      sm.process_event(e3());
      sm.process_event(e4());
      sm.process_event(e5());
      sm.process_event(e6());
      sm.process_event(e7());
      sm.process_event(e8());
      sm.process_event(e9());
      sm.process_event(e10());
      sm.process_event(e11());
      sm.process_event(e12());
      sm.process_event(e13());
      sm.process_event(e14());
      sm.process_event(e15());
      sm.process_event(e16());
      sm.process_event(e17());
      sm.process_event(e18());
      sm.process_event(e19());
      sm.process_event(e20());
      sm.process_event(e21());
      sm.process_event(e22());
      sm.process_event(e23());
      sm.process_event(e24());
      sm.process_event(e25());
      sm.process_event(e26());
      sm.process_event(e27());
      sm.process_event(e28());
      sm.process_event(e29());
      sm.process_event(e30());
      sm.process_event(e31());
      sm.process_event(e32());
      sm.process_event(e33());
      sm.process_event(e34());
      sm.process_event(e35());
      sm.process_event(e36());
      sm.process_event(e37());
      sm.process_event(e38());
      sm.process_event(e39());
      sm.process_event(e40());
      sm.process_event(e41());
      sm.process_event(e42());
      sm.process_event(e43());
      sm.process_event(e44());
      sm.process_event(e45());
      sm.process_event(e46());
      sm.process_event(e47());
      sm.process_event(e48());
      sm.process_event(e49());
      sm.process_event(e50());
    }
  });
  benchmark_memory_usage(sm);
};
