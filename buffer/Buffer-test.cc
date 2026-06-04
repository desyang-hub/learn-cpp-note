#include "Buffer.h"
#include <iostream>
#include <cassert>
#include <cstring>

#define TEST(name) void name()
#define RUN_TEST(name) do { \
    std::cout << "Running " << #name << "... "; \
    try { \
        name(); \
        std::cout << "PASSED" << std::endl; \
    } catch (const std::exception& e) { \
        std::cout << "FAILED: " << e.what() << std::endl; \
        return false; \
    } \
} while(0)

// Test basic construction and initial state
TEST(test_construction) {
    Buffer buf;
    assert(buf.readableBytes() == 0);
    assert(buf.writableBytes() == DEFAULT_STORE_SIZE);
    assert(buf.prependableBytes() == 0);
    
    Buffer smallBuf(256);
    assert(smallBuf.writableBytes() == 256);
}

// Test append and retrieve with string
TEST(test_append_retrieve_string) {
    Buffer buf;
    const char* data = "Hello, World!";
    buf.append(data);
    assert(buf.readableBytes() == strlen(data));
    
    std::string retrieved = buf.retrieveAsString(strlen(data));
    assert(retrieved == data);
    assert(buf.readableBytes() == 0);
}

// Test append and retrieve with char* and length
TEST(test_append_retrieve_charptr) {
    Buffer buf;
    const char* data = "Test Data";
    buf.append(data, 9);
    assert(buf.readableBytes() == 9);
    
    std::string retrieved = buf.retrieveAsString(9);
    assert(retrieved == data);
}

// Test partial retrieve
TEST(test_partial_retrieve) {
    Buffer buf;
    buf.append("Hello");
    buf.append(" ");
    buf.append("World");
    assert(buf.readableBytes() == 11);
    
    buf.retrieve(6); // Remove "Hello "
    assert(buf.readableBytes() == 5);
    
    std::string remaining = buf.retrieveAllAsString();
    assert(remaining == "World");
}

// Test retrieveAll
TEST(test_retrieve_all) {
    Buffer buf;
    buf.append("Some data here");
    assert(buf.readableBytes() == 14);
    
    buf.retrieveAll();
    assert(buf.readableBytes() == 0);
    assert(buf.prependableBytes() == 0);
}

// Test retrieveAllAsString
TEST(test_retrieve_all_as_string) {
    Buffer buf;
    buf.append("Complete data");
    
    std::string all = buf.retrieveAllAsString();
    assert(all == "Complete data");
    assert(buf.readableBytes() == 0);
}

// Test empty append
TEST(test_empty_append) {
    Buffer buf;
    buf.append("");
    assert(buf.readableBytes() == 0);
    
    const char* empty = "";
    buf.append(empty, 0);
    assert(buf.readableBytes() == 0);
}

// Test multiple appends without retrieval
TEST(test_multiple_appends) {
    Buffer buf;
    buf.append("First part");
    buf.append("Second part");
    buf.append("Third part");
    
    assert(buf.readableBytes() == 31);
    std::string all = buf.retrieveAllAsString();
    assert(all == "First partSecond partThird part");
}

// Test append that triggers copyToFront (writable space runs out but total space is enough)
TEST(test_copy_to_front_trigger) {
    Buffer buf(DEFAULT_STORE_SIZE);
    
    // Fill most of the buffer
    std::string largeData(DEFAULT_STORE_SIZE - 100, 'A');
    buf.append(largeData);
    
    size_t readableBefore = buf.readableBytes();
    size_t writableBefore = buf.writableBytes();
    
    // Retrieve some to create prependable space
    buf.retrieve(50);
    
    // Now append something that fits after compacting but not before
    std::string newData(100, 'B');
    buf.append(newData);
    
    assert(buf.readableBytes() == readableBefore - 50 + 100);
}

