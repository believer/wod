module.exports = {
  setupFiles: ["<rootDir>/src/setupTests.js"],
  testMatch: ["<rootDir>/lib/**/__tests__/*_test.bs.js"],
  transformIgnorePatterns: [],
  transform: {
    "^.+\\.jsx?$": "babel-jest"
  }
};
