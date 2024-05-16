# macOS Unified Logging Test

Here are a set of basic programs to test macOS Unified Logging. We are using these to debug issues with messages sent to Unified Logging not being received or shown.

Basics of Unified Logging are assumed and are not documented here.

## Setup

Open a shell and run:

```bash
bin/stream
```

Now open another shell and set persistence for the test subsystem:

```bash
bin/persist
```

## C language

Compile and run:

```bash
(cd c && bin/build && target/main)
```

## Retrieval

```bash
bin/last
```