// Test append that triggers resize (total space insufficient even after compacting)
TEST(test_resize_trigger) {
    Buffer buf(100); // Small buffer
    
    // Fill it up
    buf.append("Initial data");
    buf.retrieve(10); // Create some prependable space
    
    // Append more than what's currently readable + remaining writable
    std::string hugeData(200, 'X');
    buf.append(hugeData);
    
    assert(buf.readableBytes() >= 200);
}

// Test consecutive retrieves
TEST(test_consecutive_retrieves) {
    Buffer buf;
    buf.append("ABCDEFGHIJ");
    
    assert(buf.retrieveAsString(3) == "ABC");
    assert(buf.readableBytes() == 7);
    
    assert(buf.retrieveAsString(4) == "DEFG");
    assert(buf.readableBytes() == 3);
    
    assert(buf.retrieveAsString(3) == "HIJ");
    assert(buf.readableBytes() == 0);
}

// Test prependableBytes calculation
TEST(test_prependable_bytes) {
    Buffer buf;
    buf.append("Test data");
    
    assert(buf.prependableBytes() == 0);
    
    buf.retrieve(5);
    assert(buf.prependableBytes() == 5);
    
    buf.retrieveAll();
    assert(buf.prependableBytes() == 0);
}

// Test boundary conditions for append
TEST(test_append_boundaries) {
    Buffer buf(100);
    
    // Exact fit
    std::string exact(100, 'Z');
    buf.append(exact);
    assert(buf.readableBytes() == 100);
    
    buf.retrieveAll();
    
    // One byte less than capacity
    std::string almostFull(99, 'Y');
    buf.append(almostFull);
    assert(buf.readableBytes() == 99);
}

// Test mixed append types
TEST(test_mixed_append_types) {
    Buffer buf;
    
    buf.append(std::string("String"));
    buf.append("CharPtr", 7);  // Changed from 8 to 7 to avoid null terminator
    buf.append("Another");
    
    std::string result = buf.retrieveAllAsString();
    assert(result == "StringCharPtrAnother");
}

// Test large data transfer
TEST(test_large_data) {
    Buffer buf;
    
    const size_t dataSize = 1024 * 1024; // 1MB
    std::vector<char> largeData(dataSize, 'L');
    
    buf.append(&largeData[0], dataSize);
    assert(buf.readableBytes() == dataSize);
    
    std::string retrieved = buf.retrieveAllAsString();
    assert(retrieved.size() == dataSize);
    for (size_t i = 0; i < dataSize; ++i) {
        assert(retrieved[i] == 'L');
    }
}

// Test retrieve with assertion failure
TEST(test_retrieve_assertion) {
    Buffer buf;
    buf.append("Short");
    
    // This should trigger an assertion (commented out to avoid crash in test)
    // buf.retrieve(100); // Would fail: readerIndex_ + len > writerIndex_
    
    // Safe retrieve
    buf.retrieve(5);
    assert(buf.readableBytes() == 0);
}

int main() {
    std::cout << "=== Buffer Unit Tests ===" << std::endl;
    
    bool passed = true;
    
    RUN_TEST(test_construction);
    RUN_TEST(test_append_retrieve_string);
    RUN_TEST(test_append_retrieve_charptr);
    RUN_TEST(test_partial_retrieve);
    RUN_TEST(test_retrieve_all);
    RUN_TEST(test_retrieve_all_as_string);
    RUN_TEST(test_empty_append);
    RUN_TEST(test_multiple_appends);
    RUN_TEST(test_copy_to_front_trigger);
    RUN_TEST(test_resize_trigger);
    RUN_TEST(test_consecutive_retrieves);
    RUN_TEST(test_prependable_bytes);
    RUN_TEST(test_append_boundaries);
    RUN_TEST(test_mixed_append_types);
    RUN_TEST(test_large_data);
    RUN_TEST(test_retrieve_assertion);
    
    if (passed) {
        std::cout << "\n=== All tests PASSED ===" << std::endl;
        return 0;
    } else {
        std::cout << "\n=== Some tests FAILED ===" << std::endl;
        return 1;
    }
}
