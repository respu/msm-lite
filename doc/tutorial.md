All code examples include `boost/msm-lite.hpp` as well as declare a convienent msm namespace alias.

```cpp
#include <boost/msm-lite.hpp>
namespace msm = boost::msm::lite;
```

###0. Read Boost.MSM - eUML documentation
* [Boost.MSM - UML Short Guide](http://www.boost.org/doc/libs/1_60_0/libs/msm/doc/HTML/ch02.html)
* [Boost.MSM - eUML Documentation](http://www.boost.org/doc/libs/1_60_0/libs/msm/doc/HTML/ch03s04.html)

###1. Create events and states

State machine is composed of finite number of states and transitions which are triggered via events.

An Event is just a unique type, which will be process by the state machine.

```cpp
struct my_event { ... };
```

A State can have entry/exit behaviour which is executed whenever state is entered or left and
represents current location of the state machine processing.

To create a state below snipped might be used.

```cpp
msm::state<class idle> idle;
// or
auto idle = msm::state<class idle>{};
```

If you happen to have a Clang/GCC compiler, you can create a state on the fly.

```cpp
using namespace msm;
auto state  = "idle"_s;
```

Howerver, please notice that above solution is a non-standard extension for Clang/GCC.

`msm-lite` states cannot have data as data is injected directly into guards/actions instead.

A state machine might be a state itself.

```cpp
msm::state<msm::sm<state_machine>> composite;
```

`msm-lite` supports `terminate` state, which stops process events to be processed.

States are printable too.

```cpp
assert(string("idle") == "idle"_s.c_str());
```

![CPP(BTN)](Run_States_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/states.cpp)
![CPP(BTN)](Run_Composite_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/composite.cpp)

###2. Create guards and actions

Guards and actions are callable objects which will be executed by the state machine in order to verify whether a transition, followed by an action should take place.

Guard is required to return boolean value.
```cpp
auto guard1 = [] {
	return true;
};

auto guard2 = [](int, double) { // guard with dependencies
	return true;
};

auto guard3 = [](int, auto event, double) { // guard with an event and dependencies
	return true;
};

struct guard4 {
    bool operator()() const noexcept {
        return true;
    }
};
```

Action is required not to return.
```cpp
auto action1 = [] { };
auto action2 = [](int, double) { }; // action with dependencies
auto action3 = [](int, auto event, double) { }; // action with an event and dependencies
struct action4 {
    void operator()() noexcept { }
};
```

![CPP(BTN)](Run_Events_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/action_guards.cpp)

###3. Create a transition table

When we have states and events handy we can finally create a transition table which represents
our transitions.

`msm-lite` is using eUML-like DSL in order to be as close as possible to UML design.

* Transition Table DSL

    | Expression | Description |
    |------------|-------------|
    | state + event<e> [ guard ] | internal transition on event e when guard |
    | src\_state == dst\_state / [] {} | anonymous transition with action |
    | src\_state == dst\_state + event<e> | transition on event e without guard or action |
    | src\_state == dst\_state + event<e> [ guard ] / action | transition from src\_state to dst\_state on event e with guard and action |
    | src\_state == dst\_state + event<e> [ guard && (![]{return true;} && guard2) ] / (action, action2, []{}) | transition from src\_state to dst\_state on event e with guard and action |

To create a transition table [`make_transition_table`](user_guide.md#make_transition_table-state-machine) is provided.

```cpp
using namespace msm;
make_transition_table(
	"src_state"_s == "dst_state"_s + event<my_event> [ guard ] / action
);
```

![CPP(BTN)](Run_Transition_Table_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/transitions.cpp)

###4. Set initial states

Initial states tells the state machine where to start.

```cpp
using namespace msm;
make_transition_table(
	"src_state"_s(initial) == "dst_state"_s + event<my_event> [ guard ] / action,
	"dst_state"_s          == terminate     + event<game_over>
);
```

You can have more than one initial state. Both initial states will be executed in pseudo parallel way
and are called orthogonal regions.

```cpp
using namespace msm;
make_transition_table(
	"region_1"_s(initial) == "dst_state1"_s + event<my_event1> [ guard ] / action,
	"dst_state1"_s          == terminate    + event<game_over>

	"region_2"_s(initial) == "dst_state2"_s + event<my_event2> [ guard ] / action,
	"dst_state2"_s          == terminate    + event<game_over>
);
```

![CPP(BTN)](Run_Orthogonal_Regions_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/orthogonal_regions.cpp)
![CPP(BTN)](Run_Hello_World_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/hello_world.cpp)

###5. Create a state machine

State machine is an abstraction for transition table holding current states and processing events.
To create a state machine, firstly we have to configure our transition table.

```cpp
class example {
public:
	auto configure() noexcept {
		using namespace msm;
		return make_transition_table(
			"src_state"_s(initial) == "dst_state"_s + event<my_event> [ guard ] / action,
			"dst_state"_s          == terminate     + event<game_over>
		);
	}
};
```

Having transition table configured we can create a state machine.

```cpp
msm::sm<example> sm;
```

State machine constructor is responsible to provide required dependencies for actions and guards.

```cpp
                             /---- event
                            |
auto guard = [](double d, auto event) { return true; }
                   |
                   \-------\
                           |
auto action = [](int i){}  |
                 |         |
                 |         |
            /---/  /------/
           |      /
msm::sm<exmple> s{42, 87.0};

msm::sm<exmple> s{87.0, 42}; // order in which parameters have to passed is not specificied
```

Passing and maintaining a lot of dependencies might be tedious and require huge amount of boilerplate code.
In order to avoid it, Dependency Injection Library might be used to automate this process.
For example, we can use [experimental Boost.DI](https://github.com/boost-experimental/di).

```cpp
auto injector = di::make_injector(
    di::bind<>.to(42)
  , di::bind<interface>.to<implementation>()
);

auto sm = injector.create<sm<example>>();
assert(sm.process_event(e1{}));
```

![CPP(BTN)](Run_Hello_World_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/hello_world.cpp)
![CPP(BTN)](Run_Dependency_Injection_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/dependency_injection.cpp)
![CPP(BTN)](Run_eUML_Emulation_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/euml_emulation.cpp)

###6. Process events

State machine is a simple creature. The main feature of it is to process events.
In order to do so, `process_event` method might be used.

```cpp
msm::sm<example> sm;

assert(sm.process_event(my_event{})); // returns true when handled
assert(!sm.process_event(int{})); // not handled by the state machine
```

`msm-lite` also provides a way to dispatch dynamically created events into the state machine.

```cpp
struct runtime_event {
  int id = 0;
};
struct event1 {
  static constexpr auto id = 1;
};

auto dispatch_event = msm::make_dispatch_table<runtime_event, 1 /*min*/, 5 /*max*/>(sm);
  {
    runtime_event event{1};
    assert(dispatch_event(event, event.id)); // will call sm.process(event1{});
  }
```

![CPP(BTN)](Run_Hello_World_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/hello_world.cpp)
![CPP(BTN)](Run_Dispatch_Table_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/dispatch_table.cpp)

###8. Testing a state machine

Sometimes it is useful to verify whether a state machine is in a specific states, for example, whether
we are in a terminate state or not. We can do it with `msm-lite` using `is` or `visit_current_states`
functionality.

```cpp
msm::sm<example> sm;
assert(sm.process_event(my_event{}));
assert(sm.is(terminate)); // is(terminate, s1, ...) when you have orthogonal regions

//or

sm.visit_current_states([](auto state) { std::cout << state.c_str() << std::endl; });
```

On top of that, `msm-lite` provides testing facilities to check state machine as a whole.
`set_current_states` method is available from `testing::sm` in order to set state machine
in a requested state.

```cpp
testing::sm<example> sm{fake_data...};
sm.set_current_states("s3"_s); // set_current_states("s3"_s, "s1"_s, ...) for orthogonal regions
assert(sm.process_event(event{}));
assert(sm.is(terminate));
```

![CPP(BTN)](Run_Testing_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/testing.cpp)

###9. Debugging a state machine

`msm-lite` provides logging capabilities in order to print state machine flow.
To enable logging you have to define `BOOST_MSM_LOG`.

```cpp
template <class SM, class TEvent>
void log_process_event(const TEvent&) {
  printf("[%s][process_event] %s\n", typeid(SM).name(), typeid(TEvent).name());
}

template <class SM, class TAction, class TEvent>
void log_guard(const TAction&, const TEvent&, bool result) {
  printf("[%s][guard] %s %s %s\n", typeid(SM).name(), typeid(TAction).name(), typeid(TEvent).name(),
         (result ? "[OK]" : "[Reject]"));
}

template <class SM, class TAction, class TEvent>
void log_action(const TAction&, const TEvent&) {
  printf("[%s][action] %s %s\n", typeid(SM).name(), typeid(TAction).name(), typeid(TEvent).name());
}

template <class SM, class TSrcState, class TDstState>
void log_state_change(const TSrcState& src, const TDstState& dst) {
  printf("[%s][transition] %s -> %s\n", typeid(SM).name(), src.c_str(), dst.c_str());
}

#define BOOST_MSM_LOG(T, SM, ...) log_##T<SM>(__VA_ARGS__)
#include <boost/msm-lite.hpp>
```

![CPP(BTN)](Run_Logging_Example|https://raw.githubusercontent.com/boost-experimental/msm-lite/master/example/logging.cpp)
